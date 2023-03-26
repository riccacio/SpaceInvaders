#ifndef SPACEINVADERS_POWERUP_H
#define SPACEINVADERS_POWERUP_H
#include "../headers/Global.h"
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;

class PowerUp {
private:
    std::vector<Texture> textures = {};
    Sprite sprite;
    bool change;
public:
    //TODO fare classe enum
    enum Type {SHIELD, THREE_BUL, FAST, CHANGE_MOV};
private:
    Type type;
public:
    //constructor & destructor
    PowerUp(Vector2f pos, Type type);
    //PowerUp(Texture &texture0, Texture &texture1, Vector2f pos, int type);
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
