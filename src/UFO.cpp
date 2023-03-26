#include "../headers/UFO.h"

UFO::UFO(Vector2f pos): dead(false), timePowerUp(0){
    texture.loadFromFile("sprite/ufo.png");
    sprite.setTexture(texture);
    sprite.setPosition(pos);
    sprite.setScale(SPRITE_SCALE, SPRITE_SCALE);
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

//uff vs ship bullet
bool UFO::checkCollision(IntRect b){
    if(getHitBox().intersects(b))
        return true;
    else
        return false;
}

void UFO::dropPowerUp(Vector2f pos){

    if(type == 0){
        powerUp->emplace_back(PowerUp(pos, PowerUp::SHIELD));
    }
    else if(type == 1){
        powerUp->emplace_back(PowerUp(pos, PowerUp::THREE_BUL));
    }
    else if(type == 2){
        powerUp->emplace_back(PowerUp(pos, PowerUp::FAST));
    }
    else if(type == 3){
        powerUp->emplace_back(PowerUp(pos, PowerUp::CHANGE_MOV));
    }
}

//power-up vs ship
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

//getter and setter

Sprite &UFO::getSprite() {
    return sprite;
}

IntRect UFO::getHitBox() {
    return IntRect(sprite.getPosition().x, sprite.getPosition().y, sprite.getGlobalBounds().width, sprite.getGlobalBounds().height);
}

bool UFO::isDead() {
    return dead;
}

int UFO::getType() {
    return type;
}

void UFO::setType(int type) {
    UFO::type = type;
}

void UFO::setDead(bool dead) {
    UFO::dead = dead;
}