#include "../headers/Bullet.h"

Bullet::Bullet(Texture& texShot1, Texture& texShot2, Vector2f(pos)) : change(true){
    sprite1.setTexture(texShot1);
    sprite2.setTexture(texShot2);
    sprite1.setScale(3.5,3.5);
    sprite2.setScale(3.5,3.5);
    sprite1.setPosition(pos);
    sprite2.setPosition(pos);
}

//functions
void Bullet::draw(RenderTarget &target) {
    target.draw((change)?sprite1:sprite2);
}

void Bullet::update(int direction) {
    sprite1.move(0.0f, BULLET_SPEED * direction);
    sprite2.move(0.0f, BULLET_SPEED * direction);
}

void Bullet::changeSprite() {
    change = !change;
}

//getter
Vector2f Bullet::getPosition() {
    if(change)
        return sprite1.getPosition();
    else
        return sprite2.getPosition();
}

IntRect Bullet::getHitBox() const{
    return IntRect (sprite1.getPosition().x, sprite1.getPosition().y, sprite1.getGlobalBounds().width, sprite1.getGlobalBounds().height);
}

