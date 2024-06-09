#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

using namespace std;
using namespace sf;



class Soundeffects 
{
public:
	Soundeffects();
	~Soundeffects()
	{
	}

	void loadsounds();
	void adjustSFXVolume(float volume);
	Sound buttonclicked, enemydeath, enemydamaged, playerdamaged, enemyshoot;



private:
	vector<Sound*> sounds;

	SoundBuffer buttonclickedbuffer, enemydeathbuffer, enemydamagedbuffer, playerdamagedbuffer, enemyshootbuffer;
};


