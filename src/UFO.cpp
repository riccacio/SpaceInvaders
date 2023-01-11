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

Sprite &UFO::getSprite() {
    return sprite;
}