#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "../headers/Global.h"
#include <SFML/Graphics.hpp>
#include <fstream>

using namespace sf;

class MainWindow {
protected:
    //Private functions
    virtual void initVariables();
    virtual void initWindow();
    virtual void initFont();

    std::unique_ptr<RenderWindow> window;
    VideoMode videoMode;
    Event event;
    std::string recordS;
    Font f;
public:
    //Constructor & Destructor
    MainWindow();
    ~MainWindow() = default;

    //Functions
    [[nodiscard]] virtual bool running() const;
    virtual void pollEvents();
    virtual void update();
    virtual void render();
    virtual void run();
    static void centerItem(Text& text, float height);
    virtual void centerItem(Sprite& sprite, float height);
    virtual void readRecord();
};

#endif //MAINWINDOW_H
