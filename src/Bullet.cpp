#include "../headers/Bullet.h"

Bullet::Bullet(std::string&& pathTexture){

    this->texture.loadFromFile(pathTexture);
    sprite.setTexture(texture);
};

float Bullet::getX() const {
    return x;
}

void Bullet::setX(float x) {
    Bullet::x = x;
}

float Bullet::getY() const {
    return y;
}

void Bullet::setY(float y) {
    Bullet::y = y;
}
