#ifndef SPACEINVADERS_MENU_H
#define SPACEINVADERS_MENU_H
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

class Menu{
public:
    Menu();
    void run();
    void centerText(sf::Text& text, int height);
private:
    int record;
};

#endif //SPACEINVADERS_MENU_H
