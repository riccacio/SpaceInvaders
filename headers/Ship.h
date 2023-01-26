#ifndef SHIP_H
#define SHIP_H
#include <SFML/Graphics.hpp>
#include "../headers/Bullet.h"

using namespace sf;

class Ship{
private:
    std::shared_ptr<std::vector<Bullet>> bullets;
    Sprite sprShip;
    Sprite sprExpShip1;
    Sprite sprExpShip2;
    Texture texShip;
    Texture texExpShip1;
    Texture texExpShip2;
    Texture texShipShot;
    Clock clock;
    Time time;

    int currentPower;
    bool change;
    bool dead;
    bool hitted;
    bool invincible;
public:
    //constructor & destructor
    Ship(Vector2f pos);
    ~Ship() = default;

    //functions
    void draw(RenderTarget& target);
    void update();
    void updateBullets();
    void shoot();
    void changeSprite();

    //getter & setter
    Sprite& getSprShip();
    Texture& getTexShip();
    Vector2f getPosition();
    Time& getTime();
    IntRect getHitBox();
    std::shared_ptr<std::vector<Bullet>> getBullets();
    int getCurrentPower();
    bool isHitted();
    bool isInvincible();

    void setPosition(Vector2f pos);
    void setPositionExp1(Vector2f pos);
    void setPositionExp2(Vector2f pos);
    void setTime();
    void setTimeRestart();
    void setDead(bool dead);
    void setHitted(bool hitted);
    void setInvincible(bool invincible);
};

#endif //SHIP_H
