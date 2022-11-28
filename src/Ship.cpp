#include "../headers/Ship.h"
#include "../headers/Global.h"
#include <SFML/Graphics.hpp>

Ship::Ship(): speed(2), y(1160){
    reset();
    this->bullet = std::make_unique<Bullet>("sprite/ship_shot.png");
}

Sprite &Ship::getSprShip() {
    return sprShip;
}
void Ship::setTexShip(const Texture &texShip) {
    Ship::texShip = texShip;
}

int Ship::getReloadTimer() const {
    return reloadTimer;
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

void Ship::update(){
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        if(x>50){
            direction = -1;
            sprShip.move(speed * static_cast<float>(direction),0.0f);
            x = x - speed;
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        if (x < 1230 - WIDTH) {
            direction = 1;
            sprShip.move(speed * static_cast<float>(direction), 0.0f);
            x = x + speed;
        }
    }

    if (reloadTimer == 0){
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
            if (currentPower == 2)
                reloadTimer = FAST_RELOAD_DURATION;
            else{
                reloadTimer = RELOAD_DURATION;
                std::cout << "shoot" <<  std::endl;
            }
            //draw bullet
            //move bullet
            //quando arriva oltre il bordo in alto, deve essere distrutto
        }
    }
    else
        reloadTimer--;

}

void Ship::reset(){
    reloadTimer = 0;
    currentPower = 0;
}