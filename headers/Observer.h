#ifndef SPACEINVADERS_OBSERVER_H
#define SPACEINVADERS_OBSERVER_H
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

class Observer {
protected:
    Font textF;
    Texture texture;
    Sprite sprite;
    Text title;
    Text description;
    RectangleShape display;

    void initFont();
public:
    Observer();
    virtual ~Observer() = default;

    virtual void update(){};
};


#endif //SPACEINVADERS_OBSERVER_H
