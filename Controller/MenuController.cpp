#include "MenuController.h"
#include "../View/Info.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

MenuController::MenuController(): event(){}

void MenuController::keyPressed(){
    if (event.type== Event::KeyReleased){
        if(event.key.code == Keyboard::H){
            unique_ptr<Info> info(new Info);
            info->run();
        }
    }
}