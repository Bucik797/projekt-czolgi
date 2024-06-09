#include "Settings.h"

Settings::Settings()
{
	loadAssets();
    sfx100Button.setOutlineColor(Color::Green);
    selectedSFXButton = &sfx100Button;
    music100Button.setOutlineColor(Color::Green);
    selectedMusicButton = &music100Button;
}

void Settings::update()
{
}

void Settings::drawGraphics(RenderWindow& window)
{
    window.draw(*this);
    window.draw(logoSPR);
    window.draw(musicText);
    window.draw(sfxText);
    window.draw(music0Button);
    window.draw(music20Button);
    window.draw(music40Button);
    window.draw(music60Button);
    window.draw(music80Button);
    window.draw(music100Button);
    window.draw(sfx0Button);
    window.draw(sfx20Button);
    window.draw(sfx40Button);
    window.draw(sfx60Button);
    window.draw(sfx80Button);
    window.draw(sfx100Button);
    window.draw(music0Text);
    window.draw(music20Text);
    window.draw(music40Text);
    window.draw(music60Text);
    window.draw(music80Text);
    window.draw(music100Text);
    window.draw(sfx0Text);
    window.draw(sfx20Text);
    window.draw(sfx40Text);
    window.draw(sfx60Text);
    window.draw(sfx80Text);
    window.draw(sfx100Text);
    window.draw(closeButton);
    window.draw(closeText);
    window.draw(settingsText);
}

