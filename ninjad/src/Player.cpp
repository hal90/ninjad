#include "player.h"

Player::Player(Vector2i pos)
{
	hand = new Sprite();
	hand->SetImage(*ImgHolder::getInst()->hand);
	hand->SetCenter(9,0);
	this->blockSelected=7;

	this->curAnim = NULL;
	this->runAnim = new Animation(ImgHolder::getInst()->plyRun, 4, 32, 32, 2, true, true);
	this->runAnim->sprite.SetCenter(16,16);
	this->idleAnim = new Animation(ImgHolder::getInst()->plyIdle, 1, 32, 32, 1, true, false);
	this->idleAnim->sprite.SetCenter(16,16);
	this->jumpAnim = new Animation(ImgHolder::getInst()->plyJump, 1, 32, 32, 1, true, false);
	this->jumpAnim->sprite.SetCenter(16,16);

	precollides=false;
	input = &InputHandler::getInstance();
	setSpeedX(6);
	setSpeedY(0);
	setAccel(0);
	this->setBugMode(false);
	this->setGrounded(true);
	nextToWall=false;
	direction=false;
	hitLeft=false;
	hitRight=false;
	setSizeX(16);
	setSizeY(26);
	
	this->curAnim = this->idleAnim;

	//SetSubRect(IntRect(0,0,24,24));
	this->curAnim->sprite.SetPosition(80+pos.x,144+pos.y); //5x17
	setPosX(this->curAnim->sprite.GetPosition().x);
	setPosY(this->curAnim->sprite.GetPosition().y + (this->curAnim->sprite.GetSize().y - this->getSizeY())/2);

	this->curAnim->sprite.SetCenter(this->curAnim->sprite.GetSize().x/2, this->curAnim->sprite.GetSize().y/2);
	//this->SetRotation(90);
	
	//SetCenter(0,0);
	input = &InputHandler::getInstance(); //varf�r?
}

Player::~Player()
{
	delete hand;
	delete runAnim;
	delete idleAnim;
	delete jumpAnim;
}

void Player::update(RenderWindow* wnd)
{
	if(input->isPressRight(wnd) && !input->isPressLeft(wnd) && !hitRight)
	{
		this->runAnim->sprite.SetPosition(this->curAnim->sprite.GetPosition().x, this->curAnim->sprite.GetPosition().y);
		this->curAnim = this->runAnim;

		this->curAnim->sprite.Move((float)getSpeedX()*1, (float)getSpeedY()*0);
			if(grounded)
				this->speedx=6;
			else
				this->speedx=4;
			//direction=true;
			setPosX(this->curAnim->sprite.GetPosition().x);
			setPosY(this->curAnim->sprite.GetPosition().y + (this->curAnim->sprite.GetSize().y - this->getSizeY())/2);
	}
	if(input->isPressLeft(wnd) && !input->isPressRight(wnd) && !hitLeft)
	{
			this->curAnim->sprite.Move((float)getSpeedX()*-1, (float)getSpeedY()*0);
			if(grounded)
				this->speedx=6;
			else
				this->speedx=4;
			//direction=false;
			setPosX(this->curAnim->sprite.GetPosition().x);
			setPosY(this->curAnim->sprite.GetPosition().y + (this->curAnim->sprite.GetSize().y - this->getSizeY())/2);
	}
	this->curAnim->sprite.Move((float)0, (float)getSpeedY());
	if(input->isPressJump(wnd) && grounded)
	{
		setSpeedX(4);
		setSpeedY(-9);
		setAccel(1);
		this->bugmode=true;
		setGrounded(false);
		this->setPreCollides(false);
	}

	if(input->isPress1(wnd))
	{
		setBlockSelected(7); //standardblock
	}
	
	if(input->isPress2(wnd))
	{
		setBlockSelected(5); // jumpblock
	}
	
	if(input->isPress3(wnd))
	{
		setBlockSelected(6); //fallblock
	}
	
	if(input->isPress4(wnd))
	{
		setBlockSelected(4); //springblock
	}

	setSpeedY(getSpeedY()+getAccel());
	if(input->isPressClick(wnd))
	{}//sl�ng ut block
	this->curAnim->Update();
	//if(bugmode) cin.get();
	hand->SetPosition(this->curAnim->sprite.GetPosition().x-1,this->curAnim->sprite.GetPosition().y-4);
	if(!direction) hand->SetCenter(9,9);
	if(direction) hand->SetCenter(9,0);
	hand->FlipY(!direction);
}

void Player::testmove(RenderWindow* wnd)
{
	if(input->isPressRight(wnd) && !input->isPressLeft(wnd))
	{
		this->curAnim->sprite.Move((float)getSpeedX()*1, (float)getSpeedY()*0);
		setPosX(this->curAnim->sprite.GetPosition().x);
		setPosY(this->curAnim->sprite.GetPosition().y + (this->curAnim->sprite.GetSize().y - this->getSizeY())/2);
	}
	if(input->isPressLeft(wnd) && !input->isPressRight(wnd))
	{
		this->curAnim->sprite.Move((float)getSpeedX()*-1, (float)getSpeedY()*0);
		setPosX(this->curAnim->sprite.GetPosition().x);
		setPosY(this->curAnim->sprite.GetPosition().y + (this->curAnim->sprite.GetSize().y - this->getSizeY())/2);
	}

}

