#include "../headers/Ship.h"

Ship::Ship(Vector2f pos){
    reset();
    texShip.loadFromFile("sprite/ship.png");
    sprShip.setPosition(pos);
    sprShip.setTexture(texShip);
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

void Ship::reset(){
    currentPower = 0;
}

Vector2f Ship::getPosition() {
    return sprShip.getPosition();
}

void Ship::setPosition(Vector2f pos) {
    sprShip.setPosition(pos);
}

Texture &Ship::getTexShip(){
    return texShip;
}

void Ship::draw(RenderTarget& target) {
    target.draw(sprShip);
    for (auto &b: bullets) {
        b.draw(target);
    }
}

void Ship::updateBullets() {
    std::erase_if(bullets, [](auto& b){return b.getPosition().y <= 100;});
    for(auto& b : bullets){
            b.update();
    }
}

void Ship::update() {
    updateBullets();
}

void Ship::shoot() {
    bullets.push_back(Bullet("sprite/ship_shot.png", Vector2f(getPosition().x, getPosition().y - sprShip.getGlobalBounds().height/2.0f)));
}

void Ship::setBullets( std::vector<Bullet> &bullets) {
    this->bullets = bullets;
}


