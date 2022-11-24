#ifndef SHIP_H
#define SHIP_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "../headers/Animation.h"

using namespace sf;

class Ship{
private:
    static const int WIDTH = 115;
    static const int HEIGHT = 50;
    float x;
    float y;

    //std::vector<Bullet> bullets;

    sf::Sprite bullet_sprite;
    sf::Sprite sprite;

    sf::Texture bullet_texture;
    sf::Texture texture;

    int direction;// right=1, left=-1
    float speed;
    int shotFrequency;

    //Rect hitBox;
    Texture texShip;
    Sprite sprShip;

public:
    Ship();
    ~Ship() = default;
    Sprite &getSprShip();
    void setTexShip(const Texture &texShip);
    float getX() const;
    int getShotFrequency() const;
    float getY() const;
    float getSpeed() const;
    void setX(float x);
    int getDirection() const;
    void setDirection(int direction);
    static const int getWidth();
    static const int getHeight();
    void update();
};

#endif //SHIP_H
