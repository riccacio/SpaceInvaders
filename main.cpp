#include <iostream>
#include "View/Menu.h"

int main() {
    unique_ptr<Menu> menu(new Menu);
    menu->run();
    return 0;
}
