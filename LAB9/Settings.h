#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <string>
#include <iostream>
#include "Soundeffects.h"

using namespace sf;
using namespace std;

class Settings : public Sprite
{
public:
	Settings();
	~Settings()
	{
	}
	
	RectangleShape music0Button, music20Button, music40Button, music60Button, music80Button, music100Button, sfx0Button, sfx20Button, sfx40Button, sfx60Button, sfx80Button, sfx100Button, closeButton;
	void drawGraphics(RenderWindow& window);
	void sfxRegulation(Soundeffects& soundeffects, RenderWindow& window);
	void musicRregulation(Music& music, Music& happymusic, RenderWindow& settingswindow, Soundeffects& sfx);
	bool buttonClicked(Soundeffects sfx, RenderWindow& window, RectangleShape& button);

private:
	
	Font font;
	Texture background_TXT;
	Texture logo_TXT;
	Texture button_TXT;

	Sprite backgroundSPR, logoSPR, whiteSPR, butSPR;
	Text musicText, settingsText, closeText, sfxText, music0Text, music20Text, music40Text, music60Text, music80Text, music100Text, sfx0Text, sfx20Text, sfx40Text, sfx60Text, sfx80Text, sfx100Text;
	RectangleShape* selectedMusicButton, * selectedSFXButton;


	void update();
	void loadAssets();
};

