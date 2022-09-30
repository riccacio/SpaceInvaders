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
    //Constructor & Destructor
    Menu();
    virtual ~Menu();

    //functions
    void pollEvents();
    void update();
    void render();
    void run();
    static void centerText(Text& text, float height);
    static void centerSprite(Sprite& sprite, float height);
private:
    //Private functions
    void initVariables();
    void initWindow();
    const bool running() const;

    //Variables
    unique_ptr<RenderWindow> window;
    VideoMode videoMode;
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
    int record;
    int i;
};

#endif //SPACEINVADERS_MENU_H
