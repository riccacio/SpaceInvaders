#ifndef SPACEINVADERS_BULLETPOWER_H
#define SPACEINVADERS_BULLETPOWER_H
#include "../headers/Global.h"
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;

class BulletPower {
protected:
    std::vector<Texture> textures;
    Sprite sprite;

    bool change;
public:
    //constructor & destructor
    BulletPower();
    ~BulletPower() = default;

    //functions
    virtual void draw(RenderTarget& target);
    virtual void changeSprite();

    //getter
    virtual Vector2f getPosition();
    virtual IntRect getHitBox() const;
    virtual Sprite getSprite();

};

#endif //SPACEINVADERS_BULLETPOWER_H
