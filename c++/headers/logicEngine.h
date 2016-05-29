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
    logicEngine();
    void start(vector<Pickable*>&, Level&, vector<Player>&);
    sf::Vector2f new_empty_field(Level, vector<Player>&);//returns random empty tile
    bool snake_picked(Pickable*,Player);//Is food picked by this player?
    bool snake_collided(Level,vector<Player>, short i);//i - position in vector of snake with collision we will check
private:
    void pickNewPowerUp(vector<Pickable*>&, sf::Vector2f);
    short power_up_timer;
};

#endif // _logicEngine_H
