#ifndef SHIP_H
#define SHIP_H
#include <SFML/Graphics.hpp>
#include "../headers/Bullet.h"
#include "../headers/Alien.h"

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
    bool checkCollision(std::shared_ptr<Alien> a, Bullet b);
    IntRect getHitBox() const;
};

#endif //SHIP_H
