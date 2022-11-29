#ifndef SHIP_H
#define SHIP_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "../headers/Bullet.h"

using namespace sf;

class Ship{
private:

    std::vector<Bullet> bullet = {};
    Sprite sprBullet;
    Texture texBullet;

    int currentPower;

    //Rect hitBox;
    Texture texShip;
    Sprite sprShip;

public:
    Ship(Vector2f pos);
    ~Ship() = default;
    Sprite &getSprShip();
    Texture &getTexShip();
    void setTexShip(const Texture &texShip);
    Vector2f getPosition();
    void setPosition(Vector2f pos);
    void reset();
    void draw(RenderTarget& target);
    int getCurrentPower();
    void shoot();
    void update();
    void updateBullets();
};

#endif //SHIP_H
