#include "Settings.h"

Settings::Settings()
{
	loadAssets();
    sfx100Button.setFillColor(Color::Cyan); 
    selectedSFXButton = &sfx100Button;
    music100Button.setFillColor(Color::Cyan);
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

    Event event;
    while (window.pollEvent(event))
    {
        if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left)
        {
            this->updateSFXButtons(window);
            this->updateMusicButtons(window);
        }
    }        
}

void Settings::loadAssets()
{
    if(!background_TXT.loadFromFile("mainBackground.png")) {
        cout << "Failed to load background texture" << endl;
    }
    if (!logo_TXT.loadFromFile("gameLogo.png"))
    {
        cout << "Failed to load logo texture" << endl;
    }
    if (!button_TXT.loadFromFile("buttonbackground.png"))
    {
        cout << "Failed to load button texture" << endl;
    }

    this->setTexture(background_TXT);

    logoSPR.setTexture(logo_TXT);
    logoSPR.setPosition(50, 50);
    logoSPR.setScale(0.2, 0.2);

    music0Button.setSize(Vector2f(80, 50));
    music0Button.setFillColor(Color::White);
    music0Button.setPosition(490, 410);

    music20Button.setSize(Vector2f(115, 50));
    music20Button.setFillColor(Color::White);
    music20Button.setPosition(640, 410);

    music40Button.setSize(Vector2f(115, 50));
    music40Button.setFillColor(Color::White);
    music40Button.setPosition(790, 410);

    music60Button.setSize(Vector2f(115, 50));
    music60Button.setFillColor(Color::White);
    music60Button.setPosition(940, 410);

    music80Button.setSize(Vector2f(115, 50));
    music80Button.setFillColor(Color::White);
    music80Button.setPosition(1090, 410);

    music100Button.setSize(Vector2f(135, 50));
    music100Button.setFillColor(Color::Cyan);
    music100Button.setPosition(1240, 410);

    sfx0Button.setSize(Vector2f(80, 50));
    sfx0Button.setFillColor(Color::White);
    sfx0Button.setPosition(490, 610);

    sfx20Button.setSize(Vector2f(115, 50));
    sfx20Button.setFillColor(Color::White);
    sfx20Button.setPosition(640, 610);

    sfx40Button.setSize(Vector2f(115, 50));
    sfx40Button.setFillColor(Color::White);
    sfx40Button.setPosition(790, 610);

    sfx60Button.setSize(Vector2f(115, 50));
    sfx60Button.setFillColor(Color::White);
    sfx60Button.setPosition(940, 610);

    sfx80Button.setSize(Vector2f(135, 50));
    sfx80Button.setFillColor(Color::White);
    sfx80Button.setPosition(1090, 610);

    sfx100Button.setSize(Vector2f(135, 50));
    sfx100Button.setFillColor(Color::Cyan);
    sfx100Button.setPosition(1240, 610);

    closeButton.setOutlineColor(Color::Green);
    closeButton.setSize(Vector2f(200, 80));
    closeButton.setPosition(700, 800);
    closeButton.setTexture(&button_TXT);

    if (!font.loadFromFile("arial.ttf"))
    {
        cout << "Failed to load font" << endl;
    }

    settingsText.setFont(font);
    settingsText.setString("SETTINGS");
    settingsText.setCharacterSize(100);
    settingsText.setFillColor(Color::White);
    settingsText.setPosition(550, 50);
    settingsText.setOutlineColor(Color::Black);
    settingsText.setOutlineThickness(3);

    musicText.setFont(font);
    musicText.setString("MUSIC");
    musicText.setCharacterSize(60);
    musicText.setFillColor(Color::Black);
    musicText.setPosition(200, 400);
    musicText.setOutlineColor(Color::Green);
    musicText.setOutlineThickness(3);

    sfxText.setFont(font);
    sfxText.setString("SFX");
    sfxText.setCharacterSize(60);
    sfxText.setFillColor(Color::Black);
    sfxText.setPosition(200, 600);
    sfxText.setOutlineColor(Color::Green);
    sfxText.setOutlineThickness(3);

    music0Text.setFont(font);
    music0Text.setString("0%");
    music0Text.setCharacterSize(50);
    music0Text.setFillColor(Color::White);
    music0Text.setPosition(500, 400);
    music0Text.setOutlineColor(Color::Red);
    music0Text.setOutlineThickness(3);

    music20Text.setFont(font);
    music20Text.setString("20%");
    music20Text.setCharacterSize(50);
    music20Text.setFillColor(Color::White);
    music20Text.setPosition(650, 400);
    music20Text.setOutlineColor(Color::Red);
    music20Text.setOutlineThickness(3);

    music40Text.setFont(font);
    music40Text.setString("40%");
    music40Text.setCharacterSize(50);
    music40Text.setFillColor(Color::White);
    music40Text.setPosition(800, 400);
    music40Text.setOutlineColor(Color::Red);
    music40Text.setOutlineThickness(3);

    music60Text.setFont(font);
    music60Text.setString("60%");
    music60Text.setCharacterSize(50);
    music60Text.setFillColor(Color::White);
    music60Text.setPosition(950, 400);
    music60Text.setOutlineColor(Color::Red);
    music60Text.setOutlineThickness(3);

    music80Text.setFont(font);
    music80Text.setString("80%");
    music80Text.setCharacterSize(50);
    music80Text.setFillColor(Color::White);
    music80Text.setPosition(1100, 400);
    music80Text.setOutlineColor(Color::Red);
    music80Text.setOutlineThickness(3);

    music100Text.setFont(font);
    music100Text.setString("100%");
    music100Text.setCharacterSize(50);
    music100Text.setFillColor(Color::White);
    music100Text.setPosition(1250, 400);
    music100Text.setOutlineColor(Color::Red);
    music100Text.setOutlineThickness(3);

    sfx0Text.setFont(font);
    sfx0Text.setString("0%");
    sfx0Text.setCharacterSize(50);
    sfx0Text.setFillColor(Color::White);
    sfx0Text.setPosition(500, 600);
    sfx0Text.setOutlineColor(Color::Red);
    sfx0Text.setOutlineThickness(3);

    sfx20Text.setFont(font);
    sfx20Text.setString("20%");
    sfx20Text.setCharacterSize(50);
    sfx20Text.setFillColor(Color::White);
    sfx20Text.setPosition(650, 600);
    sfx20Text.setOutlineColor(Color::Red);
    sfx20Text.setOutlineThickness(3);

    sfx40Text.setFont(font);
    sfx40Text.setString("40%");
    sfx40Text.setCharacterSize(50);
    sfx40Text.setFillColor(Color::White);
    sfx40Text.setPosition(800, 600);
    sfx40Text.setOutlineColor(Color::Red);
    sfx40Text.setOutlineThickness(3);

    sfx60Text.setFont(font);
    sfx60Text.setString("60%");
    sfx60Text.setCharacterSize(50);
    sfx60Text.setFillColor(Color::White);
    sfx60Text.setPosition(950, 600);
    sfx60Text.setOutlineColor(Color::Red);
    sfx60Text.setOutlineThickness(3);

    sfx80Text.setFont(font);
    sfx80Text.setString("80%");
    sfx80Text.setCharacterSize(50);
    sfx80Text.setFillColor(Color::White);
    sfx80Text.setPosition(1100, 600);
    sfx80Text.setOutlineColor(Color::Red);
    sfx80Text.setOutlineThickness(3);

    sfx100Text.setFont(font);
    sfx100Text.setString("100%");
    sfx100Text.setCharacterSize(50);
    sfx100Text.setFillColor(Color::White);
    sfx100Text.setPosition(1250, 600);
    sfx100Text.setOutlineColor(Color::Red);
    sfx100Text.setOutlineThickness(3);

    closeText.setFont(font);
    closeText.setString("BACK");
    closeText.setCharacterSize(50);
    closeText.setFillColor(Color::Black);
    closeText.setPosition(730, 810);
    closeText.setOutlineColor(Color::Green);
    closeText.setOutlineThickness(3);


}

