#ifndef _logicEngine_H
#define _logicEngine_H

#include <iostream>
#include <vector>
#include <list>
#include <ctime>
#include <cstdlib>
#include "Pickable.h"

using namespace std;

class logicEngine
{
public:
    void start(Level&, Food&, vector<Player>&);
    sf::Vector2f new_empty_field(Level, vector<Player>&);//returns random empty tile
    bool snake_picked(Food,Player);//Is food picked by this player?
    bool snake_collided(Level,vector<Player>, short i);//i - position in vector of snake with collision we will check
};

#endif // _logicEngine_H
