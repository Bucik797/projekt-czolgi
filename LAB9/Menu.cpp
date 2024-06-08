#include "Menu.h"

using namespace std;
using namespace sf;

//Mainmenu
Menu::Menu()
{
    loadAssets();
}

void Menu::drawGraphics(RenderWindow& window)
{
    window.draw(*this);
    window.draw(logoSPR);
    window.draw(playButton);
    window.draw(settingsButton);
    window.draw(closeButton);

    window.draw(whiteSPR);
    window.draw(butSPR);
    window.draw(whiteName);
    window.draw(butName);
    window.draw(whiteLastname);
    window.draw(butLastname);        
}

void Menu::update()
{
}

void Menu::loadAssets()
{
    if (!background_TXT.loadFromFile("maininterface.png")) {
        cout << "Failed to load background texture" << endl;
    }
    if (!white_TXT.loadFromFile("lajcior.png")) {
        cout << "Failed to load white texture" << endl;
    }
    if (!logo_TXT.loadFromFile("gameLogo.png")) {
        cout << "Failed to load logo texture" << endl;
    }
    if (!but_TXT.loadFromFile("bucik.png")) {
        cout << "Failed to load bucik texture" << endl;
    }
    if (!font.loadFromFile("arial.ttf")) {
        cout << "Failed to load font" << endl;
    }
    
    this->setTexture(background_TXT);
    whiteSPR.setTexture(white_TXT);
    butSPR.setTexture(but_TXT);
    logoSPR.setTexture(logo_TXT);


    playButton.setPosition(520, 650);
    playButton.setOutlineColor(Color::Transparent);
    playButton.setFillColor(Color::Transparent);
    playButton.setOutlineThickness(5);  
    playButton.setRadius(120);

    settingsButton.setOutlineColor(Color::Transparent);
    settingsButton.setFillColor(Color::Transparent);
    settingsButton.setPosition(800, 650);
    settingsButton.setRadius(120);
    settingsButton.setOutlineThickness(5);

    closeButton.setOutlineColor(Color::Transparent);
    closeButton.setFillColor(Color::Transparent);
    closeButton.setPosition(1070, 650);
    closeButton.setRadius(120);
    closeButton.setOutlineThickness(5);

    butSPR.setPosition(100, 100);
    butSPR.setScale(0.5, 0.5);

    whiteSPR.setScale(0.5, 0.5);
    whiteSPR.setPosition(1000, 100);

    logoSPR.setScale(0.2, 0.2);
    logoSPR.setPosition(50, 50);
    
    whiteName.setFont(font);
    whiteName.setString("Gregorio");
    whiteName.setCharacterSize(50);
    whiteName.setFillColor(Color::White);
    whiteName.setPosition(600, 670);
    whiteName.setOutlineColor(Color::Black);
    whiteName.setOutlineThickness(8);

    butName.setFont(font);
    butName.setString("Domenico");
    butName.setCharacterSize(50);
    butName.setFillColor(Color::White);
    butName.setPosition(1000, 670);
    butName.setOutlineColor(Color::Black);
    butName.setOutlineThickness(8);

    whiteLastname.setFont(font);
    whiteLastname.setString("Bianco");
    whiteLastname.setCharacterSize(50);
    whiteLastname.setFillColor(Color::White);
    whiteLastname.setPosition(600, 730);
    whiteLastname.setOutlineColor(Color::Black);
    whiteLastname.setOutlineThickness(8);

    butLastname.setFont(font);
    butLastname.setString("Stivale");
    butLastname.setCharacterSize(50);
    butLastname.setFillColor(Color::White);
    butLastname.setPosition(1000, 730);
    butLastname.setOutlineColor(Color::Black);
    butLastname.setOutlineThickness(8);
}





