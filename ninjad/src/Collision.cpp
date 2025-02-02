#include "Collision.h"
#include "SndHolder.h"

Collision::Collision()
{
	collides=true;
	airborne=true;

	f=0;
	animerarN=0;
}

Collision::~Collision()
{}

void Collision::ninja(Block** block, NinjaIF* ninja, int nBlocks)
{
	//1. Passerar ninjan intro-d�rren?
	if(!ninja->getComplete() && !ninja->getDead())
	{
		switch(ninja->getState())
		{
		case 0:
			for(int i=0; i<nBlocks; i++)
			{
				if(ninja->curAnim->sprite.GetPosition().x == block[i]->curAnim->sprite.GetPosition().x && ninja->curAnim->sprite.GetPosition().y + (ninja->curAnim->sprite.GetSize().y/2 - block[i]->curAnim->sprite.GetSize().y/2) == block[i]->curAnim->sprite.GetPosition().y && typeid(*block[i]) == typeid(EntryDoor) && block[i]->curAnim->sprite.GetRotation()==0)
					ninja->setDrawn(true);
			}
			break;
		case 1:
			for(int i=0; i<nBlocks; i++)
			{
				if(ninja->curAnim->sprite.GetPosition().y == block[i]->curAnim->sprite.GetPosition().y && ninja->curAnim->sprite.GetPosition().x + (ninja->curAnim->sprite.GetSize().x/2 - block[i]->curAnim->sprite.GetSize().x/2) == block[i]->curAnim->sprite.GetPosition().x && typeid(*block[i]) == typeid(EntryDoor) && block[i]->curAnim->sprite.GetRotation()==90)
					ninja->setDrawn(true);
			}
			break;
		case 2:
			for(int i=0; i<nBlocks; i++)
			{
				if(ninja->curAnim->sprite.GetPosition().x == block[i]->curAnim->sprite.GetPosition().x && ninja->curAnim->sprite.GetPosition().y - (ninja->curAnim->sprite.GetSize().y/2 - block[i]->curAnim->sprite.GetSize().y/2) == block[i]->curAnim->sprite.GetPosition().y && typeid(*block[i]) == typeid(EntryDoor) && block[i]->curAnim->sprite.GetRotation()==180)
					ninja->setDrawn(true);
			}
			break;
		case 3:
			for(int i=0; i<nBlocks; i++)
			{
				if(ninja->curAnim->sprite.GetPosition().y == block[i]->curAnim->sprite.GetPosition().y && ninja->curAnim->sprite.GetPosition().x - (ninja->curAnim->sprite.GetSize().x/2 - block[i]->curAnim->sprite.GetSize().x/2) == block[i]->curAnim->sprite.GetPosition().x && typeid(*block[i]) == typeid(EntryDoor) && block[i]->curAnim->sprite.GetRotation()==-90)
					ninja->setDrawn(true);
			}
			break;
		case 6:
			for(int i=0; i<nBlocks; i++)
			{
				if(ninja->curAnim->sprite.GetPosition().x == block[i]->curAnim->sprite.GetPosition().x && ninja->curAnim->sprite.GetPosition().y + (ninja->curAnim->sprite.GetSize().y/2 - block[i]->curAnim->sprite.GetSize().y/2) == block[i]->curAnim->sprite.GetPosition().y && typeid(*block[i]) == typeid(EntryDoor) && block[i]->curAnim->sprite.GetRotation()==0)
					ninja->setDrawn(true);
			}
			break;
		case 7:
			for(int i=0; i<nBlocks; i++)
			{
				if(ninja->curAnim->sprite.GetPosition().y == block[i]->curAnim->sprite.GetPosition().y && ninja->curAnim->sprite.GetPosition().x + (ninja->curAnim->sprite.GetSize().x/2 - block[i]->curAnim->sprite.GetSize().x/2) == block[i]->curAnim->sprite.GetPosition().x && typeid(*block[i]) == typeid(EntryDoor) && block[i]->curAnim->sprite.GetRotation()==90)
					ninja->setDrawn(true);
			}
			break;
		case 4:
			for(int i=0; i<nBlocks; i++)
			{
				if(ninja->curAnim->sprite.GetPosition().x == block[i]->curAnim->sprite.GetPosition().x && ninja->curAnim->sprite.GetPosition().y - (ninja->curAnim->sprite.GetSize().y/2 - block[i]->curAnim->sprite.GetSize().y/2) == block[i]->curAnim->sprite.GetPosition().y && typeid(*block[i]) == typeid(EntryDoor) && block[i]->curAnim->sprite.GetRotation()==180)
					ninja->setDrawn(true);
			}
			break;
		case 5:
			for(int i=0; i<nBlocks; i++)
			{
				if(ninja->curAnim->sprite.GetPosition().y == block[i]->curAnim->sprite.GetPosition().y && ninja->curAnim->sprite.GetPosition().x - (ninja->curAnim->sprite.GetSize().x/2 - block[i]->curAnim->sprite.GetSize().x/2) == block[i]->curAnim->sprite.GetPosition().x && typeid(*block[i]) == typeid(EntryDoor) && block[i]->curAnim->sprite.GetRotation()==-90)
					ninja->setDrawn(true);
			}
			break;
		case 8:
			for(int i=0; i<nBlocks; i++)
			{
				if(ninja->curAnim->sprite.GetPosition().x == block[i]->curAnim->sprite.GetPosition().x && ninja->curAnim->sprite.GetPosition().y + (ninja->curAnim->sprite.GetSize().y/2 - block[i]->curAnim->sprite.GetSize().y/2) == block[i]->curAnim->sprite.GetPosition().y && typeid(*block[i]) == typeid(EntryDoor) && block[i]->curAnim->sprite.GetRotation()==0)
					ninja->setDrawn(true);
			}
			break;
		default:
			break;
		}

	if(ninja->getDrawn() == true)
	{
	//2. Passerar ninjan EXIT-d�rren?
	switch(ninja->getState())
	{
	case 0:
		for(int i=0; i<nBlocks; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().x == block[i]->curAnim->sprite.GetPosition().x && ninja->curAnim->sprite.GetPosition().y + (ninja->curAnim->sprite.GetSize().y/2 - block[i]->curAnim->sprite.GetSize().y/2) == block[i]->curAnim->sprite.GetPosition().y && typeid(*block[i]) == typeid(ExitDoor) && block[i]->curAnim->sprite.GetRotation()==0)
			{
				ninja->setDrawn(false);
				ninja->setComplete(true);
				SndHolder::getInst()->sndYay.Play();
			}
		}
		break;
	case 1:
		for(int i=0; i<nBlocks; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().y == block[i]->curAnim->sprite.GetPosition().y && ninja->curAnim->sprite.GetPosition().x + (ninja->curAnim->sprite.GetSize().x/2 - block[i]->curAnim->sprite.GetSize().x/2) == block[i]->curAnim->sprite.GetPosition().x && typeid(*block[i]) == typeid(ExitDoor) && block[i]->curAnim->sprite.GetRotation()==90)
			{
				ninja->setDrawn(false);
				ninja->setComplete(true);
				SndHolder::getInst()->sndYay.Play();
			}
		}
		break;
	case 2:
		for(int i=0; i<nBlocks; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().x == block[i]->curAnim->sprite.GetPosition().x && ninja->curAnim->sprite.GetPosition().y - (ninja->curAnim->sprite.GetSize().y/2 - block[i]->curAnim->sprite.GetSize().y/2) == block[i]->curAnim->sprite.GetPosition().y && typeid(*block[i]) == typeid(ExitDoor) && block[i]->curAnim->sprite.GetRotation()==180)
			{
				ninja->setDrawn(false);
				ninja->setComplete(true);
				SndHolder::getInst()->sndYay.Play();
			}
		}
		break;
	case 3:
		for(int i=0; i<nBlocks; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().y == block[i]->curAnim->sprite.GetPosition().y && ninja->curAnim->sprite.GetPosition().x - (ninja->curAnim->sprite.GetSize().x/2 - block[i]->curAnim->sprite.GetSize().x/2) == block[i]->curAnim->sprite.GetPosition().x && typeid(*block[i]) == typeid(ExitDoor) && block[i]->curAnim->sprite.GetRotation()==-90)
			{
				ninja->setDrawn(false);
				ninja->setComplete(true);
				SndHolder::getInst()->sndYay.Play();
			}
		}
		break;
	case 6:
		for(int i=0; i<nBlocks; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().x == block[i]->curAnim->sprite.GetPosition().x && ninja->curAnim->sprite.GetPosition().y + (ninja->curAnim->sprite.GetSize().y/2 - block[i]->curAnim->sprite.GetSize().y/2) == block[i]->curAnim->sprite.GetPosition().y && typeid(*block[i]) == typeid(ExitDoor) && block[i]->curAnim->sprite.GetRotation()==0)
			{
				ninja->setDrawn(false);
				ninja->setComplete(true);
				SndHolder::getInst()->sndYay.Play();
			}
		}
		break;
	case 7:
		for(int i=0; i<nBlocks; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().y == block[i]->curAnim->sprite.GetPosition().y && ninja->curAnim->sprite.GetPosition().x + (ninja->curAnim->sprite.GetSize().x/2 - block[i]->curAnim->sprite.GetSize().x/2) == block[i]->curAnim->sprite.GetPosition().x && typeid(*block[i]) == typeid(ExitDoor) && block[i]->curAnim->sprite.GetRotation()==90)
			{
				ninja->setDrawn(false);
				ninja->setComplete(true);
				SndHolder::getInst()->sndYay.Play();
			}
		}
		break;
	case 4:
		for(int i=0; i<nBlocks; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().x == block[i]->curAnim->sprite.GetPosition().x && ninja->curAnim->sprite.GetPosition().y - (ninja->curAnim->sprite.GetSize().y/2 - block[i]->curAnim->sprite.GetSize().y/2) == block[i]->curAnim->sprite.GetPosition().y && typeid(*block[i]) == typeid(ExitDoor) && block[i]->curAnim->sprite.GetRotation()==180)
			{
				ninja->setDrawn(false);
				ninja->setComplete(true);
				SndHolder::getInst()->sndYay.Play();
			}
		}
		break;
	case 5:
		for(int i=0; i<nBlocks; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().y == block[i]->curAnim->sprite.GetPosition().y && ninja->curAnim->sprite.GetPosition().x - (ninja->curAnim->sprite.GetSize().x/2 - block[i]->curAnim->sprite.GetSize().x/2) == block[i]->curAnim->sprite.GetPosition().x && typeid(*block[i]) == typeid(ExitDoor) && block[i]->curAnim->sprite.GetRotation()==-90)
			{
				ninja->setDrawn(false);
				ninja->setComplete(true);
				SndHolder::getInst()->sndYay.Play();
			}
		}
		break;
	case 8:
		for(int i=0; i<nBlocks; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().x == block[i]->curAnim->sprite.GetPosition().x && ninja->curAnim->sprite.GetPosition().y + (ninja->curAnim->sprite.GetSize().y/2 - block[i]->curAnim->sprite.GetSize().y/2) == block[i]->curAnim->sprite.GetPosition().y && typeid(*block[i]) == typeid(ExitDoor) && block[i]->curAnim->sprite.GetRotation()==0)
			{
				ninja->setDrawn(false);
				ninja->setComplete(true);
				SndHolder::getInst()->sndYay.Play();
			}
		}
		break;
	default:
		break;
	}

	//Ska ninjan hoppa?! :D:D:D
	switch(ninja->getState())
	{
	case 0:
		for(int i=0; i<nBlocks; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().x == block[i]->curAnim->sprite.GetPosition().x && ninja->curAnim->sprite.GetPosition().y + (ninja->curAnim->sprite.GetSize().y/2 - block[i]->curAnim->sprite.GetSize().y/2) == block[i]->curAnim->sprite.GetPosition().y && typeid(*block[i]) == typeid(JumpBlock) && block[i]->curAnim->sprite.GetRotation()==0)
			{
				ninja->setSavedState(ninja->getState());
				ninja->setState(9);
				block[i]->Animate();
			}
		}
		break;
	case 1:
		for(int i=0; i<nBlocks; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().y == block[i]->curAnim->sprite.GetPosition().y && ninja->curAnim->sprite.GetPosition().x + (ninja->curAnim->sprite.GetSize().x/2 - block[i]->curAnim->sprite.GetSize().x/2) == block[i]->curAnim->sprite.GetPosition().x && typeid(*block[i]) == typeid(JumpBlock) && block[i]->curAnim->sprite.GetRotation()==90)
				{
				ninja->setSavedState(ninja->getState());
				ninja->setState(9);
				block[i]->Animate();
			}
		}
		break;
	case 2:
		for(int i=0; i<nBlocks; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().x == block[i]->curAnim->sprite.GetPosition().x && ninja->curAnim->sprite.GetPosition().y - (ninja->curAnim->sprite.GetSize().y/2 - block[i]->curAnim->sprite.GetSize().y/2) == block[i]->curAnim->sprite.GetPosition().y && typeid(*block[i]) == typeid(JumpBlock) && block[i]->curAnim->sprite.GetRotation()==180)
				{
				ninja->setSavedState(ninja->getState());
				ninja->setState(9);
				block[i]->Animate();
			}
		}
		break;
	case 3:
		for(int i=0; i<nBlocks; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().y == block[i]->curAnim->sprite.GetPosition().y && ninja->curAnim->sprite.GetPosition().x - (ninja->curAnim->sprite.GetSize().x/2 - block[i]->curAnim->sprite.GetSize().x/2) == block[i]->curAnim->sprite.GetPosition().x && typeid(*block[i]) == typeid(JumpBlock) && block[i]->curAnim->sprite.GetRotation()==-90)
				{
				ninja->setSavedState(ninja->getState());
				ninja->setState(9);
				block[i]->Animate();
			}
		}
		break;
	case 6:
		for(int i=0; i<nBlocks; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().x == block[i]->curAnim->sprite.GetPosition().x && ninja->curAnim->sprite.GetPosition().y + (ninja->curAnim->sprite.GetSize().y/2 - block[i]->curAnim->sprite.GetSize().y/2) == block[i]->curAnim->sprite.GetPosition().y && typeid(*block[i]) == typeid(JumpBlock) && block[i]->curAnim->sprite.GetRotation()==0)
				{
				ninja->setSavedState(ninja->getState());
				ninja->setState(9);
				block[i]->Animate();
			}
		}
		break;
	case 7:
		for(int i=0; i<nBlocks; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().y == block[i]->curAnim->sprite.GetPosition().y && ninja->curAnim->sprite.GetPosition().x + (ninja->curAnim->sprite.GetSize().x/2 - block[i]->curAnim->sprite.GetSize().x/2) == block[i]->curAnim->sprite.GetPosition().x && typeid(*block[i]) == typeid(JumpBlock) && block[i]->curAnim->sprite.GetRotation()==90)
				{
				ninja->setSavedState(ninja->getState());
				ninja->setState(9);
				block[i]->Animate();
			}
		}
		break;
	case 4:
		for(int i=0; i<nBlocks; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().x == block[i]->curAnim->sprite.GetPosition().x && ninja->curAnim->sprite.GetPosition().y - (ninja->curAnim->sprite.GetSize().y/2 - block[i]->curAnim->sprite.GetSize().y/2) == block[i]->curAnim->sprite.GetPosition().y && typeid(*block[i]) == typeid(JumpBlock) && block[i]->curAnim->sprite.GetRotation()==180)
				{
				ninja->setSavedState(ninja->getState());
				ninja->setState(9);
				block[i]->Animate();
			}
		}
		break;
	case 5:
		for(int i=0; i<nBlocks; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().y == block[i]->curAnim->sprite.GetPosition().y && ninja->curAnim->sprite.GetPosition().x - (ninja->curAnim->sprite.GetSize().x/2 - block[i]->curAnim->sprite.GetSize().x/2) == block[i]->curAnim->sprite.GetPosition().x && typeid(*block[i]) == typeid(JumpBlock) && block[i]->curAnim->sprite.GetRotation()==-90)
			{
				ninja->setSavedState(ninja->getState());
				ninja->setState(9);
				block[i]->Animate();
			}
		}
		break;
	case 8:
		for(int i=0; i<nBlocks; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().x == block[i]->curAnim->sprite.GetPosition().x && ninja->curAnim->sprite.GetPosition().y + (ninja->curAnim->sprite.GetSize().y/2 - block[i]->curAnim->sprite.GetSize().y/2) == block[i]->curAnim->sprite.GetPosition().y && typeid(*block[i]) == typeid(JumpBlock) && block[i]->curAnim->sprite.GetRotation()==0)
			{
				ninja->setState(9);
				block[i]->Animate();
			}
		}
		break;
	default:
		break;
	}

	//Ska ninjan den d�da d�dens d�daste d�da d�d d�?
	switch(ninja->getState())
	{
	case 0:
		for(int i=0; i<nBlocks; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().x == block[i]->curAnim->sprite.GetPosition().x && ninja->curAnim->sprite.GetPosition().y + (ninja->curAnim->sprite.GetSize().y/2 - block[i]->curAnim->sprite.GetSize().y/2) == block[i]->curAnim->sprite.GetPosition().y && typeid(*block[i]) == typeid(TrapBlock))
			{
				ninja->setState(11);
				block[i]->Animate();
				ninja->curAnim->sprite.SetPosition(block[i]->curAnim->sprite.GetPosition().x, block[i]->curAnim->sprite.GetPosition().y);
			}
		}
		break;
	case 1:
		for(int i=0; i<nBlocks; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().y == block[i]->curAnim->sprite.GetPosition().y && ninja->curAnim->sprite.GetPosition().x + (ninja->curAnim->sprite.GetSize().x/2 - block[i]->curAnim->sprite.GetSize().x/2) == block[i]->curAnim->sprite.GetPosition().x && typeid(*block[i]) == typeid(TrapBlock))
				{
				ninja->setState(11);
				block[i]->Animate();
				ninja->curAnim->sprite.SetPosition(block[i]->curAnim->sprite.GetPosition().x, block[i]->curAnim->sprite.GetPosition().y);
			}
		}
		break;
	case 2:
		for(int i=0; i<nBlocks; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().x == block[i]->curAnim->sprite.GetPosition().x && ninja->curAnim->sprite.GetPosition().y - (ninja->curAnim->sprite.GetSize().y/2 - block[i]->curAnim->sprite.GetSize().y/2) == block[i]->curAnim->sprite.GetPosition().y && typeid(*block[i]) == typeid(TrapBlock))
				{
				ninja->setState(11);
				block[i]->Animate();
				ninja->curAnim->sprite.SetPosition(block[i]->curAnim->sprite.GetPosition().x, block[i]->curAnim->sprite.GetPosition().y);
			}
		}
		break;
	case 3:
		for(int i=0; i<nBlocks; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().y == block[i]->curAnim->sprite.GetPosition().y && ninja->curAnim->sprite.GetPosition().x - (ninja->curAnim->sprite.GetSize().x/2 - block[i]->curAnim->sprite.GetSize().x/2) == block[i]->curAnim->sprite.GetPosition().x && typeid(*block[i]) == typeid(TrapBlock))
			{
				ninja->setState(11);
				block[i]->Animate();
				ninja->curAnim->sprite.SetPosition(block[i]->curAnim->sprite.GetPosition().x, block[i]->curAnim->sprite.GetPosition().y);
			}
		}
		break;
	case 6:
		for(int i=0; i<nBlocks; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().x == block[i]->curAnim->sprite.GetPosition().x && ninja->curAnim->sprite.GetPosition().y + (ninja->curAnim->sprite.GetSize().y/2 - block[i]->curAnim->sprite.GetSize().y/2) == block[i]->curAnim->sprite.GetPosition().y && typeid(*block[i]) == typeid(TrapBlock))
				{
				ninja->setState(11);
				block[i]->Animate();
				ninja->curAnim->sprite.SetPosition(block[i]->curAnim->sprite.GetPosition().x, block[i]->curAnim->sprite.GetPosition().y);
			}
		}
		break;
	case 7:
		for(int i=0; i<nBlocks; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().y == block[i]->curAnim->sprite.GetPosition().y && ninja->curAnim->sprite.GetPosition().x + (ninja->curAnim->sprite.GetSize().x/2 - block[i]->curAnim->sprite.GetSize().x/2) == block[i]->curAnim->sprite.GetPosition().x && typeid(*block[i]) == typeid(TrapBlock))
				{
				ninja->setState(11);
				block[i]->Animate();
				ninja->curAnim->sprite.SetPosition(block[i]->curAnim->sprite.GetPosition().x, block[i]->curAnim->sprite.GetPosition().y);
			}
		}
		break;
	case 4:
		for(int i=0; i<nBlocks; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().x == block[i]->curAnim->sprite.GetPosition().x && ninja->curAnim->sprite.GetPosition().y - (ninja->curAnim->sprite.GetSize().y/2 - block[i]->curAnim->sprite.GetSize().y/2) == block[i]->curAnim->sprite.GetPosition().y && typeid(*block[i]) == typeid(TrapBlock))
				{
				ninja->setState(11);
				block[i]->Animate();
				ninja->curAnim->sprite.SetPosition(block[i]->curAnim->sprite.GetPosition().x, block[i]->curAnim->sprite.GetPosition().y);
			}
		}
		break;
	case 5:
		for(int i=0; i<nBlocks; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().y == block[i]->curAnim->sprite.GetPosition().y && ninja->curAnim->sprite.GetPosition().x - (ninja->curAnim->sprite.GetSize().x/2 - block[i]->curAnim->sprite.GetSize().x/2) == block[i]->curAnim->sprite.GetPosition().x && typeid(*block[i]) == typeid(TrapBlock))
			{
				ninja->setState(11);
				block[i]->Animate();
				ninja->curAnim->sprite.SetPosition(block[i]->curAnim->sprite.GetPosition().x, block[i]->curAnim->sprite.GetPosition().y);
			}
		}
		break;
	case 8:
		for(int i=0; i<nBlocks; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().x == block[i]->curAnim->sprite.GetPosition().x && ninja->curAnim->sprite.GetPosition().y + (ninja->curAnim->sprite.GetSize().y/2 - block[i]->curAnim->sprite.GetSize().y/2) == block[i]->curAnim->sprite.GetPosition().y && typeid(*block[i]) == typeid(TrapBlock))
			{
				ninja->setState(11);
				block[i]->Animate();
				ninja->curAnim->sprite.SetPosition(block[i]->curAnim->sprite.GetPosition().x, block[i]->curAnim->sprite.GetPosition().y);
			}
		}
		break;
	case 9:
		for(int i=0; i<nBlocks; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().x == block[i]->curAnim->sprite.GetPosition().x && ninja->curAnim->sprite.GetPosition().y + (ninja->curAnim->sprite.GetSize().y/2 - block[i]->curAnim->sprite.GetSize().y/2) == block[i]->curAnim->sprite.GetPosition().y && typeid(*block[i]) == typeid(TrapBlock))
			{
				ninja->setState(11);
				block[i]->Animate();
				ninja->curAnim->sprite.SetPosition(block[i]->curAnim->sprite.GetPosition().x, block[i]->curAnim->sprite.GetPosition().y);
			}
		}
		break;
	case 10:
		this->collides=false;
		for(int i=0; i<nBlocks && collides==false;i++)
		{
			this->collides=true;

			if(ninja->curAnim->sprite.GetPosition().x <= block[i]->curAnim->sprite.GetPosition().x - block[i]->curAnim->sprite.GetSize().x/2)//Ninjan �r till v�nster om blocket
				collides=false;
			if(ninja->curAnim->sprite.GetPosition().x >= block[i]->curAnim->sprite.GetPosition().x + block[i]->curAnim->sprite.GetSize().x/2)//Ninjan �r till h�ger om blocket
				collides=false;
			if(ninja->curAnim->sprite.GetPosition().y <= block[i]->curAnim->sprite.GetPosition().y - block[i]->curAnim->sprite.GetSize().y/2)//Ninjan �r ovanf�r blocket
				collides=false;
			if(ninja->curAnim->sprite.GetPosition().y >= block[i]->curAnim->sprite.GetPosition().y + block[i]->curAnim->sprite.GetSize().y/2)//Ninjan �r nedanf�r blocket
				collides=false;
			if((typeid(*block[i]) != typeid(TrapBlock))|| !ninja->getDrawn())
				collides=false;

			if(collides)
			{
				animerarN=i;
			}
		}
		if(collides)
		{
			ninja->setState(11);
			block[animerarN]->Animate();
			ninja->curAnim->sprite.SetPosition(block[animerarN]->curAnim->sprite.GetPosition().x, block[animerarN]->curAnim->sprite.GetPosition().y);
		}
		break;
	default:
		break;
	}
	
	//Ska ninjan hoppa l�ngdhopp?
	bool justjumped=false;
	switch(ninja->getState())
	{
	case 0:
		for(int i=0; i<nBlocks; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().x == block[i]->curAnim->sprite.GetPosition().x && ninja->curAnim->sprite.GetPosition().y + (ninja->curAnim->sprite.GetSize().y/2 - block[i]->curAnim->sprite.GetSize().y/2) == block[i]->curAnim->sprite.GetPosition().y && typeid(*block[i]) == typeid(SpringBlock) && block[i]->curAnim->sprite.GetRotation()==0)
				{
				ninja->setSavedState(ninja->getState());
				ninja->setState(10);
				block[i]->Animate();
				justjumped=true;
			}
		}
		break;
	case 1:
		for(int i=0; i<nBlocks; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().y == block[i]->curAnim->sprite.GetPosition().y && ninja->curAnim->sprite.GetPosition().x + (ninja->curAnim->sprite.GetSize().x/2 - block[i]->curAnim->sprite.GetSize().x/2) == block[i]->curAnim->sprite.GetPosition().x && typeid(*block[i]) == typeid(SpringBlock) && block[i]->curAnim->sprite.GetRotation()==90)
				{
				ninja->setSavedState(ninja->getState());
				ninja->setState(10);
				block[i]->Animate();
				justjumped=true;
			}
		}
		break;
	case 2:
		for(int i=0; i<nBlocks; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().x == block[i]->curAnim->sprite.GetPosition().x && ninja->curAnim->sprite.GetPosition().y - (ninja->curAnim->sprite.GetSize().y/2 - block[i]->curAnim->sprite.GetSize().y/2) == block[i]->curAnim->sprite.GetPosition().y && typeid(*block[i]) == typeid(SpringBlock) && block[i]->curAnim->sprite.GetRotation()==180)
				{
				ninja->setSavedState(ninja->getState());
				ninja->setState(10);
				block[i]->Animate();
				justjumped=true;
			}
		}
		break;
	case 3:
		for(int i=0; i<nBlocks; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().y == block[i]->curAnim->sprite.GetPosition().y && ninja->curAnim->sprite.GetPosition().x - (ninja->curAnim->sprite.GetSize().x/2 - block[i]->curAnim->sprite.GetSize().x/2) == block[i]->curAnim->sprite.GetPosition().x && typeid(*block[i]) == typeid(SpringBlock) && block[i]->curAnim->sprite.GetRotation()==-90)
				{
				ninja->setSavedState(ninja->getState());
				ninja->setState(10);
				block[i]->Animate();
				justjumped=true;
			}
		}
		break;
	case 6:
		for(int i=0; i<nBlocks; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().x == block[i]->curAnim->sprite.GetPosition().x && ninja->curAnim->sprite.GetPosition().y + (ninja->curAnim->sprite.GetSize().y/2 - block[i]->curAnim->sprite.GetSize().y/2) == block[i]->curAnim->sprite.GetPosition().y && typeid(*block[i]) == typeid(SpringBlock) && block[i]->curAnim->sprite.GetRotation()==0)
				{
				ninja->setSavedState(ninja->getState());
				ninja->setState(10);
				block[i]->Animate();
				justjumped=true;
			}
		}
		break;
	case 7:
		for(int i=0; i<nBlocks; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().y == block[i]->curAnim->sprite.GetPosition().y && ninja->curAnim->sprite.GetPosition().x + (ninja->curAnim->sprite.GetSize().x/2 - block[i]->curAnim->sprite.GetSize().x/2) == block[i]->curAnim->sprite.GetPosition().x && typeid(*block[i]) == typeid(SpringBlock) && block[i]->curAnim->sprite.GetRotation()==90)
				{
				ninja->setSavedState(ninja->getState());
				ninja->setState(10);
				block[i]->Animate();
				justjumped=true;
			}
		}
		break;
	case 4:
		for(int i=0; i<nBlocks; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().x == block[i]->curAnim->sprite.GetPosition().x && ninja->curAnim->sprite.GetPosition().y - (ninja->curAnim->sprite.GetSize().y/2 - block[i]->curAnim->sprite.GetSize().y/2) == block[i]->curAnim->sprite.GetPosition().y && typeid(*block[i]) == typeid(SpringBlock) && block[i]->curAnim->sprite.GetRotation()==180)
				{
				ninja->setSavedState(ninja->getState());
				ninja->setState(10);
				block[i]->Animate();
				justjumped=true;
			}
		}
		break;
	case 5:
		for(int i=0; i<nBlocks; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().y == block[i]->curAnim->sprite.GetPosition().y && ninja->curAnim->sprite.GetPosition().x - (ninja->curAnim->sprite.GetSize().x/2 - block[i]->curAnim->sprite.GetSize().x/2) == block[i]->curAnim->sprite.GetPosition().x && typeid(*block[i]) == typeid(SpringBlock) && block[i]->curAnim->sprite.GetRotation()==-90)
			{
				ninja->setSavedState(ninja->getState());
				ninja->setState(10);
				block[i]->Animate();
				justjumped=true;
			}
		}
		break;
	case 8:
		for(int i=0; i<nBlocks; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().x == block[i]->curAnim->sprite.GetPosition().x && ninja->curAnim->sprite.GetPosition().y + (ninja->curAnim->sprite.GetSize().y/2 - block[i]->curAnim->sprite.GetSize().y/2) == block[i]->curAnim->sprite.GetPosition().y && typeid(*block[i]) == typeid(SpringBlock) && block[i]->curAnim->sprite.GetRotation()==0)
			{
				ninja->setState(10);
				block[i]->Animate();
				justjumped=true;
			}
		}
		break;
	default:
		break;
	}

	//Fallblock under f�tterna?!
	airborne=true;
	switch(ninja->getState())
	{
	case 0:
		for(int i=0; i<nBlocks && airborne==true; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().x == block[i]->curAnim->sprite.GetPosition().x && ninja->curAnim->sprite.GetPosition().y + (ninja->curAnim->sprite.GetSize().y/2 + block[i]->curAnim->sprite.GetSize().y/2) == block[i]->curAnim->sprite.GetPosition().y && typeid(*block[i]) == typeid(FallBlock))
			{
				ninja->setState(8);
				block[i]->Animate();
				ninja->setSavedState(0);
			}
		}
		break;
	case 6:
		for(int i=0; i<nBlocks && airborne==true; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().x == block[i]->curAnim->sprite.GetPosition().x && ninja->curAnim->sprite.GetPosition().y + (ninja->curAnim->sprite.GetSize().y/2 + block[i]->curAnim->sprite.GetSize().y/2) == block[i]->curAnim->sprite.GetPosition().y && typeid(*block[i]) == typeid(FallBlock))
			{
				ninja->setState(8);
				block[i]->Animate();
				ninja->setSavedState(6);
			}
		}
		break;
	case 8:
		for(int i=0; i<nBlocks && airborne==true; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().x + ninja->curAnim->sprite.GetSize().x/2 >= block[i]->curAnim->sprite.GetPosition().x - block[i]->curAnim->sprite.GetSize().x/2 && ninja->curAnim->sprite.GetPosition().x - ninja->curAnim->sprite.GetSize().x/2 <= block[i]->curAnim->sprite.GetPosition().x + block[i]->curAnim->sprite.GetSize().x/2 && ninja->curAnim->sprite.GetPosition().y + (ninja->curAnim->sprite.GetSize().y/2 + block[i]->curAnim->sprite.GetSize().y/2) == block[i]->curAnim->sprite.GetPosition().y && typeid(*block[i]) == typeid(FallBlock))
			{
				ninja->setState(8);
				block[i]->Animate();
			}
		}
		break;
	default:
		break;
	}

	//3. Har blocket under f�tterna f�rsvunnit?
	if(!ninja->getDead())
	{
	airborne=true;
	switch(ninja->getState())
	{
	case 0:
		for(int i=0; i<nBlocks && airborne==true; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().x + ninja->curAnim->sprite.GetSize().x/2 >= block[i]->curAnim->sprite.GetPosition().x - block[i]->curAnim->sprite.GetSize().x/2 && ninja->curAnim->sprite.GetPosition().x - ninja->curAnim->sprite.GetSize().x/2 <= block[i]->curAnim->sprite.GetPosition().x + block[i]->curAnim->sprite.GetSize().x/2 && ninja->curAnim->sprite.GetPosition().y + (ninja->curAnim->sprite.GetSize().y/2 + block[i]->curAnim->sprite.GetSize().y/2) == block[i]->curAnim->sprite.GetPosition().y && (typeid(*block[i]) == typeid(StdBlock) || typeid(*block[i]) == typeid(FallBlock)|| typeid(*block[i]) == typeid(PlayerBlock)))
				airborne=false;
		}
	case 1:
		for(int i=0; i<nBlocks && airborne==true; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().y + ninja->curAnim->sprite.GetSize().y/2 >= block[i]->curAnim->sprite.GetPosition().y - block[i]->curAnim->sprite.GetSize().y/2 && ninja->curAnim->sprite.GetPosition().y - ninja->curAnim->sprite.GetSize().y/2 <= block[i]->curAnim->sprite.GetPosition().y + block[i]->curAnim->sprite.GetSize().y/2 && ninja->curAnim->sprite.GetPosition().x + (ninja->curAnim->sprite.GetSize().x/2 + block[i]->curAnim->sprite.GetSize().x/2) == block[i]->curAnim->sprite.GetPosition().x && (typeid(*block[i]) == typeid(StdBlock) || typeid(*block[i]) == typeid(FallBlock)|| typeid(*block[i]) == typeid(PlayerBlock)))
				airborne=false;
		}
		break;
	case 2:
		for(int i=0; i<nBlocks && airborne==true; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().x + ninja->curAnim->sprite.GetSize().x/2 >= block[i]->curAnim->sprite.GetPosition().x - block[i]->curAnim->sprite.GetSize().x/2 && ninja->curAnim->sprite.GetPosition().x - ninja->curAnim->sprite.GetSize().x/2 <= block[i]->curAnim->sprite.GetPosition().x + block[i]->curAnim->sprite.GetSize().x/2 && ninja->curAnim->sprite.GetPosition().y - (ninja->curAnim->sprite.GetSize().y/2 + block[i]->curAnim->sprite.GetSize().y/2) == block[i]->curAnim->sprite.GetPosition().y && (typeid(*block[i]) == typeid(StdBlock) || typeid(*block[i]) == typeid(FallBlock)|| typeid(*block[i]) == typeid(PlayerBlock)))
				airborne=false;
		}
		break;
	case 3:
		for(int i=0; i<nBlocks && airborne==true; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().y + ninja->curAnim->sprite.GetSize().y/2 >= block[i]->curAnim->sprite.GetPosition().y - block[i]->curAnim->sprite.GetSize().y/2 && ninja->curAnim->sprite.GetPosition().y - ninja->curAnim->sprite.GetSize().y/2 <= block[i]->curAnim->sprite.GetPosition().y + block[i]->curAnim->sprite.GetSize().y/2 && ninja->curAnim->sprite.GetPosition().x - (ninja->curAnim->sprite.GetSize().x/2 + block[i]->curAnim->sprite.GetSize().x/2) == block[i]->curAnim->sprite.GetPosition().x && (typeid(*block[i]) == typeid(StdBlock) || typeid(*block[i]) == typeid(FallBlock)|| typeid(*block[i]) == typeid(PlayerBlock)))
				airborne=false;
		}
		break;
	case 6:
		for(int i=0; i<nBlocks && airborne==true; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().x + ninja->curAnim->sprite.GetSize().x/2 >= block[i]->curAnim->sprite.GetPosition().x - block[i]->curAnim->sprite.GetSize().x/2 && ninja->curAnim->sprite.GetPosition().x - ninja->curAnim->sprite.GetSize().x/2 <= block[i]->curAnim->sprite.GetPosition().x + block[i]->curAnim->sprite.GetSize().x/2 && ninja->curAnim->sprite.GetPosition().y + (ninja->curAnim->sprite.GetSize().y/2 + block[i]->curAnim->sprite.GetSize().y/2) == block[i]->curAnim->sprite.GetPosition().y && (typeid(*block[i]) == typeid(StdBlock) || typeid(*block[i]) == typeid(FallBlock)|| typeid(*block[i]) == typeid(PlayerBlock)))
				airborne=false;
		}
	case 7:
		for(int i=0; i<nBlocks && airborne==true; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().y + ninja->curAnim->sprite.GetSize().y/2 >= block[i]->curAnim->sprite.GetPosition().y - block[i]->curAnim->sprite.GetSize().y/2 && ninja->curAnim->sprite.GetPosition().y - ninja->curAnim->sprite.GetSize().y/2 <= block[i]->curAnim->sprite.GetPosition().y + block[i]->curAnim->sprite.GetSize().y/2 && ninja->curAnim->sprite.GetPosition().x + (ninja->curAnim->sprite.GetSize().x/2 + block[i]->curAnim->sprite.GetSize().x/2) == block[i]->curAnim->sprite.GetPosition().x && (typeid(*block[i]) == typeid(StdBlock) || typeid(*block[i]) == typeid(FallBlock)|| typeid(*block[i]) == typeid(PlayerBlock)))
				airborne=false;
		}
		break;
	case 4:
		for(int i=0; i<nBlocks && airborne==true; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().x + ninja->curAnim->sprite.GetSize().x/2 >= block[i]->curAnim->sprite.GetPosition().x - block[i]->curAnim->sprite.GetSize().x/2 && ninja->curAnim->sprite.GetPosition().x - ninja->curAnim->sprite.GetSize().x/2 <= block[i]->curAnim->sprite.GetPosition().x + block[i]->curAnim->sprite.GetSize().x/2 && ninja->curAnim->sprite.GetPosition().y - (ninja->curAnim->sprite.GetSize().y/2 + block[i]->curAnim->sprite.GetSize().y/2) == block[i]->curAnim->sprite.GetPosition().y && (typeid(*block[i]) == typeid(StdBlock) || typeid(*block[i]) == typeid(FallBlock)|| typeid(*block[i]) == typeid(PlayerBlock)))
				airborne=false;
		}
		break;
	case 5:
		for(int i=0; i<nBlocks && airborne==true; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().y + ninja->curAnim->sprite.GetSize().y/2 >= block[i]->curAnim->sprite.GetPosition().y - block[i]->curAnim->sprite.GetSize().y/2 && ninja->curAnim->sprite.GetPosition().y - ninja->curAnim->sprite.GetSize().y/2 <= block[i]->curAnim->sprite.GetPosition().y + block[i]->curAnim->sprite.GetSize().y/2 && ninja->curAnim->sprite.GetPosition().x - (ninja->curAnim->sprite.GetSize().x/2 + block[i]->curAnim->sprite.GetSize().x/2) == block[i]->curAnim->sprite.GetPosition().x && (typeid(*block[i]) == typeid(StdBlock) || typeid(*block[i]) == typeid(FallBlock)|| typeid(*block[i]) == typeid(PlayerBlock)))
				airborne=false;
		}
		break;
	case 8:
		for(int i=0; i<nBlocks && airborne==true; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().x + ninja->curAnim->sprite.GetSize().x/2 >= block[i]->curAnim->sprite.GetPosition().x - block[i]->curAnim->sprite.GetSize().x/2 && ninja->curAnim->sprite.GetPosition().x - ninja->curAnim->sprite.GetSize().x/2 <= block[i]->curAnim->sprite.GetPosition().x + block[i]->curAnim->sprite.GetSize().x/2 && ninja->curAnim->sprite.GetPosition().y + (ninja->curAnim->sprite.GetSize().y/2 + block[i]->curAnim->sprite.GetSize().y/2) == block[i]->curAnim->sprite.GetPosition().y && (typeid(*block[i]) == typeid(StdBlock)|| typeid(*block[i]) == typeid(PlayerBlock)))
				airborne=false;
		}
		break;
	case 9:
		for(int i=0; i<nBlocks && airborne==true; i++)
		{
			if(ninja->curAnim->sprite.GetPosition().x + ninja->curAnim->sprite.GetSize().x/2 >= block[i]->curAnim->sprite.GetPosition().x - block[i]->curAnim->sprite.GetSize().x/2 && ninja->curAnim->sprite.GetPosition().x - ninja->curAnim->sprite.GetSize().x/2 <= block[i]->curAnim->sprite.GetPosition().x + block[i]->curAnim->sprite.GetSize().x/2 && ninja->curAnim->sprite.GetPosition().y - (ninja->curAnim->sprite.GetSize().y/2 + block[i]->curAnim->sprite.GetSize().y/2) == block[i]->curAnim->sprite.GetPosition().y && (typeid(*block[i]) == typeid(StdBlock) || typeid(*block[i]) == typeid(FallBlock)|| typeid(*block[i]) == typeid(PlayerBlock)))
				airborne=false;
		}
		break;
	case 10:
		if(!justjumped)
		{
			for(int i=0; i<nBlocks && airborne==true; i++)
			{
				if(ninja->curAnim->sprite.GetPosition().x + ninja->curAnim->sprite.GetSize().x/2 >= block[i]->curAnim->sprite.GetPosition().x - block[i]->curAnim->sprite.GetSize().x/2 && ninja->curAnim->sprite.GetPosition().x - ninja->curAnim->sprite.GetSize().x/2 <= block[i]->curAnim->sprite.GetPosition().x + block[i]->curAnim->sprite.GetSize().x/2 && ninja->curAnim->sprite.GetPosition().y + (ninja->curAnim->sprite.GetSize().y/2 + block[i]->curAnim->sprite.GetSize().y/2) == block[i]->curAnim->sprite.GetPosition().y && (typeid(*block[i]) == typeid(StdBlock)|| typeid(*block[i]) == typeid(PlayerBlock)))
					airborne=false;
			}
		}
		break;
	default:
		break;
	}

	if(airborne && ninja->getState()!=8 && ninja->getState()!=9 && ninja->getState()!=10 && ninja->getDrawn() == true)
	{
		ninja->setSavedState(ninja->getState());
		ninja->setState(8);
	}

	else if(!airborne && (ninja->getState()==8 || ninja->getState()==10) && ninja->getDrawn() == true)
	{
		this->ninjaHitsGround(ninja);
	}

	else if(!airborne && ninja->getState()==9 && ninja->getDrawn() == true)
	{
		this->ninjaHitsHead(ninja);
	}
	}
	

	//4. Krock med v�gg
	if(ninja->getState() != 8 && ninja->getState() != 9 && ninja->getState() != 10)
	{
		this->collides=false;
		ninja->testmove();
		for(int i=0; i<nBlocks && collides==false;i++)
		{
			this->collides=true;
		
			if(ninja->curAnim->sprite.GetPosition().x + ninja->curAnim->sprite.GetSize().x/2 <= block[i]->curAnim->sprite.GetPosition().x - block[i]->curAnim->sprite.GetSize().x/2)//Ninjan �r till v�nster om blocket
				collides=false;
			if(ninja->curAnim->sprite.GetPosition().x - ninja->curAnim->sprite.GetSize().x/2 >= block[i]->curAnim->sprite.GetPosition().x + block[i]->curAnim->sprite.GetSize().x/2)//Ninjan �r till h�ger om blocket
				collides=false;
			if(ninja->curAnim->sprite.GetPosition().y + ninja->curAnim->sprite.GetSize().y/2 <= block[i]->curAnim->sprite.GetPosition().y - block[i]->curAnim->sprite.GetSize().y/2)//Ninjan �r ovanf�r blocket
				collides=false;
			if(ninja->curAnim->sprite.GetPosition().y - ninja->curAnim->sprite.GetSize().y/2 >= block[i]->curAnim->sprite.GetPosition().y + block[i]->curAnim->sprite.GetSize().y/2)//Ninjan �r nedanf�r blocket
				collides=false;
			//if((typeid(*block[i]) != typeid(StdBlock) || ninja->getDrawn() != true) && typeid(*block[i]) != typeid(PlayerBlock)) //Blocket �r inte ett StdBlock
			if((typeid(*block[i]) != typeid(StdBlock) && typeid(*block[i]) != typeid(PlayerBlock)/* && typeid(*block[i]) != typeid(FallBlock)*/)|| ninja->getDrawn() != true )
				collides=false;
		}
		ninja->retrace();
		if(collides)
			ninjaHitsWall(ninja);
	}

	//4,5. Krock med v�gg (l�ngdhopp)
	if(ninja->getState()==10 || ninja->getState()==0 || ninja->getState()==6)
	{
		this->collides=false;
		for(int i=0; i<nBlocks && collides==false;i++)
		{
			if(ninja->getDirX()==1 && ninja->curAnim->sprite.GetPosition().x == block[i]->curAnim->sprite.GetPosition().x - (ninja->curAnim->sprite.GetSize().x/2 + block[i]->curAnim->sprite.GetSize().x/2) && ninja->curAnim->sprite.GetPosition().y > block[i]->curAnim->sprite.GetPosition().y - (ninja->curAnim->sprite.GetSize().y/2 + block[i]->curAnim->sprite.GetSize().y/2) && ninja->curAnim->sprite.GetPosition().y < block[i]->curAnim->sprite.GetPosition().y + (ninja->curAnim->sprite.GetSize().y/2 + block[i]->curAnim->sprite.GetSize().y/2) && (typeid(*block[i]) == typeid(StdBlock)|| typeid(*block[i]) == typeid(PlayerBlock) || typeid(*block[i]) == typeid(FallBlock)))
			{
				collides=true;
				ninja->setState(7);
				int holder=ninja->curAnim->sprite.GetPosition().y;
				ninja->curAnim->sprite.SetPosition(ninja->curAnim->sprite.GetPosition().x, (ninja->curAnim->sprite.GetPosition().y + (holder % 4)));
			}
			else if(ninja->getDirX()==-1 && ninja->curAnim->sprite.GetPosition().x == block[i]->curAnim->sprite.GetPosition().x + (ninja->curAnim->sprite.GetSize().x/2 + block[i]->curAnim->sprite.GetSize().x/2) && ninja->curAnim->sprite.GetPosition().y > block[i]->curAnim->sprite.GetPosition().y - (ninja->curAnim->sprite.GetSize().y/2 + block[i]->curAnim->sprite.GetSize().y/2) && ninja->curAnim->sprite.GetPosition().y < block[i]->curAnim->sprite.GetPosition().y + (ninja->curAnim->sprite.GetSize().y/2 + block[i]->curAnim->sprite.GetSize().y/2) && (typeid(*block[i]) == typeid(StdBlock)|| typeid(*block[i]) == typeid(PlayerBlock) || typeid(*block[i]) == typeid(FallBlock)))
			{
				collides=true;
				ninja->setState(3);
				int holder=ninja->curAnim->sprite.GetPosition().y;
				ninja->curAnim->sprite.SetPosition(ninja->curAnim->sprite.GetPosition().x, (ninja->curAnim->sprite.GetPosition().y + (holder % 4)));
			}
		}

	}

	//5. G� �ver en kant
	if((((int)(ninja->curAnim->sprite.GetPosition().x)%(int)(block[0]->curAnim->sprite.GetSize().x) == 0) && ((int)ninja->getState()%2 == 0)) || (((int)(ninja->curAnim->sprite.GetPosition().y)%(int)(block[0]->curAnim->sprite.GetSize().y) == 0) && ((int)ninja->getState()%2 == 1)) && ninja->getState() != 8 && ninja->getState() != 9 && ninja->getState() != 10 && ninja->getDrawn() == true)
	{
		this->foothold=false;
		switch(ninja->getState())
		{
		case 0:
			for(int i=0; i<nBlocks ;i++)
			{
				if(ninja->curAnim->sprite.GetPosition().x - block[i]->curAnim->sprite.GetSize().x/2 == block[i]->curAnim->sprite.GetPosition().x && ninja->curAnim->sprite.GetPosition().y + block[i]->curAnim->sprite.GetSize().y/2 + ninja->curAnim->sprite.GetSize().y/2 == block[i]->curAnim->sprite.GetPosition().y && (typeid(*block[i]) == typeid(StdBlock) || typeid(*block[i]) == typeid(FallBlock)|| typeid(*block[i]) == typeid(PlayerBlock)))
				{
					foothold=true;
				}
			}
			if(!foothold)
			{
				ninja->curAnim->sprite.SetPosition(ninja->curAnim->sprite.GetPosition().x - ninja->curAnim->sprite.GetSize().x/2, ninja->curAnim->sprite.GetPosition().y);
				ninja->setState(1);
			}
			break;
		case 1:
			for(int i=0; i<nBlocks ;i++)
			{
				if(ninja->curAnim->sprite.GetPosition().x + block[i]->curAnim->sprite.GetSize().x/2 + ninja->curAnim->sprite.GetSize().x/2 == block[i]->curAnim->sprite.GetPosition().x && ninja->curAnim->sprite.GetPosition().y + block[i]->curAnim->sprite.GetSize().y/2 == block[i]->curAnim->sprite.GetPosition().y && (typeid(*block[i]) == typeid(StdBlock) || typeid(*block[i]) == typeid(FallBlock)|| typeid(*block[i]) == typeid(PlayerBlock)))
				{
					foothold=true;
				}
			}
			if(!foothold)
			{
				ninja->curAnim->sprite.SetPosition(ninja->curAnim->sprite.GetPosition().x, ninja->curAnim->sprite.GetPosition().y + ninja->curAnim->sprite.GetSize().y/2);
				ninja->setState(2);
			}
			break;
		case 2:
			for(int i=0; i<nBlocks ;i++)
			{
				if(ninja->curAnim->sprite.GetPosition().x + block[i]->curAnim->sprite.GetSize().x/2 == block[i]->curAnim->sprite.GetPosition().x && ninja->curAnim->sprite.GetPosition().y - block[i]->curAnim->sprite.GetSize().y/2 - ninja->curAnim->sprite.GetSize().y/2 == block[i]->curAnim->sprite.GetPosition().y && (typeid(*block[i]) == typeid(StdBlock) || typeid(*block[i]) == typeid(FallBlock)|| typeid(*block[i]) == typeid(PlayerBlock)))
				{
					foothold=true;
				}
			}
			if(!foothold)
			{
				ninja->curAnim->sprite.SetPosition(ninja->curAnim->sprite.GetPosition().x + ninja->curAnim->sprite.GetSize().x/2, ninja->curAnim->sprite.GetPosition().y);
				ninja->setState(3);
			}
			break;
		case 3:
			for(int i=0; i<nBlocks ;i++)
			{
				if(ninja->curAnim->sprite.GetPosition().x - block[i]->curAnim->sprite.GetSize().x/2 - ninja->curAnim->sprite.GetSize().x/2 == block[i]->curAnim->sprite.GetPosition().x && ninja->curAnim->sprite.GetPosition().y - block[i]->curAnim->sprite.GetSize().y/2 == block[i]->curAnim->sprite.GetPosition().y && (typeid(*block[i]) == typeid(StdBlock) || typeid(*block[i]) == typeid(FallBlock)|| typeid(*block[i]) == typeid(PlayerBlock)))
				{
					foothold=true;
				}
			}
			if(!foothold)
			{
				ninja->curAnim->sprite.SetPosition(ninja->curAnim->sprite.GetPosition().x, ninja->curAnim->sprite.GetPosition().y - ninja->curAnim->sprite.GetSize().y/2);
				ninja->setState(0);
			}
			break;
		case 4:
			for(int i=0; i<nBlocks ;i++)
			{
				if(ninja->curAnim->sprite.GetPosition().x - block[i]->curAnim->sprite.GetSize().x/2 == block[i]->curAnim->sprite.GetPosition().x && ninja->curAnim->sprite.GetPosition().y - block[i]->curAnim->sprite.GetSize().y/2 - ninja->curAnim->sprite.GetSize().y/2 == block[i]->curAnim->sprite.GetPosition().y && (typeid(*block[i]) == typeid(StdBlock) || typeid(*block[i]) == typeid(FallBlock)|| typeid(*block[i]) == typeid(PlayerBlock)))
				{
					foothold=true;
				}
			}
			if(!foothold)
			{
				ninja->curAnim->sprite.SetPosition(ninja->curAnim->sprite.GetPosition().x - ninja->curAnim->sprite.GetSize().x/2, ninja->curAnim->sprite.GetPosition().y);
				ninja->setState(7);
			}
			break;
		case 5:
			for(int i=0; i<nBlocks ;i++)
			{
				if(ninja->curAnim->sprite.GetPosition().x - block[i]->curAnim->sprite.GetSize().x/2 - ninja->curAnim->sprite.GetSize().x/2 == block[i]->curAnim->sprite.GetPosition().x && ninja->curAnim->sprite.GetPosition().y + block[i]->curAnim->sprite.GetSize().y/2 == block[i]->curAnim->sprite.GetPosition().y && (typeid(*block[i]) == typeid(StdBlock) || typeid(*block[i]) == typeid(FallBlock)|| typeid(*block[i]) == typeid(PlayerBlock)))
				{
					foothold=true;
				}
			}
			if(!foothold)
			{
				ninja->curAnim->sprite.SetPosition(ninja->curAnim->sprite.GetPosition().x, ninja->curAnim->sprite.GetPosition().y + ninja->curAnim->sprite.GetSize().y/2);
				ninja->setState(4);
			}
			break;
		case 6:
			for(int i=0; i<nBlocks ;i++)
			{
				if(ninja->curAnim->sprite.GetPosition().x + block[i]->curAnim->sprite.GetSize().x/2 == block[i]->curAnim->sprite.GetPosition().x && ninja->curAnim->sprite.GetPosition().y + block[i]->curAnim->sprite.GetSize().y/2 + ninja->curAnim->sprite.GetSize().y/2 == block[i]->curAnim->sprite.GetPosition().y && (typeid(*block[i]) == typeid(StdBlock) || typeid(*block[i]) == typeid(FallBlock)|| typeid(*block[i]) == typeid(PlayerBlock)))
				{
					foothold=true;
				}
			}
			if(!foothold)
			{
				ninja->curAnim->sprite.SetPosition(ninja->curAnim->sprite.GetPosition().x + ninja->curAnim->sprite.GetSize().x/2, ninja->curAnim->sprite.GetPosition().y);
				ninja->setState(5);
			}
			break;
		case 7:
			for(int i=0; i<nBlocks ;i++)
			{
				if(ninja->curAnim->sprite.GetPosition().x + block[i]->curAnim->sprite.GetSize().x/2 + ninja->curAnim->sprite.GetSize().x/2 == block[i]->curAnim->sprite.GetPosition().x && ninja->curAnim->sprite.GetPosition().y - block[i]->curAnim->sprite.GetSize().y/2 == block[i]->curAnim->sprite.GetPosition().y && (typeid(*block[i]) == typeid(StdBlock) || typeid(*block[i]) == typeid(FallBlock)|| typeid(*block[i]) == typeid(PlayerBlock)))
				{
					foothold=true;
				}
			}
			if(!foothold)
			{
				ninja->curAnim->sprite.SetPosition(ninja->curAnim->sprite.GetPosition().x, ninja->curAnim->sprite.GetPosition().y - ninja->curAnim->sprite.GetSize().y/2);
				ninja->setState(6);
			}
			break;
		default:
			break;
		}
	}
	}
	}
}