void Player::testmoveY(RenderWindow* wnd)
{
	this->curAnim->sprite.Move(0, (float)getSpeedY());
	setPosX(this->curAnim->sprite.GetPosition().x);
	setPosY(this->curAnim->sprite.GetPosition().y + (this->curAnim->sprite.GetSize().y - this->getSizeY())/2);
}

void Player::retraceY(RenderWindow* wnd)
{
	this->curAnim->sprite.Move(0, -(float)getSpeedY());
	setPosX(this->curAnim->sprite.GetPosition().x);
	setPosY(this->curAnim->sprite.GetPosition().y + (this->curAnim->sprite.GetSize().y - this->getSizeY())/2);
}

void Player::retrace(RenderWindow* wnd)
{
	if(input->isPressRight(wnd)&& !input->isPressLeft(wnd))
	{
		this->curAnim->sprite.Move(-(float)getSpeedX()*1, -(float)getSpeedY()*0);
		setPosX(this->curAnim->sprite.GetPosition().x);
		setPosY(this->curAnim->sprite.GetPosition().y + (this->curAnim->sprite.GetSize().y - this->getSizeY())/2);
	}
	if(input->isPressLeft(wnd) && !input->isPressRight(wnd))
	{
		this->curAnim->sprite.Move(-(float)getSpeedX()*-1, -(float)getSpeedY()*0);
		setPosX(this->curAnim->sprite.GetPosition().x);
		setPosY(this->curAnim->sprite.GetPosition().y + (this->curAnim->sprite.GetSize().y - this->getSizeY())/2);
	}
}

void Player::updateSprite(RenderWindow* wnd)
{
	if(input->isPressRight(wnd) && !input->isPressLeft(wnd) && this->grounded)
	{
		this->runAnim->sprite.SetPosition(this->curAnim->sprite.GetPosition().x, this->curAnim->sprite.GetPosition().y);
		this->curAnim = this->runAnim;
		this->curAnim->sprite.FlipX(direction);
		this->curAnim->sprite.SetCenter(this->curAnim->sprite.GetSize().x/2, this->curAnim->sprite.GetSize().y/2);
	}
	else if(input->isPressLeft(wnd) && !input->isPressRight(wnd) && this->grounded)
	{
		this->runAnim->sprite.SetPosition(this->curAnim->sprite.GetPosition().x, this->curAnim->sprite.GetPosition().y);
		this->curAnim = this->runAnim;
		this->curAnim->sprite.FlipX(direction);
		this->curAnim->sprite.SetCenter(this->curAnim->sprite.GetSize().x/2, this->curAnim->sprite.GetSize().y/2);
	}
	else if(!this->grounded)
	{
		this->jumpAnim->sprite.SetPosition(this->curAnim->sprite.GetPosition().x, this->curAnim->sprite.GetPosition().y);
		this->jumpAnim->sprite.FlipX(direction);
		this->curAnim = this->jumpAnim;
	}	//jump animation
	//else if(input->isPressClick(wnd))
	//{} //block animation
	else
	{
		this->idleAnim->sprite.SetPosition(this->curAnim->sprite.GetPosition().x, this->curAnim->sprite.GetPosition().y);
		this->idleAnim->sprite.FlipX(direction);
		this->curAnim = this->idleAnim;
	}
}


int Player::getSpeedX()
{
	return speedx;
}

void Player::setSpeedX(int s)
{
	speedx = s;
}

int Player::getSpeedY()
{
	return speedy;
}

void Player::setSpeedY(int s)
{
	speedy = s;
}

int Player::getAccel()
{
	return this->acceleration;
}

void Player::setAccel(int a)
{
	this->acceleration = a;
}

Sprite* Player::getHand()
{
	return hand;
}

void Player::setBugMode(bool mode)
{
	this->bugmode=mode;
}

void Player::setGrounded(bool value)
{
	this->grounded=value;
}

void Player::setNextToWall(bool wall)
{
	this->nextToWall=wall;
}

bool Player::getDirection()
{
	return direction;
}

bool Player::getGrounded()
{
	return this->grounded;
}

void Player::setHitLeft(bool hit)
{
	this->hitLeft=hit;
}

void Player::setHitRight(bool hit)
{
	this->hitRight=hit;
}

int Player::getPosX()
{
	return posX;
}

int Player::getPosY()
{
	return posY;
}

int Player::getSizeX()
{
	return sizeX;
}

int Player::getSizeY()
{
	return sizeY;
}

void Player::setPosX(int pos)
{
	this->posX=pos;
}

void Player::setPosY(int pos)
{
	this->posY=pos;
}

void Player::setSizeX(int size)
{
	this->sizeX=size;
}

void Player::setSizeY(int size)
{
	this->sizeY=size;
}

void Player::setPreCollides(bool val)
{
	this->precollides=val;
}

bool Player::getPreCollides()
{
	return precollides;
}

void Player::setDirection(bool dir)
{
	this->direction = dir;
}

void Player::setBlockSelected(int type)
{
	blockSelected=type;
}

int Player::getBlockSelected()
{
	return blockSelected;
}