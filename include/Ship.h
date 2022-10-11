#ifndef SHIP_H
#define SHIP_H
//#include "../include/Game.h"
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;

class Ship{
private:
    static const int WIDTH;
    static const int HEIGHT;
    int x;
    int y;
    int direction;// right=1, left=-1

    //Rect hitBox;
    Texture texShip;
    Sprite sprShip;
public:
    Ship();
    ~Ship() = default;
    Sprite &getSprShip();
    void setTexShip(const Texture &texShip);
    int getX() const;
    int getY() const;//TODO delete
    void setX(int x);
    void setY(int y);//TODO delete
    int getDirection() const;
    void setDirection(int direction);
};


#endif //SHIP_H
