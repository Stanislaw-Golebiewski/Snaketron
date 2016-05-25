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

    void MoveUp();//navigate through menu
    void MoveDown();//
    void draw(sf::RenderWindow &window);
    sf::Text text[MAX_MENU_ITEMS+1];//all text objects witch will be display on menu screen
    short getActive();//returns active (highlighted) element

private:
    sf::Font font;
    short CurrentActive;

};
#endif // MENU_H
