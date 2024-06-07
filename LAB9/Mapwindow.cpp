#include "Mapwindow.h"

Mapwindow::Mapwindow()
{
	loadAssets();
}


bool Mapwindow::buttonClicked(RenderWindow& window, RectangleShape& button) {
    float mouseX = Mouse::getPosition(window).x;
    float mouseY = Mouse::getPosition(window).y;

    float btnPosX = button.getPosition().x;
    float btnPosY = button.getPosition().y;

    float btnxPosWidth = btnPosX + button.getLocalBounds().width;
    float btnyPosHeight = btnPosY + button.getLocalBounds().height;

    if (mouseX < btnxPosWidth && mouseX > btnPosX && mouseY < btnyPosHeight && mouseY > btnPosY) {
        return true;
    }
    return false;
}

bool Mapwindow::selectedSprite(RenderWindow& window, Sprite& sprite) {
    float mouseX = Mouse::getPosition(window).x;
    float mouseY = Mouse::getPosition(window).y;

    float spritePosX = sprite.getPosition().x;
    float spritePosY = sprite.getPosition().y;

    float spritePosWidth = spritePosX + sprite.getGlobalBounds().width;
    float spritePosHeight = spritePosY + sprite.getGlobalBounds().height;

    if (mouseX < spritePosWidth && mouseX > spritePosX && mouseY < spritePosHeight && mouseY > spritePosY) {
        return true;
    }
    return false;
}

void Mapwindow::loadAssets()
{
    if (!map1_TXT.loadFromFile("map1background.png") ||
        !map2_TXT.loadFromFile("map2background.png") ||
        !map3_TXT.loadFromFile("map3background.png") ||
        !map4_TXT.loadFromFile("map4background.png") ||
        !map_TXT.loadFromFile("map1.png") ||
        !button_TXT.loadFromFile("buttonbackground.png"))
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

    map2SPR.setTexture(map_TXT);
    map2SPR.setScale(0.3, 0.3);
    map2SPR.setPosition(450, 400);

    map3SPR.setTexture(map_TXT);
    map3SPR.setScale(0.3, 0.3);
    map3SPR.setPosition(800, 400);

    map4SPR.setTexture(map_TXT);
    map4SPR.setScale(0.3, 0.3);
    map4SPR.setPosition(1150, 400);

    closeButton.setOutlineColor(Color::Green);
    closeButton.setSize(Vector2f(200, 80));
    closeButton.setPosition(700, 800);
    closeButton.setTexture(&button_TXT);

    if (!font.loadFromFile("arial.ttf") ||
        !mapFont.loadFromFile("mapFont.ttf"))
    {
        cout << "Failed to load font" << endl;
    }

    mapsText.setFont(font);
    mapsText.setString("CHOOSE MAP BRO");
    mapsText.setCharacterSize(80);
    mapsText.setFillColor(Color::White);
    mapsText.setPosition(450, 30);
    mapsText.setOutlineColor(Color::Black);
    mapsText.setOutlineThickness(8);

    backText.setFont(font);
    backText.setString("BACK");
    backText.setCharacterSize(50);
    backText.setFillColor(Color::Black);
    backText.setPosition(730, 810);
    backText.setOutlineColor(Color::Green);
    backText.setOutlineThickness(3);

    map1Text.setFont(mapFont);
    map1Text.setString("BLACK MAP");
    map1Text.setCharacterSize(30);
    map1Text.setFillColor(Color::Black);
    map1Text.setPosition(100, 660);
    map1Text.setOutlineColor(Color::White);
    map1Text.setOutlineThickness(3);

    map2Text.setFont(mapFont);
    map2Text.setString("MAGIC PANTIES");
    map2Text.setCharacterSize(30);
    map2Text.setFillColor(Color::Black);
    map2Text.setPosition(450, 660);
    map2Text.setOutlineColor(Color::White);
    map2Text.setOutlineThickness(3);

    map3Text.setFont(mapFont);
    map3Text.setString("WILD WOOLVES");
    map3Text.setCharacterSize(30);
    map3Text.setFillColor(Color::Black);
    map3Text.setPosition(800, 660);
    map3Text.setOutlineColor(Color::White);
    map3Text.setOutlineThickness(3);

    map4Text.setFont(mapFont);
    map4Text.setString("MARIANOWO CITY");
    map4Text.setCharacterSize(30);
    map4Text.setFillColor(Color::Black);
    map4Text.setPosition(1150, 660);
    map4Text.setOutlineColor(Color::White);
    map4Text.setOutlineThickness(3);
}

void Mapwindow::update(bool map1completed, bool map2completed, bool map3completed)
{
    if (map1completed)
    {
        map2SPR.setTexture(map2_TXT);
    }
    if (map2completed)
    {
        map3SPR.setTexture(map3_TXT);
        map3SPR.setPosition(800, 390);
    }
    if (map3completed)
    {
        map4SPR.setTexture(map4_TXT);
        map4SPR.setPosition(1150, 370);
    }
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
