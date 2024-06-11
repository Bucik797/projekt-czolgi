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
    if (!map1_TXT.loadFromFile("Assets/Textures/map1background.png") ||
        !map2_TXT.loadFromFile("Assets/Textures/map2background.png") ||
        !map3_TXT.loadFromFile("Assets/Textures/map3background.png") ||
        !map4_TXT.loadFromFile("Assets/Textures/marianowocity.png") ||
        !map_TXT.loadFromFile("Assets/Textures/map1.png"))

    {
        cout << "Failed to load textures" << endl;
    }
    if (!background_TXT.loadFromFile("Assets/Textures/mapinterface.png")) {
        cout << "Failed to load background texture" << endl;
    }
    if (!logo_TXT.loadFromFile("Assets/Textures/gameLogo.png"))
    {
        cout << "Failed to load logo texture" << endl;
    }

    this->setTexture(background_TXT);
    this->setScale(0.9, 0.9);


    closeButton.setOutlineColor(Color::Transparent);
    closeButton.setFillColor(Color::Transparent);
    closeButton.setOutlineThickness(5);
    closeButton.setSize(Vector2f(520, 195));
    closeButton.setPosition(550, 665);

    map1button.setTexture(&map1_TXT);
    map1button.setSize(Vector2f(350, 350));
    map1button.setPosition(25, 250);

    map2button.setTexture(&map2_TXT);
    map2button.setSize(Vector2f(350, 350));
    map2button.setPosition(425, 250);

    map3button.setTexture(&map3_TXT);
    map3button.setSize(Vector2f(350, 350));
    map3button.setPosition(825, 250);

    map4button.setTexture(&map4_TXT);
    map4button.setSize(Vector2f(350, 350));
    map4button.setPosition(1225, 250);


    if (!font.loadFromFile("Assets/Fonts/arial.ttf") ||
        !mapFont.loadFromFile("Assets/Fonts/mapFont.ttf"))
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
    map1Text.setString("DARK ABBYS");
    map1Text.setCharacterSize(30);
    map1Text.setFillColor(Color::Black);
    map1Text.setPosition(100, 600);
    map1Text.setOutlineColor(Color::White);
    map1Text.setOutlineThickness(3);

    map2Text.setFont(mapFont);
    map2Text.setString("STORMY DESERT");
    map2Text.setCharacterSize(30);
    map2Text.setFillColor(Color::Black);
    map2Text.setPosition(520, 600);
    map2Text.setOutlineColor(Color::White);
    map2Text.setOutlineThickness(3);

    map3Text.setFont(mapFont);
    map3Text.setString("PLAIN PLANES");
    map3Text.setCharacterSize(30);
    map3Text.setFillColor(Color::Black);
    map3Text.setPosition(870, 600);
    map3Text.setOutlineColor(Color::White);
    map3Text.setOutlineThickness(3);

    map4Text.setFont(mapFont);
    map4Text.setString("MARIANOWO CITY");
    map4Text.setCharacterSize(30);
    map4Text.setFillColor(Color::Black);
    map4Text.setPosition(1260, 600);
    map4Text.setOutlineColor(Color::White);
    map4Text.setOutlineThickness(3);

    map2pytajnik.setFont(font);
    map2pytajnik.setString("?");
    map2pytajnik.setCharacterSize(300);
    map2pytajnik.setFillColor(Color::White);
    map2pytajnik.setPosition(500, 250);
    map2pytajnik.setOutlineColor(Color::Black);
    map2pytajnik.setOutlineThickness(8);

    map3pytajnik.setFont(font);
    map3pytajnik.setString("?");
    map3pytajnik.setCharacterSize(300);
    map3pytajnik.setFillColor(Color::White);
    map3pytajnik.setPosition(900, 250);
    map3pytajnik.setOutlineColor(Color::Black);
    map3pytajnik.setOutlineThickness(8);

    map4pytajnik.setFont(font);
    map4pytajnik.setString("?");
    map4pytajnik.setCharacterSize(300);
    map4pytajnik.setFillColor(Color::White);
    map4pytajnik.setPosition(1300, 250);
    map4pytajnik.setOutlineColor(Color::Black);
    map4pytajnik.setOutlineThickness(8);

    map1completedtext.setFont(font);
    map1completedtext.setString("");
    map1completedtext.setCharacterSize(60);
    map1completedtext.setFillColor(Color::Red);
    map1completedtext.setPosition(30, 500);
    map1completedtext.setOutlineColor(Color::Black);
    map1completedtext.setOutlineThickness(8);
    map1completedtext.rotate(-40);

    map2completedtext.setFont(font);
    map2completedtext.setString("");
    map2completedtext.setCharacterSize(60);
    map2completedtext.setFillColor(Color::Red);
    map2completedtext.setPosition(430, 500);
    map2completedtext.setOutlineColor(Color::Black);
    map2completedtext.setOutlineThickness(8);
    map2completedtext.rotate(-40);

    map3completedtext.setFont(font);
    map3completedtext.setString("");
    map3completedtext.setCharacterSize(60);
    map3completedtext.setFillColor(Color::Red);
    map3completedtext.setPosition(830, 500);
    map3completedtext.setOutlineColor(Color::Black);
    map3completedtext.setOutlineThickness(8);
    map3completedtext.rotate(-40);
}

void Mapwindow::update(bool map1completed, bool map2completed, bool map3completed)
{
    if (map1completed)
    {
        map2pytajnik.setString("");
        map1completedtext.setString("COMPLETED!");
;    }
    if (map2completed)
    {
        map3pytajnik.setString("");
        map2completedtext.setString("COMPLETED!");
    }
    if (map3completed)
    {
        map4pytajnik.setString("");
        map3completedtext.setString("COMPLETED!");
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
    window.draw(map2pytajnik);
    window.draw(map3pytajnik);
    window.draw(map4pytajnik);
    window.draw(map1completedtext);
    window.draw(map2completedtext);
    window.draw(map3completedtext);
}
