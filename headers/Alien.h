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
    Texture textureA;
    Texture textureB;
    Sprite sprite;

    std::vector<Bullet> bullets = {};
    std::uniform_int_distribution<unsigned short> shoot_distribution;

    bool change;
    int changeBulletTimer;
public:
    enum class Type{ALIEN1, ALIEN2, ALIEN3};
private:
    Type type;
public:
    //constructor & destructor
    Alien(Type type, Vector2f (pos), bool startSprite=true);
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

    //getter
    Sprite& getSprite();
    Vector2f getPosition();
    IntRect getHitBox();
    Type getType();
    std::vector<Bullet> &getBullets();
};

#endif //SPACEINVADERS_ALIEN_H