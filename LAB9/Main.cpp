#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Tank.h"
#include "Map.h"
#include "Bullet.h"
#include <vector>
#include "EnemyManager.h"
#include "MeleeEnemy.h"
#include <memory>
#include "RangeEnemy.h"
#include "Loadingscreen.h"
#include "Menu.h"
#include "Settings.h"
#include "Mapwindow.h"
#include "Tankwindow.h"


using namespace sf;
using namespace std;


enum Direction
{
    right_rotation=1,
    left_rotation=-1
};

void closebutton(RectangleShape& button, Text& text, Font& font, string textString, float posX, float posY) {
    if (!font.loadFromFile("arial.ttf")) {
        cout << "Failed to load font" << endl;
    }
    button.setSize(Vector2f(200, 100));
	button.setFillColor(Color::Red);
	button.setPosition(posX, posY);

	text.setFont(font);
	text.setString(textString);
	text.setCharacterSize(24);
	text.setFillColor(Color::White);
    text.setOutlineColor(Color::Green);
	text.setPosition(posX + 50, posY + 40);
}

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

void playMusic(Sound& music, SoundBuffer& music_buffer)
{
    if (!music_buffer.loadFromFile("kukon.wav"))
    {
        cout << "Failed to load font" << endl;
    }

    music.setBuffer(music_buffer);
}

void setBattleGraphics(Sprite& map1Background_sprite,Sprite& map2Background_sprite, Sprite& map3Background_sprite, Sprite& map4Background_sprite, Texture& map1Background_texture, Texture& map2Background_texture, Texture& map3Background_texture, Texture& map4Background_texture, Sprite& tank1Icon_sprite, Texture& tank1Icon_texture)
{
    if (//!map1Background_texture.loadFromFile("map11.png")
         !map2Background_texture.loadFromFile("map1.png")
        || !map3Background_texture.loadFromFile("map1.png")
        || !map4Background_texture.loadFromFile("map1.png")
        || !tank1Icon_texture.loadFromFile("redTank.png"))
        
    {
        cout << "Failed to load textures" << endl;
    }

    map1Background_sprite.setTexture(map1Background_texture);
    map1Background_sprite.setScale(2,2);
    map1Background_sprite.setPosition(0,0);


    map2Background_sprite.setTexture(map2Background_texture);

    map3Background_sprite.setTexture(map3Background_texture);

    map4Background_sprite.setTexture(map4Background_texture);


    //tank1Icon_sprite.setTexture(tank1Icon_texture);
    //tank1Icon_sprite.setScale(0.3, 0.3);
    //tank1Icon_sprite.setPosition(200, 800);

}

bool checkCollision(Tank& tank, const Map& map) {
    // Sprawdzenie kolizji czo³gu z ka¿d¹ cian¹ na mapie
    for (const auto& wall : map.getWalls()) {
        if (tank.getGlobalBounds().intersects(wall.getGlobalBounds())) {
            return true;  // Jeli wykryto kolizjê, zwróæ true
        }
    }

    // Sprawdzenie kolizji czo³gu z ka¿dym blokiem na mapie
    for (const auto& block : map.getBlocks()) {
        if (tank.getGlobalBounds().intersects(block.getGlobalBounds())) {
            return true;  // Jeli wykryto kolizjê, zwróæ true
        }
    }

    return false;  // Jeli nie wykryto ¿adnej kolizji, zwróæ false
}

void setBulletPosition(Tank& tank, vector<Bullet>& bullets, Clock& bulletClock)
{
    
    if (Keyboard::isKeyPressed(Keyboard::Space) && bulletClock.getElapsedTime().asSeconds()>0.5)
    {

        bullets.push_back(Bullet(0.3f,10));
        bullets.back().setPosition(tank.getCurrentPosition());
        bullets.back().setOrigin(5, 5);
        bullets.back().setRadius(5);
        bullets.back().setRotation(tank.getRotation());
        bulletClock.restart();
        //tank.setSpeed(tank.getSpeed() + 0.02f);
        //cout << bullets.size();
        
    }
    
}

void flyingBullets(vector<Bullet>& bullets, RenderWindow& window)
{
    //cout << "flying bullets " << endl;
    for (int i = 0; i < bullets.size(); i++)
    {
        double current_angle = (bullets[i].getRotation() - 90) * (3.14159265f / 180.0f);

        Vector2f movement(cos(current_angle), sin(current_angle));
        window.draw(bullets[i]);
        bullets[i].move(movement);
        
        
        //bullets[i].move(1,0);
        //cout << i << endl;
    }
}

