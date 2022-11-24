#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;

class MainWindow {
protected:
    //Constants
    static const int WIDTH = 1280;
    static const int HEIGHT = 1400;

    //Private functions
    virtual void initVariables();
    virtual void initWindow();

    std::unique_ptr<RenderWindow> window;
    VideoMode videoMode;
    Event event;
    std::string recordS;
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