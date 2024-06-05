#include "Loadingscreen.h"

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

	backgroundSPR.setTexture(backgroundTXT);
	backgroundSPR.setScale(1, 1);
	backgroundSPR.setPosition(0, 0);

	logoSPR.setTexture(logoTXT);
	logoSPR.setPosition(550, 50);
	logoSPR.setScale(0.2, 0.2);

	loadingCirlce.setRadius(30);
	loadingCirlce.setFillColor(Color::Transparent);
	loadingCirlce.setOutlineThickness(5);
	loadingCirlce.setOutlineColor(Color::Green);
	loadingCirlce.setPosition(650, 600);

}

void Loadingscreen::drawGraphics(RenderWindow& window)
{
	window.draw(*this);
	window.draw(logoSPR);	
	window.draw(loadingCirlce);
}



