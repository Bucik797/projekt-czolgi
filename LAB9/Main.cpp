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
#include <math.h>


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

void checkCollision(Tank& tank, const Map* map) {
    // Sprawdzenie kolizji czo³gu z ka¿d¹ cian¹ na mapie
    for (const auto& wall : map->getWalls()) {
        if (tank.getGlobalBounds().intersects(wall.getGlobalBounds())) {
            //return true;  // Jeli wykryto kolizjê, zwróæ true


            FloatRect tankBounds = tank.getGlobalBounds();
            
            FloatRect wallBounds = wall.getGlobalBounds();

            // Wylicz wektor odbicia (to może wymagać kalibracji w zależności od zachowania, którego oczekujesz)
            float overlapLeft = tankBounds.left + tankBounds.width - wallBounds.left;
            float overlapRight = wallBounds.left + wallBounds.width - tankBounds.left;
            float overlapTop = tankBounds.top + tankBounds.height - wallBounds.top;
            float overlapBottom = wallBounds.top + wallBounds.height - tankBounds.top;

            // Wybierz najmniejsze przecięcie, aby zdecydować, z której strony jest kolizja
            float minOverlap = min({ overlapLeft, overlapRight, overlapTop, overlapBottom });

            if (minOverlap == overlapLeft) {
                tank.setPosition(wallBounds.left - tankBounds.width+32, tank.getPosition().y);
                cout << "left" << endl;
            }
            else if (minOverlap == overlapRight) {
                tank.setPosition(wallBounds.left + wallBounds.width+30, tank.getPosition().y);
                cout << "roght" << endl;
            }
            else if (minOverlap == overlapTop) {
                tank.setPosition(tank.getPosition().x, wallBounds.top - tankBounds.height+30);
                cout << "top" << endl;
            }
            else if (minOverlap == overlapBottom) {
                tank.setPosition(tank.getPosition().x, wallBounds.top + wallBounds.height+25);
                cout << "bottom" << endl;
            }


        }
    }

    // Sprawdzenie kolizji czo³gu z ka¿dym blokiem na mapie
    for (const auto& block : map->getBlocks()) {
        if (tank.getGlobalBounds().intersects(block.getGlobalBounds())) {
            if (tank.getGlobalBounds().intersects(block.getGlobalBounds())) {
                //return true;  // Jeli wykryto kolizjê, zwróæ true


                FloatRect tankBounds = tank.getGlobalBounds();

                FloatRect wallBounds = block.getGlobalBounds();

                // Wylicz wektor odbicia (to może wymagać kalibracji w zależności od zachowania, którego oczekujesz)
                float overlapLeft = tankBounds.left + tankBounds.width - wallBounds.left;
                float overlapRight = wallBounds.left + wallBounds.width - tankBounds.left;
                float overlapTop = tankBounds.top + tankBounds.height - wallBounds.top;
                float overlapBottom = wallBounds.top + wallBounds.height - tankBounds.top;

                // Wybierz najmniejsze przecięcie, aby zdecydować, z której strony jest kolizja
                float minOverlap = min({ overlapLeft, overlapRight, overlapTop, overlapBottom });

                if (minOverlap == overlapLeft) {
                    tank.setPosition(wallBounds.left - tankBounds.width + 32, tank.getPosition().y);
                    cout << "left" << endl;
                }
                else if (minOverlap == overlapRight) {
                    tank.setPosition(wallBounds.left + wallBounds.width + 30, tank.getPosition().y);
                    cout << "roght" << endl;
                }
                else if (minOverlap == overlapTop) {
                    tank.setPosition(tank.getPosition().x, wallBounds.top - tankBounds.height + 32);
                    cout << "top" << endl;
                }
                else if (minOverlap == overlapBottom) {
                    tank.setPosition(tank.getPosition().x, wallBounds.top + wallBounds.height + 25);
                    cout << "bottom" << endl;
                }


            }
        }
    }

    //return false;  // Jeli nie wykryto ¿adnej kolizji, zwróæ false
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
    
    for (int i = 0; i < bullets.size(); i++)
    {
        double current_angle = (bullets[i].getRotation() - 90) * (3.14159265f / 180.0f);

        Vector2f movement(cos(current_angle), sin(current_angle));
        window.draw(bullets[i]);
        bullets[i].move(movement);
        
    }
}

void bulletsCollide(const Map* map, vector<Bullet>& bullets, RenderWindow& window, vector<std::unique_ptr<EnemyManager>>& enemies, Tank& tank)
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
            for (const auto& wall : map->getWalls())
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
            for (const auto& block : map->getBlocks())
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
        //cout << enemies.size() << endl;

    }
}

