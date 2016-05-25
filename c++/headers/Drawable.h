#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Level.h"
#include <vector>

using namespace std;

class Renderable
{
public:
    Renderable();
    Renderable(short, short);
    short getX();
    short getY();
    void setX(short);
    void setY(short);
    virtual void draw(sf::RenderWindow&, Level) = 0;
private:
    short x,y;
};

class Player: public Renderable
{
public:
    enum Direction {UP,DOWN,RIGHT,LEFT};//snake movement direction
    Player();
    Player(sf::Vector2f,sf::Vector2f,sf::Vector2f,Direction);
    ~Player();
    void update();// updates direction, base in input
    void move();
    void draw(sf::RenderWindow&, Level);
    void kill();
    void pick_food();//picked food setter
    void setKeys(sf::Keyboard::Key,sf::Keyboard::Key, sf::Keyboard::Key, sf::Keyboard::Key);//sets keys with are used to control snake
    bool isAlive();//alive getter
    void setColor(sf::Color);
    vector<sf::Vector2f> snake;
private:
    bool alive, picked_food;
    short length;
    Direction dir;
    sf::Keyboard::Key up,down,right,left;
    sf::Color color;
};

#endif // DRAWABLE_H
