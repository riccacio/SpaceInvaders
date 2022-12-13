#ifndef SPACEINVADERS_BULLET_H
#define SPACEINVADERS_BULLET_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../headers/Global.h"

using namespace sf;

class Bullet{
private:
    Sprite sprite1;
    Sprite sprite2;
    bool change;
public:
    Bullet(Texture& texShot1, Texture& texShot2, Vector2f pos);
    ~Bullet() = default;
    void draw(RenderTarget& target);
    void update(int direction);
    Sprite &getSprite();
    Vector2f getPosition();
    void changeSprite();
    IntRect getHitBox() const;
    bool isChange();
};

#endif //SPACEINVADERS_BULLET_H
