#ifndef SPACEINVADERS_BULLET_H
#define SPACEINVADERS_BULLET_H
#include <SFML/Graphics.hpp>

class Bullet{
private:
    static const int WIDTH;
    static const int HEIGHT;
    float x;
    float y;
    sf::Sprite sprite;
    sf::Texture texture;
public:
    Bullet(std::string&& pathTexture);
    ~Bullet() = default;
    float getX() const;
    void setX(float x);
    float getY() const;
    void setY(float y);
};


#endif //SPACEINVADERS_BULLET_H
