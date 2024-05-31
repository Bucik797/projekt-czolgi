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
        this->setScale(2, 2);
        this->setPosition(0, 0);
    }

    initializeMap();
}

void Map::initializeMap()
{
    // Tworzenie sprite'ów œcian i bloków
    Sprite longWall_sprite1(longWall_texture);
    longWall_sprite1.setPosition(100, 50);
    longWall_sprite1.setScale(0.5f, 0.5f);
    walls.push_back(longWall_sprite1);

    Sprite longWall_sprite2(longWall_texture);
    longWall_sprite2.setPosition(100, 400);
    longWall_sprite2.setScale(0.5f, 0.5f);
    walls.push_back(longWall_sprite2);

    Sprite shortWall_sprite(shortWall_texture);
    shortWall_sprite.setPosition(800, 50);
    shortWall_sprite.setScale(0.5f, 0.5f);
    walls.push_back(shortWall_sprite);

    Sprite block1_sprite(block1_texture);
    block1_sprite.setPosition(500, 300);
    block1_sprite.setScale(0.5f, 0.5f);
    blocks.push_back(block1_sprite);

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

const vector<Sprite>& Map::getWalls() const {
    return walls;
}

const vector<Sprite>& Map::getBlocks() const {
    return blocks;
}

