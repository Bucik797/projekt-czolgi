#include "Map.h"
#include <vector>

Map::Map(const string& backgroundFile, const string& longWallFile, const string& shortWallFile, const string& block1File, const string& block2File)
{
    if (!background_texture.loadFromFile(backgroundFile) ||
        !longWall_texture.loadFromFile(longWallFile) ||
        !shortWall_texture.loadFromFile(shortWallFile) ||
        !block1_texture.loadFromFile(block1File) ||
        !block2_texture.loadFromFile(block2File))
    {
        cout << "Failed to load textures" << endl;
    }
    

    initializeMap3();
}

Map::Map(const string& result_file)
{
    if (!result_texture.loadFromFile(result_file))
    {
        cout << "Failed to load gameover texture" << endl;
    }
    else
    {
        this->setTexture(result_texture);
        //this->setScale(1.5, 1.5);
        //this->setPosition(100, 0);

    }
}

void Map::initializeMap1()
{
    this->setTexture(background_texture);

    this->setScale(1.5, 1.5);
    this->setPosition(100, 0);

    // Tworzenie sprite'ów œcian i bloków

    /*

    182.6 57.8 lw
    117.8 58.6 sw
    74.6 77.4  b1
    74.4 75.8  b2


    */
    
    Sprite longWall_sprite1(longWall_texture);
    longWall_sprite1.setPosition(700, 600);
    longWall_sprite1.setScale(0.2f, 0.2f);
    walls.push_back(longWall_sprite1);

    

    Sprite longWall_sprite3(longWall_texture);
    longWall_sprite3.rotate(90);
    longWall_sprite3.setPosition(700, 600);
    longWall_sprite3.setScale(0.2f, 0.2f);
    walls.push_back(longWall_sprite3);
    
    Sprite longWall_sprite2(longWall_texture);
    longWall_sprite2.rotate(-90);
    longWall_sprite2.setPosition(145, 274);
    longWall_sprite2.setScale(0.2f, 0.2f);
    walls.push_back(longWall_sprite2);

    Sprite longWall_sprite4(longWall_texture);
    longWall_sprite4.setPosition(145, 274);
    longWall_sprite4.setScale(0.2f, 0.2f);
    walls.push_back(longWall_sprite4);



    Sprite longWall_sprite5(longWall_texture);
    longWall_sprite5.setPosition(1200, 500);
    longWall_sprite5.setScale(0.2f, 0.2f);
    walls.push_back(longWall_sprite5);

    Sprite longWall_sprite6(longWall_texture);
    longWall_sprite6.rotate(-90);
    longWall_sprite6.setPosition(1200, 315);
    longWall_sprite6.setScale(0.2f, 0.2f);
    walls.push_back(longWall_sprite6);

    Sprite longWall_sprite7(longWall_texture);
    longWall_sprite7.setPosition(1200, 318);
    longWall_sprite7.setScale(0.2f, 0.2f);
    walls.push_back(longWall_sprite7);

    Sprite longWall_sprite8(longWall_texture);
    longWall_sprite8.rotate(90);
    longWall_sprite8.setPosition(1200, 500);
    longWall_sprite8.setScale(0.2f, 0.2f);
    walls.push_back(longWall_sprite8);




   

    Sprite shortWall_sprite(shortWall_texture);
    shortWall_sprite.setPosition(800, 50);
    shortWall_sprite.setScale(0.2f, 0.2f);
    walls.push_back(shortWall_sprite);

    Sprite shortWall2_sprite(shortWall_texture);
    shortWall2_sprite.rotate(90);
    shortWall2_sprite.setPosition(859, 168);
    shortWall2_sprite.setScale(0.2f, 0.2f);
    walls.push_back(shortWall2_sprite);

    Sprite shortWall3_sprite(shortWall_texture);
    shortWall3_sprite.setPosition(800, 350);
    shortWall3_sprite.setScale(0.2f, 0.2f);
    walls.push_back(shortWall3_sprite);

    

    Sprite block1_sprite(block1_texture);
    block1_sprite.setPosition(500, 240);
    block1_sprite.setScale(0.2f, 0.2f);
    blocks.push_back(block1_sprite);

    

    Sprite block21_sprite(block2_texture);
    block21_sprite.setPosition(1200, 90);
    block21_sprite.setScale(0.2f, 0.2f);
    blocks.push_back(block21_sprite);

    Sprite block22_sprite(block2_texture);
    block22_sprite.setPosition(200, 50);
    block22_sprite.setScale(0.2f, 0.2f);
    blocks.push_back(block22_sprite);

    Sprite block23_sprite(block2_texture);
    block23_sprite.setPosition(1030, 670);
    block23_sprite.setScale(0.2f, 0.2f);
    blocks.push_back(block23_sprite);

    Sprite block24_sprite(block2_texture);
    block24_sprite.setPosition(145, 678);
    block24_sprite.setScale(0.2f, 0.2f);
    blocks.push_back(block24_sprite);

    //cout << block2_sprite.getGlobalBounds().height << " " << block2_sprite.getGlobalBounds().width << endl;
    
}

