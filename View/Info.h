#ifndef SPACEINVADERS_INFO_H
#define SPACEINVADERS_INFO_H
#include <SFML/Graphics.hpp>

using namespace sf;

class Info {
public:
    void run();
    void centerText(sf::Text& text, int height);
private:
    Event event;
    Font f1;
    Text title;
    Text shot;
    Text left;
    Text right;
    Text myst;
    Text alien1;
    Text alien2;
    Text alien3;
    Text back;

    //TODO create texture array
    Texture mystT;
    Texture alien1T;
    Texture alien2T;
    Texture alien3T;

    //TODO create sprite array
    Sprite mystS;
    Sprite alien1S;
    Sprite alien2S;
    Sprite alien3S;
};

#endif //SPACEINVADERS_INFO_H
