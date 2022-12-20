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
    Sprite spriteExp;
    Texture textureA;
    Texture textureB;
    Texture textureExp;
    Texture texShot1;
    Texture texShot2;
    std::vector<Bullet> bullets = {};
    std::uniform_int_distribution<unsigned short> shoot_distribution;
    Clock clock;
    Time time;

    bool change;
    bool hitted;
    bool dead;
    int changeBulletTimer;
    int type;
    int index;
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
    IntRect getHitBox() const;
    Sprite& getSpriteExp();
    Time& getTime();
    bool isDead();
    bool isHitted();
    int getType();
    int getIndex();

    void setPositionSpriteExp(Vector2f pos);
    void setDead(bool dead);
    void setHitted(bool hitted);
    void setTimeRestart();
    void setIndex(int index);

};

#endif //SPACEINVADERS_ALIEN_H
