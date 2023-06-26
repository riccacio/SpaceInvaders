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

    virtual void initFont();
    virtual void displayAchievements(std::string title, std::string description, std::string textureName, Vector2f size);
public:
    Observer();
    virtual ~Observer() = default;

    virtual void update();
    virtual void draw(RenderTarget &target) const;
};

#endif //SPACEINVADERS_OBSERVER_H