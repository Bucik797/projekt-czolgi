
#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <string>
#include <iostream>
#include "Loadingscreen.h"


using namespace std;
using namespace sf;

class Menu : public Sprite
{
public:
	Menu();
	~Menu()
	{
	}


	CircleShape playButton, settingsButton, closeButton;
	void update();
	void drawGraphics(RenderWindow& window);


private:

	Font font;
	Texture background_TXT;
	Texture white_TXT;
	Texture but_TXT;
	Texture logo_TXT;


	Sprite backgroundSPR, logoSPR, whiteSPR, butSPR;
	Text whiteName, butName, whiteLastname, butLastname;

	void loadAssets();
};

