#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "../headers/Global.h"
#include <fstream>
#include <SFML/Graphics.hpp>

using namespace sf;

class MainWindow {
protected:
    std::unique_ptr<RenderWindow> window;
    VideoMode videoMode;
    Event event;
    Font f;
    std::string recordS;

    virtual void initVariables();
    virtual void initWindow();
    virtual void initFont();
public:
    //constructor & destructor
    MainWindow();
    virtual ~MainWindow() = default;

    //functions
    virtual void run();
    [[nodiscard]] virtual bool running() const;
    virtual void pollEvents();
    virtual void update();
    virtual void render();
    static void centerItem(Text& text, float height);
    virtual void centerItem(Sprite& sprite, float height);
    virtual void readRecord();
};

#endif //MAINWINDOW_H