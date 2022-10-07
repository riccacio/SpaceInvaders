#ifndef INFO_H
#define INFO_H
#include "../include/MainWindow.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class Info: public MainWindow {
public:
    //Constructor & Destructor
    Info();
    ~Info() = default;

    //functions
    void pollEvents() override;
    void render() override;
    static void centerItem(Text& text, float height);
private:
    //Function
    void initVariables() override;
    void initWindow() override;

    //Variables
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
    std::vector<Texture> aliensT = {};
    std::vector<Sprite> aliensS = {};
};

#endif //INFO_H
