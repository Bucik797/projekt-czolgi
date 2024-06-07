#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <iostream>

using namespace sf;
using namespace std;

class Loadingscreen : public Sprite
{
public:
	Loadingscreen();
	~Loadingscreen() {}
	void update();
	void drawGraphics(RenderWindow& window);


private:
	void loadAssets();
		
	Sprite backgroundSPR, logoSPR;
	Texture backgroundTXT, logoTXT;

};

