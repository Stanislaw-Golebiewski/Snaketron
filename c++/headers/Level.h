#ifndef LEVEL_H
#define LEVEL_H
#include <iostream>
#include <fstream>
#include <vector>
#include <SFML/Graphics.hpp>
using namespace std;

class Level
{
public:
    Level(sf::Vector2f);
    short getWidth();
    short getHeight();
    sf::Vector2f getTileSize();
    //bool **field;
    void loadFromFile(string);
    void printLog();
    void update(vector<sf::Vector2f>);
private:
    sf::Vector2f size_of_window;
    short map_width, map_height;
    short tile_width, tile_height;
};
#endif // LEVEL_H
