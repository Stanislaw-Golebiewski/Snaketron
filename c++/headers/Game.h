#ifndef _Game_h
#define _Game_h
#include "Level.h"
#include "renderEngine.h"
#include "Drawable.h"
#include "logicEngine.h"
#include "Menu.h"
#include <vector>


using namespace sf;

class Game
{
public:
    Game(Vector2f v);
    ~Game();
    void start();//game manager
    void game();//game loop
    void menu();//menu loop

    enum State {MENU, GAME, PAUSE, WON, END};
    State game_state;

    void input();

    renderEngine render;
    logicEngine logic;
    Event event;
    Level level;
    Menu men;

    void setPlayers(short);

    Vector2f window_size;

    vector<Player> players;
    vector<Pickable*> objects;
};
#endif // _Game_H
