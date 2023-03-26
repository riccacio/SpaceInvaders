#ifndef SHIP_H
#define SHIP_H
#include <SFML/Graphics.hpp>
#include "../headers/Bullet.h"

using namespace sf;

class Ship{
private:
    std::shared_ptr<std::vector<Bullet>> bullets;
    std::vector<Texture> shipTextures;
    Sprite sprite;

    Clock clock;
    Time time;

    bool change;
    bool dead;
    bool hitted;
    bool invincible;
    bool powerUpHitted;
public:
    enum class CurrentPower{NORMAL, SHIELD, FAST, THREE_BUL, CHANGE_MOV};
private:
    CurrentPower currentPower;
public:
    //constructor & destructor
    Ship(Vector2f pos);
    ~Ship() = default;

    //functions
    void draw(RenderTarget& target);
    void update();
    void updateBullets();
    void shoot();
    void changeSprite();

    //getter & setter
    Sprite& getSprite();
    Texture& getTexShip();
    Vector2f getPosition();
    Time& getTime();
    IntRect getHitBox();
    std::shared_ptr<std::vector<Bullet>> getBullets();
    CurrentPower getCurrentPower();
    bool isHitted();
    bool isInvincible();
    bool isPowerUpHitted();

    void setTime();
    void setTimeRestart();
    void setDead(bool dead);
    void setHitted(bool hitted);
    void setInvincible(bool invincible);
    void setCurrentPower(CurrentPower currentPower);
    void setPowerUpHitted(bool powerUpHitted);
};

#endif //SHIP_H
