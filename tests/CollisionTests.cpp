#include "gtest/gtest.h"
#include <SFML/Graphics.hpp>
#include "../headers/Game.h"

TEST(Game, checkDeadAliens) {
    std::unique_ptr<Game> game(new Game);
    int initialAlienCount = game->getAliens()->size();

    sf::Texture texShot;
    texShot.loadFromFile("sprite/ship_shot.png");

    sf::Vector2f bulletPosition = (*game->getAliens())[35]->getPositionA();
    game->getShip()->getBullets()->emplace_back(texShot, texShot, bulletPosition);

    game->checkDeadAliens();

    int expectedAlienCount = initialAlienCount - 1;
    int actualAlienCount = game->getAliens()->size();

    std::cout << "Initial alien count: " << initialAlienCount << std::endl;
    std::cout << "Expected alien count: " << expectedAlienCount << std::endl;
    std::cout << "Actual alien count: " << actualAlienCount << std::endl;

    EXPECT_EQ(actualAlienCount, expectedAlienCount);
}

