#include "headers/Drawable.h"

Renderable::Renderable(){}
Renderable::Renderable(short X, short Y)
{
    x = X;
    y = Y;
}
short Renderable::getX(){ return x;}
short Renderable::getY(){ return y;}
void Renderable::setX(short X){ x = X; }
void Renderable::setY(short Y){ y = Y; }

Player::~Player()
{
    snake.clear();
}
Player::Player(sf::Vector2f v1,sf::Vector2f v2,sf::Vector2f v3,Direction d):Renderable::Renderable(v3.x,v3.y)
{
    picked_food = false;
    alive = true;
    color = sf::Color::White;
    snake.push_back(v1);snake.push_back(v2);snake.push_back(v3);
    dir = d;
}
void Player::draw(sf::RenderWindow &window, Level level)
{
    for(int i = 0; i < (int)snake.size(); ++i)
    {
        sf::RectangleShape snake_part;
        snake_part.setSize(sf::Vector2f(level.getTileSize().x - 2,level.getTileSize().y - 2));
        snake_part.setPosition(snake[i].x*level.getTileSize().x + 1,snake[i].y*level.getTileSize().y + 1);
        snake_part.setFillColor(color);
        window.draw(snake_part);
    }
}

void Player::update()
{
    if(sf::Keyboard::isKeyPressed(up))dir = UP;
    if(sf::Keyboard::isKeyPressed(down))dir = DOWN;
    if(sf::Keyboard::isKeyPressed(right))dir = LEFT;
    if(sf::Keyboard::isKeyPressed(left))dir = RIGHT;
}

void Player::move()
{
    if(alive)
    {
        sf::Vector2f v;
        switch (dir)
        {
        case UP:
            v.x = getX();
            v.y = getY()-1;
            break;
        case DOWN:
            v.x = getX();
            v.y = getY()+1;
            break;
        case LEFT:
            v.x = getX()-1;
            v.y = getY();
            break;
        case RIGHT:
            v.x = getX()+1;
            v.y = getY();
            break;
        }
        setX(v.x); setY(v.y);
        snake.push_back(v);
        if(picked_food)picked_food = false;
        else snake.erase(snake.begin());
    }
}
void Player::pick_food(){picked_food = true;}
void Player::kill()
{
    alive = false;
    color = sf::Color::Red;
}
bool Player::isAlive(){ return alive;}

void Player::setKeys(sf::Keyboard::Key UP,sf::Keyboard::Key DOWN, sf::Keyboard::Key RIGHT, sf::Keyboard::Key LEFT)
{
    up = UP;
    down = DOWN;
    right = RIGHT;
    left = LEFT;
}
Player::Player(): Renderable::Renderable(0,0)
{
    snake.push_back(sf::Vector2f(0,0));
    dir = LEFT;
    picked_food = false;
    alive = true;
    color = sf::Color::White;
}
void Player::setColor(sf::Color c){color = c;}
