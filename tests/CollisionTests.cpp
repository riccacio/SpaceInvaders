#include "gtest/gtest.h"
#include <SFML/Graphics.hpp>
#include "../headers/Game.h"

TEST(Game, checkDeadAliens) {
    std::unique_ptr<Game> game(new Game(0,3,0, 0, 0));
    int initialAlienCount = game->getAliens()->size();

    sf::Vector2f bulletPosition = (*game->getAliens())[35]->getPosition();
    game->getShip()->getBullets()->emplace_back(bulletPosition, Bullet::Type::SHIP);

    game->checkDeadAliens();

    int expectedAlienCount = initialAlienCount - 1;
    int actualAlienCount = game->getAliens()->size();

    std::cout << "Initial alien count: " << initialAlienCount << std::endl;
    std::cout << "Expected alien count: " << expectedAlienCount << std::endl;
    std::cout << "Actual alien count: " << actualAlienCount << std::endl;

    EXPECT_EQ(actualAlienCount, expectedAlienCount);
}