void createEnemies(vector<unique_ptr<EnemyManager>>& enemies)
{
    enemies.push_back(make_unique<MeleeEnemy>(100, 50, 4.0f, "meleeEnemy.png", 100, 100, 1));
    enemies.push_back(make_unique<MeleeEnemy>(100, 50, 3.0f, "meleeEnemy.png", 350, 100, 2));
    enemies.push_back(make_unique<RangeEnemy>(80, 20, 2.0f, "rangeEnemy.png", 300, 300, 3));
    enemies.push_back(make_unique<RangeEnemy>(80, 50, 2.0f, "rangeEnemy.png", 400, 500, 4));
}

void drawEnemies(const vector<unique_ptr<EnemyManager>>& enemies, RenderWindow& window, Tank& tank)
{
    for (const auto& enemy : enemies) {
        enemy->drawEnemy(window);
        enemy->move(tank);
        
    }
}

void mapResult(const vector<unique_ptr<EnemyManager>>& enemies, RenderWindow& resultwindow, RenderWindow& battleWindow, int window_width, int window_height, bool& m1c, Mapwindow& mw, Map& gameover, Map& ggwp, Tank& tank)
{
    if (enemies.size() == 0)
    {
        m1c = true;
        mw.update(m1c, false, false);  // Wywołanie update po ustawieniu m1c
        resultwindow.create(VideoMode(845,607), "resultwindow");
        
        
        battleWindow.close();
    }

    if (tank.getHealth()==0)
    {
        cout << tank.getHealth();
        mw.update(m1c, false, false);  // Wywołanie update po ustawieniu m1c
        resultwindow.create(VideoMode(window_width, window_height), "resultwindow");
        battleWindow.close();
    }
}


void setEnemybulletPosition(const vector<unique_ptr<EnemyManager>>& enemies,vector<Bullet>& e1b, vector<Bullet>& e2b, Clock& e1sc, Clock& e2sc, Tank& tank)
{
    
    if (e1sc.getElapsedTime().asSeconds() > 1.2)
    {
        for (const auto& enemy : enemies) {
            if (enemy->getId() == 3) {

                e1sc.restart();
                e1b.push_back(Bullet(0.15f, 50));
                e1b.back().setPosition(enemy->getCurrentPosition());
                e1b.back().setOrigin(5, 5);
                e1b.back().setRadius(5);
                e1b.back().setAngle(atan2(tank.getPosition().y - e1b.back().getPosition().y, tank.getPosition().x - e1b.back().getPosition().x));
                break;  // zakończ pętlę po znalezieniu odpowiedniego wroga
            }
        }
        


    }

    if (e2sc.getElapsedTime().asSeconds() > 2.1)
    {
        for (const auto& enemy : enemies) {
            if (enemy->getId() == 4) {

                e2sc.restart();
                e2b.push_back(Bullet(0.8f, 10));
                e2b.back().setPosition(enemy->getCurrentPosition());
                e2b.back().setOrigin(5, 5);
                e2b.back().setRadius(7);
                e2b.back().setAngle(atan2(tank.getPosition().y - e2b.back().getPosition().y, tank.getPosition().x - e2b.back().getPosition().x));
                break;  // zakończ pętlę po znalezieniu odpowiedniego wroga
            }
        }
        
    }

}


void flyingEnemyBullets(vector<Bullet>& e1b, vector<Bullet>& e2b, RenderWindow& window,float v1, float v2)
{
    
    for (int i = 0; i < e1b.size(); i++)
    {
        window.draw(e1b[i]);
        e1b[i].move(cos(e1b[i].getAngle())*v1,sin(e1b[i].getAngle()) * v1);
    }

    for (int i = 0; i < e2b.size(); i++)
    {
        window.draw(e2b[i]);
        e2b[i].move(cos(e2b[i].getAngle()) * v2, sin(e2b[i].getAngle()) * v2);
        
    }
}