void Collision::ninjaHitsWall(NinjaIF* ninja)
{
	switch(ninja->getState())
	{
	case 0:
			ninja->setState(3);
		break;
	case 1:
			ninja->setState(0);
		break;
	case 2:
			ninja->setState(1);
		break;
	case 3:
			ninja->setState(2);
		break;
	case 4:
			ninja->setState(5);
		break;
	case 5:
			ninja->setState(6);
		break;
	case 6:
			ninja->setState(7);
		break;
	case 7:
			ninja->setState(4);
		break;
	default:
		break;

	}
}

void Collision::ninjaHitsGround(NinjaIF* ninja)
{
	switch(ninja->getSavedState())
	{
	case 0:
			ninja->setState(0);
		break;
	case 1:
			ninja->setState(0);
		break;
	case 2:
			ninja->setState(0);
		break;
	case 3:
			ninja->setState(0);
		break;
	case 4:
			ninja->setState(6);
		break;
	case 5:
			ninja->setState(6);
		break;
	case 6:
			ninja->setState(6);
		break;
	case 7:
			ninja->setState(6);
		break;
	default:
		break;

	}
}

void Collision::ninjaHitsHead(NinjaIF* ninja)
{
	switch(ninja->getSavedState())
	{
	case 0:
			ninja->setState(4);
		break;
	case 1:
			ninja->setState(4);
		break;
	case 2:
			ninja->setState(4);
		break;
	case 3:
			ninja->setState(4);
		break;
	case 4:
			ninja->setState(2);
		break;
	case 5:
			ninja->setState(2);
		break;
	case 6:
			ninja->setState(2);
		break;
	case 7:
			ninja->setState(2);
		break;
	default:
		break;

	}
}

