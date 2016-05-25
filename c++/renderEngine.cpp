#include "headers/renderEngine.h"

renderEngine::renderEngine(sf::Vector2f v)
{
    window.setFramerateLimit(4);
    window.create(sf::VideoMode(v.x,v.y),"Snake");
    window.clear(sf::Color(255,0,0));
    //window.setMouseCursorVisible(false);
}

void renderEngine::start(Food food, Level level,vector<Player> players)
{
    window.setFramerateLimit(12);
    window.clear(sf::Color(0,0,0));
    food.draw(window, level);
    for(int i = 0; i < (int)players.size(); i++)players[i].draw(window, level);
    window.display();
}

void renderEngine::menu(Menu menu)
{
    window.setFramerateLimit(10);
    window.clear(sf::Color(0,0,0));
    menu.draw(window);
    window.display();
}
