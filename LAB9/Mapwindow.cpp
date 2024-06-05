#include "Mapwindow.h"

Mapwindow::Mapwindow()
{
	loadAssets();
}

void Mapwindow::loadAssets()
{
    if (!map1_TXT.loadFromFile("map11.png") ||
        !map2_TXT.loadFromFile("map1.png") ||
        !map3_TXT.loadFromFile("map1.png") ||
        !map4_TXT.loadFromFile("map1.png"))
    {
        cout << "Failed to load textures" << endl;
    }
    if (!background_TXT.loadFromFile("mainBackground.png")) {
        cout << "Failed to load background texture" << endl;
    }
    if (!logo_TXT.loadFromFile("gameLogo.png"))
    {
        cout << "Failed to load logo texture" << endl;
    }

    this->setTexture(background_TXT);

    map1SPR.setTexture(map1_TXT);
    map1SPR.setScale(0.3, 0.3);
    map1SPR.setPosition(100, 400);

    map2SPR.setTexture(map2_TXT);
    map2SPR.setScale(0.3, 0.3);
    map2SPR.setPosition(500, 400);

    map3SPR.setTexture(map3_TXT);
    map3SPR.setScale(0.3, 0.3);
    map3SPR.setPosition(900, 400);

    map4SPR.setTexture(map4_TXT);
    map4SPR.setScale(0.3, 0.3);
    map4SPR.setPosition(1300, 400);

    closeButton.setOutlineColor(Color::Green);
    closeButton.setSize(Vector2f(200, 80));
    closeButton.setFillColor(Color::Black);
    closeButton.setPosition(50, 480);

    if (!font.loadFromFile("arial.ttf") ||
        !mapFont.loadFromFile("mapFont.ttf"))
    {
        cout << "Failed to load font" << endl;
    }

    mapsText.setFont(font);
    mapsText.setString("CHOOSE YOUR FAV MAP");
    mapsText.setCharacterSize(80);
    mapsText.setFillColor(Color::White);
    mapsText.setPosition(500, 30);
    mapsText.setOutlineColor(Color::Black);
    mapsText.setOutlineThickness(8);

    backText.setFont(font);
    backText.setString("Back");
    backText.setCharacterSize(50);
    backText.setFillColor(Color::White);
    backText.setPosition(1320, 805);
    backText.setOutlineColor(Color::Black);
    backText.setOutlineThickness(3);

    map1Text.setFont(mapFont);
    map1Text.setString("SILENT VALLEY");
    map1Text.setCharacterSize(30);
    map1Text.setFillColor(Color::Black);
    map1Text.setPosition(100, 670);
    map1Text.setOutlineColor(Color::White);
    map1Text.setOutlineThickness(3);

    map2Text.setFont(mapFont);
    map2Text.setString("MAGIC PANTIES");
    map2Text.setCharacterSize(30);
    map2Text.setFillColor(Color::Black);
    map2Text.setPosition(500, 670);
    map2Text.setOutlineColor(Color::White);
    map2Text.setOutlineThickness(3);

    map3Text.setFont(mapFont);
    map3Text.setString("WILD WOOLVES");
    map3Text.setCharacterSize(30);
    map3Text.setFillColor(Color::Black);
    map3Text.setPosition(900, 670);
    map3Text.setOutlineColor(Color::White);
    map3Text.setOutlineThickness(3);

    map4Text.setFont(mapFont);
    map4Text.setString("MARIANOWO CITY");
    map4Text.setCharacterSize(30);
    map4Text.setFillColor(Color::Black);
    map4Text.setPosition(1300, 670);
    map4Text.setOutlineColor(Color::White);
    map4Text.setOutlineThickness(3);
}

void Mapwindow::update()
{
}

void Mapwindow::drawGraphics(RenderWindow& window)
{
    window.draw(*this);
    window.draw(map1SPR);
    window.draw(map2SPR);
    window.draw(map3SPR);
    window.draw(map4SPR);
    window.draw(closeButton);
    window.draw(mapsText);
    window.draw(backText);
    window.draw(map1Text);
    window.draw(map2Text);
    window.draw(map3Text);
    window.draw(map4Text);
}
