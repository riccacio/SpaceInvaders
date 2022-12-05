#ifndef SPACEINVADERS_MAP_H
#define SPACEINVADERS_MAP_H
#include "../headers/Ship.h"
#include "../headers/Alien.h"

class Map {
private:
    std::shared_ptr<Ship> ship;
    std::vector<std::shared_ptr<Alien>> aliens;
public:
    Map();
    ~Map() = default;

    void createShip();
    void createAliens(int type);
    std::shared_ptr<Ship> getShip();
    //const std::vector<Alien> &getAliens() const;
    const std::vector<std::shared_ptr<Alien>> &getAliens() const;
};

#endif //SPACEINVADERS_MAP_H
