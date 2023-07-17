#ifndef SPACEINVADERS_UFO_H
#define SPACEINVADERS_UFO_H
#include <SFML/Graphics.hpp>
#include "../headers/PowerUp.h"

using namespace sf;

class UFO {
private:
    std::shared_ptr<std::vector<PowerUp>> powerUp;
    Texture texture;
    Sprite sprite;

    int timePowerUp;
    int type;
    bool dead;
public:
    //constructor & destructor
    UFO(Vector2f pos);
    ~UFO() = default;

    //functions
    void draw(RenderTarget& target);
    void drawPowerUp(RenderTarget& target);
    void update();
    bool checkCollision(FloatRect hitBox);
    void dropPowerUp(Vector2f pos);
    void updatePowerUp();
    bool checkCollisionPU(FloatRect shipHB);

    //getter and setter
    Sprite& getSprite();
    FloatRect getHitBox();
    bool isDead();
    int getType();
    void setType(int type);
    void setDead(bool dead);
};

#endif //SPACEINVADERS_UFO_H