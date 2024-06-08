#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

class Map : public Sprite
{
public:
    Map(const string& backgroundFile, const string& longWallFile, const string& shortWallFile, const string& block1File, const string& block2File);
    Map(const string& gameoverFile);
    void drawGraphics(RenderWindow& window);
    void drawGameOver(RenderWindow& window, RectangleShape& resultButton);
    void drawGGWP(RenderWindow& window, RectangleShape& resultButton);
    const vector<Sprite>& getWalls() const;

    const vector<Sprite>& getBlocks() const;


private:
    Texture result_texture;
    Texture background_texture;
    Texture longWall_texture;
    Texture shortWall_texture;
    Texture block1_texture;
    Texture block2_texture;

    vector<Sprite> walls;
    vector<Sprite> blocks;

    void initializeMap();

};