void enemyBulletsCollide(const Map* map, vector<Bullet>& e1b, vector<Bullet>& e2b, RenderWindow& window, Tank& tank, vector<unique_ptr<EnemyManager>>& enemies)
{
    for (auto it = e1b.begin(); it != e1b.end();)
    {
        bool isErased = false;

        // Sprawdzenie, czy pocisk opuścił okno
        auto bounds = it->getGlobalBounds();
        if (bounds.left + bounds.width < 0 || bounds.top + bounds.height < 0 ||
            bounds.left > window.getSize().x || bounds.top > window.getSize().y) {
            it = e1b.erase(it);
            isErased = true;

        }
         if (!isErased)
        {
            // Sprawdź kolizje z murami
            for (const auto& wall : map->getWalls())
            {
                if (it->getGlobalBounds().intersects(wall.getGlobalBounds()))
                {
                    it = e1b.erase(it);
                    isErased = true;
                    break; // Wyjdź z wewnętrznej pętli, ponieważ iterator został zmieniony
                }
            }
        }
         
        // Jeśli pocisk nie został jeszcze usunięty, sprawdź bloki
        if (!isErased)
        {
            for (const auto& block : map->getBlocks())
            {
                if (it->getGlobalBounds().intersects(block.getGlobalBounds()))
                {
                    it = e1b.erase(it);
                    isErased = true;
                    break; // Wyjdź z wewnętrznej pętli, ponieważ iterator został zmieniony
                }
            }
        }
        
        if (!isErased)
        {
            if (it->getGlobalBounds().intersects(tank.getGlobalBounds()))
            {
                it = e1b.erase(it);
                for (const auto& enemy : enemies) {
                    if (enemy->getId() == 3) {

                        enemy->dealDamage(tank);
                        break;  // zakończ pętlę po znalezieniu odpowiedniego wroga
                    }
                }
                
                isErased = true;
                break;
            }
        }
        

        

        // Jeżeli pocisk nie został usunięty przez żadną z kolizji, przejdź do następnego
        if (!isErased)
        {
            ++it;
        }

        //e1b.erase(remove(e1b.begin(), e1b.end(), nullptr), e1b.end());
       
        

    }

    for (auto it = e2b.begin(); it != e2b.end();)
    {
        bool isErased = false;

        // Sprawdzenie, czy pocisk opuścił okno
        auto bounds = it->getGlobalBounds();
        if (bounds.left + bounds.width < 0 || bounds.top + bounds.height < 0 ||
            bounds.left > window.getSize().x || bounds.top > window.getSize().y) {
            it = e2b.erase(it);
            isErased = true;

        }
        if (!isErased)
        {
            // Sprawdź kolizje z murami
            for (const auto& wall : map->getWalls())
            {
                if (it->getGlobalBounds().intersects(wall.getGlobalBounds()))
                {
                    it = e2b.erase(it);
                    isErased = true;
                    break; // Wyjdź z wewnętrznej pętli, ponieważ iterator został zmieniony
                }
            }
        }

        // Jeśli pocisk nie został jeszcze usunięty, sprawdź bloki
        if (!isErased)
        {
            for (const auto& block : map->getBlocks())
            {
                if (it->getGlobalBounds().intersects(block.getGlobalBounds()))
                {
                    it = e2b.erase(it);
                    isErased = true;
                    break; // Wyjdź z wewnętrznej pętli, ponieważ iterator został zmieniony
                }
            }
        }

        if (!isErased)
        {
            if (it->getGlobalBounds().intersects(tank.getGlobalBounds()))
            {
                it = e2b.erase(it);
                for (const auto& enemy : enemies) {
                    if (enemy->getId() == 4) {

                        enemy->dealDamage(tank);
                        break;  // zakończ pętlę po znalezieniu odpowiedniego wroga
                    }
                }
                isErased = true;
                break;
            }
        }




        // Jeżeli pocisk nie został usunięty przez żadną z kolizji, przejdź do następnego
        if (!isErased)
        {
            ++it;
        }

        //e2b.erase(remove(e2b.begin(), e2b.end(), nullptr), e2b.end());


    }


}

void collisionDamage(vector<unique_ptr<EnemyManager>>& enemies, Tank& tank)
{
    for (auto it = enemies.begin(); it != enemies.end(); ++it) {
        if ((*it)->getGlobalBounds().intersects(tank.getGlobalBounds()))
        {
            if ((*it)->getId() == 1 || (*it)->getId() == 2) {
                (*it)->dealDamage(tank);
            }
            if ((*it)->getId() == 3 || (*it)->getId() == 4) {
                tank.setHealth(0);
            }
            enemies.erase(it); // Bezpieczne usunięcie
            break; // Zatrzymaj pętlę po usunięciu elementu
        }
    }

    
}

