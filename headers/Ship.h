#ifndef SHIP_H
#define SHIP_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "../headers/Bullet.h"

using namespace sf;

class Ship{
private:
    const float WIDTH = 115;
    const float HEIGHT = 50;

    std::unique_ptr<Bullet> bullet;
    Sprite bullet_sprite;
    Sprite sprBullet;

    Texture bullet_texture;
    Texture texBullet;

    int currentPower;

    //Rect hitBox;
    Texture texShip;
    Sprite sprShip;

public:
    Ship(Vector2f pos);
    ~Ship() = default;
    Sprite &getSprShip();
    void setTexShip(const Texture &texShip);
    Vector2f getPosition();
    void setPosition(Vector2f pos);
    float getWidth() const;
    float getHeight() const;
    void reset();
    void update();
    int getCurrentPower();
};

#endif //SHIP_H
