#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <string>
#include <iostream>

using namespace sf;
using namespace std;

class Tankwindow : public Sprite
{
public:
	Tankwindow();
	~Tankwindow()
	{
	}

	void drawGraphics(RenderWindow& window);

	RectangleShape tank1button, tank2button, tank3button, closeButton;
	void update(bool mc1, bool mc3);

private:

	Font font;
	Texture background_TXT;
	Texture logo_TXT;
	Texture button_TXT;
	Texture tank1TXT, tank2TXT, tank3TXT;

	Sprite player1_sprite, player2_sprite, P1R_sprite, P1L_sprite, P2R_sprite, P2L_sprite;
	Sprite backgroundSPR, logoSPR, tank1SPR, tank2SPR, tank3SPR;
	Text tank1Text, tank2Text, tank3Text;
	Text tank2locked, tank3locked;

	
	
	
	void loadAssets();
};

