#ifndef INFO_H
#define INFO_H
#include "../headers/MainWindow.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class Info: public MainWindow {
private:
    //Function
    void initVariables() override;

    //Variables
    Font f;
    std::vector<Text> graphicText = {};
    std::vector<Texture> aliensT = {};
    std::vector<Sprite> aliensS = {};
public:
    //Constructor & Destructor
    Info();
    ~Info() = default;

    //Functions
    void pollEvents() override;
    void render() override;
};

#endif //INFO_H
