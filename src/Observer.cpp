#include "../headers/Observer.h"

Observer::Observer() {
    initFont();
}

void Observer::initFont() {
    textF.loadFromFile("font/arcade.TTF");
}


