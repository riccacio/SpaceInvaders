#ifndef SPACEINVADERS_MENU_H
#define SPACEINVADERS_MENU_H
#include <iostream>

using namespace std;

class Menu{
public:
    Menu();
    ~Menu();

    void run();
private:
    int record = 3950;
};

#endif //SPACEINVADERS_MENU_H
