#ifndef SPACEINVADERS_MAP_H
#define SPACEINVADERS_MAP_H
#include "../headers/Ship.h"
#include "../headers/Alien.h"
#include "../headers/UFO.h"

class Map {
private:
    std::shared_ptr<Ship> ship;
    std::vector<std::shared_ptr<Alien>> aliens;
public:
    //constructor & destructor
    Map();
    ~Map() = default;

    //functions
    void createShip();
    void createAliens(int type, Vector2f(pos), bool startSprite=true);
    std::shared_ptr<Ship> getShip();
    const std::vector<std::shared_ptr<Alien>> &getAliens() const;
};

#endif //SPACEINVADERS_MAP_H
