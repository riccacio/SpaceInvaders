#include "../headers/Alien.h"

Alien::Alien(int type, Vector2f (pos), bool startSprite) : change(startSprite), direction(1), moveTimer(0) {
    switch (type) {
        case 0:
            textureA.loadFromFile("sprite/alien1_0.png");
            spriteA.setTexture(textureA);
            spriteA.setPosition(Vector2f (pos));
            textureB.loadFromFile("sprite/alien1_1.png");
            spriteB.setTexture(textureB);
            spriteB.setPosition(Vector2f (pos));
            spriteA.setScale(4, 4);
            spriteB.setScale(4, 4);
            break;
        case 1:
            textureA.loadFromFile("sprite/alien2_0.png");
            spriteA.setTexture(textureA);
            spriteA.setPosition(pos);
            textureB.loadFromFile("sprite/alien2_1.png");
            spriteB.setTexture(textureB);
            spriteB.setPosition(pos);
            spriteA.setScale(4, 4);
            spriteB.setScale(4, 4);
            break;
        case 2:
            textureA.loadFromFile("sprite/alien3_0.png");
            spriteA.setTexture(textureA);
            spriteA.setPosition(pos);
            textureB.loadFromFile("sprite/alien3_1.png");
            spriteB.setTexture(textureB);
            spriteB.setPosition(Vector2f (pos));
            spriteA.setScale(4, 4);
            spriteB.setScale(4, 4);
            break;
        default:
            break;
    }
}

void Alien::draw(RenderTarget& target) {
    target.draw((change)?spriteA:spriteB);
}

const Sprite &Alien::getSprite0() const {
    return spriteA;
}

const Sprite &Alien::getSpriteA() const {
    return spriteA;
}

void Alien::setSpriteA(const Sprite &spriteA) {
    Alien::spriteA = spriteA;
}

const Sprite &Alien::getSpriteB() const {
    return spriteB;
}

void Alien::setSpriteB(const Sprite &spriteB) {
    Alien::spriteB = spriteB;
}

void Alien::changeSprite() {
    change = !change;
}

void Alien::update() {
    if(moveTimer){
        moveTimer = ALIEN_MOVE_PAUSE;
        if(spriteA.getPosition().x + spriteA.getGlobalBounds().width <= WIDTH && spriteB.getPosition().x + spriteB.getGlobalBounds().width){
                spriteA.setPosition(spriteA.getPosition().x + ALIEN_SPEED, spriteA.getPosition().y);
                spriteB.setPosition(spriteB.getPosition().x + ALIEN_SPEED, spriteB.getPosition().y);
        }
        else if(spriteA.getPosition().x > 0 && spriteB.getPosition().x > 0){
            spriteA.setPosition(spriteA.getPosition().x, spriteA.getPosition().y + 1);
            spriteB.setPosition(spriteB.getPosition().x , spriteB.getPosition().y + 1);
            spriteA.setPosition(spriteA.getPosition().x - ALIEN_SPEED, spriteA.getPosition().y);
            spriteB.setPosition(spriteB.getPosition().x - ALIEN_SPEED, spriteB.getPosition().y);
        }
    }
    else
        moveTimer --;
}

