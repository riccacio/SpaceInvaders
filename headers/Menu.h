#ifndef MENU_H
#define MENU_H
#include "../headers/MainWindow.h"
#include "../headers/Info.h"
#include "../headers/Game.h"
#include <SFML/Audio.hpp>

class Menu: public MainWindow{
private:
    std::vector<Text> graphicText = {};
    Texture texShip;
    Sprite sprShip;
    SoundBuffer buffer;
    Sound sound;

    int i;

    void initVariables() override;
    void initText();
public:
    //constructor
    Menu();

    //functions
    void pollEvents() override;
    void keyboardEvent(auto& e);
    void update() override;
    void render() override;
    void music();
};

#endif // MENU_H