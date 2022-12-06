#include "../headers/Alien.h"

Alien::Alien(int type, Vector2f (pos), bool startSprite) : change(startSprite){

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

Sprite& Alien::getSpriteA(){
    return spriteA;
}
Sprite& Alien::getSpriteB(){
    return spriteB;
}

void Alien::draw(RenderTarget& target) {
    target.draw((change)?spriteA:spriteB);
}

Vector2f Alien::getPositionA() {
    return spriteA.getPosition();
}

void Alien::setSpriteA(const Sprite &spriteA) {
    Alien::spriteA = spriteA;
}

Vector2f Alien::getPositionB()  {
    return spriteB.getPosition();
}

void Alien::setSpriteB(const Sprite &spriteB) {
    Alien::spriteB = spriteB;
}

void Alien::setPositionA(Vector2f pos) {
    spriteA.setPosition(pos);
}

void Alien::changeSprite() {
    change = !change;
}
void Alien::setPositionB(Vector2f pos) {
    spriteB.setPosition(pos);
}
