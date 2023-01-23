#include "../headers/UFO.h"

UFO::UFO(Vector2f pos){
    texture.loadFromFile("sprite/ufo.png");
    sprite.setTexture(texture);
    sprite.setPosition(pos);
    sprite.setScale(4,4);
}

void UFO::draw(RenderTarget& target){
    target.draw(sprite);
}

void UFO::update(){
    sprite.move(-1.f,0.f);
}

bool UFO::checkCollision(IntRect b){
    if(getHitBox().intersects(b))
        return true;
    else
        return false;
}

Sprite &UFO::getSprite() {
    return sprite;
}

IntRect UFO::getHitBox() {
    return IntRect(sprite.getPosition().x, sprite.getPosition().y, sprite.getGlobalBounds().width, sprite.getGlobalBounds().height);
}