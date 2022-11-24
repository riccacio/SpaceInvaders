#ifndef MENU_H
#define MENU_H
#include "../headers/MainWindow.h"
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
    void checkEvent(auto& e);
private:
    void initVariables() override;

    //Variables
    Font f;
    std::vector<Text> graphicText = {};
    Texture texShip;
    Sprite sprShip;
    SoundBuffer buffer;
    Sound sound;
    int record;
    int i;
};

#endif // MENU_H