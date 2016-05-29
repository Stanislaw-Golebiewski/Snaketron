#include "headers/logicEngine.h"

using namespace std;

logicEngine::logicEngine(){ srand((unsigned) time(NULL)); power_up_timer = rand()%150 + 200;}

void logicEngine::start(vector<Pickable*> &objects, Level &level, vector<Player> &players)
{
    for(int i = 0; i < (int)objects.size(); i++){cout << objects[i]->getX() << " " << objects[i]->getY() << endl;}
    if(power_up_timer == 0)
    {
        power_up_timer = rand()%300 + 200;
        pickNewPowerUp(objects, new_empty_field(level, players));
    }
    else power_up_timer--;
    for(int i = 0; i < (int)players.size(); i++)players[i].move();
    for(int i = 0; i < (int)players.size(); i++)
    {
        if(snake_picked(objects[0],players[i]))
        {
            objects[0]->pick(new_empty_field(level,players),players[i]);
        }
    }
    for(int i = 0; i < (int)players.size(); i++)
    {
        if(!players[i].isAlive())continue;
        if(snake_collided(level,players,i)){cout << "Snake " << i << " collided" << endl; players[i].kill();}
    }

}

sf::Vector2f logicEngine::new_empty_field(Level level, vector<Player> &players)
{
    int a = 100;
    bool found = false;
    int x,y;
    while(!found)
    {
        if(!a)break;
        else a--;
        x = rand()%level.getWidth();
        y = rand()%level.getHeight();
        found = true;
    }
    sf::Vector2f V(x,y);
    return V;
}

bool logicEngine::snake_picked(Pickable *p ,Player snake)
{
    for(int i = 0; i < (int)snake.snake.size(); i++)
    {
        if(p->getX() == snake.getX() && p->getY() == snake.getY()) return true;
    }
    return false;
}

bool logicEngine::snake_collided(Level level, vector<Player> players, short
                                 id)
{
    short playerX = players[id].getX();
    short playerY = players[id].getY();
    //first of all we check collision with external walls
    if(playerX < 0 || playerX >= level.getWidth() || playerY < 0 || playerY >= level.getHeight()) return true;
    //then we should check collisions witch another snake or snakes
    for(int i = 0; i < (int)players.size(); i++)
    {
        if(i == id)continue;
        for(int j = 0; j < (int)players[i].snake.size(); j++)
        {
            if(playerX == (int)players[i].snake[j].x && playerY == (int)players[i].snake[j].y) return true;
        }
    }
    return false;
}

void logicEngine::pickNewPowerUp(vector<Pickable*> &objects, sf::Vector2f v)
{
    Pickable *p;
    objects.push_back(p);
    objects[objects.size()-1] = new PowerUp(INVISIBLE);
    objects[objects.size()-1]->setX(v.x);
    objects[objects.size()-1]->setY(v.y);
}
