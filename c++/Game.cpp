#include "headers/Game.h"
#include <iostream>

using namespace std;
using namespace sf;

Game::Game(Vector2f v):render(v), level(v), men(v)
{
    level.loadFromFile("basic_map.txt");
    game_state = MENU;
    window_size = v;
    Pickable *p = new Food;
    objects.push_back(p);
}

Game::~Game()
{
    players.clear();
}

void Game::input()
{
    switch (game_state)
    {
        case GAME:
            while (render.window.pollEvent(event)) if (event.type == sf::Event::Closed) {render.window.close(); game_state = END;}
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {render.window.close();game_state = END;}
            for(int i = 0; i < (int)players.size(); i++)players[i].update();
            break;
        case MENU:
            while (render.window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed) {render.window.close(); game_state = END;}
                if (event.type == sf::Event::KeyPressed)
                {
                    if(event.key.code == sf::Keyboard::Right) men.MoveUp();
                    if(event.key.code == sf::Keyboard::Left) men.MoveDown();
                }
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {render.window.close();game_state = END;}
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) game_state = GAME;
            break;
        default:
            game_state = END;
            break;
    }
}

void Game::setPlayers(short count)
{
    Player p1(Vector2f(0,level.getHeight()/2),Vector2f(1,level.getHeight()/2),Vector2f(2,level.getHeight()/2),Player::RIGHT);
    Player p2(Vector2f(level.getWidth()-1,level.getHeight()/2),Vector2f(level.getWidth()-2,level.getHeight()/2),Vector2f(level.getWidth()-3,level.getHeight()/2),Player::LEFT);
    Player p3(Vector2f(level.getWidth()/2,0),Vector2f(level.getWidth()/2,1),Vector2f(level.getWidth()/2,2),Player::DOWN);
    Player p4(Vector2f(level.getWidth()/2,level.getHeight()-1),Vector2f(level.getWidth()/2,level.getHeight()-2),Vector2f(level.getWidth()/2,level.getHeight()-3),Player::UP);

    for(int i = 0; i < count; i++)
    {
        switch(i)
        {
        case 0:
            p1.setKeys(Keyboard::W,Keyboard::S,Keyboard::A,Keyboard::D);
            p1.setColor(Color::Green);
            players.push_back(p1);
            break;
        case 1:
            p2.setKeys(Keyboard::Up,Keyboard::Down,Keyboard::Left,Keyboard::Right);
            p2.setColor(Color::Blue);
            players.push_back(p2);
            break;
        case 2:
            p3.setKeys(Keyboard::I,Keyboard::K,Keyboard::J,Keyboard::L);
            p3.setColor(Color::Magenta);
            players.push_back(p3);
            break;
        case 3:
            p4.setKeys(Keyboard::Num8,Keyboard::Num5,Keyboard::Num4,Keyboard::Num6);
            p4
            .setColor(Color::Cyan);
            players.push_back(p4);
            break;
        }
    }

}
