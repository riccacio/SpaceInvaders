#ifndef SHIP_H
#define SHIP_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "../headers/Bullet.h"

using namespace sf;

class Ship{
private:
    std::vector<Bullet> bullets = {};
    Sprite sprShip;
    Sprite sprBullet;
    Texture texShip;
    Texture texBullet;
    //Rect hitBox;
    int currentPower;
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
    void update();
    void updateBullets();
    void setBullets(std::vector<Bullet> &bullets);
    void shoot();
};

#endif //SHIP_H
