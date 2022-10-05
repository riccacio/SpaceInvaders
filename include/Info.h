#ifndef INFO_H
#define INFO_H
#include <SFML/Graphics.hpp>

using namespace sf;

class Info {
public:
    //Constructor & Destructor
    Info();

    //functions
    bool running() const;
    void pollEvents();
    void update();
    void render();
    void run();
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
    Text title;
    Text shot;
    Text left;
    Text right;
    Text myst;
    Text alien1;
    Text alien2;
    Text alien3;
    Text back;
    /*TODO riscrivere gli array in questo modo:
     * "std::vector<Text> text = {}"
     * nel .cpp dentro "initVariables()":
     * "for (int i = 0; i<=9; i++)
     *      text.emplace_back();"
     *
     */
    Texture aliensT[4];
    Sprite aliensS[4];
};

#endif //INFO_H