void bulletsCollide(const Map& map, vector<Bullet>& bullets, RenderWindow& window, vector<std::unique_ptr<EnemyManager>>& enemies, Tank& tank)
{
    for (auto it = bullets.begin(); it != bullets.end();)
    {
        bool isErased = false;

        // Sprawdzenie, czy pocisk opuścił okno
        auto bounds = it->getGlobalBounds();
        if (bounds.left + bounds.width < 0 || bounds.top + bounds.height < 0 ||
            bounds.left > window.getSize().x || bounds.top > window.getSize().y) {
            it = bullets.erase(it);
            isErased = true;
            
        }
        if (!isErased)
        {
            // Sprawdź kolizje z murami
            for (const auto& wall : map.getWalls())
            {
                if (it->getGlobalBounds().intersects(wall.getGlobalBounds()))
                {
                    it = bullets.erase(it);
                    isErased = true;
                    break; // Wyjdź z wewnętrznej pętli, ponieważ iterator został zmieniony
                }
            }
        }

        // Jeśli pocisk nie został jeszcze usunięty, sprawdź bloki
        if (!isErased)
        {
            for (const auto& block : map.getBlocks())
            {
                if (it->getGlobalBounds().intersects(block.getGlobalBounds()))
                {
                    it = bullets.erase(it);
                    isErased = true;
                    break; // Wyjdź z wewnętrznej pętli, ponieważ iterator został zmieniony
                }
            }
        }

        if (!isErased)
        {
            for ( auto& enemy : enemies)
            {
                if (it->getGlobalBounds().intersects(enemy->getGlobalBounds()))
                {
                    enemy->takeDamage(tank);
                    if (enemy->getHp() <= 0) {
                        enemy.reset(); // Usuń obiekt przeciwnika
                    }
                    it = bullets.erase(it);
                    isErased = true;
                    break; // Wyjdź z wewnętrznej pętli, ponieważ iterator został zmieniony
                }
            }
        }



        // Jeżeli pocisk nie został usunięty przez żadną z kolizji, przejdź do następnego
        if (!isErased)
        {
            ++it;
        }

        enemies.erase(remove(enemies.begin(), enemies.end(), nullptr), enemies.end());
        cout << enemies.size() << endl;

    }
}

void drawEnemies(const vector<unique_ptr<EnemyManager>>& enemies, RenderWindow& window)
{
    for (const auto& enemy : enemies) {
        enemy->drawEnemy(window);
    }
}

void map1complete(const vector<unique_ptr<EnemyManager>>& enemies, RenderWindow& mapsWindow, RenderWindow& battleWindow, int window_width, int window_height, bool& m1c, Mapwindow& mw)
{
    if (enemies.size() == 0)
    {
        m1c = true;
        mw.update(m1c, false, false);  // Wywołanie update po ustawieniu m1c
        mapsWindow.create(VideoMode(window_width, window_height), "mapwindow", Style::None);
        battleWindow.close();
    }
}



