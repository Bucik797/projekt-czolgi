#include "Loadingscreen.h"
#include <iostream>
#include <math.h>

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

	loadingCircle.setRadius(30);
	loadingCircle.setFillColor(Color::Transparent);
	loadingCircle.setOutlineThickness(5);
	loadingCircle.setOutlineColor(Color::Green);
	loadingCircle.setPosition(650, 600);
}

void Loadingscreen::drawGraphics(RenderWindow& window, Clock& clock)
{
	window.draw(*this);
	window.draw(logoSPR);

	Time elapsed = clock.getElapsedTime();
	float pulseSpeed = 5.0f;
	float scaleFactor = 1.0f + 0.2f * sin(pulseSpeed * elapsed.asSeconds());
	loadingCircle.setRadius(30 * scaleFactor);
	loadingCircle.setOrigin(loadingCircle.getRadius(), loadingCircle.getRadius());
	loadingCircle.setPosition(650, 600); 

	window.draw(loadingCircle);
}



