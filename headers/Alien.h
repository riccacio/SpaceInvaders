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
    bool change;
    bool dead;
    int changeBulletTimer;
    int type;
    std::uniform_int_distribution<unsigned short> shoot_distribution;
public:
    Alien(int type, Vector2f (pos), bool startSprite=true);
    ~Alien() = default;
    void draw(RenderTarget& target);
    Vector2f getPositionA();
    Sprite& getSpriteA();
    Sprite& getSpriteB();
    void setPositionA(Vector2f pos);
    void setPositionB(Vector2f pos);
    void setPositionSpriteExp(Vector2f pos);
    void setSpriteA(const Sprite &spriteA);
    Vector2f getPositionB();
    void setSpriteB(const Sprite &spriteB);
    Sprite &getSpriteExp();
    std::vector<Bullet> &getBullets();
    void changeSprite();
    int getType();
    void update(std::mt19937_64& i_random_engine);
    bool isDead() const;
    void setDead(bool dead);
    void updateBullets();
    void shoot();
    void checkCollision(IntRect shipHB);
    IntRect getHitBox() const;
};

#endif //SPACEINVADERS_ALIEN_H
