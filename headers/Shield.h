#ifndef SPACEINVADERS_SHIELD_H
#define SPACEINVADERS_SHIELD_H
#include <SFML/Graphics.hpp>
#include "../headers/Global.h"

using namespace sf;

class Shield {
private:
    std::vector<Texture> textures;
    Sprite sprite;

    bool hitted;
    bool deletable;
public:
    enum class Type{LeftUp, LeftBot, RightUp, RightBot, Unique};
    Type type;
    //constructor & destructor
    Shield(Type type, Vector2f pos);
    ~Shield() = default;

    //functions
    void draw(RenderTarget& target);
    void update();
    bool checkCollision(IntRect hitBox);

    //getter and setter
    Sprite& getSprite();
    IntRect getHitBox();
    bool isHitted() const;
    void setHitted(bool hitted);
    bool isDeletable() const;
    void setDeletable(bool deletable);
};


#endif //SPACEINVADERS_SHIELD_H
