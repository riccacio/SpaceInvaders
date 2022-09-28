#ifndef SPACEINVADERS_INFO_H
#define SPACEINVADERS_INFO_H
#include <iostream>
#include <SFML/Graphics.hpp>


using namespace std;

class Info {
public:
    void run();
    void centerText(sf::Text& text, int height);
};

#endif //SPACEINVADERS_INFO_H
