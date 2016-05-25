#ifndef _renderEngine_h
#define _renderEngine_h
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Pickable.h"
#include "Level.h"
#include "Menu.h"
#include <vector>

class renderEngine
{
public:
    sf::RenderWindow window;

    renderEngine(sf::Vector2f);
    void start(Food,Level,vector<Player>);
    void menu(Menu);
};
#endif // _renderEngine_H
