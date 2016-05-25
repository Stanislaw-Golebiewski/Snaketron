#ifndef PICKABLE_H
#define PICKABLE_H
#include "Drawable.h"

class Pickable: public Renderable
{
public:
    Pickable();
    virtual void pick(sf::Vector2f) = 0;
};

class Food: public Pickable
{
public:
    Food();
    ~Food();
    void draw(sf::RenderWindow&, Level);
    void pick(sf::Vector2f);
};

class PowerUp:public Pickable
{

};
#endif // PICKABLE_H
