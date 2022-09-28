#include <iostream>
#include "View/Menu.h"
#include "View/Info.h"

int main() {
    unique_ptr<Menu> menu(new Menu);
    menu->run();
    /*unique_ptr<Info> info(new Info);
    info->run();*/
    return 0;
}
