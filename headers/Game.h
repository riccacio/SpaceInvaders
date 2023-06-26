#ifndef GAME_H
#define GAME_H
#include "../headers/MainWindow.h"
#include "../headers/Ship.h"
#include "../headers/Alien.h"
#include "../headers/Map.h"
#include "../headers/GameOver.h"
#include "../headers/AliensDestroyedAchievement.h"
#include "../headers/AchievementDataHandler.h"
#include "../headers/ExtraLifeAchievements.h"
#include "../headers/GoodJobAchievement.h"
#include <chrono>
#include <random>
#include <iostream>
#include <sstream>
#include <SFML/Audio.hpp>

class Game: public MainWindow{
public:
    std::shared_ptr<Ship> ship;
    std::shared_ptr<std::vector<std::shared_ptr<Alien>>> aliens;
    std::shared_ptr<std::vector<std::shared_ptr<Shield>>> shields;
    std::shared_ptr<UFO> ufo;
    Map map;

    AchievementDataHandler handler;
    std::shared_ptr<AliensDestroyedAchievement> killObserver;
    std::shared_ptr<ExtraLifeAchievements> lifeObserver;
    std::shared_ptr<GoodJobAchievement> goodJobObserver;

    std::vector<Text> graphicText = {};
    std::vector<Sprite> sprShipL = {};
    std::vector<SoundBuffer> soundBuffers = {};
    std::vector<Sound> sounds = {};
    std::mt19937_64 random_engine;
    RectangleShape line;
    RectangleShape powerUpBar;

    Clock clock;
    Clock clockUFO;
    Clock clockAch;
    Time invincibilityTime;
    Time spawnUfoTime;
    Time timerAch;

    int reloadTimer;
    int record;
    int score;
    int lives;
    int moveTimer;
    int timeAliens;
    int stage;
    float direction;
    bool changeMusic;
    int ufoPlayingMusic;
    int speedAlienLevel;
    float speedAlien;
    float powerupDuration;
    bool livesIncremented;
    bool lifeLost;

    void initVariables() override;
    void initItems();
    void initText();
public:
    //constructor
    Game(int score, int lives, int speedAlienLevel, int stage, bool life);

    //functions
    void run() override;
    void pollEvents() override;
    void update() override;
    void render() override;
    void centerItem(Sprite& s, float height) override;

    void createShip();
    void updateScoreRecord();
    void moveAliens();
    void checkDeadAliens();
    void checkHitShields();
    void checkHitAlienBulletShields();
    void checkHitAlienShields();
    void checkEndLevel();
    void checkGameOver();

    void readRecord() override;
    void writeRecord() const;
    void stopMusic();

    //getter
    const std::shared_ptr<Ship> &getShip() const;
    const std::shared_ptr<std::vector<std::shared_ptr<Alien>>> &getAliens() const;
};

#endif //GAME_H