void Settings::loadAssets()
{
    if(!background_TXT.loadFromFile("mapinterface.png")) {
        cout << "Failed to load background texture" << endl;
    }
    if (!logo_TXT.loadFromFile("gameLogo.png"))
    {
        cout << "Failed to load logo texture" << endl;
    }
    if (!button_TXT.loadFromFile("settingsguzior.png"))
    {
        cout << "Failed to load button texture" << endl;
    }

    this->setTexture(background_TXT);
    this->setScale(0.9, 0.9);

    logoSPR.setTexture(logo_TXT);
    logoSPR.setPosition(50, 50);
    logoSPR.setScale(0.2, 0.2);

    music0Button.setSize(Vector2f(100, 100));
    music0Button.setTexture(&button_TXT);
    music0Button.setPosition(400, 300);
    music0Button.setOutlineColor(Color::Transparent);
    music0Button.setOutlineThickness(5);

    music20Button.setSize(Vector2f(100, 100));
    music20Button.setTexture(&button_TXT);
    music20Button.setPosition(550, 300);
    music20Button.setOutlineColor(Color::Transparent);
    music20Button.setOutlineThickness(5);    

    music40Button.setSize(Vector2f(100, 100));
    music40Button.setTexture(&button_TXT);
    music40Button.setPosition(700, 300);
    music40Button.setOutlineColor(Color::Transparent);
    music40Button.setOutlineThickness(5);

    music60Button.setSize(Vector2f(100, 100));
    music60Button.setTexture(&button_TXT);
    music60Button.setPosition(850, 300);
    music60Button.setOutlineColor(Color::Transparent);
    music60Button.setOutlineThickness(5);

    music80Button.setSize(Vector2f(100, 100));
    music80Button.setTexture(&button_TXT);
    music80Button.setPosition(1000, 300);
    music80Button.setOutlineColor(Color::Transparent);
    music80Button.setOutlineThickness(5);

    music100Button.setSize(Vector2f(100, 100));
    music100Button.setTexture(&button_TXT);
    music100Button.setPosition(1150, 300);
    music100Button.setOutlineColor(Color::Green);
    music100Button.setOutlineThickness(5);

    sfx0Button.setSize(Vector2f(100, 100));
    sfx0Button.setTexture(&button_TXT);
    sfx0Button.setPosition(400, 500);
    sfx0Button.setOutlineColor(Color::Transparent);
    sfx0Button.setOutlineThickness(5);

    sfx20Button.setSize(Vector2f(100, 100));
    sfx20Button.setTexture(&button_TXT);
    sfx20Button.setPosition(550, 500);
    sfx20Button.setOutlineColor(Color::Transparent);
    sfx20Button.setOutlineThickness(5);

    sfx40Button.setSize(Vector2f(100, 100));
    sfx40Button.setTexture(&button_TXT);
    sfx40Button.setPosition(700, 500);
    sfx40Button.setOutlineColor(Color::Transparent);
    sfx40Button.setOutlineThickness(5);

    sfx60Button.setSize(Vector2f(100, 100));
    sfx60Button.setTexture(&button_TXT);
    sfx60Button.setPosition(850, 500);
    sfx60Button.setOutlineColor(Color::Transparent);
    sfx60Button.setOutlineThickness(5);

    sfx80Button.setSize(Vector2f(100, 100));
    sfx80Button.setTexture(&button_TXT);
    sfx80Button.setPosition(1000, 500);
    sfx80Button.setOutlineColor(Color::Transparent);
    sfx80Button.setOutlineThickness(5);

    sfx100Button.setSize(Vector2f(100, 100));
    sfx100Button.setTexture(&button_TXT);
    sfx100Button.setPosition(1150, 500);
    sfx100Button.setOutlineColor(Color::Green);
    sfx100Button.setOutlineThickness(5);

    closeButton.setOutlineColor(Color::Transparent);
    closeButton.setFillColor(Color::Transparent);
    closeButton.setOutlineThickness(5);
    closeButton.setSize(Vector2f(520, 195));
    closeButton.setPosition(550, 665);


    if (!font.loadFromFile("arial.ttf"))
    {
        cout << "Failed to load font" << endl;
    }

    settingsText.setFont(font);
    settingsText.setString("SETTINGS BRO");
    settingsText.setCharacterSize(100);
    settingsText.setFillColor(Color::White);
    settingsText.setPosition(450, 50);
    settingsText.setOutlineColor(Color::Black);
    settingsText.setOutlineThickness(3);

    musicText.setFont(font);
    musicText.setString("MUSIC");
    musicText.setCharacterSize(60);
    musicText.setFillColor(Color::Black);
    musicText.setPosition(750, 225);
    musicText.setOutlineColor(Color::Green);
    musicText.setOutlineThickness(3);

    sfxText.setFont(font);
    sfxText.setString("SFX");
    sfxText.setCharacterSize(60);
    sfxText.setFillColor(Color::Black);
    sfxText.setPosition(770, 425);
    sfxText.setOutlineColor(Color::Green);
    sfxText.setOutlineThickness(3);

    music0Text.setFont(font);
    music0Text.setString("0%");
    music0Text.setCharacterSize(35);
    music0Text.setFillColor(Color::Transparent);
    music0Text.setPosition(430, 330);
    music0Text.setOutlineColor(Color::Green);
    music0Text.setOutlineThickness(1);

    music20Text.setFont(font);
    music20Text.setString("20%");
    music20Text.setCharacterSize(35);
    music20Text.setFillColor(Color::Transparent);
    music20Text.setPosition(565, 330);
    music20Text.setOutlineColor(Color::Green);
    music20Text.setOutlineThickness(1);

    music40Text.setFont(font);
    music40Text.setString("40%");
    music40Text.setCharacterSize(35);
    music40Text.setFillColor(Color::Transparent);
    music40Text.setPosition(715, 330);
    music40Text.setOutlineColor(Color::Green);
    music40Text.setOutlineThickness(1);

    music60Text.setFont(font);
    music60Text.setString("60%");
    music60Text.setCharacterSize(35);
    music60Text.setFillColor(Color::Transparent);
    music60Text.setPosition(865, 330);
    music60Text.setOutlineColor(Color::Green);
    music60Text.setOutlineThickness(1);

    music80Text.setFont(font);
    music80Text.setString("80%");
    music80Text.setCharacterSize(35);
    music80Text.setFillColor(Color::Transparent);
    music80Text.setPosition(1015, 330);
    music80Text.setOutlineColor(Color::Green);
    music80Text.setOutlineThickness(1);

    music100Text.setFont(font);
    music100Text.setString("100%");
    music100Text.setCharacterSize(35);
    music100Text.setFillColor(Color::Transparent);
    music100Text.setPosition(1160, 330);
    music100Text.setOutlineColor(Color::Green);
    music100Text.setOutlineThickness(1);

    sfx0Text.setFont(font);
    sfx0Text.setString("0%");
    sfx0Text.setCharacterSize(35);
    sfx0Text.setFillColor(Color::Transparent);
    sfx0Text.setPosition(430, 530);
    sfx0Text.setOutlineColor(Color::Green);
    sfx0Text.setOutlineThickness(1);

    sfx20Text.setFont(font);
    sfx20Text.setString("20%");
    sfx20Text.setCharacterSize(35);
    sfx20Text.setFillColor(Color::Transparent);
    sfx20Text.setPosition(565, 530);
    sfx20Text.setOutlineColor(Color::Green);
    sfx20Text.setOutlineThickness(1);

    sfx40Text.setFont(font);
    sfx40Text.setString("40%");
    sfx40Text.setCharacterSize(35);
    sfx40Text.setFillColor(Color::Transparent);
    sfx40Text.setPosition(715, 530);
    sfx40Text.setOutlineColor(Color::Green);
    sfx40Text.setOutlineThickness(1);

    sfx60Text.setFont(font);
    sfx60Text.setString("60%");
    sfx60Text.setCharacterSize(35);
    sfx60Text.setFillColor(Color::Transparent);
    sfx60Text.setPosition(865, 530);
    sfx60Text.setOutlineColor(Color::Green);
    sfx60Text.setOutlineThickness(1);

    sfx80Text.setFont(font);
    sfx80Text.setString("80%");
    sfx80Text.setCharacterSize(35);
    sfx80Text.setFillColor(Color::Transparent);
    sfx80Text.setPosition(1015, 530);
    sfx80Text.setOutlineColor(Color::Green);
    sfx80Text.setOutlineThickness(1);

    sfx100Text.setFont(font);
    sfx100Text.setString("100%");
    sfx100Text.setCharacterSize(35);
    sfx100Text.setFillColor(Color::Transparent);
    sfx100Text.setPosition(1160, 530);
    sfx100Text.setOutlineColor(Color::Green);
    sfx100Text.setOutlineThickness(1);


}

