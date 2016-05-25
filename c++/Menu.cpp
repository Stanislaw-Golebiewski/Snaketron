#include "headers/Menu.h"
using namespace sf;
Menu::Menu(sf::Vector2f v)
{
    if(!font.loadFromFile("fonts/prstart.ttf"))
    {
        std::cout << "menu-log: there is not font" << std::endl;
    }
    else
    {
       std::cout << "menu-log: font ok" << std::endl;
    }
    text[0].setFont(font);
    text[0].setColor(sf::Color::Red);
    text[0].setString("1");
    text[0].setPosition(sf::Vector2f(v.x/5*1 - text[0].getLocalBounds().width/2,v.y/5));

    text[1].setFont(font);
    text[1].setColor(sf::Color::White);
    text[1].setString("2");
    text[1].setPosition(sf::Vector2f(v.x/5*2 - text[1].getLocalBounds().width/2,v.y/5));

    text[2].setFont(font);
    text[2].setColor(sf::Color::White);
    text[2].setString("3");
    text[2].setPosition(sf::Vector2f(v.x/5*3 - text[2].getLocalBounds().width/2,v.y/5));

    text[3].setFont(font);
    text[3].setColor(sf::Color::White);
    text[3].setString("4");
    text[3].setPosition(sf::Vector2f(v.x/5*4 - text[3].getLocalBounds().width/2,v.y/5));

    text[4].setFont(font);
    text[4].setColor(sf::Color::Yellow);
    text[4].setString("Press SPACE to start");
    text[4].setPosition(sf::Vector2f(v.x/2 - text[4].getLocalBounds().width/2,v.y/2));

    CurrentActive = 0;
}

Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow &window)
{
    for(int i = 0; i < MAX_MENU_ITEMS+1; i++) window.draw(text[i]);
}

void Menu::MoveDown()
{
    if(CurrentActive > 0)
    {
        text[CurrentActive].setColor(sf::Color::White);
        text[CurrentActive-1].setColor(sf::Color::Red);
        CurrentActive--;
    }
}

void Menu::MoveUp()
{
    if(CurrentActive < 3)
    {
        text[CurrentActive].setColor(sf::Color::White);
        text[CurrentActive+1].setColor(sf::Color::Red);
        CurrentActive++;
    }
}

short Menu::getActive(){ return CurrentActive;}
