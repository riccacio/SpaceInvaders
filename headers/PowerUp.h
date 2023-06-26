#ifndef SPACEINVADERS_POWERUP_H
#define SPACEINVADERS_POWERUP_H
#include "../headers/Global.h"
#include "../headers/BulletPower.h"
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;

class PowerUp: public BulletPower {
public:
    enum class Type {SHIELD, THREE_BUL, FAST, CHANGE_MOV};
private:
    Type type;
public:
    //constructor & destructor
    PowerUp(Vector2f pos, Type type);
    ~PowerUp() = default;

    //functions
    void draw(RenderTarget& target) override;
    void update();
};

#endif //SPACEINVADERS_POWERUP_H