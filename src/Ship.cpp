#include "../headers/Ship.h"
#include "../headers/Global.h"

#include <SFML/Graphics.hpp>

Ship::Ship(): speed(2), y(1160), shotFrequency(25) {}

Sprite &Ship::getSprShip() {
    return sprShip;
}
void Ship::setTexShip(const Texture &texShip) {
    Ship::texShip = texShip;
}

int Ship::getShotFrequency() const {
    return shotFrequency;
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
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        std::cout << x << std::endl;
        if(x>50){
            direction=-1;
            sprShip.move(speed*static_cast<float>(direction),0.0f);
            x = x - speed;
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        std::cout << x << std::endl;
        if(x<1230-WIDTH){
            direction=1;
            sprShip.move(speed*static_cast<float>(direction),0.0f);
            x = x + speed;
        }
    }
/*


    if (0 == reload_timer)
    {
        if (1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            if (2 == current_power)
            {
                reload_timer = FAST_RELOAD_DURATION;
            }
            else
            {
                reload_timer = RELOAD_DURATION;
            }

            bullets.push_back(Bullet(0, -PLAYER_BULLET_SPEED, x, y));

            if (3 == current_power)
            {
                bullets.push_back(Bullet(0, -PLAYER_BULLET_SPEED, x - 0.375f * BASE_SIZE, y));
                bullets.push_back(Bullet(0, -PLAYER_BULLET_SPEED, x + 0.375f * BASE_SIZE, y));
            }
        }
    }
    else
    {
        reload_timer--;
    }*/
}