#include "../headers/Bullet.h"

Bullet::Bullet(Vector2f pos, Type type) : change(true), type(type){
    for(int i=0; i<=2; i++){
        bulletTextures.emplace_back();
    }
    bulletTextures[0].loadFromFile("sprite/ship_shot.png");
    bulletTextures[1].loadFromFile("sprite/alien_shot0.png");
    bulletTextures[2].loadFromFile("sprite/alien_shot1.png");

    if(type == Type::SHIP){
        sprite.setTexture(bulletTextures[0]);
    }
    else{
        sprite.setTexture(bulletTextures[1]);
    }
    sprite.setScale(BULLET_SCALE, BULLET_SCALE);
    sprite.setPosition(pos.x - sprite.getGlobalBounds().width/2.f, pos.y);
}

//functions
void Bullet::draw(RenderTarget &target) {
    if(type == Type::SHIP){
        sprite.setTexture((change)?bulletTextures[0]:bulletTextures[0]);
    }
    else if(type == Type::ALIEN){
        sprite.setTexture((change)?bulletTextures[1]:bulletTextures[2]);
    }
    target.draw(sprite);
}

void Bullet::update(int direction) {
    sprite.move(0.0f, BULLET_SPEED * direction);
}

void Bullet::changeSprite() {
    change = !change;
}

//getter
Vector2f Bullet::getPosition() {
    return sprite.getPosition();
}

IntRect Bullet::getHitBox() const{
    return IntRect (sprite.getPosition().x, sprite.getPosition().y, sprite.getGlobalBounds().width, sprite.getGlobalBounds().height);
}

Sprite Bullet::getSprite() {
    return sprite;
}