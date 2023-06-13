#ifndef SPACEINVADERS_BULLET_H
#define SPACEINVADERS_BULLET_H
#include "../headers/Global.h"
#include "../headers/BulletPower.h"
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;

class Bullet: public BulletPower{
public:
    enum class Type {SHIP, ALIEN};
private:
    Type type;
public:
    //constructor & destructor
    Bullet(Vector2f pos, Type type);
    ~Bullet() = default;

    //functions
    void draw(RenderTarget& target) override;
    void update(int direction);
};

#endif //SPACEINVADERS_BULLET_H
