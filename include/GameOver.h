#ifndef GAMEOVER_H
#define GAMEOVER_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <sstream>

using namespace sf;

class GameOver {
public:
    //Constructor
    GameOver();

    //Functions
    bool running() const;
    void pollEvents();
    void update();
    void render();
    void run();
    void music();
    static void centerItem(Text& text, float height);
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
    std::vector<Text> text = {};
    Text title;
    SoundBuffer buffer;
    Sound sound;

    bool close;
};

#endif //GAMEOVER_H
