#ifndef SNDHOLDER_H
#define SNDHOLDER_H
#include <SFML\Audio.hpp>

using namespace sf;

class SndHolder
{
private:
	static SndHolder* pInstance;
	SndHolder();

public:
	SoundBuffer click;
	SoundBuffer yay;
	SoundBuffer scream;
	SoundBuffer suction;
	SoundBuffer spring;
	SoundBuffer drumroll;
	SoundBuffer theme;
	SoundBuffer intro;
	SoundBuffer wdupNinja;
	SoundBuffer sexyNinja;

	Sound sndClick;
	Sound sndYay;
	Sound sndScream;
	Sound sndSuction;
	Sound sndSpring;
	Sound musDrumroll;
	Sound musTheme;
	Sound musIntro;
	Sound sndWdupNinja;
	Sound sndSexyNinja;
	bool soundOn;

	void onoff();
	void sndOn(bool on);

	~SndHolder();
	static SndHolder* getInst();
};

#endif