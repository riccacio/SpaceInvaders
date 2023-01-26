#ifndef SPACEINVADERS_MAP_H
#define SPACEINVADERS_MAP_H
#include "../headers/Ship.h"
#include "../headers/Alien.h"
#include "../headers/UFO.h"

class Map {
private:
    std::shared_ptr<Ship> ship;
    std::shared_ptr<std::vector<std::shared_ptr<Alien>>> aliens;
    std::shared_ptr<UFO> ufo;
public:
    //constructor & destructor
    Map();
    ~Map() = default;

    //functions
    void createShip();
    void createAliens(int type, Vector2f pos, bool startSprite=true);
    void createUFO();

    //getter
    std::shared_ptr<Ship> getShip();
    std::shared_ptr<std::vector<std::shared_ptr<Alien>>> getAliens();
    std::shared_ptr<UFO> getUFO();
};

#endif //SPACEINVADERS_MAP_H
