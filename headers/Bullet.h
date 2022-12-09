#ifndef SPACEINVADERS_BULLET_H
#define SPACEINVADERS_BULLET_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../headers/Global.h"

using namespace sf;

class Bullet{
private:
    Sprite sprite;
public:
    Bullet(Texture& texShipShot, Vector2f pos);
    ~Bullet() = default;
    void draw(RenderTarget& target);
    void update(int direction);
    const Sprite &getSprite() const;
    Vector2f getPosition();
};

#endif //SPACEINVADERS_BULLET_H
