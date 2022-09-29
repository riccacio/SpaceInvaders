#ifndef SPACEINVADERS_INFO_H
#define SPACEINVADERS_INFO_H
#include <SFML/Graphics.hpp>

using namespace sf;

class Info {
public:
    void run();
    static void centerText(sf::Text& text, float height);
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
    Texture aliensT[4];
    Sprite aliensS[4];
};

#endif //SPACEINVADERS_INFO_H
