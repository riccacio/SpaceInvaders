#ifndef INFO_H
#define INFO_H
#include <SFML/Graphics.hpp>

using namespace sf;

class Info {
public:
    static const int WIDTH = 1280;
    static const int HEIGHT = 1400;
    //Constructor & Destructor
    Info();
    ~Info() = default;

    //functions
    bool running() const;
    void pollEvents();
    void update();
    void render();
    void run();
    static void centerText(Text& text, float height);
private:
    //Private functions
    void initVariables();
    void initWindow();

    //Variables
    std::unique_ptr<RenderWindow> window;
    VideoMode videoMode;
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

#endif //INFO_H
