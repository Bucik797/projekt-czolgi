#include "Endscreen.h"

Endscreen::Endscreen()
{
	loadAssets();
}

void Endscreen::loadAssets()
{
	if (!backgroundTXT.loadFromFile("endscreen.png"))
	{
		cout << "Error loading Endscreen.png" << endl;
	}
	this->setTexture(backgroundTXT);

	closebutton.setSize(Vector2f(765, 474));
	closebutton.setPosition(0, 0);
	closebutton.setFillColor(Color::Transparent);
	closebutton.setOutlineColor(Color::Transparent);
}

void Endscreen::drawGraphics(RenderWindow& window)
{
	window.draw(*this);
	window.draw(closebutton);
}