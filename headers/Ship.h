#ifndef SHIP_H
#define SHIP_H
#include <SFML/Graphics.hpp>
#include "../headers/Bullet.h"

using namespace sf;

class Ship{
private:
    std::vector<Bullet> bullets = {};
    Sprite sprShip;
    Texture texShip;
    Texture texShipShot;
    int currentPower;
public:
    Ship(Vector2f pos);
    ~Ship() = default;
    Sprite &getSprShip();
    Texture &getTexShip();
    Vector2f getPosition();
    std::vector<Bullet> &getBullets() ;
    void setPosition(Vector2f pos);
    void reset();
    void draw(RenderTarget& target);
    int getCurrentPower() const;
    void update();
    void updateBullets();
    void shoot();
    template <typename T>
    void checkCollision(const std::vector<T>& aliens, T a, Bullet b);
    IntRect getHitBox() const;
};

#endif //SHIP_H