int main() {
    int window_width = 1600;
    int window_height = 900;
    int resulstwin_width = 765;
    int resultwin_height = 474;


    RenderWindow battleWindow, loadingwindow, menuwindow, settingswindow, mapwindow, tankwindow,resultwindow;
    bool isFullscreen = false;
    bool loaded = false;
    bool driving_backwards;
    bool map1completed = false;
    bool map2completed = false;
    bool map3completed = false;
    bool gamecompleted = false;
    Clock clock;
    Clock bulletClock;
    Clock enemy1ShootsClock;
    Clock enemy2ShootsClock;
    

    vector <Bullet> bullets;
    vector <Bullet> enemy1_bullets;
    vector <Bullet> enemy2_bullets;
    //vector <CircleShape> cirlcles;

    Direction angle;

    RectangleShape closeButton,resultButton;
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


    Tank tank(1500, 800, 0.1f, 200, tank1Icon_texture, 0.2,false,30);
    Map map1("map1background.png", "longWall.png", "shortWall.png", "block1.png", "block2.png");
    Map map2("map2background2.png", "longWallmap2.png", "shortWallmap2.png", "block1map2.png", "block2map2.png");
    Map map3("map3background.png", "longWallmap3.png", "shortWallmap3.png", "block1map3.png", "block2map3.png");
    Map map4("map4background.png", "car1map4.png", "car2map4.png", "car2map4.png", "car3map4.png");
    Map* choosen_map;
    choosen_map = &map1;
    Map gameover("gameover.png");
    Map ggwp("ggwp.png");

    vector<unique_ptr<EnemyManager>> enemies;
    //createEnemies(enemies);

    for (auto& enemy : enemies) {
        cout << enemy->getPosition().x << " " << enemy->getPosition().y << endl;

  }


    loadingwindow.create(VideoMode(1300, 700), "Loadingscreen", Style::None);
    loadingwindow.setVisible(true);
    loadingwindow.requestFocus();
    Loadingscreen ls;
    Menu menu;
    Settings sts;
    Mapwindow mw;
    Tankwindow tw;    
    battleWindow.setFramerateLimit(30);

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
                            choosen_map = &map1;
                            tankwindow.create(VideoMode(window_width, window_height), "Tankwindow", Style::None);
                            mapwindow.close();
                        }
                        if (selectedSprite(mapwindow, mw.map2SPR))
                        {
                            //if (map1completed)
                            //{
                                choosen_map = &map2;
                                tankwindow.create(VideoMode(window_width, window_height), "Tankwindow", Style::None);
                                mapwindow.close();
                            //}                            
                        }
                        if (selectedSprite(mapwindow, mw.map3SPR))
                        {
                            //if (map2completed)
                            //{
                                choosen_map = &map3;
                                tankwindow.create(VideoMode(window_width, window_height), "Tankwindow", Style::None);
                                mapwindow.close();
                            //}                            
                        }
                        if (selectedSprite(mapwindow, mw.map4SPR))
                        {
                            //if (map3completed)
                            //{
                                choosen_map = &map4;
                                tankwindow.create(VideoMode(window_width, window_height), "Tankwindow", Style::None);
                                mapwindow.close();
                            //}                            
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
                                createEnemies(enemies);
                                tank.setHealth(5000);
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
                    choosen_map->drawGraphics(battleWindow);
                    //map2.drawGraphics(battleWindow);
                    
                    
                    tank.driving();
                    tank.boundCollision(battleWindow);
                    setBulletPosition(tank, bullets, bulletClock);
                    setEnemybulletPosition(enemies, enemy1_bullets, enemy2_bullets, enemy1ShootsClock, enemy2ShootsClock, tank);
                    
                    checkCollision(tank, choosen_map); 


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
                    flyingEnemyBullets(enemy1_bullets, enemy2_bullets, battleWindow, 0.2f,0.5f);
                    bulletsCollide(choosen_map, bullets, battleWindow,enemies,tank);
                    enemyBulletsCollide(choosen_map, enemy1_bullets, enemy2_bullets, battleWindow, tank, enemies);
                    collisionDamage(enemies, tank);
                    
                    drawEnemies(enemies, battleWindow, tank);
                    
                    battleWindow.draw(closeButton);
                    battleWindow.draw(closeText);
                    mapResult(enemies, resultwindow, battleWindow, resulstwin_width, resultwin_height, map1completed, mw,gameover,ggwp,tank);
                    mw.update(map1completed, map2completed, map3completed);
                    battleWindow.display();

                    

                }

                while (resultwindow.isOpen())
                {
                    resultwindow.clear();

                    //if (map1completed)
                    //{
                      //  ggwp.drawGGWP(resultwindow, resultButton);
                    //}
                    //else
                    //{
                        gameover.drawGameOver(resultwindow, resultButton,enemies);
                    //}
                    
                    Event resultevent;

                    while (resultwindow.pollEvent(resultevent))
                    {
                        if (resultevent.type == Event::Closed)
                        {
                            resultwindow.close();
                            battleWindow.close();
                            mapwindow.create(VideoMode(window_width, window_height), "Mapwindow", Style::None);
                        }

                        if (resultevent.type == Event::MouseButtonPressed) {
                            if (resultevent.mouseButton.button == Mouse::Left) {
                                if (buttonClicked(resultwindow, resultButton))
                                {
                                    resultwindow.close();
                                    battleWindow.close();
                                    mapwindow.create(VideoMode(window_width, window_height), "Mapwindow", Style::None);
                                }
                            }
                        }
                    }
                    resultwindow.display();
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




        
