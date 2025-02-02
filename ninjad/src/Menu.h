#ifndef MENU_H
#define MENU_H
#include "ImgHolder.h"
#include "InputHandler.h"
#include <iostream>
#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>
#include "SndHolder.h"
#include "Animation.h"

using namespace sf;

class Menu
{
private:
	RenderWindow* menuWnd;
	Sprite* background;

	Sprite** previewArray;

	Sprite** levelButtons;
	Sprite* numbers;
	Sprite* quitButton;
	Sprite* htpButton;		//How to play knapp
	Sprite* credButton;
	Sprite* credScreen;
	Sprite* howToPlayScreen;
	Sprite* locked;
	
	Sprite* mptr;

	Sprite* menuHUD;
	String* nNinjas;
	String* nStd;
	String* nFall;
	String* nJump;
	String* nSpring;
	String* nNinjReq;
	Image* map;

	Font* font;

	bool howToPlay;
	bool credits;
	bool isLocked;

	int buttonPointed;
	int buttonClicked;

	Vector2i btnFrame;

	InputHandler* input;
	unsigned short unlocked;
	
	bool switchBool(bool tf);
	void changeText(bool preview);

	void changePreview(unsigned short u);
	int findType(Color col);
	Sprite* createSprite(int type);

protected:
public:
	Menu();
	~Menu();

	void splashScreen();
	int levelSelect();

	int update();
	int eventHandler(Event e);
	void render();

	int checkMousePos();

	void Show(bool tf);

	void setUnlockedLevels(unsigned short levels);
};

#endif