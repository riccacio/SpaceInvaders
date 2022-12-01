#include "../headers/Map.h"

Map::Map() {
}

void Map::createShip() {
    this->ship = std::make_shared<Ship>(Vector2f (0,0));
}

std::shared_ptr<Ship> Map::getShip() {
    return ship;
}

const std::vector<Bullet> &Map::getBullets() const {
    return bullets;
}
/*
void Map::creteBullets(Vector2f pos) {
    bullets.push_back(Bullet("sprite/ship_shot.png", pos));
    ship->setBullets(bullets);
    bullets.clear();
}
*/