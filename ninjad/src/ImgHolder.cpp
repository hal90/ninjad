#include "ImgHolder.h"
#include <iostream>

ImgHolder* ImgHolder::pInstance = NULL;

ImgHolder::ImgHolder()
{
	background = new Image();
	background->LoadFromFile("./data/sprites/game/background.png");
	background->SetSmooth(false);

	hud = new Image();
	hud->LoadFromFile("./data/sprites/hud/HUD.png");
	hud->SetSmooth(false);

	buttons = new Image();
	buttons->LoadFromFile("./data/sprites/hud/buttons.png");
	buttons->SetSmooth(false);

	arrows = new Image();
	arrows->LoadFromFile("./data/sprites/hud/arrows.png");
	arrows->SetSmooth(false);

	blocks = new Image();
	blocks->LoadFromFile("./data/sprites/game/Blocks.png");
	blocks->SetSmooth(false);

	blkSpringAct = new Image();
	blkSpringAct->LoadFromFile("./data/sprites/game/blk_spring.png");
	blkSpringAct->SetSmooth(false);

	blkFallAct = new Image();
	blkFallAct->LoadFromFile("./data/sprites/game/blk_fall.png");
	blkFallAct->SetSmooth(false);

	blkTrapIdle = new Image();
	blkTrapIdle->LoadFromFile("./data/sprites/game/blk_trap.png");
	blkTrapIdle->SetSmooth(false);

	ninRun = new Image();
	ninRun->LoadFromFile("./data/sprites/game/nin_run.png");
	ninRun->SetSmooth(false);

	ninSlide = new Image();
	ninSlide->LoadFromFile("./data/sprites/game/nin_slide.png");
	ninSlide->SetSmooth(false);

	ninFall = new Image();
	ninFall->LoadFromFile("./data/sprites/game/nin_fall.png");
	ninFall->SetSmooth(false);

	ninClimb = new Image();
	ninClimb->LoadFromFile("./data/sprites/game/nin_climb.png");
	ninClimb->SetSmooth(false);

	ninDeath = new Image();
	ninDeath->LoadFromFile("./data/sprites/game/nin_death.png");
	ninDeath->SetSmooth(false);

	ninArm = new Image();
	ninArm->LoadFromFile("./data/sprites/game/nin_arm.png");
	ninArm->SetSmooth(false);

	colorCode = new Image();
	colorCode->LoadFromFile("./data/sprites/game/colorcode.png");

	plyRun = new Image();
	plyRun->LoadFromFile("./data/sprites/game/ply_run.png");
	plyRun->SetSmooth(false);

	plyIdle = new Image();
	plyIdle->LoadFromFile("./data/sprites/game/ply_idle.png");
	plyIdle->SetSmooth(false);

	plyJump = new Image();
	plyJump->LoadFromFile("./data/sprites/game/ply_jump.png");
	plyJump->SetSmooth(false);

	hand = new Image();
	hand->LoadFromFile("./data/sprites/game/hand.png");
	plyJump->SetSmooth(false);

	pauseScreen = new Image();
	pauseScreen->LoadFromFile("./data/sprites/game/pauseScreen.png");
	pauseScreen->SetSmooth(false);

	icon = new Image();
	icon->LoadFromFile("./data/misc/icon.png");

	creditScreen = new Image();
	creditScreen->LoadFromFile("./data/sprites/menu/Creditscreen.png");
	creditScreen->SetSmooth(false);
	
	splashScreen = new Image();
	splashScreen->LoadFromFile("./data/sprites/menu/Splashscreen.png");
	splashScreen->SetSmooth(false);

	pressAnyKey = new Image();
	pressAnyKey->LoadFromFile("./data/sprites/menu/pressanykey.png");
	pressAnyKey->SetSmooth(false);

	menuButton = new Image();
	menuButton->LoadFromFile("./data/sprites/menu/button.png");
	menuButton->SetSmooth(false);

	menuNumbers = new Image();
	menuNumbers->LoadFromFile("./data/sprites/menu/numbers.png");
	menuNumbers->SetSmooth(false);

	title = new Image();
	title->LoadFromFile("./data/sprites/menu/title.png");
	title->SetSmooth(false);

	mousePtr = new Image();
	mousePtr->LoadFromFile("./data/sprites/menu/mptr.png");
	mousePtr->SetSmooth(false);

	howToPlay = new Image();
	howToPlay->LoadFromFile("./data/sprites/menu/howtoplay.png");
	howToPlay->SetSmooth(false);

	menuhud = new Image();
	menuhud->LoadFromFile("./data/sprites/menu/menuHUD.png");
	menuhud->SetSmooth(false);

	levelComplete = new Image();
	levelComplete->LoadFromFile("./data/sprites/game/levelComplete.png");	
	levelComplete->SetSmooth(false);

	blockFrame = new Image();
	blockFrame->LoadFromFile("./data/sprites/hud/blockFrame.png");
	blockFrame->SetSmooth(false);

	locked = new Image();
	locked->LoadFromFile("./data/sprites/menu/locked.png");
	locked->SetSmooth(false);

	nMaps = 25;
	maps = new Image*[nMaps];
	char dst[3];
	for(int i = 0; i < nMaps; i++)
	{
		itoa(i, dst, 10);
		std::string fname = "./data/maps/map";
		fname += dst;
		fname += ".png";
		maps[i] = new Image();
		maps[i]->LoadFromFile(fname);
				
		maps[i]->SetSmooth(false);
	}
	
}

ImgHolder::~ImgHolder()
{
	delete background;
	delete hud;
	delete buttons;
	delete arrows;
	delete blocks;
	delete blkSpringAct;
	delete blkFallAct;
	delete ninRun;
	delete ninSlide;
	delete ninFall;
	delete ninDeath;
	delete ninClimb;
	delete ninArm;
	delete colorCode;
	delete plyRun;
	delete plyIdle;
	delete plyJump;
	delete hand;
	delete pauseScreen;
	delete icon;
	delete blockFrame;
	delete howToPlay;
	delete levelComplete;

		delete title;
	delete mousePtr;

	//delete menuBackground;
	delete creditScreen;
	delete splashScreen;
	delete pressAnyKey;
	delete menuButton;
	delete menuNumbers;
	delete locked;
	delete menuhud;

	for(int i = 0; i < nMaps; i++)
		delete maps[i];
	
	delete []maps;
}

ImgHolder* ImgHolder::getInst()
{
	if(pInstance == NULL)
		pInstance = new ImgHolder();

	return pInstance;
}

Image* ImgHolder::getMaps(int i)
{
	if(i < 0 || i > nMaps-1)
		return NULL;
	else
		return maps[i];
}