#include "Tankwindow.h"

Tankwindow::Tankwindow()
{
    loadAssets();
}

void Tankwindow::update(bool mc1, bool mc3)
{
    if (mc1)
    {
        
        tank2locked.setString("");
        
    }
    if (mc3)
    {
        tank3locked.setString("");
        
    }
    
}


void Tankwindow::loadAssets()
{
    if (!tank1TXT.loadFromFile("ytank.png") ||
        !tank2TXT.loadFromFile("rtank.png") ||
        !tank3TXT.loadFromFile("btank.png"))
    {
        cout << "Failed to load textures" << endl;
    }
    if (!background_TXT.loadFromFile("tankinterface.png")) {
        cout << "Failed to load background texture" << endl;
    }
    if (!logo_TXT.loadFromFile("gameLogo.png"))
    {
        cout << "Failed to load logo texture" << endl;
    }
    this->setTexture(background_TXT);
    this->setScale(0.9, 0.9);


    closeButton.setOutlineColor(Color::Transparent);
    closeButton.setSize(Vector2f(610, 150));
    closeButton.setFillColor(Color::Transparent);
    closeButton.setPosition(500, 660);
    closeButton.setOutlineThickness(5);

    tank1button.setSize(Vector2f(350, 350));
    tank1button.setPosition(200, 250);
    tank1button.setTexture(&tank1TXT);

    tank2button.setSize(Vector2f(350, 350));
    tank2button.setPosition(600, 250);
    tank2button.setTexture(&tank2TXT);

    tank3button.setSize(Vector2f(350, 350));
    tank3button.setPosition(1000, 250);
    tank3button.setTexture(&tank3TXT);

    if (!font.loadFromFile("arial.ttf"))
    {
        cout << "Failed to load font" << endl;
    }

    tank1Text.setFont(font);
    tank1Text.setString("SPEEDY");
    tank1Text.setCharacterSize(50);
    tank1Text.setFillColor(Color::White);
    tank1Text.setPosition(200, 600);
    tank1Text.setOutlineColor(Color::Black);
    tank1Text.setOutlineThickness(8);

    tank2Text.setFont(font);
    tank2Text.setString("NORMAL");
    tank2Text.setCharacterSize(50);
    tank2Text.setFillColor(Color::White);
    tank2Text.setPosition(600, 600);
    tank2Text.setOutlineColor(Color::Black);
    tank2Text.setOutlineThickness(8);

    tank3Text.setFont(font);
    tank3Text.setString("HEAVY");
    tank3Text.setCharacterSize(50);
    tank3Text.setFillColor(Color::White);
    tank3Text.setPosition(1000, 600);
    tank3Text.setOutlineColor(Color::Black);
    tank3Text.setOutlineThickness(8);

    tank2locked.setFont(font);
    tank2locked.setString("LOCKED!");
    tank2locked.setCharacterSize(80);
    tank2locked.setFillColor(Color::White);
    tank2locked.setPosition(630, 500);
    tank2locked.setOutlineColor(Color::Black);
    tank2locked.setOutlineThickness(8);
    tank2locked.rotate(-45);

    tank3locked.setFont(font);
    tank3locked.setString("LOCKED!");
    tank3locked.setCharacterSize(80);
    tank3locked.setFillColor(Color::White);
    tank3locked.setPosition(1030, 500);
    tank3locked.setOutlineColor(Color::Black);
    tank3locked.setOutlineThickness(8);
    tank3locked.rotate(-45);

}

void Tankwindow::drawGraphics(RenderWindow& window)
{
    window.draw(*this);
    window.draw(tank1button);
    window.draw(tank2button);
    window.draw(tank3button);
    window.draw(tank1Text);
    window.draw(tank2Text);
    window.draw(tank3Text);
    window.draw(closeButton);
    window.draw(tank2locked);
    window.draw(tank3locked);
}



