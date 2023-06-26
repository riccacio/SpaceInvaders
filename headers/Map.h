#ifndef SPACEINVADERS_MAP_H
#define SPACEINVADERS_MAP_H
#include "../headers/Ship.h"
#include "../headers/Alien.h"
#include "../headers/UFO.h"
#include "../headers/Shield.h"

class Map {
private:
    std::shared_ptr<Ship> ship;
    std::shared_ptr<std::vector<std::shared_ptr<Alien>>> aliens;
    std::shared_ptr<std::vector<std::shared_ptr<Shield>>> shields;
    std::shared_ptr<UFO> ufo;
public:
    //constructor & destructor
    Map();
    ~Map() = default;

    //functions
    void createShip();
    void createAliens(Alien::Type type, Vector2f pos, bool startSprite=true);
    void createUFO();
    void createShields(Shield::Type type, Vector2f pos);

    //getter
    std::shared_ptr<Ship> getShip();
    std::shared_ptr<std::vector<std::shared_ptr<Alien>>> getAliens();
    std::shared_ptr<UFO> getUFO();
    std::shared_ptr<std::vector<std::shared_ptr<Shield>>> getShields();
};

#endif //SPACEINVADERS_MAP_H