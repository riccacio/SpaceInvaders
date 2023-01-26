#include "../headers/PowerUp.h"

PowerUp::PowerUp(Texture &texture0, Texture &texture1, Vector2f pos, int type): type(type), change(true){
    sprite0.setTexture(texture0);
    sprite1.setTexture(texture1);
    sprite0.setScale(4,4);
    sprite1.setScale(4,4);
    sprite0.setPosition(pos.x-sprite0.getGlobalBounds().width/2.f, pos.y);
    sprite1.setPosition(pos.x-sprite1.getGlobalBounds().width/2.f, pos.y);
}

void PowerUp::draw(RenderTarget &target) {
    target.draw((change)?sprite0:sprite1);
}

void PowerUp::update(){
    sprite0.move(0.f, POWERUP_SPEED);
    sprite1.move(0.f, POWERUP_SPEED);
}

void PowerUp::changeSprite() {
    change = !change;
}

Vector2f PowerUp::getPosition() {
    if(change)
        return sprite0.getPosition();
    else
        return sprite1.getPosition();
}

IntRect PowerUp::getHitBox() const{
    if(change)
        return IntRect (sprite0.getPosition().x, sprite0.getPosition().y, sprite0.getGlobalBounds().width, sprite0.getGlobalBounds().height);
    else
        return IntRect (sprite1.getPosition().x, sprite1.getPosition().y, sprite1.getGlobalBounds().width, sprite1.getGlobalBounds().height);
}

Sprite PowerUp::getSprite() {
    return sprite0;
}