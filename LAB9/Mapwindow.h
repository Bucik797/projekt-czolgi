#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <string>
#include <iostream>

using namespace sf;
using namespace std;

class Mapwindow : public Sprite
{
public:
	Mapwindow();
	~Mapwindow()
	{
	}

	void drawGraphics(RenderWindow& window);

	RectangleShape playButton, settingsButton, closeButton;
	Sprite backgroundSPR, logoSPR, map1SPR, map2SPR, map3SPR, map4SPR;

private:
	
	Font font, mapFont;
	Texture background_TXT;
	Texture logo_TXT;
	Texture button_TXT;
	Texture map1_TXT, map2_TXT, map3_TXT, map4_TXT;

	Text mapsText, map1Text, map2Text, map3Text, map4Text, backText;

	void update();
	void loadAssets();
};

