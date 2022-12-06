#include "../headers/Alien.h"

Alien::Alien(int type, Vector2f (pos), bool startSprite) : change(startSprite){
    shoot_distribution = std::uniform_int_distribution<unsigned short>(0, std::max<short>(ENEMY_SHOOT_CHANCE_MIN, ENEMY_SHOOT_CHANCE - ENEMY_SHOOT_CHANCE_INCREASE));
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
    for (auto &b: bullets) {
        b.draw(target);
    }
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

void Alien::updateBullets() {
    std::erase_if(bullets, [](auto& b){return b.getPosition().y >= 1270;});
    for(auto& b : bullets){
        b.update(1);
    }
}

void Alien::shoot() {
    //TODO come in ship non carica l'immagine
    bullets.emplace_back(Bullet("sprite/alien_shot0.png", "sprite/alien_shot1.png",Vector2f(getPositionA().x + spriteA.getGlobalBounds().width/2.0f, getPositionA().y + spriteA.getGlobalBounds().height/2.0f)));
}

void Alien::update(std::mt19937_64 &i_random_engine) {
    updateBullets();
    //shoot();
    if (0 == shoot_distribution(i_random_engine)){
        shoot();
    }
}
