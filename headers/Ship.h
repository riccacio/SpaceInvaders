#ifndef SHIP_H
#define SHIP_H
#include <SFML/Graphics.hpp>
#include "../headers/Bullet.h"

using namespace sf;

class Ship{
private:
    std::shared_ptr<std::vector<Bullet>> bullets;
    Sprite sprShip;
    Sprite sprShip3;
    Sprite sprShipShield;
    Sprite sprExpShip1;
    Sprite sprExpShip2;
    Texture texShip;
    Texture texShip3;
    Texture texShipShield;
    Texture texExpShip1;
    Texture texExpShip2;
    Texture texShipShot;
    Clock clock;
    Time time;

    /*
     * normal: -1
     * shield: 0
     * fast reloading: 1
     * 3 bullets: 2
     * mirrored controls: 3
     */
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
    Sprite& getSprShip3();
    Sprite& getSprShipShield();
    Texture& getTexShip();
    Vector2f getPosition();
    Time& getTime();
    IntRect getHitBox();
    std::shared_ptr<std::vector<Bullet>> getBullets();
    int getCurrentPower();
    bool isHitted();
    bool isInvincible();

    void setPosition(Vector2f pos);
    void setPosition3(Vector2f pos);
    void setPositionShield(Vector2f pos);
    void setPositionExp1(Vector2f pos);
    void setPositionExp2(Vector2f pos);
    void setTime();
    void setTimeRestart();
    void setDead(bool dead);
    void setHitted(bool hitted);
    void setInvincible(bool invincible);
    void setCurrentPower(int currentPower);
};

#endif //SHIP_H
