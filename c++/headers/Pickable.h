#ifndef PICKABLE_H
#define PICKABLE_H
#include "Drawable.h"

class Pickable: public Renderable
{
public:
    Pickable();
    virtual void pick(sf::Vector2f, Player&) = 0;
};

class Food: public Pickable
{
public:
    Food();
    ~Food();
    void draw(sf::RenderWindow&, Level);
    void pick(sf::Vector2f, Player&);
};

class PowerUp:public Pickable
{
public:
    PowerUp(Type);
    ~PowerUp();
    void draw(sf::RenderWindow&, Level);
    void pick(sf::Vector2f, Player&);
    void power_up(vector<Player>&);
private:
    Type type;
    sf::Texture texture;
};

#endif // PICKABLE_H
