#include "../headers/Bullet.h"

Bullet::Bullet(const std::string& path, Vector2f(pos)){
    texture.loadFromFile(path);
    sprite.setTexture(texture);
    sprite.setScale(1,4);
    sprite.setPosition(pos);
}

void Bullet::draw(RenderTarget &target) {
    target.draw(sprite);
}

void Bullet::update() {
    sprite.move(0.0f, -SHIP_BULLET_SPEED);
}

Vector2f Bullet::getPosition() {
    return sprite.getPosition();
}



