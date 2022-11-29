#ifndef SPACEINVADERS_BULLET_H
#define SPACEINVADERS_BULLET_H
#include <SFML/Graphics.hpp>
#include "../headers/Global.h"

using namespace sf;

class Bullet{
private:
    Sprite sprite;
    Texture texture;
public:
    Bullet(std::string path, Vector2f pos);
    ~Bullet() = default;
    void draw(RenderTarget& target);
    void update();
    Vector2f getPosition();
};

#endif //SPACEINVADERS_BULLET_H