bool Settings::buttonClicked(RenderWindow& window, RectangleShape& button) {
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

void Settings::musciRregulation(Sound& music, RenderWindow& settingswindow)
{
    
    if (buttonClicked(settingswindow, music0Button))
    {
        music.setVolume(0.0f);
    }
    if (buttonClicked(settingswindow, music20Button))
    {
        music.setVolume(20.0f);
    }
    if (buttonClicked(settingswindow, music40Button))
    {
        music.setVolume(40.0f);
    }
    if (buttonClicked(settingswindow, music60Button))
    {
        music.setVolume(60.0f);
    }
    if (buttonClicked(settingswindow, music80Button))
    {
        music.setVolume(80.0f);
    }
    if (buttonClicked(settingswindow, music100Button))
    {
        music.setVolume(100.0f);
    }
}

void Settings::updateSFXButtons(RenderWindow& window)
{
    if (buttonClicked(window, sfx0Button)) {
        selectedSFXButton->setFillColor(Color::White);
        selectedSFXButton = &sfx0Button;
        sfx0Button.setFillColor(Color::Cyan);
    }
    if (buttonClicked(window, sfx20Button)) {
        selectedSFXButton->setFillColor(Color::White);
        selectedSFXButton = &sfx20Button;
        sfx20Button.setFillColor(Color::Cyan);
    }
    if (buttonClicked(window, sfx40Button)) {
        selectedSFXButton->setFillColor(Color::White);
        selectedSFXButton = &sfx40Button;
        sfx40Button.setFillColor(Color::Cyan);
    }
    if (buttonClicked(window, sfx60Button)) {
        selectedSFXButton->setFillColor(Color::White);
        selectedSFXButton = &sfx60Button;
        sfx60Button.setFillColor(Color::Cyan);
    }
    if (buttonClicked(window, sfx80Button)) {
        selectedSFXButton->setFillColor(Color::White);
        selectedSFXButton = &sfx80Button;
        sfx80Button.setFillColor(Color::Cyan);
    }
    if (buttonClicked(window, sfx100Button)) {
        selectedSFXButton->setFillColor(Color::White);
        selectedSFXButton = &sfx100Button;
        sfx100Button.setFillColor(Color::Cyan);
    }
}

void Settings::updateMusicButtons(RenderWindow& window)
{
    if (buttonClicked(window, music0Button)) {
        selectedMusicButton->setFillColor(Color::White);
        selectedMusicButton = &music0Button;
        music0Button.setFillColor(Color::Cyan);
    }
    if (buttonClicked(window, music20Button)) {
        selectedMusicButton->setFillColor(Color::White);
        selectedMusicButton = &music20Button;
        music20Button.setFillColor(Color::Cyan);
    }
    if (buttonClicked(window, music40Button)) {
        selectedMusicButton->setFillColor(Color::White);
        selectedMusicButton = &music40Button;
        music40Button.setFillColor(Color::Cyan);
    }
    if (buttonClicked(window, music60Button)) {
        selectedMusicButton->setFillColor(Color::White);
        selectedMusicButton = &music60Button;
        music60Button.setFillColor(Color::Cyan);
    }
    if (buttonClicked(window, music80Button)) {
        selectedMusicButton->setFillColor(Color::White);
        selectedMusicButton = &music80Button;
        music80Button.setFillColor(Color::Cyan);
    }
    if (buttonClicked(window, music100Button)) {
        selectedMusicButton->setFillColor(Color::White);
        selectedMusicButton = &music100Button;
        music100Button.setFillColor(Color::Cyan);
    }
}
