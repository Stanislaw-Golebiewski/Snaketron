#include "headers/Level.h"

Level::Level(sf::Vector2f v)
{
    tile_width = tile_height = 0;
    map_width = map_height = 0;
    size_of_window = v;
}

void Level::loadFromFile(string file_name)
{
    fstream file;
    short width, height;
    string full_name = "maps/"+file_name;
    file.open(full_name.c_str(), ios::in);
    if(!file.is_open())
    {
        cout << "map-log: loading file is unsuccesfull :( " << endl;
        return;
    }
    else cout << "map-log: map loaded" << endl;
    file >> width >> height;
    this->map_width = width;
    this->map_height = height;
    tile_width = size_of_window.x / width;
    tile_height = size_of_window.y / height;
    file.close();
}

short Level::getWidth()
{
    return map_width;
}

short Level::getHeight()
{
    return map_height;
}

sf::Vector2f Level::getTileSize()
{
    sf::Vector2f v(tile_width, tile_height);
    return v;
}

void Level::printLog()
{
    cerr << "*****Level log****\nmap size: " << map_width << " x " << map_height << "\ntile size: " << tile_width << " x " <<  tile_height << endl;
}

void Level::update(vector<sf::Vector2f> player)
{
}
