#ifndef SPACEINVADERS_UFO_H
#define SPACEINVADERS_UFO_H
#include <SFML/Graphics.hpp>

using namespace sf;

class UFO {
private:
    //TODO vettore di powerUP
    Sprite sprite;
    Texture texture;
public:
    //constructor & destructor
    UFO(Vector2f pos);
    ~UFO() = default;

    //functions
    void draw(RenderTarget& target);
    void update();
    bool checkCollision(IntRect hitBox);

    //getter
    Sprite& getSprite();
    IntRect getHitBox();
};


#endif //SPACEINVADERS_UFO_H
