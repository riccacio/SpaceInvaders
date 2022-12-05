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
    void createAliens(int type, Vector2f(pos));
    std::shared_ptr<Ship> getShip();
    void draw(RenderTarget& target);
    const std::vector<std::shared_ptr<Alien>> &getAliens() const;
};

#endif //SPACEINVADERS_MAP_H
