#include "../headers/UFO.h"

UFO::UFO(Vector2f pos): dead(false), timePowerUp(0){
    srand(time(NULL));
    for (int i = 0; i<=9; i++)
        textures.emplace_back();

    textures[0].loadFromFile("sprite/ufo.png");
    int i=1;
    for(int j = 0; j<4; j++){
        for(int k = 0; k<2; k++){
            textures[i].loadFromFile("sprite/powerup" + std::to_string(j) + std::to_string(k) + ".png");
            i++;
        }
    }
    sprite.setTexture(textures[0]);
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
    std::erase_if(*powerUp, [](auto& p){return p.getPosition().y >= BOTTOM_LIMIT-p.getSprite().getGlobalBounds().height;});
    for(auto& p : *powerUp) {
        p.update();

    }
    if(timePowerUp == 0){
        timePowerUp = POWERUP_DURATION;
        for(auto& p : *powerUp){
            p.changeSprite();
        }
    }
    else
        timePowerUp--;
}

bool UFO::checkCollision(IntRect b){
    if(getHitBox().intersects(b))
        return true;
    else
        return false;
}

void UFO::dropPowerUp(Vector2f pos){
    if(type == 0){
        powerUp->emplace_back(PowerUp(textures[1], textures[2], pos, type));
    }
    else if(type == 1){
        powerUp->emplace_back(PowerUp(textures[3], textures[4], pos, type));
    }
    else if(type == 2){
        powerUp->emplace_back(PowerUp(textures[5], textures[6], pos, type));
    }
    else if(type == 3){
        powerUp->emplace_back(PowerUp(textures[7], textures[8], pos, type));
    }
}

bool UFO::checkCollisionPU(IntRect shipHB) {
    int i=0;
    for(auto p : *powerUp){
        if(p.getHitBox().intersects(shipHB)){
            powerUp->erase(powerUp->begin() + i);
            return true;
        }
        i++;
    }
    return false;

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

int UFO::getType() {
    return type;
}

void UFO::setDead(bool dead) {
    UFO::dead = dead;
}

bool UFO::isDead() {
    return dead;
}