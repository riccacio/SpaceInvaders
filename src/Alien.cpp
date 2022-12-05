#include "../headers/Alien.h"

Alien::Alien(int type) {
    this->type = type;
    switch (type) {
        case 0:
            texture.loadFromFile("sprite/alien2_0.png");
            sprite0.setTexture(texture);
            sprite0.setPosition(50,200);
            sprite0.setScale(4,4);
            break;
        case 1:
            texture.loadFromFile("sprite/alien2_0.png");
            sprite1.setTexture(texture);
            sprite1.setPosition(600,600);
            sprite1.setScale(3.5,3.5);
            break;
        case 2:
            texture.loadFromFile("sprite/alien3_0.png");
            sprite2.setTexture(texture);
            sprite2.setPosition(700,600);
            sprite2.setScale(3.5,3.5);
            break;
        default:
            break;
    }
}

void Alien::draw(RenderTarget& target) {
    /*
     * TODO stampare gli sprite 5x8
     * 1 fila sprite0
     * 2 file sprite1
     * 2 file sprite2
     */
}

const std::vector<Sprite> &Alien::getSprites() const {
    return sprites;
}

