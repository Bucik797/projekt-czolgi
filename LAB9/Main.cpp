// Dominik But Grzegorz Białobrzewski
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
#include "Soundeffects.h"
#include "Endscreen.h"


using namespace sf;
using namespace std;


enum Direction
{
    right_rotation=1,
    left_rotation=-1
};


bool buttonClicked(Soundeffects& sfx,RenderWindow& window, RectangleShape& button) {
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

bool buttonClicked(Soundeffects& sfx, RenderWindow& window, CircleShape& button) {
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

void playMusic(Music& music, Music& happymusic, Music& gameover, Music& tututu)
{
    if (!music.openFromFile("Assets/Music/muzyczka.wav"))
    {
        cout << "Failed to load music" << endl;
    }
    if (!happymusic.openFromFile("Assets/Music/happymusic.wav"))
    {
        cout << "Failed to load happymusic" << endl;
    }
    if (!gameover.openFromFile("Assets/Music/gameover.wav"))
    {
        cout << "Failed to load game over sound" << endl;
    }
    if (!tututu.openFromFile("Assets/Music/tututu.wav"))
    {
        cout << "Failed to load game over sound" << endl;
    }
    
    happymusic.setLoop(true);
    music.setLoop(true);
}

void setBattleGraphics(Sprite& map1Background_sprite,Sprite& map2Background_sprite, Sprite& map3Background_sprite, Sprite& map4Background_sprite, Texture& map1Background_texture, Texture& map2Background_texture, Texture& map3Background_texture, Texture& map4Background_texture, Texture& tank1Icon_texture, Texture& tank2Icon_texture, Texture& tank3Icon_texture)
{
    if (!map2Background_texture.loadFromFile("Assets/Textures/map1.png")
        || !map3Background_texture.loadFromFile("Assets/Textures/map1.png")
        || !map4Background_texture.loadFromFile("Assets/Textures/map1.png")
        || !tank1Icon_texture.loadFromFile("Assets/Textures/yellow1Tank.png")
        || !tank2Icon_texture.loadFromFile("Assets/Textures/red1Tank.png")
        || !tank3Icon_texture.loadFromFile("Assets/Textures/blue1Tank.png"))
        
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

void checkCollision(Tank* tank, const Map* map) {
    
    for (const auto& wall : map->getWalls()) {
        if (tank->getGlobalBounds().intersects(wall.getGlobalBounds())) {
            


            FloatRect tankBounds = tank->getGlobalBounds();
            
            FloatRect wallBounds = wall.getGlobalBounds();

            
            float overlapLeft = tankBounds.left + tankBounds.width - wallBounds.left;
            float overlapRight = wallBounds.left + wallBounds.width - tankBounds.left;
            float overlapTop = tankBounds.top + tankBounds.height - wallBounds.top;
            float overlapBottom = wallBounds.top + wallBounds.height - tankBounds.top;

            
            float minOverlap = min({ overlapLeft, overlapRight, overlapTop, overlapBottom });

            if (minOverlap == overlapLeft) {
                tank->setPosition(wallBounds.left - tankBounds.width+32, tank->getPosition().y);
                
            }
            else if (minOverlap == overlapRight) {
                tank->setPosition(wallBounds.left + wallBounds.width+30, tank->getPosition().y);
                
            }
            else if (minOverlap == overlapTop) {
                tank->setPosition(tank->getPosition().x, wallBounds.top - tankBounds.height+30);
                
            }
            else if (minOverlap == overlapBottom) {
                tank->setPosition(tank->getPosition().x, wallBounds.top + wallBounds.height+25);
                
            }


        }
    }

    
    for (const auto& block : map->getBlocks()) {
        if (tank->getGlobalBounds().intersects(block.getGlobalBounds())) {
            if (tank->getGlobalBounds().intersects(block.getGlobalBounds())) {
                


                FloatRect tankBounds = tank->getGlobalBounds();

                FloatRect wallBounds = block.getGlobalBounds();

                
                float overlapLeft = tankBounds.left + tankBounds.width - wallBounds.left;
                float overlapRight = wallBounds.left + wallBounds.width - tankBounds.left;
                float overlapTop = tankBounds.top + tankBounds.height - wallBounds.top;
                float overlapBottom = wallBounds.top + wallBounds.height - tankBounds.top;

                
                float minOverlap = min({ overlapLeft, overlapRight, overlapTop, overlapBottom });

                if (minOverlap == overlapLeft) {
                    tank->setPosition(wallBounds.left - tankBounds.width + 32, tank->getPosition().y);
                    
                }
                else if (minOverlap == overlapRight) {
                    tank->setPosition(wallBounds.left + wallBounds.width + 30, tank->getPosition().y);
                    
                }
                else if (minOverlap == overlapTop) {
                    tank->setPosition(tank->getPosition().x, wallBounds.top - tankBounds.height + 32);
                    
                }
                else if (minOverlap == overlapBottom) {
                    tank->setPosition(tank->getPosition().x, wallBounds.top + wallBounds.height + 25);
                    
                }


            }
        }
    }

    for (const auto car : map->getmovingCars())
    {
        if (tank->getGlobalBounds().intersects(car.getGlobalBounds()))
        {
            tank->setHealth(0);
        }
    }

    
}

void setBulletPosition(Tank* tank, vector<Bullet>& bullets, Clock& bulletClock,Soundeffects& sfx,Tank& tank1, Tank& tank2, Tank& tank3)
{
    
    if (Keyboard::isKeyPressed(Keyboard::Space) && bulletClock.getElapsedTime().asSeconds()>1)
    {
        
        bullets.push_back(Bullet(0.3f,10));
        bullets.back().setPosition(tank->getCurrentPosition());
        bullets.back().setOrigin(5, 5);
        bullets.back().setRadius(5);
        bullets.back().setRotation(tank->getRotation());
        bulletClock.restart();
        sfx.playershoot.play();

        if (tank == &tank1)
        {
            bullets.back().setFillColor(Color::Yellow);
        }
        if (tank == &tank2)
        {
            bullets.back().setFillColor(Color::Red);
        }
        if (tank == &tank3)
        {
            bullets.back().setFillColor(Color::Cyan);
        }
        
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

void bulletsCollide(const Map* map, vector<Bullet>& bullets, RenderWindow& window, vector<std::unique_ptr<EnemyManager>>& enemies, Tank* tank, Soundeffects& sfx)
{
    for (auto it = bullets.begin(); it != bullets.end();)
    {
        bool isErased = false;

        
        auto bounds = it->getGlobalBounds();
        if (bounds.left + bounds.width < 0 || bounds.top + bounds.height < 0 ||
            bounds.left > window.getSize().x || bounds.top > window.getSize().y) {
            it = bullets.erase(it);
            isErased = true;
            
        }
        if (!isErased)
        {
            
            for (const auto& wall : map->getWalls())
            {
                if (it->getGlobalBounds().intersects(wall.getGlobalBounds()))
                {
                    it = bullets.erase(it);
                    isErased = true;
                    break; 
                }
            }
        }

       
        if (!isErased)
        {
            for (const auto& block : map->getBlocks())
            {
                if (it->getGlobalBounds().intersects(block.getGlobalBounds()))
                {
                    it = bullets.erase(it);
                    isErased = true;
                    break; 
                }
            }
        }

        if (!isErased)
        {
            for (const auto& car : map->getmovingCars())
            {
                if (it->getGlobalBounds().intersects(car.getGlobalBounds()))
                {
                    it = bullets.erase(it);
                    isErased = true;
                    break; 
                }
            }
        }

        if (!isErased)
        {
            for ( auto& enemy : enemies)
            {
                if (it->getGlobalBounds().intersects(enemy->getGlobalBounds()))
                {
                    enemy->takeDamageAnimation(*tank);
                    enemy->takeDamage(*tank);
                    sfx.enemydamaged.play();
                    
                    if (enemy->getHp() <= 0) {
                        enemy.reset(); 
                    }
                    it = bullets.erase(it);
                    isErased = true;
                    break; 
                }
            }
        }



        
        if (!isErased)
        {
            ++it;
        }

        enemies.erase(remove(enemies.begin(), enemies.end(), nullptr), enemies.end());
        

    }
}

void createEnemiesMap1(vector<unique_ptr<EnemyManager>>& enemies)
{
    enemies.push_back(make_unique<MeleeEnemy>(100, 50, 6.0f, "Assets/Textures/meleeEnemy.png", 300, 700, 1));
    enemies.push_back(make_unique<MeleeEnemy>(100, 50, 5.5f, "Assets/Textures/meleeEnemy.png", 350, 400, 1));
    enemies.push_back(make_unique<RangeEnemy>(80, 30, 3.5f, "Assets/Textures/rangeEnemy.png", 100, 100, 3));
    enemies.push_back(make_unique<RangeEnemy>(80, 30, 3.5f, "Assets/Textures/rangeEnemy.png", 150, 600, 3));
}

void createEnemiesMap2(vector<unique_ptr<EnemyManager>>& enemies)
{
    
    enemies.push_back(make_unique<MeleeEnemy>(100, 80, 6.0f, "Assets/Textures/meleeEnemy.png", 500, 600, 1));
    enemies.push_back(make_unique<MeleeEnemy>(100, 80, 6.5f, "Assets/Textures/meleeEnemy.png", 650, 400, 1));
    enemies.push_back(make_unique<RangeEnemy>(140, 50, 3.0f, "Assets/Textures/demon.png", 300, 100, 4));
    enemies.push_back(make_unique<RangeEnemy>(140, 50, 3.0f, "Assets/Textures/demon.png", 350, 750, 5));
}

void createEnemiesMap3(vector<unique_ptr<EnemyManager>>& enemies)
{
    enemies.push_back(make_unique<MeleeEnemy>(100, 80, 6.0f, "Assets/Textures/zombie.png", 600, 350, 2));
    enemies.push_back(make_unique<MeleeEnemy>(100, 80, 6.0f, "Assets/Textures/zombie.png", 650, 500, 2));
    enemies.push_back(make_unique<MeleeEnemy>(100, 80, 6.5f, "Assets/Textures/zombie.png", 700, 650, 2));
    enemies.push_back(make_unique<RangeEnemy>(140, 50, 3.0f, "Assets/Textures/demon.png", 250, 100, 4));
    enemies.push_back(make_unique<RangeEnemy>(140, 50, 3.0f, "Assets/Textures/demon.png", 300, 750, 5));
}

void createEnemiesMap4(vector<unique_ptr<EnemyManager>>& enemies)
{
    enemies.push_back(make_unique<MeleeEnemy>(100, 80, 6.0f, "Assets/Textures/zombie.png",850, 150, 2));
    enemies.push_back(make_unique<MeleeEnemy>(100, 80, 6.5f, "Assets/Textures/zombie.png", 800, 700, 2));
    enemies.push_back(make_unique<RangeEnemy>(80, 30, 3.5f, "Assets/Textures/rangeEnemy.png", 180, 300, 3));
    enemies.push_back(make_unique<RangeEnemy>(80, 30, 3.5f, "Assets/Textures/rangeEnemy.png", 200, 400, 3));
    enemies.push_back(make_unique<RangeEnemy>(140, 50, 3.0f, "Assets/Textures/demon.png", 350, 200, 4));
    enemies.push_back(make_unique<RangeEnemy>(140, 50, 3.0f, "Assets/Textures/demon.png", 150, 500, 4));
    enemies.push_back(make_unique<RangeEnemy>(140, 50, 3.0f, "Assets/Textures/demon.png", 350, 800, 5));
}

void mapSelect(Map* choosen_map, Map& map1, Map map2, Map& map3, Map& map4, vector<unique_ptr<EnemyManager>>& enemies, RenderWindow& battleWindow, RenderWindow& tankwindow)
{
    
    if (choosen_map == &map1)
    {
        
        createEnemiesMap1(enemies);
    }

    if (choosen_map == &map2)
    {
        
        createEnemiesMap2(enemies);
    }
    if (choosen_map == &map3)
    {
        
        createEnemiesMap3(enemies);
    }

    if (choosen_map == &map4)
    {
        
        createEnemiesMap4(enemies);
    }
    battleWindow.create(VideoMode(1600,900), "map1");
    battleWindow.setKeyRepeatEnabled(false);
    tankwindow.close();
    
}

void drawEnemies(const vector<unique_ptr<EnemyManager>>& enemies, RenderWindow& window, Tank* tank)
{
    for (const auto& enemy : enemies) {
        enemy->drawEnemy(window);
        enemy->move(*tank);
        
    }
}

void mapResult(Music& tututu, RenderWindow& endwindow, const vector<unique_ptr<EnemyManager>>& enemies, RenderWindow& resultwindow, RenderWindow& battleWindow, int window_width, int window_height, bool& m1c, bool& m2c, bool& m3c, bool& gmc, Mapwindow& mw, Map& gameover, Map& ggwp, Tank* tank, Map* choosen_map, Map& map2, Map& map3, Map& map4, Music& music1, Music& happymusic, Music& gameOver, Tankwindow& tw)
{
    if (tank->getHealth() == 0)
    {
        
        resultwindow.create(VideoMode(window_width, window_height), "resultwindow", Style::None);
        battleWindow.close();
        music1.pause();
        happymusic.stop();
        gameOver.play(); 
        

    }
    else if (enemies.size() == 0)
    {
        
        choosen_map->setCompleted(true);
        if (map2.getCompleted())
        {
            m2c = true;
        }
        if (map3.getCompleted())
        {
            m3c = true;
        }
        if (map4.getCompleted())
        {
            gmc = true;
        }
        m1c = true;
        mw.update(m1c, m2c, m3c);
        tw.update(m1c, m3c);
        if (gmc)
        {
            endwindow.create(VideoMode(1024, 1024), "endwindow", Style::None);
            resultwindow.close();
            battleWindow.close();
            music1.pause();
            happymusic.stop();
            tututu.play();
        }
        else
        {
            resultwindow.create(VideoMode(845, 607), "resultwindow", Style::None);
            battleWindow.close();
            music1.pause();
            happymusic.play();
            

        }
    }
}

void setEnemybulletPosition(const vector<unique_ptr<EnemyManager>>& enemies, vector<Bullet>& e1b, vector<Bullet>& e2b, Clock& e1sc, Clock& e2sc, Tank* tank, Clock& e3sc,Soundeffects& sfx)
{
    
    if (e1sc.getElapsedTime().asSeconds() > 1.2)
    {
        
        for (const auto& enemy : enemies) {
            if (enemy->getId() == 3) { 
                
                e1sc.restart();
                e1b.push_back(Bullet(0.15f, 50));
                e1b.back().setPosition(enemy->getCurrentPosition().x+20,enemy->getCurrentPosition().y+20);
                e1b.back().setOrigin(5, 5);
                e1b.back().setRadius(5);
                e1b.back().setAngle(atan2(tank->getPosition().y - e1b.back().getPosition().y, tank->getPosition().x - e1b.back().getPosition().x));
                sfx.enemyshoot.play();
                
            }
        }
        


    }
    
    if (e2sc.getElapsedTime().asSeconds() > 2.1)
    {
        for (const auto& enemy : enemies) {
            if (enemy->getId() == 4) {
                
                e2sc.restart();
                e2b.push_back(Bullet(0.8f, 10));
                e2b.back().setPosition(enemy->getCurrentPosition().x + 20, enemy->getCurrentPosition().y + 20);
                e2b.back().setOrigin(5, 5);
                e2b.back().setRadius(7);
                e2b.back().setAngle(atan2(tank->getPosition().y - e2b.back().getPosition().y, tank->getPosition().x - e2b.back().getPosition().x));
                sfx.enemyshoot.play();
            }
        }
        
    }
    
    if (e3sc.getElapsedTime().asSeconds() > 2.5)
    {
        for (const auto& enemy : enemies) {
            if (enemy->getId() == 5) {
                
                e3sc.restart();
                e2b.push_back(Bullet(1.5f, 10));
                e2b.back().setPosition(enemy->getCurrentPosition().x + 20, enemy->getCurrentPosition().y + 20);
                e2b.back().setOrigin(5, 5);
                e2b.back().setRadius(7);
                e2b.back().setAngle(atan2(tank->getPosition().y - e2b.back().getPosition().y, tank->getPosition().x - e2b.back().getPosition().x));
                sfx.enemyshoot.play();
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
    
void boomAnimation(const vector<unique_ptr<EnemyManager>>& enemies,float dt,float dt1)
{
    for (const auto& enemy : enemies)
    {
        enemy->update(dt,dt1);
    }
}
    
void enemyBulletsCollide(const Map* map, vector<Bullet>& e1b, vector<Bullet>& e2b, RenderWindow& window, Tank* tank, vector<unique_ptr<EnemyManager>>& enemies, Soundeffects& sfx)
{
    for (auto it = e1b.begin(); it != e1b.end();)
    {
        bool isErased = false;

        
        auto bounds = it->getGlobalBounds();
        if (bounds.left + bounds.width < 0 || bounds.top + bounds.height < 0 ||
            bounds.left > window.getSize().x || bounds.top > window.getSize().y) {
            it = e1b.erase(it);
            isErased = true;

        }
         if (!isErased)
        {
            
            for (const auto& wall : map->getWalls())
            {
                if (it->getGlobalBounds().intersects(wall.getGlobalBounds()))
                {
                    it = e1b.erase(it);
                    isErased = true;
                    break; 
                }
            }
        }
         
        
        if (!isErased)
        {
            for (const auto& block : map->getBlocks())
            {
                if (it->getGlobalBounds().intersects(block.getGlobalBounds()))
                {
                    it = e1b.erase(it);
                    isErased = true;
                    break; 
                }
            }
        }

        if (!isErased)
        {
            for (const auto& car : map->getmovingCars())
            {
                if (it->getGlobalBounds().intersects(car.getGlobalBounds()))
                {
                    it = e1b.erase(it);
                    isErased = true;
                    break; 
                }
            }
        }
        
        if (!isErased)
        {
            if (it->getGlobalBounds().intersects(tank->getGlobalBounds()))
            {
                it = e1b.erase(it);
                for (const auto& enemy : enemies) {
                    if (enemy->getId() == 3) {
                        enemy->dealRangeDamageAnimation(*tank);
                        enemy->dealDamage(*tank);
                        sfx.playerdamaged.play();
                        break;  
                    }
                }
                
                isErased = true;
                break;
            }
        }
        

        

        
        if (!isErased)
        {
            ++it;
        }

        
       
        

    }
    
    for (auto it = e2b.begin(); it != e2b.end();)
    {
        bool isErased = false;

        
        auto bounds = it->getGlobalBounds();
        if (bounds.left + bounds.width < 0 || bounds.top + bounds.height < 0 ||
            bounds.left > window.getSize().x || bounds.top > window.getSize().y) {
            it = e2b.erase(it);
            isErased = true;

        }
        if (!isErased)
        {
            
            for (const auto& wall : map->getWalls())
            {
                if (it->getGlobalBounds().intersects(wall.getGlobalBounds()))
                {
                    it = e2b.erase(it);
                    isErased = true;
                    break; 
                }
            }
        }

        
        if (!isErased)
        {
            for (const auto& block : map->getBlocks())
            {
                if (it->getGlobalBounds().intersects(block.getGlobalBounds()))
                {
                    it = e2b.erase(it);
                    isErased = true;
                    break; 
                }
            }
        }

        if (!isErased)
        {
            for (const auto& car : map->getmovingCars())
            {
                if (it->getGlobalBounds().intersects(car.getGlobalBounds()))
                {
                    it = e2b.erase(it);
                    isErased = true;
                    break; 
                }
            }
        }


        if (!isErased)
        {
            if (it->getGlobalBounds().intersects(tank->getGlobalBounds()))
            {
                it = e2b.erase(it);
                for (const auto& enemy : enemies) {
                    if (enemy->getId() == 4 || enemy->getId() == 5) {

                        enemy->dealRangeDamageAnimation(*tank);
                        enemy->dealDamage(*tank);
                        sfx.playerdamaged.play();
                        break;  
                    }
                }
                isErased = true;
                break;
            }
        }




        
        if (!isErased)
        {
            ++it;
        }

        


    }
    


}

void collisionDamage(vector<unique_ptr<EnemyManager>>& enemies, Tank* tank,Clock& zc,Soundeffects& sfx)
{
    for (auto it = enemies.begin(); it != enemies.end(); ++it) {
        if ((*it)->getGlobalBounds().intersects(tank->getGlobalBounds()))
        {

            if ((*it)->getId() == 1)
            {
                
                sfx.playerdamaged.play();
                (*it)->dealDamage(*tank); 
                enemies.erase(it);
                break;
                
            }

            if ((*it)->getId() == 2 && zc.getElapsedTime().asSeconds()>1.0f)
            {
                
                sfx.playerdamaged.play();
                (*it)->dealDamage(*tank);
                (*it)->dealRangeDamageAnimation(*tank);
                zc.restart();
            }


            
            if ((*it)->getId() == 3 || (*it)->getId() == 4 || (*it)->getId() == 5) 
            {
                
                sfx.playerdamaged.play();
                tank->setHealth(0);
                enemies.erase(it);
                break;
            }
             
        }
    }

    
}

void setgodModeVoice(Sound& demon_sound, SoundBuffer& demon_buffer)
{
    
    if (!demon_buffer.loadFromFile("Assets/SFX/godmode.wav"))
    {
        cout << "error godmode sound" << endl;
    }
    else
    {
        demon_sound.setBuffer(demon_buffer);
        
        
    }

}

void godModeON(RenderWindow& window,Clock& godmode_clock,Font& font,Tank* choosen_tank,bool& godmodeON,int& current_str,Event& event,Sound& demon_sound)
{
    
    if (!godmodeON)
    {

        current_str = choosen_tank->getStrength();
        demon_sound.play();
    }
    
    godmodeON = !godmodeON;
    godmodeON ? choosen_tank->setStrength(200) : choosen_tank->setStrength(current_str);
    cout << godmodeON << endl;
    
    
    
}

void setGodmodestring(Font& font1, Text& godmode)
{
    if (!font1.loadFromFile("Assets/Fonts/arial.ttf"))
    {
        cout << "error dupa" << endl;
    }
    godmode.setFont(font1);
    godmode.setString("GODMODE ON");
    godmode.setCharacterSize(20);
    godmode.setFillColor(Color::White);
    godmode.setPosition(1400, 50);
    godmode.setOutlineColor(Color::Black);
    godmode.setOutlineThickness(1);
}


int main()
{
    int window_width = 1600;
    int window_height = 900;
    int resulstwin_width = 765;
    int resultwin_height = 474;
    int current_str = 0;

    RenderWindow endwindow, battleWindow, loadingwindow, menuwindow, settingswindow, mapwindow, tankwindow, resultwindow;
    bool isFullscreen = false;
    bool loaded = false;
    bool driving_backwards;
    bool map1completed = false;
    bool map2completed = false;
    bool map3completed = false;
    bool gamecompleted = false;
    bool godmodeON = false;
    Clock clock;
    Clock bulletClock;
    Clock enemy1ShootsClock;
    Clock enemy2ShootsClock;
    Clock enemy3ShootsClock;
    Clock zombie_clock;
    Clock explosion_clock;
    Clock explosion_E_clock;
    Clock godmode_clock;

    vector <Bullet> bullets;
    vector <Bullet> enemy_bullets;
    vector <Bullet> enemy2_bullets;
    

    Direction angle;

    RectangleShape  resultButton;
    Sprite map1Background_sprite, map2Background_sprite, map3Background_sprite, map4Background_sprite, tank1Icon_sprite;
    Sprite longWall1_sprite, shortWall_sprite, block1_sprite, block2_sprite;
    Texture longWall_texture, shortWall_texture, block1_texture, block2_texture;
    Texture map1Background_texture, map2Background_texture, map3Background_texture, map4Background_texture, tank1Icon_texture, tank2Icon_texture, tank3Icon_texture;
    Text closeText;
    Text godmode;
    Font font;
    Font font1;

    Sound demon_sound;
    SoundBuffer demon_buffer;

    
    


    Soundeffects soundeffects;
    Music music1, happymusic, gameOver, tututu;
    setGodmodestring(font1, godmode);
    setgodModeVoice(demon_sound, demon_buffer);
    setBattleGraphics(map1Background_sprite, map2Background_sprite, map3Background_sprite, map4Background_sprite, map1Background_texture, map2Background_texture, map3Background_texture, map4Background_texture, tank1Icon_texture, tank2Icon_texture, tank3Icon_texture);


    playMusic(music1, happymusic, gameOver, tututu);
    music1.play();



    Tank tank1(1500, 450, 0.25f, 200, tank1Icon_texture, 0.25, false, 30);
    Tank tank2(1500, 450, 0.15f, 400, tank2Icon_texture, 0.15, false, 45);
    Tank tank3(1500, 450, 0.05f, 6000, tank3Icon_texture, 0.05, false, 70);
    Tank* choosen_tank;
    choosen_tank = &tank1;
    Map map1("Assets/Textures/map1background.png", "Assets/Textures/longWall.png", "Assets/Textures/shortWall.png", "Assets/Textures/block1.png", "Assets/Textures/block2.png", false);
    Map map2("Assets/Textures/map2background2.png", "Assets/Textures/longWallmap2.png", "Assets/Textures/shortWallmap2.png", "Assets/Textures/block1map2.png", "Assets/Textures/block2map2.png", false);
    Map map3("Assets/Textures/map3background3.png", "Assets/Textures/longWallmap3.png", "Assets/Textures/shortWallmap3.png", "Assets/Textures/block1map3.png", "Assets/Textures/block2map3.png", false);
    Map map4("Assets/Textures/map4background4.png", "Assets/Textures/car1map4.png", "Assets/Textures/car2map4.png", "Assets/Textures/car3map4.png", "Assets/Textures/car4map4.png", false);
    Map* choosen_map;
    choosen_map = &map1;
    Map gameover("Assets/Textures/gameover.png");
    Map ggwp("Assets/Textures/ggwp.png");

    vector<unique_ptr<EnemyManager>> enemies;
    
    map4.createMovingSprites();

    for (auto& enemy : enemies) {
        cout << enemy->getPosition().x << " " << enemy->getPosition().y << endl;

    }

    Loadingscreen ls;
    loadingwindow.create(VideoMode(1300, 700), "Loadingscreen", Style::None);
    loadingwindow.setVisible(true);
    loadingwindow.requestFocus();
    loadingwindow.clear();
    ls.drawGraphics(loadingwindow, clock);
    loadingwindow.display();
    Menu menu;
    Settings sts;
    Mapwindow mw;
    Tankwindow tw;
    Endscreen ends;
    battleWindow.setFramerateLimit(30);

    while (loadingwindow.isOpen()) {
        Event loadingEvent;

        loadingwindow.clear();
        ls.drawGraphics(loadingwindow, clock);
        loadingwindow.display();

        Time elapsed = clock.getElapsedTime();

        if (elapsed.asSeconds() > 6.0f) {
            menuwindow.create(VideoMode(window_width, window_height), "Menu", Style::None);
            loadingwindow.close();
            break;
        }

        while (loadingwindow.pollEvent(loadingEvent)) {
            if (loadingEvent.type == Event::Closed) {
                loadingwindow.close();
            }
        }
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
                    if (buttonClicked(soundeffects, menuwindow, menu.closeButton))
                    {
                        menuwindow.close();
                        loadingwindow.close();
                    }
                    if (buttonClicked(soundeffects, menuwindow, menu.settingsButton))
                    {
                        settingswindow.create(VideoMode(window_width, window_height), "Settings", Style::None);
                        
                        menuwindow.close();
                    }
                    if (buttonClicked(soundeffects, menuwindow, menu.playButton))
                    {
                        mapwindow.create(VideoMode(window_width, window_height), "Mapwindow", Style::None);
                        
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
                }
                if (event2.type == Event::MouseButtonPressed) {
                    if (event2.mouseButton.button == Mouse::Left) {
                        if (buttonClicked(soundeffects, settingswindow, sts.closeButton))
                        {
                            menuwindow.create(VideoMode(window_width, window_height), "Menu", Style::None);
                            settingswindow.close();
                        }
                        sts.musicRregulation(music1, happymusic, settingswindow, soundeffects);
                        sts.sfxRegulation(soundeffects, settingswindow);
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
                        if (buttonClicked(soundeffects, mapwindow, mw.closeButton))
                        {
                            menuwindow.create(VideoMode(window_width, window_height), "Menu", Style::None);
                            mapwindow.close();
                        }
                        if (buttonClicked(soundeffects, mapwindow, mw.map1button))
                        {
                            if (!map1completed)
                            {
                                choosen_map = &map1;
                                choosen_map->initializeMap1();
                                tankwindow.create(VideoMode(window_width, window_height), "Tankwindow", Style::None);
                                mapwindow.close();
                            }
                            
                        }
                        if (buttonClicked(soundeffects, mapwindow, mw.map2button))
                        {
                            if (map1.getCompleted())
                            {
                                if (!map2completed)
                                {
                                    choosen_map = &map2;
                                    choosen_map->initializeMap2();
                                    tankwindow.create(VideoMode(window_width, window_height), "Tankwindow", Style::None);
                                    mapwindow.close();
                                }
                                
                            }
                        }
                        if (buttonClicked(soundeffects, mapwindow, mw.map3button))
                        {
                            if (map2.getCompleted())
                            {
                                if (!map3completed)
                                {
                                    choosen_map = &map3;
                                    choosen_map->initializeMap3();
                                    tankwindow.create(VideoMode(window_width, window_height), "Tankwindow", Style::None);
                                    mapwindow.close();
                                }
                                
                            }
                        }
                        if (buttonClicked(soundeffects, mapwindow, mw.map4button))
                        {
                            if (map3.getCompleted())
                            {
                                choosen_map = &map4;
                                choosen_map->initializeMap4();
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
                            if (buttonClicked(soundeffects, tankwindow, tw.closeButton))
                            {
                                mapwindow.create(VideoMode(window_width, window_height), "mapwindow", Style::None);
                                tankwindow.close();
                            }

                            if (buttonClicked(soundeffects, tankwindow, tw.tank1button))
                            {
                                choosen_tank = &tank1;
                                choosen_tank->setHealth(200);
                                choosen_tank->setPosition(1500, 450);
                                mapSelect(choosen_map, map1, map2, map3, map4, enemies, battleWindow,tankwindow);    
                                if (choosen_map == &map2)
                                {
                                    createEnemiesMap2(enemies);
                                }
                            }

                            if (buttonClicked(soundeffects, tankwindow, tw.tank2button))
                            {
                                if (map1completed)
                                {
                                    choosen_tank = &tank2;
                                    choosen_tank->setHealth(400);
                                    choosen_tank->setPosition(1500, 450);
                                    mapSelect(choosen_map, map1, map2, map3, map4, enemies, battleWindow, tankwindow);
                                    if (choosen_map == &map2)
                                    {
                                        createEnemiesMap2(enemies);
                                    }
                                }
                                
                                
                            }

                            if (buttonClicked(soundeffects, tankwindow, tw.tank3button))
                            {
                                if (map3completed)
                                {
                                    choosen_tank = &tank3;
                                    choosen_tank->setHealth(600);
                                    choosen_tank->setPosition(1500, 450);
                                    mapSelect(choosen_map, map1, map2, map3, map4, enemies, battleWindow, tankwindow);
                                    if (choosen_map == &map2)
                                    {
                                        createEnemiesMap2(enemies);
                                    }
                                }
                                
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
                    
                         if (choosen_map == &map4)
                         {
                             map4.moveSprites(battleWindow);
                         }
                         
                         
                    
                    choosen_tank->driving();
                    choosen_tank->boundCollision(battleWindow);
                    setBulletPosition(choosen_tank, bullets, bulletClock,soundeffects,tank1,tank2,tank3);
                    setEnemybulletPosition(enemies, enemy_bullets, enemy2_bullets, enemy1ShootsClock, enemy2ShootsClock, choosen_tank,enemy3ShootsClock,soundeffects);
                    checkCollision(choosen_tank, choosen_map);
                    

                    while (battleWindow.pollEvent(event5))
                    {
                        if (event5.type == Event::Closed)
                        {
                            tankwindow.create(VideoMode(window_width, window_height), "Tankwindow", Style::None);
                            battleWindow.close();

                        }   
                        if (event5.type == Event::KeyReleased && event5.key.code == Keyboard::F1)
                        {
                            godModeON(battleWindow, godmode_clock, font, choosen_tank, godmodeON, current_str, event5,demon_sound);
                        }
                        
                    }

                    float dt = explosion_clock.restart().asSeconds();
                    float dt1 = explosion_E_clock.restart().asSeconds();

                    
                    boomAnimation(enemies, dt,dt1);
                    battleWindow.draw(*choosen_tank);
                    flyingBullets(bullets, battleWindow);
                    flyingEnemyBullets(enemy_bullets, enemy2_bullets, battleWindow, 0.2f, 0.5f);
                    bulletsCollide(choosen_map, bullets, battleWindow, enemies, choosen_tank, soundeffects);
                    enemyBulletsCollide(choosen_map, enemy_bullets, enemy2_bullets, battleWindow, choosen_tank, enemies,soundeffects);
                    collisionDamage(enemies, choosen_tank,zombie_clock,soundeffects);

                    drawEnemies(enemies, battleWindow, choosen_tank);

                    battleWindow.draw(closeText);
                    mapResult(tututu, endwindow, enemies, resultwindow, battleWindow, resulstwin_width, resultwin_height, map1completed,map2completed, map3completed,gamecompleted, mw, gameover, ggwp, choosen_tank, choosen_map,map2,map3,map4, music1, happymusic, gameOver,tw);
                    if (godmodeON)
                    {
                        
                        battleWindow.draw(godmode);

                    }

                    battleWindow.display();



                }
                while (endwindow.isOpen())
                {
					endwindow.clear();
					ends.drawGraphics(endwindow);
					Event endevent;

                    while (endwindow.pollEvent(endevent))
                    {
                        if (endevent.type == Event::Closed)
                        {
							endwindow.close();
                            loadingwindow.close();
						}

                        if (endevent.type == Event::MouseButtonPressed) {
                            if (endevent.mouseButton.button == Mouse::Left) {
                                if (buttonClicked(soundeffects, endwindow, ends.closebutton))
                                {
									endwindow.close();
									loadingwindow.close();
								}
							}
						}
					}
					endwindow.display();
				}

                while (resultwindow.isOpen())
                {
                    resultwindow.clear();

                    if (choosen_map->getCompleted())
                    {
                        
                        ggwp.drawGGWP(resultwindow, resultButton, enemies);
                        
                    }
                    else
                    {
                        gameover.drawGameOver(resultwindow, resultButton, enemies);
                    }

                    Event resultevent;

                    while (resultwindow.pollEvent(resultevent))
                    {
                        if (resultevent.type == Event::Closed)
                        {
                            happymusic.stop();
                            music1.play();
                            resultwindow.close();
                            mapwindow.create(VideoMode(window_width, window_height), "Mapwindow", Style::None);
                        }

                        if (resultevent.type == Event::MouseButtonPressed) {
                            if (resultevent.mouseButton.button == Mouse::Left) {
                                
                                if (buttonClicked(soundeffects, resultwindow, resultButton))
                                {
                                    happymusic.stop();
                                    music1.play();
                                    resultwindow.close();
                                    mapwindow.create(VideoMode(window_width, window_height), "Mapwindow", Style::None); // Return to map window
                                }
                            }
                        }
                    }
                    resultwindow.display();
                }


            }

            mapwindow.clear();
           
            mw.drawGraphics(mapwindow);
            mapwindow.display();
        }


        menuwindow.clear();
        menu.drawGraphics(menuwindow);
        menuwindow.display();
    }
    return 0;
}       
