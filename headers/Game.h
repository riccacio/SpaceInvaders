#ifndef GAME_H
#define GAME_H
#include "../headers/MainWindow.h"
#include "../headers/Ship.h"
#include "../headers/Alien.h"
#include "../headers/Map.h"
#include "../headers/GameOver.h"
#include <chrono>
#include <random>
#include <array>
#include <iostream>
#include <sstream>
#include <SFML/Audio.hpp>

class Game: public MainWindow{
private:
    std::shared_ptr<Ship> ship;
    std::vector<std::shared_ptr<Alien>> aliens;
    Map map;
    std::vector<Text> graphicText = {};
    std::vector<Sprite> sprShipL = {};
    std::mt19937_64 random_engine;
    RectangleShape line;
    SoundBuffer shipBuffer;
    SoundBuffer shipExpBuffer;
    SoundBuffer alienBuffer1;
    SoundBuffer alienBuffer2;
    SoundBuffer alienExpBuffer;
    Sound shipSound;
    Sound shipExpSound;
    Sound alienSound1;
    Sound alienSound2;
    Sound alienExpSound;
    Clock clock;
    Clock clockUFO;
    Time invincibilityTime;
    Time spawnUfoTime;

    int reloadTimer;
    int record;
    int score;
    int lives;
    int moveTimer;
    int timeAliens;
    float direction;
    bool changeMusic;
    float speedAlien;

    void initVariables() override;
    void initItems();
    void initText();
public:
    //constructor & destructor
    Game();
    ~Game() = default;

    //functions
    void run() override;
    void pollEvents() override;
    void update() override;
    void render() override;
    void createShip();
    void centerItem(Sprite& s, float height) override;
    void updateScoreRecord();
    void moveAliens();
};

#endif //GAME_H
