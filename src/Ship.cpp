#include "../headers/Ship.h"

Ship::Ship(Vector2f pos) : change(true), dead(false){
    currentPower = 0;
    texShip.loadFromFile("sprite/ship.png");
    texExpShip1.loadFromFile("sprite/ship_destroyed_0.png");
    texExpShip2.loadFromFile("sprite/ship_destroyed_1.png");
    texShipShot.loadFromFile("sprite/ship_shot.png");
    sprShip.setPosition(pos);
    sprExpShip1.setPosition(pos);
    sprExpShip2.setPosition(pos);
    sprShip.setTexture(texShip);
    sprExpShip1.setTexture(texExpShip1);
    sprExpShip2.setTexture(texExpShip2);
    sprShip.setScale(4,4);
}

//functions
void Ship::draw(RenderTarget& target) {
    if(dead){
        target.draw((change)?sprExpShip1:sprExpShip2);
    }
    else
        target.draw(sprShip);
    for (auto &b: *bullets) {
        b.draw(target);
    }
}

void Ship::update() {
    updateBullets();
    setTime();
}

void Ship::updateBullets() {
    std::erase_if(*bullets, [](auto& b){return b.getPosition().y <= 100;});
    for(auto& b : *bullets){
        b.update(-1);
    }
}

void Ship::shoot() {
    bullets->emplace_back(Bullet(texShipShot, texShipShot, Vector2f(getPosition().x, getPosition().y - sprShip.getGlobalBounds().height / 2.0f)));
}

void Ship::changeSprite() {
    change = !change;
}

//getter & setter
Sprite &Ship::getSprShip() {
    return sprShip;
}

Texture &Ship::getTexShip(){
    return texShip;
}

Vector2f Ship::getPosition() {
    return sprShip.getPosition();
}

Time &Ship::getTime() {
    return time;
}

IntRect Ship::getHitBox(){
    return IntRect(sprShip.getPosition().x, sprShip.getPosition().y,sprShip.getGlobalBounds().width, sprShip.getGlobalBounds().height);
}

std::shared_ptr<std::vector<Bullet>> Ship::getBullets() {
    return bullets;
}

int Ship::getCurrentPower(){
    return currentPower;
}

void Ship::setPosition(Vector2f pos) {
    sprShip.setPosition(pos);
}

void Ship::setPositionExp1(Vector2f pos) {
    sprExpShip1.setPosition(pos);
}

void Ship::setTime() {
    Ship::time = clock.getElapsedTime();
}

void Ship::setTimeRestart() {
    Ship::time = clock.restart();
}

void Ship::setPositionExp2(Vector2f pos) {
    sprExpShip2.setPosition(pos);
}

void Ship::setDead(bool dead) {
    Ship::dead = dead;
}