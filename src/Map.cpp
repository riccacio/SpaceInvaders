#include "../headers/Map.h"

Map::Map() {
}

void Map::createShip() {
    this->ship = std::make_shared<Ship>(Vector2f (0,0));
}

std::shared_ptr<Ship> Map::getShip() {
    return ship;
}

void Map::createAliens(int type, Vector2f(pos)) {
    aliens.emplace_back(new Alien(type, pos));
}

const std::vector<std::shared_ptr<Alien>> &Map::getAliens() const {
    return aliens;
}

void Map::draw(RenderTarget &target) {
    for(auto& a : aliens){
        target.draw(a->getSprite0());
    }
}

