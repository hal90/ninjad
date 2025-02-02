#include "Game.h"
#include <iostream>
using namespace std;

Game::Game()
{
	mainWnd = NULL;
	mainLvl = NULL;
	ninjhold = NULL;
	player = NULL;
	background = NULL;
	hud = NULL;
	player = NULL;
	collision = NULL;
	pauseScreen = NULL;
	completeScreen = NULL;
	clockHold = NULL;

	mptr = new Sprite();
	mptr->SetImage(*ImgHolder::getInst()->mousePtr);
	mptr->SetCenter(0,0);
	mptr->SetPosition(0,0);

	FPS = 0;
	ninjasIn = 0;
	paused = false;
	reset = false;
	levelComplete = false;

	SndHolder::getInst()->sndWdupNinja.Play();

}

Game::~Game()
{
	if(mainWnd){
		delete mainWnd;
		mainWnd = NULL;
	}
	if(mainLvl)
		delete mainLvl;
	if(ninjhold)
		delete ninjhold;
	if(player)
		delete player;
	if(background)
		delete background;
	if(hud)
		delete hud;
	if(pauseScreen)
		delete pauseScreen;
	if(completeScreen)
		delete completeScreen;
	if(clockHold)
		delete clockHold;
	if(collision)
		delete collision;
	//delete InputHandler::getInstance();
	if(mptr)
		delete mptr;
}

bool Game::init(int level)
{
	input = &InputHandler::getInstance();
	mainWnd = new RenderWindow(VideoMode(1024, 768, 32), "Ninja'd", Style::Close, WindowSettings());
	mainWnd->Show(false);
	FPS = 30;
	mainWnd->SetFramerateLimit(FPS);
	mainWnd->SetIcon(16, 16, ImgHolder::getInst()->icon->GetPixelsPtr());
	mainWnd->ShowMouseCursor(false);

	background = new Sprite();
	background->SetImage(*ImgHolder::getInst()->background);

	pauseScreen = new Sprite();
	pauseScreen->SetImage(*ImgHolder::getInst()->pauseScreen);
	pauseScreen->SetPosition(96, 160);

	completeScreen = new Sprite();
	completeScreen->SetImage(*ImgHolder::getInst()->levelComplete); 
	completeScreen->SetPosition(0, 0);

	hud = new HUDisplay();

	currLevel = level;
	mainLvl = new Level(currLevel);
	ninjhold = new NinjaHolder(mainLvl->getNNinjas(), 0, 6, mainLvl->getEntryDoor()); //mainLvl->getNrOfNinjas()
	player = new Player(mainLvl->getStartPos());
	collision = new Collision();

	ninjasIn = 0;
	levelComplete = false;
	clockHold = new Clock();
	return false;
}

int Game::run()
{
	bool running = true;
	mainWnd->Show(true);
	while(running)
	{
		//float framerate = 1.0f/ mainWnd->GetFrameTime();
		//cout << framerate << endl;		
		checkCollision();
		running = update();
		render();
		
	}

	//return -1 = quit bak till menyn, -2 = reset till samma bana igen,  -3 = next level
	if(levelComplete)
	{
		showLevelComplete();
		return -3;
	}
	else if(reset)
		return -2;		
	else
		return -1;
}

void Game::cleanUp()
{

}

void Game::checkCollision()
{
	//L�ter kollisionsklass sk�ta detta.
	for(int i=0;i<ninjhold->getNr();i++)
		collision->ninja(mainLvl->getBlocks(), ninjhold->getNinjas(i), mainLvl->getNr());

	collision->player(mainLvl->getBlocks(), player, mainLvl->getNr(), mainWnd);
}

bool Game::update()
{
	bool run = true;
	Event e;
	
	while (mainWnd->GetEvent(e) && run)
		run = eventHandler(e);				//Flyttade ner hela den h�r superscoopen till en egen funktion ist�llet. Fresh.
	
	if(!run)
		return false;

	if(!paused)
	{
		if(clockHold->GetElapsedTime() > 3 && !ninjhold->getNinjas(0)->isActive())
			for(int i = 0; i < ninjhold->getNr(); i++)
				ninjhold->getNinjas(i)->setActive(true);
	
		for(int i=0;i<ninjhold->getNr();i++)
			ninjhold->getNinjas(i)->update();

		player->update(mainWnd);
		player->updateSprite(mainWnd);

		run = !isNextLevel();

		hud->update(mainLvl, player, ninjasIn, player->getBlockSelected());				//Ska skicka levelID, Ninjor max, ninjor inne, antal block <- levelID osv borde vara ints i main.cpp
	}
	
	return run;
}