int main() {
    int window_width = 1600;
    int window_height = 900;
   
    RenderWindow battleWindow, loadingwindow, menuwindow, settingswindow, mapwindow, tankwindow;
    bool isFullscreen = false;
    bool loaded = false;
    bool driving_backwards;
    bool map1completed = false;
    bool map2completed = false;
    bool map3completed = false;
    bool gamecompleted = false;
    Clock clock;
    Clock bulletClock;

    vector <Bullet> bullets;
    //vector <CircleShape> cirlcles;

    Direction angle;

    RectangleShape closeButton;
    Sprite map1Background_sprite, map2Background_sprite, map3Background_sprite, map4Background_sprite, tank1Icon_sprite;
    Sprite longWall1_sprite, shortWall_sprite, block1_sprite, block2_sprite;
    Texture longWall_texture, shortWall_texture, block1_texture, block2_texture;
    Texture map1Background_texture, map2Background_texture, map3Background_texture, map4Background_texture, tank1Icon_texture;
    Text closeText; 
    Font font;
       
    Sound music;
    SoundBuffer music_buffer;
        //Music music;

   closebutton(closeButton, closeText, font, "Close", 1200, 800);
    setBattleGraphics(map1Background_sprite, map2Background_sprite, map3Background_sprite, map4Background_sprite, map1Background_texture, map2Background_texture, map3Background_texture, map4Background_texture, tank1Icon_sprite, tank1Icon_texture);

    playMusic(music, music_buffer);
        //music.play();


    Tank tank(100, 100, 0.2f, 100, tank1Icon_texture, 0.2,false,30);
    Map map1("map11.png", "longWall.png", "shortWall.png", "block1.png", "block2.png");
    vector<std::unique_ptr<EnemyManager>> enemies;
    enemies.push_back(make_unique<MeleeEnemy>(100, 15, 0.1f,"meleeEnemy.png",100,100));
    enemies.push_back(make_unique<MeleeEnemy>(200, 20, 0.2f,"meleeEnemy.png",350,100));
    enemies.push_back(make_unique<RangeEnemy>(80, 26, 0.1f,"rangeEnemy.png",300,300));
    enemies.push_back(make_unique<RangeEnemy>(80, 26, 0.1f, "rangeEnemy.png",400, 500));
    /*for (auto& enemy : enemies) {
      enemy->takeDamage(tank);
      enemy->dealDamage(tank);

  }
*/

    loadingwindow.create(VideoMode(1300, 700), "Loadingscreen", Style::None);
    loadingwindow.setVisible(true);
    loadingwindow.requestFocus();
    Loadingscreen ls;
    Menu menu;
    Settings sts;
    Mapwindow mw;
    Tankwindow tw;    

    while (loadingwindow.isOpen())
    {
        CircleShape loadingCircle(30);
        loadingCircle.setFillColor(Color::Transparent);
        loadingCircle.setOutlineThickness(5);
        loadingCircle.setOutlineColor(Color::Green);
        loadingCircle.setPosition(650, 600);

        Time elapsed = clock.getElapsedTime();
        Event loadingEvent;
        float pulseSpeed = 5.0f;

        float scaleFactor = 1.0f + 0.2f * sin(pulseSpeed * elapsed.asSeconds());
        loadingCircle.setRadius(30 * scaleFactor);
        loadingCircle.setOrigin(loadingCircle.getRadius(), loadingCircle.getRadius());


        if (elapsed.asSeconds() > 10.0f)
        {
            menuwindow.create(VideoMode(window_width, window_height), "basicWindow");

            loadingwindow.setVisible(false);
            break;
        }

        while (loadingwindow.pollEvent(loadingEvent))
        {
            if (loadingEvent.type == Event::Closed) loadingwindow.close();
        }

        loadingwindow.clear();
        ls.drawGraphics(loadingwindow);
        loadingwindow.draw(loadingCircle);
        loadingwindow.display();
    }


    while (menuwindow.isOpen()) {
        Event event;

        while (menuwindow.pollEvent(event))
        {
            
            if (event.type == Event::Closed)
            {
                menuwindow.close();
            }

            if (event.type == Event::MouseButtonPressed) {
                if (event.mouseButton.button == Mouse::Left) {
                    if (buttonClicked(menuwindow, menu.closeButton))
                    {
                        menuwindow.close();
                        loadingwindow.close();
                    }
                    if (buttonClicked(menuwindow, menu.settingsButton))
                    {
                        settingswindow.create(VideoMode(window_width, window_height), "Settings", Style::None);
                        //menuwindow.setVisible(false);
                        menuwindow.close();
                    }
                    if (buttonClicked(menuwindow, menu.playButton))
                    {
                        mapwindow.create(VideoMode(window_width, window_height), "Mapwindow", Style::None);
                        //menuwindow.setVisible(false);
                        menuwindow.close();
                    }                    
                }
            }
        }

        while (settingswindow.isOpen())
        {
            Event event2;
            while (settingswindow.pollEvent(event2))
            {
                if (event2.type == Event::Closed) {

                    menuwindow.setVisible(true);
                    settingswindow.close();
;                }
                if (event2.type == Event::MouseButtonPressed) {
                    if (event2.mouseButton.button == Mouse::Left) {
                        if (buttonClicked(settingswindow, sts.closeButton))
                        {
                            menuwindow.create(VideoMode(window_width, window_height), "Menu", Style::None);
                            settingswindow.close();
                        }
                        sts.musciRregulation(music, settingswindow);
                    }
                }
            }

            settingswindow.clear();
            sts.drawGraphics(settingswindow);
            settingswindow.display();
        }


        while (mapwindow.isOpen())
        {
            Event event3;
            while (mapwindow.pollEvent(event3))
            {
                if (event3.type == Event::Closed) {
                    mapwindow.close();
                    menuwindow.create(VideoMode(window_width, window_height), "Menu", Style::None);
                }

                if (event3.type == Event::MouseButtonPressed) {
                    if (event3.mouseButton.button == Mouse::Left) {
                        if (buttonClicked(mapwindow, mw.closeButton))
                        {
                            menuwindow.create(VideoMode(window_width, window_height), "Menu", Style::None);
                            mapwindow.close();
                        }
                        if (selectedSprite(mapwindow, mw.map1SPR))
                        {
                            tankwindow.create(VideoMode(window_width, window_height), "Tankwindow", Style::None);
                            mapwindow.close();
                        }
                        if (selectedSprite(mapwindow, mw.map2SPR))
                        {
                            if (map1completed)
                            {
                                tankwindow.create(VideoMode(window_width, window_height), "Tankwindow", Style::None);
                                mapwindow.close();
                            }                            
                        }
                        if (selectedSprite(mapwindow, mw.map3SPR))
                        {
                            if (map2completed)
                            {
                                tankwindow.create(VideoMode(window_width, window_height), "Tankwindow", Style::None);
                                mapwindow.close();
                            }                            
                        }
                        if (selectedSprite(mapwindow, mw.map4SPR))
                        {
                            if (map3completed)
                            {
                                tankwindow.create(VideoMode(window_width, window_height), "Tankwindow", Style::None);
                                mapwindow.close();
                            }                            
                        }
                    }
                }
            }

            while (tankwindow.isOpen())
            {
                Event event4;
                while (tankwindow.pollEvent(event4))
                {
                    if (event4.type == Event::Closed)
                    {
                        mapwindow.create(VideoMode(window_width, window_height), "mapwindow", Style::None);
                        tankwindow.close();

                    }
                    if (event4.type == Event::MouseButtonPressed) {
                        if (event4.mouseButton.button == Mouse::Left) {
                            if (buttonClicked(tankwindow, tw.closeButton))
                            {
                                mapwindow.create(VideoMode(window_width, window_height), "mapwindow", Style::None);
                                tankwindow.close();
                            }
                            if (buttonClicked(tankwindow, tw.playButton))
                            {
                                battleWindow.create(VideoMode(window_width, window_height), "map1");
                                tankwindow.close();
                            }
                        }
                    }
                }
                tankwindow.clear();
                tw.drawGraphics(tankwindow);
                tankwindow.display();


                while (battleWindow.isOpen())
                {
                    Event event5;
                    battleWindow.clear();
                    map1.drawGraphics(battleWindow);


                    tank.driving();
                    tank.boundCollision(battleWindow);
                    setBulletPosition(tank, bullets, bulletClock);
                    
                    //bullet1.setCurrentPosition(tank);
                    

                    if (checkCollision(tank, map1)&& (Keyboard::isKeyPressed(Keyboard::Up)||Keyboard::isKeyPressed(Keyboard::Down))) {
                        // Cofniêcie czo³gu, jeli wykryto kolizjê
                        

                        tank.isDrivingBackwards() ? tank.move(1) : tank.move(-1);
                        //cout << tank.isDrivingBackwards();
                      
                    }
                    if (checkCollision(tank, map1) && (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::Left))) {
                        // Cofniêcie czo³gu, jeli wykryto kolizjê


                        tank.isRotatingLeft() ? tank.rotate(1) : tank.rotate(-1);
                        //cout << tank.isRotatingLeft();
                    }

                    while (battleWindow.pollEvent(event5))
                    {
                        if (event5.type == Event::Closed)
                        {
                            tankwindow.create(VideoMode(window_width, window_height), "Tankwindow", Style::None)
;                           battleWindow.close();

                        }
                        if (event5.type == Event::MouseButtonPressed) {
                            if (event5.mouseButton.button == Mouse::Left) {
                                if (buttonClicked(battleWindow, closeButton))
                                {
                                    tankwindow.create(VideoMode(window_width, window_height), "Tankwindow", Style::None);
                                    battleWindow.close();
                                }
                            }
                        }
                    }                                       
                    
                    battleWindow.draw(tank);
                    flyingBullets(bullets, battleWindow);
                    bulletsCollide(map1, bullets, battleWindow,enemies,tank);
                    //bullet1.shooted(battleWindow);
                    //bullet1.drawBullets(battleWindow);
                    //battleWindow.draw(bullet1);
                    
                    
                    drawEnemies(enemies, battleWindow);
                    battleWindow.draw(closeButton);
                    battleWindow.draw(closeText);
                    map1complete(enemies, mapwindow, battleWindow, window_width, window_height, map1completed, mw);
                    mw.update(map1completed, map2completed, map3completed);
                    battleWindow.display();
                }

            }
            mapwindow.clear();
            mw.update(map1completed, map2completed, map3completed);
            mw.drawGraphics(mapwindow);
            mapwindow.display();
        
        }
        menuwindow.clear();
        menu.drawGraphics(menuwindow);
        menuwindow.display();

    }

    return 0;
}




        
