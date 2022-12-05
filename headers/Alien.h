#ifndef SPACEINVADERS_ALIEN_H
#define SPACEINVADERS_ALIEN_H
#include <SFML/Graphics.hpp>

using namespace sf;

class Alien {
private:
    std::vector<Sprite> sprites;
    Sprite sprite0;
    Sprite sprite1;
    Sprite sprite2;
    Texture texture;
    int type;
public:
    Alien(int type);
    ~Alien() = default;
    void draw(RenderTarget& target);
    const std::vector<Sprite> &getSprites() const;
};


#endif //SPACEINVADERS_ALIEN_H
