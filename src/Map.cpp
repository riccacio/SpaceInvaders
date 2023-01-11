#include "../headers/Map.h"

Map::Map() {
}

//functions
void Map::createShip() {
    ship = std::make_shared<Ship>(Vector2f (0,0));
}

void Map::createAliens(int type, Vector2f pos, bool startSprite) {
    aliens->emplace_back(new Alien(type, pos, startSprite));
}

void Map::createUFO(){
    ufo = std::make_shared<UFO>(Vector2f(0, 0));
}

//getter
std::shared_ptr<Ship> Map::getShip() {
    return ship;
}

void Map::createAliens(int type, Vector2f(pos), bool startSprite) {
    aliens.emplace_back(new Alien(type, pos, startSprite));
}

const std::vector<std::shared_ptr<Alien>> &Map::getAliens() const {
    return aliens;
}

std::shared_ptr<UFO> Map::getUFO() {
    return ufo;
}