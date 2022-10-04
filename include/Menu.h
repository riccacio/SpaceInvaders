#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <sstream>

using namespace sf;

class Menu{
public:
    //Constructor
    Menu();

    //Functions
    bool running() const;
    void pollEvents();
    void update();
    void render();
    void run();
    static void centerItem(Text& text, float height);
    static void centerItem(Sprite& sprite, float height);
    void music();
private:
    //Constants
    static const int WIDTH = 1280;
    static const int HEIGHT = 1400;
    //Private functions
    void initVariables();
    void initWindow();

    //Variables
    std::unique_ptr<RenderWindow> window;
    VideoMode videoMode;
    Event event;

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
