#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

using namespace sf;
using namespace std;

bool buttonClicked(RenderWindow& window, RectangleShape& button) {
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

bool selectedSprite(RenderWindow& window, Sprite& sprite) {
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


void setBasicGraphics(RectangleShape& closeButton, RectangleShape& settingsButton, RectangleShape& playButton, Sprite& background_sprite, Sprite& bucik_sprite, Sprite& lajcior_sprite, Texture& background_texture, Texture& lajt_texture, Texture& bucior_texture)
{
    if (!background_texture.loadFromFile("background.png")
        || !lajt_texture.loadFromFile("lajcior.png")
        || !bucior_texture.loadFromFile("bucik.png"))
    {
        cout << "Failed to load textures" << endl;
    }

    background_sprite.setTexture(background_texture);
    lajcior_sprite.setTexture(lajt_texture);
    bucik_sprite.setTexture(bucior_texture);
    

    playButton.setSize(Vector2f(300, 80));
    playButton.setFillColor(Color::White);
    playButton.setPosition(230, 800);

    settingsButton.setSize(Vector2f(300, 80));
    settingsButton.setFillColor(Color::White);
    settingsButton.setPosition(730, 800);

    closeButton.setSize(Vector2f(200, 80));
    closeButton.setFillColor(Color::White);
    closeButton.setPosition(1300, 800);

    bucik_sprite.setPosition(850, 200);
    bucik_sprite.setScale(0.4, 0.4);

    lajcior_sprite.setScale(0.4, 0.4);
    lajcior_sprite.setPosition(150, 200);

    
}

void setBasicText(Text& playText, Text& settingsText, Text& closeText, Text& titleText, Font& font)
{
    if (!font.loadFromFile("arial.ttf"))
    {
        cout << "Failed to load font" << endl;
    }

    playText.setFont(font);
    playText.setString("Play");
    playText.setCharacterSize(50);
    playText.setFillColor(Color::White);
    playText.setPosition(300, 805);
    playText.setOutlineColor(Color::Black);
    playText.setOutlineThickness(3);

    settingsText.setFont(font);
    settingsText.setString("Settings");
    settingsText.setCharacterSize(50);
    settingsText.setFillColor(Color::White);
    settingsText.setPosition(770, 805);
    settingsText.setOutlineColor(Color::Black);
    settingsText.setOutlineThickness(3);

    closeText.setFont(font);
    closeText.setString("Exit");
    closeText.setCharacterSize(50);
    closeText.setFillColor(Color::White);
    closeText.setPosition(1320, 805);
    closeText.setOutlineColor(Color::Black);
    closeText.setOutlineThickness(3);

    titleText.setFont(font);
    titleText.setString("DS4 TANKS");
    titleText.setCharacterSize(80);
    titleText.setFillColor(Color::White);
    titleText.setPosition(700, 200);
    titleText.setOutlineColor(Color::Black);
    titleText.setOutlineThickness(8);


}

void setMapsGraphics(Sprite& map1_sprite, Texture& map1_texture, Sprite& map2_sprite, Texture& map2_texture, Sprite& map3_sprite, Texture& map3_texture, Sprite& map4_sprite, Texture& map4_texture)
{
    if (!map1_texture.loadFromFile("map11.png")||
        !map2_texture.loadFromFile("map1.png") ||
        !map3_texture.loadFromFile("map1.png") ||
        !map4_texture.loadFromFile("map1.png"))
    {
        cout << "Failed to load textures" << endl;
    }
    
    map1_sprite.setTexture(map1_texture);
    map1_sprite.setScale(0.3, 0.3);
    map1_sprite.setPosition(100, 400);

    map2_sprite.setTexture(map2_texture);
    map2_sprite.setScale(0.3, 0.3);
    map2_sprite.setPosition(500, 400);

    map3_sprite.setTexture(map3_texture);
    map3_sprite.setScale(0.3, 0.3);
    map3_sprite.setPosition(900, 400);

    map4_sprite.setTexture(map4_texture);
    map4_sprite.setScale(0.3, 0.3);
    map4_sprite.setPosition(1300, 400);

    
}

void setMapText(Text& mapsText, Text& backText, Text& map1Text, Text& map2Text, Text& map3Text, Text& map4Text, Font& mapFont, Font& font)
{
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

void setSettingsGraphics(RectangleShape& fullscreenONButton, RectangleShape& fullscreenOFFButton, RectangleShape& music0Button, RectangleShape& music25Button, RectangleShape& music50Button, RectangleShape& music75Button, RectangleShape& music100Button, RectangleShape& sfx0Button, RectangleShape& sfx25Button, RectangleShape& sfx50Button, RectangleShape& sfx75Button, RectangleShape& sfx100Button)
{
    fullscreenONButton.setSize(Vector2f(80, 50));
    fullscreenONButton.setFillColor(Color::White);
    fullscreenONButton.setPosition(760, 210);

    fullscreenOFFButton.setSize(Vector2f(100, 50));
    fullscreenOFFButton.setFillColor(Color::White);
    fullscreenOFFButton.setPosition(860, 210);

    music0Button.setSize(Vector2f(80, 50));
    music0Button.setFillColor(Color::White);
    music0Button.setPosition(490, 410);

    music25Button.setSize(Vector2f(115, 50));
    music25Button.setFillColor(Color::White);
    music25Button.setPosition(640, 410);

    music50Button.setSize(Vector2f(115, 50));
    music50Button.setFillColor(Color::White);
    music50Button.setPosition(790, 410);

    music75Button.setSize(Vector2f(115, 50));
    music75Button.setFillColor(Color::White);
    music75Button.setPosition(940, 410);

    music100Button.setSize(Vector2f(135, 50));
    music100Button.setFillColor(Color::White);
    music100Button.setPosition(1090, 410);



    sfx0Button.setSize(Vector2f(80, 50));
    sfx0Button.setFillColor(Color::Cyan);
    sfx0Button.setPosition(490, 610);

    sfx25Button.setSize(Vector2f(115, 50));
    sfx25Button.setFillColor(Color::Cyan);
    sfx25Button.setPosition(640, 610);

    sfx50Button.setSize(Vector2f(115, 50));
    sfx50Button.setFillColor(Color::Cyan);
    sfx50Button.setPosition(790, 610);

    sfx75Button.setSize(Vector2f(115, 50));
    sfx75Button.setFillColor(Color::Cyan);
    sfx75Button.setPosition(940, 610);

    sfx100Button.setSize(Vector2f(135, 50));
    sfx100Button.setFillColor(Color::Cyan);
    sfx100Button.setPosition(1090, 610);



}

void setSettingsText(Text& fullscreenText, Text& musicText, Text& sfxText, Font& font, Text& fullscreenONText, Text& fullscreenOFFText, Text& music0Text, Text& music25Text, Text& music50Text, Text& music75Text, Text& music100Text, Text& sfx0Text, Text& sfx25Text, Text& sfx50Text, Text& sfx75Text, Text& sfx100Text)
{
    if (!font.loadFromFile("arial.ttf"))
    {
        cout << "Failed to load font" << endl;
    }

    fullscreenText.setFont(font);
    fullscreenText.setString("FULLSCREEN");
    fullscreenText.setCharacterSize(50);
    fullscreenText.setFillColor(Color::White);
    fullscreenText.setPosition(200, 200);
    fullscreenText.setOutlineColor(Color::Black);
    fullscreenText.setOutlineThickness(3);

    musicText.setFont(font);
    musicText.setString("MUSIC");
    musicText.setCharacterSize(50);
    musicText.setFillColor(Color::White);
    musicText.setPosition(200, 400);
    musicText.setOutlineColor(Color::Black);
    musicText.setOutlineThickness(3);

    sfxText.setFont(font);
    sfxText.setString("SFX");
    sfxText.setCharacterSize(50);
    sfxText.setFillColor(Color::White);
    sfxText.setPosition(200, 600);
    sfxText.setOutlineColor(Color::Black);
    sfxText.setOutlineThickness(3);

    fullscreenONText.setFont(font);
    fullscreenONText.setString("ON");
    fullscreenONText.setCharacterSize(50);
    fullscreenONText.setFillColor(Color::White);
    fullscreenONText.setPosition(770, 200);
    fullscreenONText.setOutlineColor(Color::Black);
    fullscreenONText.setOutlineThickness(3);

    fullscreenOFFText.setFont(font);
    fullscreenOFFText.setString("OFF");
    fullscreenOFFText.setCharacterSize(50);
    fullscreenOFFText.setFillColor(Color::White);
    fullscreenOFFText.setPosition(870, 200);
    fullscreenOFFText.setOutlineColor(Color::Black);
    fullscreenOFFText.setOutlineThickness(3);

    music0Text.setFont(font);
    music0Text.setString("0%");
    music0Text.setCharacterSize(50);
    music0Text.setFillColor(Color::White);
    music0Text.setPosition(500, 400);
    music0Text.setOutlineColor(Color::Black);
    music0Text.setOutlineThickness(3);

    music25Text.setFont(font);
    music25Text.setString("25%");
    music25Text.setCharacterSize(50);
    music25Text.setFillColor(Color::White);
    music25Text.setPosition(650, 400);
    music25Text.setOutlineColor(Color::Black);
    music25Text.setOutlineThickness(3);

    music50Text.setFont(font);
    music50Text.setString("50%");
    music50Text.setCharacterSize(50);
    music50Text.setFillColor(Color::White);
    music50Text.setPosition(800, 400);
    music50Text.setOutlineColor(Color::Black);
    music50Text.setOutlineThickness(3);

    music75Text.setFont(font);
    music75Text.setString("75%");
    music75Text.setCharacterSize(50);
    music75Text.setFillColor(Color::White);
    music75Text.setPosition(950, 400);
    music75Text.setOutlineColor(Color::Black);
    music75Text.setOutlineThickness(3);

    music100Text.setFont(font);
    music100Text.setString("100%");
    music100Text.setCharacterSize(50);
    music100Text.setFillColor(Color::White);
    music100Text.setPosition(1100, 400);
    music100Text.setOutlineColor(Color::Black);
    music100Text.setOutlineThickness(3);

    sfx0Text.setFont(font);
    sfx0Text.setString("0%");
    sfx0Text.setCharacterSize(50);
    sfx0Text.setFillColor(Color::White);
    sfx0Text.setPosition(500, 600);
    sfx0Text.setOutlineColor(Color::Black);
    sfx0Text.setOutlineThickness(3);

    sfx25Text.setFont(font);
    sfx25Text.setString("25%");
    sfx25Text.setCharacterSize(50);
    sfx25Text.setFillColor(Color::White);
    sfx25Text.setPosition(650, 600);
    sfx25Text.setOutlineColor(Color::Black);
    sfx25Text.setOutlineThickness(3);

    sfx50Text.setFont(font);
    sfx50Text.setString("50%");
    sfx50Text.setCharacterSize(50);
    sfx50Text.setFillColor(Color::White);
    sfx50Text.setPosition(800, 600);
    sfx50Text.setOutlineColor(Color::Black);
    sfx50Text.setOutlineThickness(3);

    sfx75Text.setFont(font);
    sfx75Text.setString("75%");
    sfx75Text.setCharacterSize(50);
    sfx75Text.setFillColor(Color::White);
    sfx75Text.setPosition(950, 600);
    sfx75Text.setOutlineColor(Color::Black);
    sfx75Text.setOutlineThickness(3);

    sfx100Text.setFont(font);
    sfx100Text.setString("100%");
    sfx100Text.setCharacterSize(50);
    sfx100Text.setFillColor(Color::White);
    sfx100Text.setPosition(1100, 600);
    sfx100Text.setOutlineColor(Color::Black);
    sfx100Text.setOutlineThickness(3);



}

void setPlayersText(Text& player1Text, Text& player2Text, Font& font, Text& battleText)
{
    if (!font.loadFromFile("arial.ttf"))
    {
        cout << "Failed to load font" << endl;
    }

    player1Text.setFont(font);
    player1Text.setString("Player 1");
    player1Text.setCharacterSize(50);
    player1Text.setFillColor(Color::White);
    player1Text.setPosition(400, 100);
    player1Text.setOutlineColor(Color::Black);
    player1Text.setOutlineThickness(3);

    player2Text.setFont(font);
    player2Text.setString("Player 2");
    player2Text.setCharacterSize(50);
    player2Text.setFillColor(Color::White);
    player2Text.setPosition(1100, 100);
    player2Text.setOutlineColor(Color::Black);
    player2Text.setOutlineThickness(3);

    battleText.setFont(font);
    battleText.setString("BATTLE");
    battleText.setCharacterSize(50);
    battleText.setFillColor(Color::White);
    battleText.setPosition(710, 790);
    battleText.setOutlineColor(Color::Black);
    battleText.setOutlineThickness(3);


}

void setPlayersGraphics(Sprite& P1L_sprite, Sprite& P1R_sprite, Sprite& P2L_sprite, Sprite& P2R_sprite, Sprite& player1_sprite, Sprite& player2_sprite, Texture& P1L_texture, Texture& P1R_texture, Texture& P2L_texture, Texture& P2R_texture, Texture& player1_texture, Texture& player2_texture, RectangleShape& battleButton)
{
    if (!P1L_texture.loadFromFile("left.png") ||
        !P1R_texture.loadFromFile("right.png") ||
        !P2L_texture.loadFromFile("left.png") ||
        !P2R_texture.loadFromFile("right.png") ||
        !player1_texture.loadFromFile("tank1.png") ||
        !player2_texture.loadFromFile("tank1.png"))
    {
        cout << "Failed to load textures" << endl;
    }

    P1L_sprite.setTexture(P1L_texture);
    P1L_sprite.setScale(0.1, 0.1);
    P1L_sprite.setPosition(400, 700);

    P1R_sprite.setTexture(P1R_texture);
    P1R_sprite.setScale(0.1, 0.1);
    P1R_sprite.setPosition(500, 700);

    P2L_sprite.setTexture(P2L_texture);
    P2L_sprite.setScale(0.1, 0.1);
    P2L_sprite.setPosition(1100, 700);

    P2R_sprite.setTexture(P2R_texture);
    P2R_sprite.setScale(0.1, 0.1);
    P2R_sprite.setPosition(1200, 700);

    player1_sprite.setTexture(player1_texture);
    player1_sprite.setScale(0.7, 0.7);
    player1_sprite.setPosition(300, 300);

    player2_sprite.setTexture(player2_texture);
    player2_sprite.setScale(0.7, 0.7);
    player2_sprite.setPosition(900, 300);

    battleButton.setSize(Vector2f(200, 60));
    battleButton.setFillColor(Color::White);
    battleButton.setPosition(700, 800);
}

void playMusic(Sound& music, SoundBuffer& music_buffer)
{
    if (!music_buffer.loadFromFile("kukon.wav"))
    {
        cout << "Failed to load font" << endl;
    }

    music.setBuffer(music_buffer);
}

void setBattleGraphics(Sprite& map1Background_sprite,Sprite& map2Background_sprite, Sprite& map3Background_sprite, Sprite& map4Background_sprite, Texture& map1Background_texture, Texture& map2Background_texture, Texture& map3Background_texture, Texture& map4Background_texture)
{
    if (!map1Background_texture.loadFromFile("map11.png")
        || !map2Background_texture.loadFromFile("map1.png")
        || !map3Background_texture.loadFromFile("map1.png")
        || !map4Background_texture.loadFromFile("map1.png"))
    {
        cout << "Failed to load textures" << endl;
    }

    map1Background_sprite.setTexture(map1Background_texture);
    map1Background_sprite.setScale(2,2);
    map1Background_sprite.setPosition(0,0);


    map2Background_sprite.setTexture(map2Background_texture);

    map3Background_sprite.setTexture(map3Background_texture);

    map4Background_sprite.setTexture(map4Background_texture);

}


int main() {
    int window_width = 1920;
    int window_height = 1080;
    RenderWindow loadingScreen(VideoMode(1300,700), "Loading screen", Style::None);
    RenderWindow basicWindow;
    RenderWindow settingsWindow;
    RenderWindow mapsWindow;
    RenderWindow playerWindow;
    RenderWindow battleWindow;
    bool isFullscreen = false;
    bool loaded = false;
    Clock clock;
    


    RectangleShape closeButton, settingsButton, playButton, fullscreenONButton, fullscreenOFFButton, battleButton;
    RectangleShape  music0Button, music25Button, music50Button, music75Button, music100Button, sfx0Button, sfx25Button, sfx50Button, sfx75Button, sfx100Button;
    Sprite background_sprite, bucik_sprite, lajcior_sprite, map1_sprite, map2_sprite, map3_sprite, map4_sprite, P1L_sprite, P1R_sprite, P2L_sprite, P2R_sprite, player1_sprite, player2_sprite;
    Sprite map1Background_sprite, map2Background_sprite, map3Background_sprite, map4Background_sprite;
    Texture map1Background_texture, map2Background_texture, map3Background_texture, map4Background_texture;
    Text playText, settingsText, closeText, titleText, mapsText, backText, map1Text, map2Text, map3Text, map4Text, player1Text, player2Text, battleText;
    Text fullscreenText, musicText, sfxText, fullscreenONText, fullscreenOFFText, music0Text, music25Text, music50Text, music75Text, music100Text, sfx0Text, sfx25Text, sfx50Text, sfx75Text, sfx100Text;
    Texture background_texture, lajt_texture, bucior_texture, map1_texture, map2_texture, map3_texture, map4_texture, P1L_texture, P1R_texture, P2L_texture, P2R_texture, player1_texture, player2_texture;
    Font font, mapFont;

    Sound music;
    SoundBuffer music_buffer;
    //Music music;


    setBasicGraphics(closeButton, settingsButton, playButton, background_sprite, bucik_sprite, lajcior_sprite, background_texture, lajt_texture, bucior_texture);
    setMapsGraphics(map1_sprite, map1_texture, map2_sprite, map2_texture, map3_sprite, map3_texture, map4_sprite, map4_texture);
    setBasicText(playText, settingsText, closeText, titleText, font);
    setMapText(mapsText, backText, map1Text, map2Text, map3Text, map4Text, mapFont, font);
    setSettingsText(fullscreenText, musicText, sfxText, font, fullscreenONText, fullscreenOFFText, music0Text, music25Text, music50Text, music75Text, music100Text, sfx0Text, sfx25Text, sfx50Text, sfx75Text, sfx100Text);
    setSettingsGraphics(fullscreenONButton, fullscreenOFFButton, music0Button, music25Button, music50Button, music75Button, music100Button, sfx0Button, sfx25Button, sfx50Button, sfx75Button, sfx100Button);
    setPlayersText(player1Text, player2Text, font, battleText);
    setPlayersGraphics(P1L_sprite, P1R_sprite, P2L_sprite, P2R_sprite, player1_sprite, player2_sprite, P1L_texture, P1R_texture, P2L_texture, P2R_texture, player1_texture, player2_texture, battleButton);
    setBattleGraphics(map1Background_sprite, map2Background_sprite, map3Background_sprite, map4Background_sprite, map1Background_texture, map2Background_texture, map3Background_texture, map4Background_texture);
    
    playMusic(music, music_buffer);
    //music.play();

    while (loadingScreen.isOpen())
    {
        Time elapsed = clock.getElapsedTime();
        Event loadingEvent;
        //cout << elapsed.asSeconds() << endl;

        
        if (elapsed.asSeconds() > 6.0f)
        {

            basicWindow.create(VideoMode(window_width, window_height), "basicWindow", Style::Fullscreen);
            loadingScreen.setVisible(false);
            break;


        }
        //eqwewqewq

        while (loadingScreen.pollEvent(loadingEvent))
        {
            if (loadingEvent.type == Event::Closed) loadingScreen.close();
        }

        loadingScreen.clear();
        loadingScreen.draw(background_sprite); 
        loadingScreen.draw(lajcior_sprite);
        loadingScreen.draw(bucik_sprite);
        loadingScreen.display();

    }


    


    
    while (basicWindow.isOpen()) {
        Event event;

        while (basicWindow.pollEvent(event))
        {
            if (event.type == Event::Closed) basicWindow.close();

            if (event.type == Event::MouseButtonPressed) {
                if (event.mouseButton.button == Mouse::Left) {
                    if (buttonClicked(basicWindow, closeButton))
                    {
                        basicWindow.close();
                        loadingScreen.close();
                    }
                    if (buttonClicked(basicWindow, settingsButton))
                    {
                        settingsWindow.create(VideoMode(window_width, window_height), "settingsWindow", Style::Fullscreen);
                        //basicWindow.setVisible(false);
                        basicWindow.close();
                    }
                    if (buttonClicked(basicWindow, playButton))
                    {
                        mapsWindow.create(VideoMode(window_width, window_height), "mapsWindow",Style::Fullscreen);
                        //basicWindow.setVisible(false);
                        basicWindow.close();
                    }
                }
            }
        }


        while (settingsWindow.isOpen())
        {
            Event event2;
            while (settingsWindow.pollEvent(event2))
            {
                if (event2.type == Event::Closed) {

                    basicWindow.setVisible(true);
                    settingsWindow.close();
                }

                if (event2.type == Event::MouseButtonPressed) {
                    if (event2.mouseButton.button == Mouse::Left) {
                        if (buttonClicked(settingsWindow, closeButton))
                        {
                            //basicWindow.setVisible(true);
                            basicWindow.create(VideoMode(window_width, window_height), "basicWindow", Style::Fullscreen);
                            settingsWindow.close();
                        }
                        if (buttonClicked(settingsWindow, music0Button))
                        {
                            music.setVolume(0.0f);
                        }
                        if (buttonClicked(settingsWindow, music25Button))
                        {
                            music.setVolume(25.0f);
                        }
                        if (buttonClicked(settingsWindow, music50Button))
                        {
                            music.setVolume(50.0f);
                        }
                        if (buttonClicked(settingsWindow, music75Button))
                        {
                            music.setVolume(75.0f);
                        }
                        if (buttonClicked(settingsWindow, music100Button))
                        {
                            music.setVolume(100.0f);
                        }
                        /*
                        if (buttonClicked(settingsWindow, fullscreenONButton))
                        {
                            isFullscreen = true;
                            settingsWindow.create(VideoMode(1730, 979), "settingsWindow", Style::Fullscreen);
                        }
                        if (buttonClicked(settingsWindow, fullscreenOFFButton))
                        {
                            isFullscreen = false;
                            settingsWindow.create(VideoMode(1730, 979), "settingsWindow");
                        }
                        */

                    }
                }
            }

            settingsWindow.clear();
            settingsWindow.draw(background_sprite);
            settingsWindow.draw(closeButton);
            //settingsWindow.draw(fullscreenText);
            settingsWindow.draw(musicText);
            settingsWindow.draw(sfxText);
            settingsWindow.draw(backText);
            //settingsWindow.draw(fullscreenONButton);
            //settingsWindow.draw(fullscreenOFFButton);
            settingsWindow.draw(music0Button);
            settingsWindow.draw(music25Button);
            settingsWindow.draw(music50Button);
            settingsWindow.draw(music75Button);
            settingsWindow.draw(music100Button);
            settingsWindow.draw(sfx0Button);
            settingsWindow.draw(sfx25Button);
            settingsWindow.draw(sfx50Button);
            settingsWindow.draw(sfx75Button);
            settingsWindow.draw(sfx100Button);
            //settingsWindow.draw(fullscreenONText);
            //settingsWindow.draw(fullscreenOFFText);
            settingsWindow.draw(music0Text);
            settingsWindow.draw(music25Text);
            settingsWindow.draw(music50Text);
            settingsWindow.draw(music75Text);
            settingsWindow.draw(music100Text);
            settingsWindow.draw(sfx0Text);
            settingsWindow.draw(sfx25Text);
            settingsWindow.draw(sfx50Text);
            settingsWindow.draw(sfx75Text);
            settingsWindow.draw(sfx100Text);
            settingsWindow.display();
        }



        

        while (mapsWindow.isOpen())
        {
            Event event3;
            while (mapsWindow.pollEvent(event3))
            {
                if (event3.type == Event::Closed) {
                    mapsWindow.close();
                    basicWindow.setVisible(true);
                }

                if (event3.type == Event::MouseButtonPressed) {
                    if (event3.mouseButton.button == Mouse::Left) {
                        if (buttonClicked(mapsWindow, closeButton))
                        {
                            basicWindow.create(VideoMode(window_width, window_height), "basicWindow", Style::Fullscreen);
                            mapsWindow.close();
                            
                        }
                        if (selectedSprite(mapsWindow, map1_sprite))
                        {
                            playerWindow.create(VideoMode(window_width, window_height), "playerWindow", Style::Fullscreen);
                            //mapsWindow.setVisible(false);
                            mapsWindow.close();
                            
                        }
                        if (selectedSprite(mapsWindow, map2_sprite))
                        {
                            playerWindow.create(VideoMode(window_width, window_height), "playerWindow", Style::Fullscreen);
                            mapsWindow.close();
                        }
                        if (selectedSprite(mapsWindow, map3_sprite))
                        {
                            playerWindow.create(VideoMode(window_width, window_height), "playerWindow", Style::Fullscreen);
                            mapsWindow.close();
                        }
                        if (selectedSprite(mapsWindow, map4_sprite))
                        {
                            playerWindow.create(VideoMode(window_width, window_height), "playerWindow", Style::Fullscreen);
                            mapsWindow.close();
                        }
                    }
                }
            }

            while (playerWindow.isOpen()) 
            {
                Event event4;
                while (playerWindow.pollEvent(event4))
                {
                    if (event4.type == Event::Closed)
                    {
                        mapsWindow.create(VideoMode(window_width, window_height), "fff", Style::Fullscreen);
                        playerWindow.close();
                        
                    }
                    if (event4.type == Event::MouseButtonPressed) {
                        if (event4.mouseButton.button == Mouse::Left) {
                            if (buttonClicked(playerWindow, closeButton))
                            {
                                //mapsWindow.setVisible(true);
                                mapsWindow.create(VideoMode(window_width, window_height), "fff", Style::Fullscreen);
                                playerWindow.close();
                                
                                
                            }
                            if (buttonClicked(playerWindow, battleButton))
                            {
                                battleWindow.create(VideoMode(window_width, window_height), "map1", Style::Fullscreen);
                                playerWindow.close();
                            }
                            
                        }
                    }

                }
                playerWindow.clear();
                playerWindow.draw(background_sprite);
                playerWindow.draw(P1L_sprite);
                playerWindow.draw(P1R_sprite);
                playerWindow.draw(P2L_sprite);
                playerWindow.draw(P2R_sprite);
                playerWindow.draw(player1_sprite);
                playerWindow.draw(player2_sprite);
                playerWindow.draw(battleButton);
                playerWindow.draw(closeButton);
                playerWindow.draw(battleText);
                playerWindow.draw(player1Text);
                playerWindow.draw(player2Text);
                playerWindow.draw(backText);
                playerWindow.display();


                while (battleWindow.isOpen())
                {
                    Event event5;
                    while (battleWindow.pollEvent(event5))
                    {
                        if (event5.type == Event::Closed)
                        {
                            playerWindow.create(VideoMode(window_width, window_height), "fff", Style::Fullscreen);
                            battleWindow.close();

                        }
                        if (event5.type == Event::MouseButtonPressed) {
                            if (event5.mouseButton.button == Mouse::Left) {
                                if (buttonClicked(battleWindow, closeButton))
                                {
                                    
                                    playerWindow.create(VideoMode(window_width, window_height), "fff", Style::Fullscreen);
                                    battleWindow.close();


                                }
                                

                            }
                        }

                    }
                    battleWindow.clear();
                    battleWindow.draw(map1Background_sprite);
                    battleWindow.draw(closeButton);
                    battleWindow.draw(closeText);
                    battleWindow.display();
                }



            }




            mapsWindow.clear();
            mapsWindow.draw(background_sprite);
            mapsWindow.draw(mapsText);
            mapsWindow.draw(closeButton);
            mapsWindow.draw(backText);
            mapsWindow.draw(map1_sprite);
            mapsWindow.draw(map2_sprite);
            mapsWindow.draw(map3_sprite);
            mapsWindow.draw(map4_sprite);
            mapsWindow.draw(map1Text);
            mapsWindow.draw(map2Text);
            mapsWindow.draw(map3Text);
            mapsWindow.draw(map4Text);
            mapsWindow.display();
        }




        basicWindow.clear(Color::Cyan);
        basicWindow.draw(background_sprite);
        basicWindow.draw(playButton);
        basicWindow.draw(settingsButton);
        basicWindow.draw(closeButton);
        basicWindow.draw(titleText);
        basicWindow.draw(playText);
        basicWindow.draw(settingsText);
        basicWindow.draw(closeText);
        basicWindow.draw(titleText);
        basicWindow.display();
        
    }

    




    return 0;
}
