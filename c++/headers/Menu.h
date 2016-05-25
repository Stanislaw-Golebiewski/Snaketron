#ifndef MENU_H
#define MENU_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#define MAX_MENU_ITEMS 5

class Menu
{
public:
    Menu(sf::Vector2f);
    ~Menu();

    void MoveUp();
    void MoveDown();
    void draw(sf::RenderWindow &window);
    sf::Text text[MAX_MENU_ITEMS+1];
    short getActive();

private:
    sf::Font font;
    short CurrentActive;

};
#endif // MENU_H
