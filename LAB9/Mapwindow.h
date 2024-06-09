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
	bool buttonClicked(RenderWindow& window, RectangleShape& button);
	bool selectedSprite(RenderWindow& window, Sprite& sprite);
	void update(bool map1completed, bool map2completed, bool map3completed);

	RectangleShape closeButton, map1button, map2button, map3button, map4button;
	Sprite backgroundSPR, logoSPR;

private:


	Font font, mapFont;
	Texture background_TXT;
	Texture logo_TXT;
	Texture map_TXT, map1_TXT, map2_TXT, map3_TXT, map4_TXT;

	Text mapsText, map1Text, map2Text, map3Text, map4Text;

	void loadAssets();
};

