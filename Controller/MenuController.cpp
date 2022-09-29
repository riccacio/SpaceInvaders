#include "MenuController.h"
#include "../View/Info.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

void keyPressed(){
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::H)){
        unique_ptr<Info> info(new Info);
        info->run();
    }
}