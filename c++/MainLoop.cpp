#include "headers/Game.h"

using namespace sf;
/*
To do:
-player tiles in vector - DONE
-updating "field" array in logicEngine (Level method) - NO NEEDED?
-picking random empty field method (logicEngine) - NOW IT CAN RESPOWN IN SNAKE <---
-implement pick food logic for snake - DONE
-snake collision (with wall and another snakes), we will check only head collision - DONE
-test 2 - snakes first gameplay IT WORKS!
-upgrade collisions (with prediction) <---
-adding players mechanizm
-test gameplay 2,3,4 snakes
-constant step loop
-add  options manager
-powerups implementation
*/
void Game::start()
{
    while(game_state != END)
    {
        switch (game_state)
        {
        case MENU:
            menu();
            break;
        case GAME:
            game();
            break;
        case PAUSE:
            break;
        case WON:
        break;
        case END:
            break;
        }
    }
}
void Game::game()
{
    while(render.window.isOpen())
    {
        input();
        logic.start(objects, level, players);
        render.start(objects, level, players);
    }
}

void Game::menu()
{
    while(game_state == MENU)
    {
        input();
        render.menu(men);
    }
    setPlayers(men.getActive()+1);
    cout << men.getActive()+1 << endl;
}
