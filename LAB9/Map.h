#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

class Map : public Sprite
{
public:
    Map(const string& backgroundFile, const string& longWallFile, const string& shortWallFile, const string& block1File, const string& block2File);

    void drawGraphics(RenderWindow& window);
    const vector<Sprite>& getWalls() const;

private:
    Texture background_texture;
    Texture longWall_texture;
    Texture shortWall_texture;
    Texture block1_texture;
    Texture block2_texture;

    vector<Sprite> walls;
    vector<Sprite> blocks;

    void initializeMap();

};
