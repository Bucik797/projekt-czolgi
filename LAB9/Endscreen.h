#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <string>
#include <iostream>

using namespace sf;
using namespace std;

class Endscreen : public Sprite
{
public:
	Endscreen();
	~Endscreen()
	{
	}

	void loadAssets();
	void drawGraphics(RenderWindow &window);
	RectangleShape closebutton;


private:
	Texture backgroundTXT;

};


