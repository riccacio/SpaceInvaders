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

    //Functions
    void pollEvents() override;
    void render() override;
private:
    //Function
    void initVariables() override;

    //Variables
    Font f;
    std::vector<Text> graphicText = {};
    std::vector<Texture> aliensT = {};
    std::vector<Sprite> aliensS = {};
};

#endif //INFO_H
