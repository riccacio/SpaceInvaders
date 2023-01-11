#ifndef SPACEINVADERS_ALIEN_H
#define SPACEINVADERS_ALIEN_H
#include "../headers/Global.h"
#include "../headers/Bullet.h"
#include <iostream>
#include <random>
#include <SFML/Graphics.hpp>

using namespace sf;

class Alien {
private:
    Sprite spriteA;
    Sprite spriteB;
    Texture textureA;
    Texture textureB;
    Texture texShot1;
    Texture texShot2;
    std::vector<Bullet> bullets = {};
    std::uniform_int_distribution<unsigned short> shoot_distribution;

    bool change;
    bool hitted;
    int changeBulletTimer;
    int type;
public:
    //constructor & destructor
    Alien(int type, Vector2f (pos), bool startSprite=true);
    ~Alien() = default;

    //functions
    void draw(RenderTarget& target);
    void update(std::mt19937_64& i_random_engine);
    void updateBullets();
    void changeSprite();
    void shoot();
    bool checkCollision(IntRect shipHB);
    bool checkCollision(Bullet &b);
    bool checkCollisionAlienShip(IntRect shipHB);

    //getter & setter
    Sprite& getSpriteA();
    Sprite& getSpriteB();
    Vector2f getPositionA();
    IntRect getHitBox();
    int getType();

    void setHitted(bool hitted);
};

#endif //SPACEINVADERS_ALIEN_H
