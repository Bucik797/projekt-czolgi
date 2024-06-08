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
    else
    {
        // Ustawienie tekstury t³a
        this->setTexture(background_texture);
        
        this->setScale(1.5,1.5);
        this->setPosition(100, 0);
    }

    initializeMap();
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

void Map::initializeMap()
{
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




   // cout << longWall_sprite1.getGlobalBounds().height << " " << longWall_sprite1.getGlobalBounds().width << endl;

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

    //cout << shortWall_sprite.getGlobalBounds().height << " " << shortWall_sprite.getGlobalBounds().width << endl;

    Sprite block1_sprite(block1_texture);
    block1_sprite.setPosition(500, 240);
    block1_sprite.setScale(0.2f, 0.2f);
    blocks.push_back(block1_sprite);

    //cout << block1_sprite.getGlobalBounds().height << " " << block1_sprite.getGlobalBounds().width << endl;

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

void Map::drawGameOver(RenderWindow& window, RectangleShape& resultButton)
{
    window.draw(*this);
    resultButton.setPosition(320, 350);
    resultButton.setFillColor(Color::Transparent);
    resultButton.setSize(Vector2f(100, 40));
    window.draw(resultButton);
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


