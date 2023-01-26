#ifndef SPACEINVADERS_UFO_H
#define SPACEINVADERS_UFO_H
#include <SFML/Graphics.hpp>
#include "../headers/PowerUp.h"

using namespace sf;

class UFO {
private:
    std::shared_ptr<std::vector<PowerUp>> powerUp;
    Sprite sprite;
    Texture texture;
    Texture texturePowerUp00;
    Texture texturePowerUp01;
    Texture texturePowerUp10;
    Texture texturePowerUp11;
    Texture texturePowerUp20;
    Texture texturePowerUp21;
    Texture texturePowerUp30;
    Texture texturePowerUp31;
    int type;
    bool dead;
public:
    void setType(int type);
    void setDead(bool dead);
    bool isDead();

public:
    //constructor & destructor
    UFO(Vector2f pos);
    ~UFO() = default;

    //functions
    void draw(RenderTarget& target);
    void drawPowerUp(RenderTarget& target);
    void update();
    bool checkCollision(IntRect hitBox);
    void dropPowerUp(Vector2f pos);
    void updatePowerUp();

    //getter
    Sprite& getSprite();
    IntRect getHitBox();
};


#endif //SPACEINVADERS_UFO_H
