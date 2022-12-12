#include "../headers/Bullet.h"

Bullet::Bullet(Texture& texShot, Vector2f(pos)){
    sprite.setTexture(texShot);
    sprite.setScale(3,3);
    sprite.setPosition(pos);
}

void Bullet::draw(RenderTarget &target) {
    target.draw(sprite);
}

void Bullet::update(int direction) {
    sprite.move(0.0f, BULLET_SPEED * direction);
}

Vector2f Bullet::getPosition() {
    return sprite.getPosition();
}

Sprite &Bullet::getSprite(){
    return sprite;
}

IntRect Bullet::getHitBox() const{
    return IntRect (sprite.getPosition().x, sprite.getPosition().y, sprite.getGlobalBounds().width, sprite.getGlobalBounds().height);
}

