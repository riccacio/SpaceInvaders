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
    int moveTimer;
    int direction;
public:
    Alien(int type, Vector2f (pos), bool startSprite=true);
    ~Alien() = default;
    void draw(RenderTarget& target);
    const Sprite &getSpriteA() const;
    void setSpriteA(const Sprite &spriteA);
    const Sprite &getSpriteB() const;
    void setSpriteB(const Sprite &spriteB);
    const Sprite &getSprite0() const;
    void changeSprite();
    void update();

};


#endif //SPACEINVADERS_ALIEN_H
