#include "Map.h"

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
        this->setScale(2, 2);
        this->setPosition(0, 0);
    }

    initializeMap();
}

void Map::initializeMap()
{
    // Tworzenie sprite'ów œcian i bloków
    /*
    Sprite longWall_sprite1(longWall_texture);
    longWall_sprite1.setPosition(1510, 0);
    longWall_sprite1.setScale(0.3f, 0.3f);
    walls.push_back(longWall_sprite1);

    Sprite longWall_sprite2(longWall_texture);
    longWall_sprite2.setPosition(1510, 274);
    longWall_sprite2.setScale(0.3f, 0.3f);
    walls.push_back(longWall_sprite2);

    Sprite longWall_sprite3(longWall_texture);
    longWall_sprite3.setPosition(1510, 548);
    longWall_sprite3.setScale(0.3f, 0.3f);
    walls.push_back(longWall_sprite3);

    Sprite longWall_sprite4(longWall_texture);
    longWall_sprite4.setPosition(1510, 822);
    longWall_sprite4.setScale(0.3f, 0.3f);
    walls.push_back(longWall_sprite4);

    Sprite longWall_sprite5(longWall_texture);
    longWall_sprite5.rotate(-90.0f);
    longWall_sprite5.setPosition(1239, 87);
    longWall_sprite5.setScale(0.3f, 0.3f);
    walls.push_back(longWall_sprite5);

    Sprite longWall_sprite6(longWall_texture);
    longWall_sprite6.rotate(-90.0f);
    longWall_sprite6.setPosition(965, 87);
    longWall_sprite6.setScale(0.3f, 0.3f);
    walls.push_back(longWall_sprite6);

    Sprite longWall_sprite7(longWall_texture);
    longWall_sprite7.rotate(-90.0f);
    longWall_sprite7.setPosition(692, 87);
    longWall_sprite7.setScale(0.3f, 0.3f);
    walls.push_back(longWall_sprite7);

    Sprite longWall_sprite8(longWall_texture);
    longWall_sprite8.rotate(-90.0f);
    longWall_sprite8.setPosition(419, 87);
    longWall_sprite8.setScale(0.3f, 0.3f);
    walls.push_back(longWall_sprite8);

    Sprite longWall_sprite9(longWall_texture);
    longWall_sprite9.rotate(-90.0f);
    longWall_sprite9.setPosition(146, 87);
    longWall_sprite9.setScale(0.3f, 0.3f);
    walls.push_back(longWall_sprite9);

    Sprite longWall_sprite10(longWall_texture);
    longWall_sprite10.setPosition(0, 0);
    longWall_sprite10.setScale(0.3f, 0.3f);
    walls.push_back(longWall_sprite10);

    Sprite block2_sprite(block2_texture);
    block2_sprite.setPosition(1400, 500);
    block2_sprite.setScale(0.5f, 0.5f);
    blocks.push_back(block2_sprite);

    Sprite block3_sprite(block1_texture);
    block3_sprite.setPosition(900, 700);
    block3_sprite.setScale(0.5f, 0.5f);
    blocks.push_back(block3_sprite);

    Sprite block4_sprite(block2_texture);
    block4_sprite.setPosition(1200, 200);
    block4_sprite.setScale(0.5f, 0.5f);
    blocks.push_back(block4_sprite);

    */
    
    Sprite longWall_sprite1(longWall_texture);
    longWall_sprite1.setPosition(699, 597);
    longWall_sprite1.setScale(0.3f, 0.3f);
    walls.push_back(longWall_sprite1);

    Sprite longWall_sprite2(longWall_texture);
    longWall_sprite2.setPosition(145, 274);
    longWall_sprite2.setScale(0.3f, 0.3f);
    walls.push_back(longWall_sprite2);

    Sprite longWall_sprite3(longWall_texture);
    longWall_sprite3.rotate(90);
    longWall_sprite3.setPosition(1568, 548);
    longWall_sprite3.setScale(0.3f, 0.3f);
    walls.push_back(longWall_sprite3);
    
    



    //cout << longWall_sprite1.getGlobalBounds().height << " " << longWall_sprite1.getGlobalBounds().width << endl;

    Sprite shortWall_sprite(shortWall_texture);
    shortWall_sprite.setPosition(800, 50);
    shortWall_sprite.setScale(0.3f, 0.3f);
    walls.push_back(shortWall_sprite);
    //cout << shortWall_sprite.getGlobalBounds().height << " " << shortWall_sprite.getGlobalBounds().width << endl;

    Sprite block1_sprite(block1_texture);
    block1_sprite.setPosition(500, 300);
    block1_sprite.setScale(0.3f, 0.3f);
    blocks.push_back(block1_sprite);

    //cout << block1_sprite.getGlobalBounds().height << " " << block1_sprite.getGlobalBounds().width << endl;

    
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

const vector<Sprite>& Map::getWalls() const
{
    return walls;
}

