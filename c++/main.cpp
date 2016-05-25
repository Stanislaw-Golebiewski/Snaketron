#include "headers/Game.h"

int main()
{
    sf::Vector2f window_size(800,800);
    Game game(window_size);
    game.start();
    return 0;
}
