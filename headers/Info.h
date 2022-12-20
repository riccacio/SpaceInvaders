#ifndef INFO_H
#define INFO_H
#include "../headers/MainWindow.h"

class Info: public MainWindow {
private:
    std::vector<Text> graphicText = {};
    std::vector<Texture> aliensT = {};
    std::vector<Sprite> aliensS = {};

    void initVariables() override;
    void initText();
public:
    //constructor & destructor
    Info();
    ~Info() = default;

    //functions
    void pollEvents() override;
    void render() override;
};

#endif //INFO_H
