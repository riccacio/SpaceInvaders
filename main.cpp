#include <iostream>
#include "headers/Menu.h"

int main() {
    std::unique_ptr<Menu> menu(new Menu);
    menu->run();
    return 0;
}
