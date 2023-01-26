#include "../headers/UFO.h"

UFO::UFO(Vector2f pos): dead(false){
    srand(time(NULL));
    texture.loadFromFile("sprite/ufo.png");
    texturePowerUp00.loadFromFile("sprite/powerup00.png");
    texturePowerUp01.loadFromFile("sprite/powerup01.png");
    texturePowerUp10.loadFromFile("sprite/powerup10.png");
    texturePowerUp11.loadFromFile("sprite/powerup11.png");
    texturePowerUp20.loadFromFile("sprite/powerup20.png");
    texturePowerUp21.loadFromFile("sprite/powerup21.png");
    texturePowerUp30.loadFromFile("sprite/powerup30.png");
    texturePowerUp31.loadFromFile("sprite/powerup31.png");
    sprite.setTexture(texture);
    sprite.setPosition(pos);
    sprite.setScale(4,4);
    powerUp = std::make_shared<std::vector<PowerUp>>();
}

void UFO::draw(RenderTarget& target){
    target.draw(sprite);
}

void UFO::drawPowerUp(RenderTarget& target){
    for(auto& p : *powerUp){
        p.draw(target);
    }
}

void UFO::update(){
    sprite.move(-1.f,0.f);
}

void UFO::updatePowerUp(){
    std::erase_if(*powerUp, [](auto& p){return p.getPosition().y >= 1265;});
    for(auto& p : *powerUp){
        p.changeSprite();
        p.update();
    }
}

bool UFO::checkCollision(IntRect b){
    if(getHitBox().intersects(b))
        return true;
    else
        return false;
}

void UFO::dropPowerUp(Vector2f pos){
    if(type == 0){
        powerUp->emplace_back(PowerUp(texturePowerUp00, texturePowerUp01, pos, type));
    }
    else if(type == 1){
        powerUp->emplace_back(PowerUp(texturePowerUp10,texturePowerUp11, pos, type));
    }
    else if(type == 2){
        powerUp->emplace_back(PowerUp(texturePowerUp20, texturePowerUp21, pos, type));
    }
    else if(type == 3){
        powerUp->emplace_back(PowerUp(texturePowerUp30, texturePowerUp31, pos, type));
    }
}

Sprite &UFO::getSprite() {
    return sprite;
}

IntRect UFO::getHitBox() {
    return IntRect(sprite.getPosition().x, sprite.getPosition().y, sprite.getGlobalBounds().width, sprite.getGlobalBounds().height);
}

void UFO::setType(int type) {
    UFO::type = type;
}

void UFO::setDead(bool dead) {
    UFO::dead = dead;
}

bool UFO::isDead() {
    return dead;
}