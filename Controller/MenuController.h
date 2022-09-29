#ifndef SPACEINVADERS_MENUCONTROLLER_H
#define SPACEINVADERS_MENUCONTROLLER_H
#include <SFML/Graphics.hpp>

class MenuController {
public:
    MenuController();

    void keyPressed();
private:
    sf::Event event;
};


#endif //SPACEINVADERS_MENUCONTROLLER_H
