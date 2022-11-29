#include "../headers/Ship.h"
#include <SFML/Graphics.hpp>

Ship::Ship(Vector2f pos){
    reset();
    texShip.loadFromFile("sprite/ship.png");
    sprShip.setPosition(pos);
    sprShip.setTexture(texShip);
    this->bullet = std::make_unique<Bullet>("sprite/ship_shot.png");
}

Sprite &Ship::getSprShip() {
    return sprShip;
}
void Ship::setTexShip(const Texture &texShip) {
    Ship::texShip = texShip;
}

int Ship::getCurrentPower() {
    return currentPower;
}
float Ship::getWidth() const{
    return WIDTH;
}

float Ship::getHeight() const{
    return HEIGHT;
}

void Ship::update(){
    /*
    if (Keyboard::isKeyPressed(Keyboard::Left)){
        if(sprite.getPosition().x>50){
            direction = -1;
            sprShip.move(speed * static_cast<float>(direction),0.0f);
            x = x - speed;
        }
    }
    if (Keyboard::isKeyPressed(Keyboard::Right)) {
        if (x < 1230 - WIDTH) {
            direction = 1;
            sprShip.move(speed * static_cast<float>(direction), 0.0f);
            x = x + speed;
        }
    }


*/
}

void Ship::reset(){
    currentPower = 0;
}

Vector2f Ship::getPosition() {
    return sprShip.getPosition();
}

void Ship::setPosition(Vector2f pos) {
    sprShip.setPosition(pos);
}


