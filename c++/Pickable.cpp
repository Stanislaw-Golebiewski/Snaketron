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
void Food::pick(sf::Vector2f v)
{
    setX(v.x); setY(v.y);
}

