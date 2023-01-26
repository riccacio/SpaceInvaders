#ifndef SPACEINVADERS_UFO_H
#define SPACEINVADERS_UFO_H
#include <SFML/Graphics.hpp>
#include "../headers/PowerUp.h"

using namespace sf;

class UFO {
private:
    std::shared_ptr<std::vector<PowerUp>> powerUp;
    Sprite sprite;
    std::vector<Texture> textures = {};
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
    bool checkCollision(IntRect hitBox);
    void dropPowerUp(Vector2f pos);
    void updatePowerUp();
    bool checkCollisionPU(IntRect shipHB);

    //getter
    Sprite& getSprite();
    IntRect getHitBox();
    void setType(int type);
    int getType();
    void setDead(bool dead);
    bool isDead();
};


#endif //SPACEINVADERS_UFO_H
