#ifndef SPACEINVADERS_ALIEN_H
#define SPACEINVADERS_ALIEN_H
#include "../headers/Global.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class Alien {
private:
    Sprite spriteA;
    Sprite spriteB;
    Texture textureA;
    Texture textureB;
    bool change;
public:
    Alien(int type, Vector2f (pos), bool startSprite=true);
    ~Alien() = default;
    void draw(RenderTarget& target);
    Vector2f getPositionA();
    Sprite& getSpriteA();
    Sprite& getSpriteB();
    void setSpriteA(const Sprite &spriteA);
    Vector2f getPositionB() ;
    void setSpriteB(const Sprite &spriteB);
    void changeSprite();
};

#endif //SPACEINVADERS_ALIEN_H
