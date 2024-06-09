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
        !map4_TXT.loadFromFile("marianowocity.png") ||
        !map_TXT.loadFromFile("map1.png"))

    {
        cout << "Failed to load textures" << endl;
    }
    if (!background_TXT.loadFromFile("mapinterface.png")) {
        cout << "Failed to load background texture" << endl;
    }
    if (!logo_TXT.loadFromFile("gameLogo.png"))
    {
        cout << "Failed to load logo texture" << endl;
    }

    this->setTexture(background_TXT);
    this->setScale(0.9, 0.9);


    closeButton.setOutlineColor(Color::Transparent);
    closeButton.setFillColor(Color::Transparent);
    closeButton.setOutlineThickness(5);
    closeButton.setSize(Vector2f(600, 200));
    closeButton.setPosition(500, 650);

    map1button.setTexture(&map1_TXT);
    map1button.setSize(Vector2f(350, 350));
    map1button.setPosition(25, 250);

    map2button.setTexture(&map_TXT);
    map2button.setSize(Vector2f(350, 350));
    map2button.setPosition(425, 250);

    map3button.setTexture(&map_TXT);
    map3button.setSize(Vector2f(350, 350));
    map3button.setPosition(825, 250);

    map4button.setTexture(&map_TXT);
    map4button.setSize(Vector2f(350, 350));
    map4button.setPosition(1225, 250);


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

    map1Text.setFont(mapFont);
    map1Text.setString("BLACK MAP");
    map1Text.setCharacterSize(30);
    map1Text.setFillColor(Color::Black);
    map1Text.setPosition(100, 600);
    map1Text.setOutlineColor(Color::White);
    map1Text.setOutlineThickness(3);

    map2Text.setFont(mapFont);
    map2Text.setString("DEZERCJA");
    map2Text.setCharacterSize(30);
    map2Text.setFillColor(Color::Black);
    map2Text.setPosition(500, 600);
    map2Text.setOutlineColor(Color::White);
    map2Text.setOutlineThickness(3);

    map3Text.setFont(mapFont);
    map3Text.setString("PLAIN PLANES");
    map3Text.setCharacterSize(30);
    map3Text.setFillColor(Color::Black);
    map3Text.setPosition(800, 600);
    map3Text.setOutlineColor(Color::White);
    map3Text.setOutlineThickness(3);

    map4Text.setFont(mapFont);
    map4Text.setString("MARIANOWO CITY");
    map4Text.setCharacterSize(30);
    map4Text.setFillColor(Color::Black);
    map4Text.setPosition(1150, 600);
    map4Text.setOutlineColor(Color::White);
    map4Text.setOutlineThickness(3);
}

void Mapwindow::update(bool map1completed, bool map2completed, bool map3completed)
{
    if (map1completed)
    {
        map2button.setTexture(&map2_TXT);
    }
    if (map2completed)
    {
        map3button.setTexture(&map3_TXT);
    }
    if (map3completed)
    {
        map4button.setTexture(&map4_TXT);
    }
}

void Mapwindow::drawGraphics(RenderWindow& window)
{
    window.draw(*this);
    window.draw(closeButton);
    window.draw(map1button);
    window.draw(map2button);
    window.draw(map3button);
    window.draw(map4button);
    window.draw(mapsText);
    window.draw(map1Text);
    window.draw(map2Text);
    window.draw(map3Text);
    window.draw(map4Text);
}
