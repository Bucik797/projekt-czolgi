#include "Loadingscreen.h"
#include <iostream>

Loadingscreen::Loadingscreen()
{
	loadAssets();
}

void Loadingscreen::update()
{
}

void Loadingscreen::loadAssets()
{
	if (!backgroundTXT.loadFromFile("loadingTanks.png"))
	{
		cout << "Failed to load background texture" << endl;
	}
	if (!logoTXT.loadFromFile("gameLogo.png"))
	{
		cout << "Failed to load logo texture" << endl;
	}

	this->setTexture(backgroundTXT);

	logoSPR.setTexture(logoTXT);
	logoSPR.setPosition(550, 50);
	logoSPR.setScale(0.2, 0.2);
}

void Loadingscreen::drawGraphics(RenderWindow& window)
{
	window.draw(*this);
	window.draw(logoSPR);
}