void Map::initializeMap2()
{
    
    
    this->setTexture(background_texture);
    //this->setTextureRect(IntRect(0, 200, 1600, 900));
    this->setScale(2, 2);
    this->setPosition(0, 0);

    // 1600 x 900
    Sprite longWall_sprite1(longWall_texture);
    longWall_sprite1.setPosition(500, 200);
    longWall_sprite1.setScale(0.5f, 0.5f);
    walls.push_back(longWall_sprite1);



    Sprite longWall_sprite3(longWall_texture);
    longWall_sprite3.rotate(90);
    longWall_sprite3.setPosition(430, 280);
    longWall_sprite3.setScale(0.5f, 0.5f);
    walls.push_back(longWall_sprite3);

    Sprite longWall_sprite2(longWall_texture);
    longWall_sprite2.rotate(-90);
    longWall_sprite2.setPosition(1180, 846);
    longWall_sprite2.setScale(0.5f, 0.5f);
    walls.push_back(longWall_sprite2);

    Sprite longWall_sprite4(longWall_texture);
    longWall_sprite4.setPosition(456, 789);
    longWall_sprite4.setScale(0.5f, 0.5f);
    walls.push_back(longWall_sprite4);



    Sprite longWall_sprite5(longWall_texture);
    longWall_sprite5.setPosition(1200, 400);
    longWall_sprite5.setScale(0.5f, 0.5f);
    walls.push_back(longWall_sprite5);

    Sprite longWall_sprite6(longWall_texture);
    longWall_sprite6.rotate(-90);
    longWall_sprite6.setPosition(860, 315);
    longWall_sprite6.setScale(0.5f, 0.5f);
    walls.push_back(longWall_sprite6);

    Sprite longWall_sprite7(longWall_texture);
    longWall_sprite7.setPosition(656, 685);
    longWall_sprite7.setScale(0.5f, 0.5f);
    walls.push_back(longWall_sprite7);

    Sprite longWall_sprite8(longWall_texture);
    longWall_sprite8.rotate(90);
    longWall_sprite8.setPosition(1500, 300);
    longWall_sprite8.setScale(0.5f, 0.5f);
    walls.push_back(longWall_sprite8);



    //6 blok 8 sciana


    Sprite shortWall_sprite(shortWall_texture);
    shortWall_sprite.setPosition(200, 350);
    shortWall_sprite.setScale(0.5f, 0.5f);
    walls.push_back(shortWall_sprite);

    Sprite shortWall2_sprite(shortWall_texture);
    shortWall2_sprite.rotate(90);
    shortWall2_sprite.setPosition(759, 568);
    shortWall2_sprite.setScale(0.5f, 0.5f);
    walls.push_back(shortWall2_sprite);

    Sprite shortWall3_sprite(shortWall_texture);
    shortWall3_sprite.setPosition(500, 450);
    shortWall3_sprite.setScale(0.5f, 0.5f);
    walls.push_back(shortWall3_sprite);



    Sprite block1_sprite(block1_texture);
    block1_sprite.setPosition(650, 440);
    block1_sprite.setScale(0.5f, 0.5f);
    blocks.push_back(block1_sprite);



    Sprite block21_sprite(block2_texture);
    block21_sprite.setPosition(1200, 90);
    block21_sprite.setScale(0.5f, 0.5f);
    blocks.push_back(block21_sprite);

    Sprite block22_sprite(block2_texture);
    block22_sprite.setPosition(200, 50);
    block22_sprite.setScale(0.5f, 0.5f);
    blocks.push_back(block22_sprite);

    Sprite block23_sprite(block2_texture);
    block23_sprite.setPosition(1030, 670);
    block23_sprite.setScale(0.5f, 0.5f);
    blocks.push_back(block23_sprite);

    Sprite block24_sprite(block2_texture);
    block24_sprite.setPosition(145, 678);
    block24_sprite.setScale(0.5f, 0.5f);
    blocks.push_back(block24_sprite);
}

