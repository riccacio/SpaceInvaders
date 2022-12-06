#ifndef SPACEINVADERS_BULLET_H
#define SPACEINVADERS_BULLET_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../headers/Global.h"

using namespace sf;

class Bullet{
private:
    Sprite sprite;
    Texture textureS;
    Texture textureA1;
    Texture textureA2;
public:
    Bullet(std::string path, Vector2f pos);
    Bullet(std::string path1, std::string path2, Vector2f pos);
    ~Bullet() = default;
    void draw(RenderTarget& target);
    void update(int direction);
    Vector2f getPosition();
};

#endif //SPACEINVADERS_BULLET_H
