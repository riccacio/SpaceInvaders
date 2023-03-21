#ifndef SPACEINVADERS_BULLET_H
#define SPACEINVADERS_BULLET_H
#include "../headers/Global.h"
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;
/*
enum Type{
    ALIEN, SHIP
};*/

class Bullet{
private:
    //TODO uno sprite invece di due e creare le texture in base all'uso
    Sprite sprite1;
    Sprite sprite2;
    bool change;

public:
    Bullet(Texture& texShot1, Texture& texShot2, Vector2f pos);
    ~Bullet() = default;
    //functions
    void draw(RenderTarget& target);
    void update(int direction);
    void changeSprite();

    //getter
    Vector2f getPosition();
    IntRect getHitBox() const;
    Sprite getSprite();

};

#endif //SPACEINVADERS_BULLET_H
