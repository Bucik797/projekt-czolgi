#include <SFML/Graphics.hpp>
#include <iostream>
#include "EnemyManager.h"

using namespace sf;
using namespace std;

class Map : public Sprite
{
public:
    Map(const string& backgroundFile, const string& longWallFile, const string& shortWallFile, const string& block1File, const string& block2File, bool c);
    Map(const string& gameoverFile);

    void drawGraphics(RenderWindow& window);
    void drawGameOver(RenderWindow& window, RectangleShape& resultButton, vector<unique_ptr<EnemyManager>>& enemies);
    void drawGGWP(RenderWindow& window, RectangleShape& resultButton);

    void initializeMap1();
    void initializeMap2();
    void initializeMap3();
    void initializeMap4();
    void moveSprites(RenderWindow& window);

    void setCompleted(bool c);
    bool getCompleted();
    void createMovingSprites();

    const vector<Sprite>& getWalls() const;
    const vector<Sprite>& getBlocks() const;
    const vector<Sprite>& getmovingCars() const;

private:

    bool completed;
    Texture result_texture;
    Texture background_texture;
    Texture longWall_texture;
    Texture shortWall_texture;
    Texture block1_texture;
    Texture block2_texture;
    

    vector<Sprite> walls;
    vector<Sprite> blocks;
    vector<Sprite> movingCars;
    
    
    
    
};
