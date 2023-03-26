#ifndef SPACEINVADERS_BULLET_H
#define SPACEINVADERS_BULLET_H
#include "../headers/Global.h"
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;

class Bullet{
private:
    std::vector<Texture> bulletTextures;
    Sprite sprite;

    bool change;
public:
    enum class Type {SHIP, ALIEN};
private:
    Type type;
public:
    Bullet(Vector2f pos, Type type);
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
