#ifndef SHIP_H
#define SHIP_H
#include <SFML/Graphics.hpp>
#include "../headers/Bullet.h"

using namespace sf;

class Ship{
private:
    std::vector<Bullet> bullets = {};
public:
    const std::vector<Bullet> &getBullets() const;

private:
    Sprite sprShip;
    Texture texShip;
    Texture texShipShot;
    FloatRect ship_hitBox;
    int currentPower;
public:
    Ship(Vector2f pos);
    ~Ship() = default;
    Sprite &getSprShip();
    Texture &getTexShip();
    Vector2f getPosition();
    void setPosition(Vector2f pos);
    void reset();
    void draw(RenderTarget& target);
    int getCurrentPower() const;
    void update();
    void updateBullets();
    void shoot();
};

#endif //SHIP_H
