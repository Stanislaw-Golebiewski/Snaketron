#ifndef Movable_h
#define Movable_h

#include <SFML/Graphics.hpp>
#include <vector>

using namespace sf;
using namespace std;

class Movable
{
public:
    int x,y;
    RectangleShape squere;
    FloatRect get_FloatRect();
    virtual Vector2f check_move();
};
class Player:public Movable
{
public:
    Player();
    float speed;
    bool move_up, move_down, move_left, move_right;

    void aktualizuj();//input for player
    void rusz(Vector2f);
    Vector2f check_move();
    Vector2f get_centre();

    void shoot(Vector2f);
    void destroy();
};

class Bullet:public Movable
{
public:
    Bullet(void);
    int speed;
    int size;
    void update();
    void move(Vector2f, short);
    void add_new(Vector2f,Vector2f);
    void delete_bullet(short);
    void set_bool(short, bool);
    Vector2f get_position(short);
    Vector2f movment_vector(short);
};
#endif // Movable_h