bool Game::eventHandler(Event e)
{
	if(e.Type == Event::MouseMoved)
		mptr->SetPosition(e.MouseMove.X, e.MouseMove.Y);
	if(e.Type == Event::MouseButtonPressed)
	{
		if (!(InputHandler::getInstance().getMousePosX(mainWnd) > 96 && InputHandler::getInstance().getMousePosX(mainWnd) < 608 
			&& InputHandler::getInstance().getMousePosY(mainWnd) > 160 && InputHandler::getInstance().getMousePosY(mainWnd) < 672))			//Om musen �r inom HUD
		{
			hud->HUDClicked(mainWnd);
		}
	}
	else if(e.Type == Event::MouseButtonReleased)
	{
		if(!(InputHandler::getInstance().getMousePosX(mainWnd) > 96 && InputHandler::getInstance().getMousePosX(mainWnd) < 608 
			&& InputHandler::getInstance().getMousePosY(mainWnd) > 160 && InputHandler::getInstance().getMousePosY(mainWnd) < 672))	
		{
			int lvl;

			switch(hud->HUDReleased(mainWnd))
			{
			case 0:
				break;
			case 1:
				e.Type = Event::Closed;
				break;
			case 2:
				reset = true;
				e.Type = Event::Closed;
				break;
			case 3:
				if(paused)
				{
					SndHolder::getInst()->sndOn(true);
					paused = false;
				}
				else
				{
					SndHolder::getInst()->sndOn(false);
					paused = true;
				}
				break;
			case 4:				
				SndHolder::getInst()->onoff();				
				break;				
			case 5:
				if(FPS < 100 && !paused)
				{
					mainWnd->SetFramerateLimit(FPS + 2);
					FPS += 2;
				}
				break;
			case 6:
				if(FPS > 30 && !paused)
				{
					mainWnd->SetFramerateLimit(FPS - 2);
					FPS -= 2;
				}
				break;
			}	
		}
		else if(!input->isPressJump(mainWnd))
		{			

			Vector2f mousePos(input->getMousePosX(mainWnd), input->getMousePosY(mainWnd));
			bool add=true;
			float x = mousePos.x - player->curAnim->sprite.GetPosition().x;
			float y = mousePos.y - player->curAnim->sprite.GetPosition().y; 
			float magnitude = sqrt((x*x)+(y*y));
			x /= magnitude;
			y /= magnitude;

			mainLvl->addBlock(player->getBlockSelected(),player->curAnim->sprite.GetPosition().x+(32*x), player->curAnim->sprite.GetPosition().y+(32*y), 0, player,ninjhold);
			
		}
	}

		sf::Vector2f mousePos(input->getMousePosX(mainWnd), input->getMousePosY(mainWnd));
		float angle;
		angle = 57.3065f * atan2(mousePos.y - player->curAnim->sprite.GetPosition().y, mousePos.x - player->curAnim->sprite.GetPosition().x);
		player->getHand()->SetRotation(360-angle);

	if (e.Type == Event::Closed)
	{
		mainWnd->Close();
		return false;
	}

	player->setDirection(!(player->curAnim->sprite.GetPosition().x > mousePos.x));
	return true;
}

void Game::render()
{	
	mainWnd->Clear(Color(255, 255, 255));
	mainWnd->Draw(*background);
	hud->render(mainWnd);
	mainLvl->render(mainWnd);
	for(int i=0;i<ninjhold->getNr();i++)
		if(ninjhold->getNinjas(i)->getDrawn()==true)
			mainWnd->Draw(ninjhold->getNinjas(i)->curAnim->sprite);
	mainWnd->Draw(player->curAnim->sprite);
	mainWnd->Draw(*player->getHand());

	if(paused)
		mainWnd->Draw(*pauseScreen);

	mainWnd->Draw(*mptr);
	mainWnd->Display();
}


unsigned short Game::getCompleteNinjas()
{
	unsigned short num = 0;

	for(int i = 0; i < this->ninjhold->getNr(); i++)
	{
		if(ninjhold->getNinjas(i)->getComplete())
			num++;
	}

	return num;
}

bool Game::isNextLevel()
{

	ninjasIn = getCompleteNinjas();

	if(ninjasIn >= mainLvl->getNNinjReq() && collision->isPlayerAtExit(player, mainLvl->getExitDoor()))
	{
		levelComplete = true;
		return true;
	}

	return false;
}

void Game::showLevelComplete()
{
	SndHolder::getInst()->sndSexyNinja.Play();

	Event e;
	bool stop = false;
	mainWnd->Draw(*completeScreen);
	mainWnd->Display(); 
	unsigned short ticks = 0;
	while(!stop)
	{
		while (mainWnd->GetEvent(e))
		{
			if((e.Type == Event::MouseButtonReleased || e.Type == Event::KeyReleased) && ticks > 30)
				stop = true;

			ticks++;
		}
	}
	
}