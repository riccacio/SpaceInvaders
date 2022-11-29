#ifndef MENU_H
#define MENU_H
#include "../headers/MainWindow.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <sstream>

using namespace sf;

class Menu: public MainWindow{
private:
    void initVariables() override;
    void initText();

    //Variables
    std::vector<Text> graphicText = {};
    Texture texShip;
    Sprite sprShip;
    SoundBuffer buffer;
    Sound sound;
    int i;
public:
    //Constructor and Destructor
    Menu();
    ~Menu() = default;

    //Functions
    void pollEvents() override;
    void render() override;
    void update() override;
    void music();
    void keyboardEvent(auto& e);
};

#endif // MENU_H