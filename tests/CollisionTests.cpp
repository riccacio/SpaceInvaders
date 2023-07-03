#include "gtest/gtest.h"
#include <SFML/Graphics.hpp>
#include "../headers/Game.h"

//check ship bullet vs Alien
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
// check alien bullet vs ship
TEST(Alien, checkCollision) {
    std::unique_ptr<Game> game(new Game(0,3,0, 0, 0));
    std::unique_ptr<Alien> alien(new Alien(Alien::Type::ALIEN1, Vector2f{55, 120}));

    sf::Vector2f shipPosition = (game->getShip()->getPosition());
    alien->getBullets().emplace_back(shipPosition, Bullet::Type::ALIEN);

    ASSERT_TRUE(alien->checkCollision(game->getShip()->getHitBox()));

}
//check ship bullet vs shield
TEST(Game, checkHitShields) {
    std::unique_ptr<Game> game(new Game(0,3,0, 0, 0));
    int initialShieldCount = game->getShields()->size();

    sf::Vector2f bulletPosition = (*game->getShields())[16]->getSprite().getPosition();
    game->getShip()->getBullets()->emplace_back(bulletPosition, Bullet::Type::SHIP);

    game->checkHitShields();
    game->getShip()->getBullets()->emplace_back(bulletPosition, Bullet::Type::SHIP);
    game->checkHitShields();

    int expectedShieldCount = initialShieldCount - 1;
    int actualShieldCount = game->getShields()->size();

    std::cout << "Initial shield count: " << initialShieldCount << std::endl;
    std::cout << "Expected shield count: " << expectedShieldCount << std::endl;
    std::cout << "Actual shield count: " << actualShieldCount << std::endl;

    EXPECT_EQ(actualShieldCount, expectedShieldCount);

}
//check the dropped powerUp vs Ship
TEST(Ufo, checkCollisionPU) {
    std::unique_ptr<UFO> ufo(new UFO(Vector2f{565,200}));
    std::unique_ptr<Game> game(new Game(0,3,0, 0, 0));

    sf::Vector2f shipPosition = (game->getShip()->getPosition());
    ufo->setType(2);
    ufo->dropPowerUp(shipPosition);

    ASSERT_TRUE(ufo->checkCollisionPU(game->getShip()->getHitBox()));
}