void Map::initializeMap3()
{
    

    this->setTexture(background_texture);
    //this->setTextureRect(IntRect(0, 200, 1600, 900));
    this->setScale(2, 2);
    this->setPosition(0, 0);

    // 1600 x 900
    Sprite longWall_sprite1(longWall_texture);
    longWall_sprite1.setPosition(750, 150);
    longWall_sprite1.setScale(0.5f, 0.5f);
    walls.push_back(longWall_sprite1);

    Sprite longWall_sprite2(longWall_texture);
    longWall_sprite2.rotate(-90);
    longWall_sprite2.setPosition(1180, 746);
    longWall_sprite2.setScale(0.5f, 0.5f);
    walls.push_back(longWall_sprite2);
    
    Sprite longWall_sprite7(longWall_texture);
    longWall_sprite7.setPosition(256, 485);
    longWall_sprite7.setScale(0.5f, 0.5f);
    walls.push_back(longWall_sprite7);

    Sprite longWall_sprite8(longWall_texture);
    longWall_sprite8.rotate(90);
    longWall_sprite8.setPosition(1550, 200);
    longWall_sprite8.setScale(0.5f, 0.5f);
    walls.push_back(longWall_sprite8);



    //6 blok 8 sciana


    Sprite shortWall_sprite(shortWall_texture);
    shortWall_sprite.setPosition(250, 150);
    shortWall_sprite.setScale(0.5f, 0.5f);
    walls.push_back(shortWall_sprite);

    Sprite shortWall2_sprite(shortWall_texture);
    shortWall2_sprite.rotate(90);
    shortWall2_sprite.setPosition(559, 768);
    shortWall2_sprite.setScale(0.5f, 0.5f);
    walls.push_back(shortWall2_sprite);

    Sprite shortWall3_sprite(shortWall_texture);
    shortWall3_sprite.rotate(90);
    shortWall3_sprite.setPosition(1000, 350);
    shortWall3_sprite.setScale(0.5f, 0.5f);
    walls.push_back(shortWall3_sprite);

    Sprite shortWall4_sprite(shortWall_texture);
    //shortWall4_sprite.rotate(90);
    shortWall4_sprite.setPosition(666, 666);
    shortWall4_sprite.setScale(0.5f, 0.5f);
    walls.push_back(shortWall4_sprite);



    Sprite block1_sprite(block1_texture);
    block1_sprite.setPosition(650, 440);
    block1_sprite.setScale(0.7f, 0.7f);
    blocks.push_back(block1_sprite);



    Sprite block21_sprite(block1_texture);
    block21_sprite.setPosition(1200, 90);
    block21_sprite.setScale(0.7f, 0.7f);
    blocks.push_back(block21_sprite);

    Sprite block22_sprite(block1_texture);
    block22_sprite.setPosition(200, 50);
    block22_sprite.setScale(0.7f, 0.7f);
    blocks.push_back(block22_sprite);

    Sprite block23_sprite(block2_texture);
    block23_sprite.setPosition(1030, 670);
    block23_sprite.setScale(0.7f, 0.7f);
    blocks.push_back(block23_sprite);

    Sprite block24_sprite(block2_texture);
    block24_sprite.setPosition(145, 678);
    block24_sprite.setScale(0.7f, 0.7f);
    blocks.push_back(block24_sprite);
}

void Map::drawGraphics(RenderWindow& window)
{
    // Rysowanie t³a
    window.draw(*this);

    // Rysowanie œcian
    for (const auto& wall : walls)
    {
        window.draw(wall);
    }

    // Rysowanie bloków
    for (const auto& block : blocks)
    {
        window.draw(block);
    }
}

void Map::drawGameOver(RenderWindow& window, RectangleShape& resultButton, vector<unique_ptr<EnemyManager>>& enemies)
{
    window.draw(*this);
    resultButton.setPosition(320, 350);
    resultButton.setFillColor(Color::Transparent);
    resultButton.setSize(Vector2f(100, 40));
    window.draw(resultButton);
    for (auto& enemy : enemies)
    {
        
            
            
            enemy.reset(); // Usuń obiekt przeciwnika
            break; // Wyjdź z wewnętrznej pętli, ponieważ iterator został zmieniony
        
    }
    cout << enemies.size() << endl;
    enemies.erase(remove(enemies.begin(), enemies.end(), nullptr), enemies.end());
}

void Map::drawGGWP(RenderWindow& window, RectangleShape& resultButton)
{
    
    window.draw(*this);
    resultButton.setPosition(250, 450);
    resultButton.setFillColor(Color::Transparent);
    resultButton.setSize(Vector2f(320,110));
    window.draw(resultButton);

}

const vector<Sprite>& Map::getWalls() const {
    return walls;
}

const vector<Sprite>& Map::getBlocks() const {
    return blocks;
}


