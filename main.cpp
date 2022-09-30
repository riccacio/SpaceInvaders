#include <iostream>
#include "View/Menu.h"

int main() {
    Menu* menu = new Menu();
    //unique_ptr<Menu> menu(new Menu);
    menu->run();
    return 0;
}
