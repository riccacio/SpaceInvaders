#include "../include/Ship.h"
#include <SFML/Graphics.hpp>

Ship::Ship() {}

Sprite &Ship::getSprShip() {
    return sprShip;
}
void Ship::setTexShip(const Texture &texShip) {
    Ship::texShip = texShip;
}

int Ship::getX() const {
    return x;
}

int Ship::getY() const {
    return y;
}

void Ship::setX(int x) {
    Ship::x = x;
}

void Ship::setY(int y) {
    Ship::y = y;
}

int Ship::getDirection() const {
    return direction;
}

void Ship::setDirection(int direction) {
    Ship::direction = direction;
}

