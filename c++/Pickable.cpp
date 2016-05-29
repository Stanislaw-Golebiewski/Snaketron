#include "headers/Pickable.h"

Pickable::Pickable():Renderable::Renderable(0,0){}

Food::Food():Pickable::Pickable(){}
Food::~Food(){}
void Food::draw(sf::RenderWindow &window, Level level)
{
    sf::RectangleShape food;
    food.setSize(sf::Vector2f(level.getTileSize().x,level.getTileSize().y));
    food.setPosition(getX()*level.getTileSize().x,getY()*level.getTileSize().y);
    food.setFillColor(sf::Color::Yellow);
    window.draw(food);
}
void Food::pick(sf::Vector2f v, Player &player)
{
    player.pick_food();
    setX(v.x); setY(v.y);
}

PowerUp::PowerUp(Type t)
{
    type = t;
    switch (type)
    {
    case TIME:
        break;
    case INVISIBLE:
        break;
    case GROW:
        break;
    case CHANGE:
        break;
    }
}

PowerUp::~PowerUp(){};

void PowerUp::draw(sf::RenderWindow &window, Level level)
{
    sf::CircleShape circle;
    circle.setRadius(level.getTileSize().x/2);
    circle.setPosition(getX()*level.getTileSize().x, getY()*level.getTileSize().y);
    circle.setFillColor(sf::Color(0,50,100));
    window.draw(circle);
}

void PowerUp::pick(sf::Vector2f v, Player &player)
{
    switch (type)
    {
    case TIME:
        break;
    case INVISIBLE:
        break;
    case GROW:
        break;
    case CHANGE:
        break;
    }
}
