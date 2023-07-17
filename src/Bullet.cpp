#include "../headers/Bullet.h"

Bullet::Bullet(Vector2f pos, Type type) : type(type){
    textures[0].loadFromFile("sprite/ship_shot.png");
    textures[1].loadFromFile("sprite/alien_shot0.png");
    textures[2].loadFromFile("sprite/alien_shot1.png");

    if(type == Type::SHIP){
        sprite.setTexture(textures[0]);
    }
    else{
        sprite.setTexture(textures[1]);
    }
    sprite.setScale(BULLET_SCALE, BULLET_SCALE);
    sprite.setPosition(pos.x - sprite.getGlobalBounds().width/2.f, pos.y);
}

//functions
void Bullet::draw(RenderTarget &target) {
    if(type == Type::SHIP){
        sprite.setTexture(textures[0]);
    }
    else if(type == Type::ALIEN){
        sprite.setTexture((change)?textures[1]:textures[2]);
    }
    target.draw(sprite);
}

void Bullet::update(float direction) {
    sprite.move(0.0f, BULLET_SPEED * direction);
}