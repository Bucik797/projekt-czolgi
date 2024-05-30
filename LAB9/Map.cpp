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
}

void Map::drawGraphics(RenderWindow& window)
{
    Sprite longWall_sprite(longWall_texture);
    Sprite shortWall_sprite(shortWall_texture);
    Sprite block1_sprite(block1_texture);
    Sprite block2_sprite(block2_texture);

    // Przyk³adowe pozycje dla sprite'ów
    longWall_sprite.setPosition(100, 100);
    shortWall_sprite.setPosition(200, 200);
    block1_sprite.setPosition(300, 300);
    block2_sprite.setPosition(400, 400);

    // Rysowanie sprite'ów
    window.draw(*this); // Rysowanie t³a
    window.draw(longWall_sprite);
    window.draw(shortWall_sprite);
    window.draw(block1_sprite);
    window.draw(block2_sprite);
}