bool Settings::buttonClicked(Soundeffects sfx, RenderWindow& window, RectangleShape& button) {
    float mouseX = Mouse::getPosition(window).x;
    float mouseY = Mouse::getPosition(window).y;

    float btnPosX = button.getPosition().x;
    float btnPosY = button.getPosition().y;

    float btnxPosWidth = btnPosX + button.getLocalBounds().width;
    float btnyPosHeight = btnPosY + button.getLocalBounds().height;

    if (mouseX < btnxPosWidth && mouseX > btnPosX && mouseY < btnyPosHeight && mouseY > btnPosY) {
        sfx.buttonclicked.play();
        return true;
    }
    return false;
}

void Settings::musicRregulation(Music& music, Music& happymusic, RenderWindow& window, Soundeffects& sfx)
{    
    if (selectedMusicButton)
    {
        selectedMusicButton->setOutlineColor(Color::Transparent);
    }

    if (buttonClicked(sfx, window, music0Button))
    {
        music.setVolume(0);
        selectedMusicButton = &music0Button;
    }
    else if (buttonClicked(sfx, window, music20Button))
    {
        music.setVolume(20);
        selectedMusicButton = &music20Button;
    }
    else if (buttonClicked(sfx, window, music40Button))
    {
        music.setVolume(40);
        selectedMusicButton = &music40Button;
    }
    else if (buttonClicked(sfx, window, music60Button))
    {
        music.setVolume(60);
        selectedMusicButton = &music60Button;
    }
    else if (buttonClicked(sfx, window, music80Button))
    {
        music.setVolume(80);
        selectedMusicButton = &music80Button;
    }
    else if (buttonClicked(sfx, window, music100Button))
    {
        music.setVolume(100);
        selectedMusicButton = &music100Button;
    }

    if (selectedMusicButton)
    {
        selectedMusicButton->setOutlineColor(Color::Green);
    }
}

void Settings::sfxRegulation(Soundeffects& soundeffects, sf::RenderWindow& window) 
{
    if (selectedSFXButton)
    {
        selectedSFXButton->setOutlineColor(Color::Transparent);
    }

    if (buttonClicked(soundeffects, window, sfx0Button))
    {
        soundeffects.adjustSFXVolume(0);
        selectedSFXButton = &sfx0Button;
    }
    else if (buttonClicked(soundeffects, window, sfx20Button))
    {
        soundeffects.adjustSFXVolume(20);
        selectedSFXButton = &sfx20Button;
    }
    else if (buttonClicked(soundeffects, window, sfx40Button))
    {
        soundeffects.adjustSFXVolume(40);
        selectedSFXButton = &sfx40Button;
    }
    else if (buttonClicked(soundeffects, window, sfx60Button))
    {
        soundeffects.adjustSFXVolume(60);
        selectedSFXButton = &sfx60Button;
    }
    else if (buttonClicked(soundeffects, window, sfx80Button))
    {
        soundeffects.adjustSFXVolume(80);
        selectedSFXButton = &sfx80Button;
    }
    else if (buttonClicked(soundeffects,window, sfx100Button))
    {
        soundeffects.adjustSFXVolume(100);
        selectedSFXButton = &sfx100Button;
    }

    if (selectedSFXButton)
    {
        selectedSFXButton->setOutlineColor(Color::Green);
    }
}


