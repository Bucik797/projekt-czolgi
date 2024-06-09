#include "Soundeffects.h"

Soundeffects::Soundeffects()
{
	loadsounds();
}

void Soundeffects::loadsounds()
{
    if (!buttonclickedbuffer.loadFromFile("buttonclicked.wav"))
    {
        cout << "Failed to load button sound" << endl;
    }
    if (!enemydamagedbuffer.loadFromFile("enemydamaged.wav"))
    {
        cout << "Failed to load enemy dmg sound" << endl;
    }
    if (!playerdamagedbuffer.loadFromFile("takingdmg.wav"))
    {
        cout << "Failed to load player dmg sound" << endl;
    }
    if (!enemydeathbuffer.loadFromFile("enemydeath.wav"))
    {
        cout << "Failed to load enemy death sound" << endl;
    }
    if (!enemyshootbuffer.loadFromFile("enemyshot.wav"))
    {
        cout << "Failed to load enemy shot sound" << endl;
    }
    

    enemydamaged.setBuffer(enemydamagedbuffer);
    sounds.push_back(&enemydamaged);

    playerdamaged.setBuffer(playerdamagedbuffer);
    sounds.push_back(&playerdamaged);

    enemydeath.setBuffer(enemydeathbuffer);
    sounds.push_back(&enemydeath);

    enemyshoot.setBuffer(enemyshootbuffer);
    sounds.push_back(&enemyshoot);

    buttonclicked.setBuffer(buttonclickedbuffer);
    sounds.push_back(&buttonclicked);
}

void Soundeffects::adjustSFXVolume(float volume)
{
    for (auto sound : sounds)
    {
        sound->setVolume(volume);
    }
}
