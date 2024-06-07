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
    window.draw(playText);
    window.draw(settingsText);
    window.draw(closeText);
    window.draw(whiteSPR);
    window.draw(butSPR);
    window.draw(creditsText);
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
    if (!background_TXT.loadFromFile("mainBackground.png")) {
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
    if (!button_TXT.loadFromFile("buttonbackground.png")) {
        cout << "Failed to load button background" << endl;
    }

    this->setTexture(background_TXT);

    whiteSPR.setTexture(white_TXT);
    butSPR.setTexture(but_TXT);
    logoSPR.setTexture(logo_TXT);
    playButton.setTexture(&button_TXT);
    settingsButton.setTexture(&button_TXT);
    closeButton.setTexture(&button_TXT);


    playButton.setOutlineColor(Color::Green);
    playButton.setSize(Vector2f(250, 80));
    playButton.setPosition(50, 280);

    settingsButton.setOutlineColor(Color::Green);
    settingsButton.setSize(Vector2f(250, 80));
    settingsButton.setPosition(50, 380);

    closeButton.setOutlineColor(Color::Green);
    closeButton.setSize(Vector2f(250, 80));
    closeButton.setPosition(50, 480);

    butSPR.setPosition(1000, 200);
    butSPR.setScale(0.5, 0.5);

    whiteSPR.setScale(0.5, 0.5);
    whiteSPR.setPosition(600, 200);

    logoSPR.setScale(0.2, 0.2);
    logoSPR.setPosition(50, 50);

    playText.setFont(font);
    playText.setString("Play");
    playText.setCharacterSize(45);
    playText.setFillColor(Color::Black);
    playText.setPosition(60, 290);
    playText.setOutlineColor(Color::Green);
    playText.setOutlineThickness(3);

    settingsText.setFont(font);
    settingsText.setString("Settings");
    settingsText.setCharacterSize(45);
    settingsText.setFillColor(Color::Black);
    settingsText.setPosition(60, 390);
    settingsText.setOutlineColor(Color::Green);
    settingsText.setOutlineThickness(3);

    closeText.setFont(font);
    closeText.setString("Exit");
    closeText.setCharacterSize(45);
    closeText.setFillColor(Color::Black);
    closeText.setPosition(60, 490);
    closeText.setOutlineColor(Color::Green);
    closeText.setOutlineThickness(3);

    creditsText.setFont(font);
    creditsText.setString("Credits");
    creditsText.setCharacterSize(80);
    creditsText.setFillColor(Color::Black);
    creditsText.setPosition(800, 100);
    creditsText.setOutlineColor(Color::Red);
    creditsText.setOutlineThickness(8);
    
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





