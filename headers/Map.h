#ifndef SPACEINVADERS_MAP_H
#define SPACEINVADERS_MAP_H
#include "../headers/Ship.h"

class Map {
private:
    std::shared_ptr<Ship> ship;
public:
    Map();
    ~Map() = default;

    void createShip();
    std::shared_ptr<Ship> getShip();
};

#endif //SPACEINVADERS_MAP_H
