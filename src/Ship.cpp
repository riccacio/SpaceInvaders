#include "../include/Ship.h"
#include <SFML/Graphics.hpp>

Ship::Ship(): speed(10),y(1160) {}

Sprite &Ship::getSprShip() {
    return sprShip;
}
void Ship::setTexShip(const Texture &texShip) {
    Ship::texShip = texShip;
}

float Ship::getX() const {
    return x;
}

float Ship::getY() const {
    return y;
}

float Ship::getSpeed() const {
    return speed;
}

void Ship::setX(float x) {
    Ship::x = x;
}


int Ship::getDirection() const {
    return direction;
}

void Ship::setDirection(int direction) {
    Ship::direction = direction;
}

const int Ship::getWidth(){
    return WIDTH;
}

const int Ship::getHeight() {
    return HEIGHT;
}

