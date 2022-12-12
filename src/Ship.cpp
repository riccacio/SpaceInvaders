#include "../headers/Ship.h"

Ship::Ship(Vector2f pos){
    reset();
    texShip.loadFromFile("sprite/ship.png");
    texShipShot.loadFromFile("sprite/ship_shot.png");
    sprShip.setPosition(pos);
    sprShip.setTexture(texShip);
    sprShip.setScale(4,4);
}

Sprite &Ship::getSprShip() {
    return sprShip;
}

int Ship::getCurrentPower() const {
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
            b.update(-1);
    }
}

void Ship::update() {
    updateBullets();
}

void Ship::shoot() {
    bullets.emplace_back(Bullet(texShipShot, Vector2f(getPosition().x, getPosition().y - sprShip.getGlobalBounds().height / 2.0f)));
}

std::vector<Bullet> &Ship::getBullets() {
    return bullets;
}

IntRect Ship::getHitBox() const{
    return IntRect(sprShip.getPosition().x, sprShip.getPosition().y,sprShip.getGlobalBounds().width, sprShip.getGlobalBounds().height);
}
template <typename T>
void Ship::checkCollision(const std::vector<T>&aliens, T a, Bullet b) {
    aliens.erase(std::remove_if(aliens.begin(), aliens.end(),
                                [&]{ return b.getHitBox().intersects(a.getHitBox()); }), aliens.end());
}

