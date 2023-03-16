#include "../headers/Alien.h"

Alien::Alien(int type, Vector2f (pos), bool startSprite) : change(startSprite), changeBulletTimer(0){
    shoot_distribution = std::uniform_int_distribution <unsigned short> (0, std::max<short>(ENEMY_SHOOT_CHANCE_MIN, ENEMY_SHOOT_CHANCE - ENEMY_SHOOT_CHANCE_INCREASE));

    texShot1.loadFromFile("sprite/alien_shot0.png");
    texShot2.loadFromFile("sprite/alien_shot1.png");

    this->type = type;
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

//functions
void Alien::draw(RenderTarget& target) {
    target.draw((change)?spriteA:spriteB);

    for (auto &b: bullets) {
        b.draw(target);
    }
}

void Alien::update(std::mt19937_64 &i_random_engine) {
    updateBullets();
    if (0 == shoot_distribution(i_random_engine)){
        shoot();
    }
    //bullet animation
    if(changeBulletTimer == 0){
        changeBulletTimer = ALIEN_BULLET_DURATION;
        for(auto& b : bullets){
            b.changeSprite();
        }
    }
    else
        changeBulletTimer--;
}

void Alien::updateBullets() {
    std::erase_if(bullets, [](auto& b){return b.getPosition().y >= BOTTOM_LIMIT-b.getSprite().getGlobalBounds().height;});
    //bullet movement
    for(auto& b : bullets){
        b.update(1);
    }
}

void Alien::changeSprite() {
    change = !change;
}

void Alien::shoot() {
    bullets.emplace_back(Bullet(texShot1, texShot2, Vector2f(getPositionA().x + spriteA.getGlobalBounds().width/2.0f, getPositionA().y + spriteA.getGlobalBounds().height/2.0f)));
}

//alien bullet vs ship
bool Alien::checkCollision(IntRect shipHB) {
    int i=0;
    for(auto b : bullets){
        if(b.getHitBox().intersects(shipHB)){
            bullets.erase(bullets.begin() + i);
            return true;
        }
        i++;
    }
    return false;
}

//alien vs ship bullet
bool Alien::checkCollision(Bullet& b){
    if(getHitBox().intersects(b.getHitBox())){
        return true;
    }
    else
        return false;
}

//alien vs ship
bool Alien::checkCollisionAlienShip(IntRect shipHB) {
    if(shipHB.intersects(getHitBox()))
        return true;
    else
        return false;
}

//getter and setter
Sprite& Alien::getSpriteA(){
    return spriteA;
}

Sprite& Alien::getSpriteB(){
    return spriteB;
}

Vector2f Alien::getPositionA() {
    return spriteA.getPosition();
}

IntRect Alien::getHitBox() {
    return IntRect(spriteA.getPosition().x, spriteA.getPosition().y, spriteA.getGlobalBounds().width, spriteA.getGlobalBounds().height);
}

int Alien::getType(){
    return type;
}