void Collision::player(Block** block, Player* player, int nBlocks, RenderWindow* wnd)
{
	f++;
	this->firstTime=true;
	this->savedSpeed=0;

	//Golv/tak-test
	bool wallcollide=false;
	int knuffarN=0;

	this->collides=true;
	while(collides)
	{


		this->collides=false;
		for(int i=0;i<nBlocks;i++)
		{
			if(player->getPosX() > block[i]->curAnim->sprite.GetPosition().x - (player->getSizeX()/2 + block[i]->curAnim->sprite.GetSize().x/2) && player->getPosX() < block[i]->curAnim->sprite.GetPosition().x + (player->getSizeX()/2 + block[i]->curAnim->sprite.GetSize().x/2) && (typeid(*block[i]) == typeid(StdBlock) || typeid(*block[i]) == typeid(FallBlock)|| typeid(*block[i]) == typeid(PlayerBlock))) //Kolliderar i x-led
			{
				if(player->getPosY() > block[i]->curAnim->sprite.GetPosition().y - (player->getSizeY()/2 + block[i]->curAnim->sprite.GetSize().y/2) && player->getPosY() < block[i]->curAnim->sprite.GetPosition().y + (player->getSizeY()/2 + block[i]->curAnim->sprite.GetSize().y/2)) //Kolliderar i y-led
				{
					this->collides=true;
					knuffarN=block[i]->curAnim->sprite.GetPosition().x;
				}

			}
		}

		if(collides && player->getPosX() <= knuffarN)
		{
			player->curAnim->sprite.SetPosition(player->curAnim->sprite.GetPosition().x - 1, player->curAnim->sprite.GetPosition().y);
			player->setPosX(player->getPosX() - 1);
		}
		else if(collides && player->getPosX() > knuffarN)
		{
			player->curAnim->sprite.SetPosition(player->curAnim->sprite.GetPosition().x + 1, player->curAnim->sprite.GetPosition().y);
			player->setPosX(player->getPosX() + 1);
		}
	}


	this->collides=true;
	while(collides)
	{


		this->collides=false;
		player->testmove(wnd);
		for(int i=0;i<nBlocks;i++)
		{
			if(player->getPosX() > block[i]->curAnim->sprite.GetPosition().x - (player->getSizeX()/2 + block[i]->curAnim->sprite.GetSize().x/2) && player->getPosX() < block[i]->curAnim->sprite.GetPosition().x + (player->getSizeX()/2 + block[i]->curAnim->sprite.GetSize().x/2) && (typeid(*block[i]) == typeid(StdBlock) || typeid(*block[i]) == typeid(FallBlock)|| typeid(*block[i]) == typeid(PlayerBlock))) //Kolliderar i x-led
			{
				if(player->getPosY() > block[i]->curAnim->sprite.GetPosition().y - (player->getSizeY()/2 + block[i]->curAnim->sprite.GetSize().y/2) && player->getPosY() < block[i]->curAnim->sprite.GetPosition().y + (player->getSizeY()/2 + block[i]->curAnim->sprite.GetSize().y/2)) //Kolliderar i y-led
					this->collides=true;
			}
		}
		player->retrace(wnd);

		if(collides && player->getSpeedX() > 0)
		{
			player->setSpeedX(player->getSpeedX()-1);
			wallcollide=true;
		}

		else if(collides && player->getSpeedX() < 0)
		{
			player->setSpeedX(player->getSpeedX()+1);
			wallcollide=true;
		}
		
		else if(collides && player->getSpeedX() == 0)
		{
			collides=false;
		}
	}



	this->collides=true;
	while(collides)
	{
		this->collides=false;
		player->testmoveY(wnd);
		for(int i=0;i<nBlocks;i++)
		{
			if(player->getPosX() > block[i]->curAnim->sprite.GetPosition().x - (player->getSizeX()/2 + block[i]->curAnim->sprite.GetSize().x/2) && player->getPosX() < block[i]->curAnim->sprite.GetPosition().x + (player->getSizeX()/2 + block[i]->curAnim->sprite.GetSize().x/2) && (typeid(*block[i]) == typeid(StdBlock) || typeid(*block[i]) == typeid(FallBlock)|| typeid(*block[i]) == typeid(PlayerBlock))) //Kolliderar i x-led
			{
				if(player->getPosY() > block[i]->curAnim->sprite.GetPosition().y - (player->getSizeY()/2 + block[i]->curAnim->sprite.GetSize().y/2) && player->getPosY() < block[i]->curAnim->sprite.GetPosition().y + (player->getSizeY()/2 + block[i]->curAnim->sprite.GetSize().y/2)) //Kolliderar i y-led
					this->collides=true;
			}
		}
		player->retraceY(wnd);

		if(collides && player->getSpeedY() > 0)
		{
			if(firstTime)
			{
				savedSpeed=player->getSpeedY();
				firstTime=false;
			}
			player->setSpeedY(player->getSpeedY()-1);
		}
	
		else if(collides && player->getSpeedY() < 0)
		{
			if(firstTime)
			{
				savedSpeed=player->getSpeedY();
				firstTime=false;
			}
			player->setSpeedY(player->getSpeedY()+1);
		}

		else if(collides && player->getSpeedY() == 0)
		{
			collides=false;
		}
		
	}

	//Ground-check
	collides=false;
	for(int i=0;i<nBlocks;i++)
	{
		if(player->getPosY() == block[i]->curAnim->sprite.GetPosition().y - (player->getSizeY()/2 + block[i]->curAnim->sprite.GetSize().y/2) && player->getPosX() > block[i]->curAnim->sprite.GetPosition().x - (player->getSizeX()/2 + block[i]->curAnim->sprite.GetSize().x/2) && player->getPosX() < block[i]->curAnim->sprite.GetPosition().x + (player->getSizeX()/2 + block[i]->curAnim->sprite.GetSize().x/2) && (typeid(*block[i]) == typeid(StdBlock) || typeid(*block[i]) == typeid(FallBlock)|| typeid(*block[i]) == typeid(PlayerBlock)))
		{
			collides=true;
		}
	}

	if(!collides)
	{
		if(player->getPreCollides())
			player->setSpeedY(1);
		player->setAccel(1);
		player->setSpeedX(4);
		player->setGrounded(false);
		player->setPreCollides(false);
	}
	else
	{
		player->setAccel(0);
		player->setSpeedX(6);
		player->setGrounded(true);
		player->setPreCollides(true);
	}

	//Roofcheck
	collides=false;
	for(int i=0;i<nBlocks;i++)
	{
		if(player->getPosY() == block[i]->curAnim->sprite.GetPosition().y + (player->getSizeY()/2 + block[i]->curAnim->sprite.GetSize().y/2) && player->getPosX() > block[i]->curAnim->sprite.GetPosition().x - (player->getSizeX()/2 + block[i]->curAnim->sprite.GetSize().x/2) && player->getPosX() < block[i]->curAnim->sprite.GetPosition().x + (player->getSizeX()/2 + block[i]->curAnim->sprite.GetSize().x/2) && (typeid(*block[i]) == typeid(StdBlock) || typeid(*block[i]) == typeid(FallBlock)|| typeid(*block[i]) == typeid(PlayerBlock)))
		{
			collides=true;
		}
	}

	if(collides && player->getGrounded())
	{
		player->setAccel(0);
		player->setSpeedY(0);
		//player->setGrounded(true);
	}

	//Wall-check
	bool rightwall=false;
	bool leftwall=false;
	for(int i=0;i<nBlocks;i++)
	{
		if(player->getPosX() == block[i]->curAnim->sprite.GetPosition().x - (player->getSizeX()/2 + block[i]->curAnim->sprite.GetSize().x/2) && player->getPosY() > block[i]->curAnim->sprite.GetPosition().y - (player->getSizeY()/2 + block[i]->curAnim->sprite.GetSize().y/2) && player->getPosY() < block[i]->curAnim->sprite.GetPosition().y + (player->getSizeY()/2 + block[i]->curAnim->sprite.GetSize().y/2) && (typeid(*block[i]) == typeid(StdBlock) || typeid(*block[i]) == typeid(FallBlock)|| typeid(*block[i]) == typeid(PlayerBlock)))
		{
			wallcollide=true;
			rightwall=true;
		}
		if(player->getPosX() == block[i]->curAnim->sprite.GetPosition().x + (player->getSizeX()/2 + block[i]->curAnim->sprite.GetSize().x/2) && player->getPosY() > block[i]->curAnim->sprite.GetPosition().y - (player->getSizeY()/2 + block[i]->curAnim->sprite.GetSize().y/2) && player->getPosY() < block[i]->curAnim->sprite.GetPosition().y + (player->getSizeY()/2 + block[i]->curAnim->sprite.GetSize().y/2) && (typeid(*block[i]) == typeid(StdBlock) || typeid(*block[i]) == typeid(FallBlock)|| typeid(*block[i]) == typeid(PlayerBlock)))
		{
			wallcollide=true;
			leftwall=true;
		}
	}

	if(leftwall)
	{
		player->setHitLeft(true);
	}
	else
	{
		player->setHitLeft(false);
	}

	if(rightwall)
	{
		player->setHitRight(true);
	}
	else
	{
		player->setHitRight(false);
	}

	

}




bool Collision::isPlayerAtExit(Player* p, Block* d)
{
	if(p->curAnim->sprite.GetPosition().x > d->curAnim->sprite.GetPosition().x - d->curAnim->sprite.GetSize().x/2 && p->curAnim->sprite.GetPosition().x < d->curAnim->sprite.GetPosition().x + d->curAnim->sprite.GetSize().x/2 && p->curAnim->sprite.GetPosition().y + (p->curAnim->sprite.GetSize().y/2 - d->curAnim->sprite.GetSize().y/2) == d->curAnim->sprite.GetPosition().y )
	{
		return true;
	}
	return false;
}