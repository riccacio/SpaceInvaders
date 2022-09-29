#ifndef SPACEINVADERS_MENU_H
#define SPACEINVADERS_MENU_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <sstream>

using namespace sf;
using namespace std;

class Menu{
public:
    static const int WIDTH = 1280;
    static const int HEIGHT = 1400;

    Menu();
    void run();
    static void centerText(Text& text, float height);
    static void centerSprite(Sprite& sprite, float height);
private:
    int record;
    int i;
    Event event;
    Font f1;
    Text title;
    Text text;
    Text info;
    Text hiScore;
    Text recordText;
    Texture texShip;
    Sprite sprShip;
    SoundBuffer buffer;
    Sound sound;
};

#endif //SPACEINVADERS_MENU_H
