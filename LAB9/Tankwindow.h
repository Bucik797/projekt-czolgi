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

	RectangleShape playButton, closeButton;

private:
	
	Font font;
	Texture background_TXT;
	Texture logo_TXT;
	Texture button_TXT;
	//Texture tank1_TXT, tank2_TXT, tank3_TXT;
	Texture P1L_texture, P1R_texture, P2L_texture, P2R_texture, player1_texture, player2_texture;

	Sprite player1_sprite, player2_sprite, P1R_sprite, P1L_sprite, P2R_sprite, P2L_sprite;
	Sprite backgroundSPR, logoSPR, tank1SPR, tank2SPR, tank3SPR;
	Text player1Text, player2Text, battleText;
	//Text tanksText, tank1Text, tank2Text, tank3Text, backText;

	void update();
	
	void loadAssets();
};

