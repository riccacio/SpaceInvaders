#include "../headers/Ship.h"

Ship::Ship(Vector2f pos) : change(true), dead(false), hitted(false), invincible(false), powerUpHitted(false){
    currentPower = -1;
    texShip.loadFromFile("sprite/ship.png");
    texShip3.loadFromFile("sprite/ship3.png");
    texShipShield.loadFromFile("sprite/shipShield.png");
    texExpShip1.loadFromFile("sprite/ship_destroyed_0.png");
    texExpShip2.loadFromFile("sprite/ship_destroyed_1.png");
    texShipShot.loadFromFile("sprite/ship_shot.png");
    sprShip.setTexture(texShip);
    sprShip3.setTexture(texShip3);
    sprShipShield.setTexture(texShipShield);
    sprExpShip1.setTexture(texExpShip1);
    sprExpShip2.setTexture(texExpShip2);
    sprShip.setPosition(pos);
    sprShip3.setPosition(pos);
    sprShipShield.setPosition(pos);
    sprExpShip1.setPosition(pos);
    sprExpShip2.setPosition(pos);
    sprShip.setScale(4,4);
    sprShip3.setScale(4,4);
    sprShipShield.setScale(4,4);
    sprExpShip1.setScale(4,4);
    sprExpShip2.setScale(4,4);
    bullets = std::make_shared<std::vector<Bullet>>();
}

//functions
void Ship::draw(RenderTarget& target) {
    if(dead)
        target.draw((change)?sprExpShip1:sprExpShip2);
    else{
        if(currentPower == 2)
            target.draw(sprShip3);
        else if(currentPower == 0)
            target.draw(sprShipShield);
        else
            target.draw(sprShip);
    }
    for (auto &b: *bullets) {
        b.draw(target);
    }
}

void Ship::update() {
    updateBullets();
    setTime();
}

void Ship::updateBullets() {
    std::erase_if(*bullets, [](auto& b){return b.getPosition().y <= TOP_LIMIT;});
    for(auto& b : *bullets){
        b.update(-1);
    }
}

void Ship::shoot() {
    if(currentPower == 2){
        bullets->emplace_back(Bullet(texShipShot, texShipShot, Vector2f(getPosition().x-BULLET_OFFSET, getPosition().y - sprShip.getGlobalBounds().height / 2.0f)));
        bullets->emplace_back(Bullet(texShipShot, texShipShot, Vector2f(getPosition().x, getPosition().y - sprShip.getGlobalBounds().height / 2.0f)));
        bullets->emplace_back(Bullet(texShipShot, texShipShot, Vector2f(getPosition().x+BULLET_OFFSET, getPosition().y - sprShip.getGlobalBounds().height / 2.0f)));
    }
    else{
        bullets->emplace_back(Bullet(texShipShot, texShipShot, Vector2f(getPosition().x, getPosition().y - sprShip.getGlobalBounds().height / 2.0f)));
    }
}

void Ship::changeSprite() {
    change = !change;
}

//getter & setter
Sprite &Ship::getSprShip() {
    return sprShip;
}

Sprite &Ship::getSprShip3() {
    return sprShip3;
}

Sprite &Ship::getSprShipShield() {
    return sprShipShield;
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
    return IntRect(sprShip.getPosition().x-sprShip.getGlobalBounds().width/2, (sprShip.getPosition().y-sprShip.getGlobalBounds().height/2)+PADDING,sprShip.getGlobalBounds().width, sprShip.getGlobalBounds().height);
}

std::shared_ptr<std::vector<Bullet>> Ship::getBullets() {
    return bullets;
}

int Ship::getCurrentPower(){
    return currentPower;
}

bool Ship::isHitted() {
    return hitted;
}

bool Ship::isInvincible() {
    return invincible;
}

bool Ship::isPowerUpHitted() {
    return powerUpHitted;
}


void Ship::setPosition3(Vector2f pos) {
    sprShip3.setPosition(pos);
}

void Ship::setPositionShield(Vector2f pos) {
    sprShipShield.setPosition(pos);
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

void Ship::setHitted(bool hitted) {
    Ship::hitted = hitted;
}

void Ship::setInvincible(bool invincible) {
    Ship::invincible = invincible;
}

void Ship::setCurrentPower(int currentPower) {
    Ship::currentPower = currentPower;
}

void Ship::setPowerUpHitted(bool powerUpHitted) {
    Ship::powerUpHitted = powerUpHitted;
}


