#include "../headers/Ship.h"

Ship::Ship(Vector2f pos) : change(true), dead(false), hitted(false), invincible(false), powerUpHitted(false){
    currentPower = NORMAL;
    for (int j = 0; j<5; j++)
        shipTextures.emplace_back();
    /*
     * 0 = default
     * 1 = 3 bullets
     * 2 = shield
     * 3 = exp 1
     * 4 = exp 2
     */
    for(int j = 0; j<5; j++){
        shipTextures[j].loadFromFile("sprite/ship" + std::to_string(j) + ".png");
    }
    sprite.setTexture(shipTextures[0]);
    sprite.setPosition(pos);
    sprite.setScale(SPRITE_SCALE, SPRITE_SCALE);
    bullets = std::make_shared<std::vector<Bullet>>();
}

//functions
void Ship::draw(RenderTarget& target) {
    if(dead){
        sprite.setTexture((change)?shipTextures[3]:shipTextures[4]);
        target.draw(sprite);
    }

    else{
        if(currentPower == THREE_BUL){
            sprite.setTexture(shipTextures[1]);
            target.draw(sprite);
        }
        else if(currentPower == SHIELD){
            sprite.setTexture(shipTextures[2]);
            target.draw(sprite);
        }
        else {
            sprite.setTexture(shipTextures[0]);
            target.draw(sprite);
        }
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
    if(currentPower == THREE_BUL){
        bullets->emplace_back(Bullet(Vector2f(getPosition().x-BULLET_OFFSET, getPosition().y - sprite.getGlobalBounds().height / 2.0f), Bullet::SHIP));
        bullets->emplace_back(Bullet(Vector2f(getPosition().x, getPosition().y - sprite.getGlobalBounds().height / 2.0f), Bullet::SHIP));
        bullets->emplace_back(Bullet(Vector2f(getPosition().x+BULLET_OFFSET, getPosition().y - sprite.getGlobalBounds().height / 2.0f), Bullet::SHIP));
    }
    else{
        bullets->emplace_back(Bullet(Vector2f(getPosition().x, getPosition().y - sprite.getGlobalBounds().height / 2.0f), Bullet::SHIP));
    }
}

void Ship::changeSprite() {
    change = !change;
}

//getter & setter
Sprite &Ship::getSprite() {
    return sprite;
}

Texture &Ship::getTexShip(){
    return shipTextures[0];
}

Vector2f Ship::getPosition() {
    return sprite.getPosition();
}

Time &Ship::getTime() {
    return time;
}
IntRect Ship::getHitBox(){
    return IntRect(sprite.getPosition().x - sprite.getGlobalBounds().width / 2, (sprite.getPosition().y - sprite.getGlobalBounds().height / 2) + PADDING, sprite.getGlobalBounds().width, sprite.getGlobalBounds().height);
}

std::shared_ptr<std::vector<Bullet>> Ship::getBullets() {
    return bullets;
}

Ship::CurrentPower Ship::getCurrentPower(){
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

void Ship::setTime() {
    Ship::time = clock.getElapsedTime();
}

void Ship::setTimeRestart() {
    Ship::time = clock.restart();
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

void Ship::setCurrentPower(Ship::CurrentPower currentPower) {
    Ship::currentPower = currentPower;
}

void Ship::setPowerUpHitted(bool powerUpHitted) {
    Ship::powerUpHitted = powerUpHitted;
}


