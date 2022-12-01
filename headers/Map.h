#ifndef SPACEINVADERS_MAP_H
#define SPACEINVADERS_MAP_H
#include "../headers/Ship.h"

class Map {
private:
    std::shared_ptr<Ship> ship;
    std::vector<Bullet> bullets = {};
    bool firstTime;
public:
    Map();
    ~Map() = default;

    void createShip();
    //void creteBullets(Vector2f pos);
    const std::vector<Bullet> &getBullets() const;
    std::shared_ptr<Ship> getShip();
};

#endif //SPACEINVADERS_MAP_H
