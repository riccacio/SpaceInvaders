#ifndef MENU_H
#define MENU_H
#include "../include/MainWindow.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <sstream>

using namespace sf;

class Menu: public MainWindow{
public:
    //Constructor and Destructor
    Menu();
    ~Menu() = default;

    //Functions
    void pollEvents() override;
    void render() override;
    void run() override;
    void music();
private:
    //Variables
    Font f;
    Text title;
    Text text;
    Text info;
    Text hiScore;
    Text recordText;
    Texture texShip;
    Sprite sprShip;
    SoundBuffer buffer;
    Sound sound;
    int record;
    int i;
};

#endif // MENU_H
