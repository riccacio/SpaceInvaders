#ifndef SPACEINVADERS_POWERUP_H
#define SPACEINVADERS_POWERUP_H
#include "../headers/Global.h"
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;

class PowerUp {
private:
    //TODO usare uno sprite solo, far cambiare lo sprite in base al tipo
    Sprite sprite0;
    Sprite sprite1;
    //TODO usare un'enum
    int type;

    bool change;
public:
    //constructor & destructor
    PowerUp(Texture &texture0, Texture &texture1, Vector2f pos, int type);
    ~PowerUp() = default;

    //functions
    void draw(RenderTarget& target);
    void update();
    void changeSprite();

    //getter
    Vector2f getPosition();
    IntRect getHitBox() const;
    Sprite getSprite();
};


#endif //SPACEINVADERS_POWERUP_H
