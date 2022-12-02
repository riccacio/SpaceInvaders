#include "../headers/Map.h"

Map::Map() {
}

void Map::createShip() {
    this->ship = std::make_shared<Ship>(Vector2f (0,0));
}

std::shared_ptr<Ship> Map::getShip() {
    return ship;
}
