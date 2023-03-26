#include "../headers/Alien.h"

Alien::Alien(Type type, Vector2f (pos), bool startSprite) : change(startSprite), changeBulletTimer(0), type(type){
    shoot_distribution = std::uniform_int_distribution <unsigned short> (0, std::max<short>(ENEMY_SHOOT_CHANCE_MIN, ENEMY_SHOOT_CHANCE - ENEMY_SHOOT_CHANCE_INCREASE));

    switch (type) {
        case ALIEN1:
            textureA.loadFromFile("sprite/alien1_0.png");
            textureB.loadFromFile("sprite/alien1_1.png");
            sprite.setTexture(textureA);
            break;
        case ALIEN2:
            textureA.loadFromFile("sprite/alien2_0.png");
            textureB.loadFromFile("sprite/alien2_1.png");
            sprite.setTexture(textureA);
            break;
        case ALIEN3:
            textureA.loadFromFile("sprite/alien3_0.png");
            textureB.loadFromFile("sprite/alien3_1.png");
            sprite.setTexture(textureA);
            break;
        default:
            break;
    }
    sprite.setPosition(Vector2f (pos));
    sprite.setScale(SPRITE_SCALE, SPRITE_SCALE);
}

//functions
void Alien::draw(RenderTarget& target) {
    sprite.setTexture((change)?textureA:textureB);
    target.draw(sprite);

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
    bullets.emplace_back(Bullet(Vector2f(getPosition().x + sprite.getGlobalBounds().width / 2.0f,
                                         getPosition().y + sprite.getGlobalBounds().height / 2.0f), Bullet::ALIEN));
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
Sprite& Alien::getSprite(){
    return sprite;
}

Vector2f Alien::getPosition() {
    return sprite.getPosition();
}

IntRect Alien::getHitBox() {
    return IntRect(sprite.getPosition().x, sprite.getPosition().y, sprite.getGlobalBounds().width, sprite.getGlobalBounds().height);
}

Alien::Type Alien::getType() {
    return type;
}

