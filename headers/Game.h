#ifndef GAME_H
#define GAME_H
#include "../headers/MainWindow.h"
#include "../headers/Ship.h"
#include "../headers/Alien.h"
#include "../headers/Map.h"
//#include "../headers/GameOver.h"
#include <SFML/Audio.hpp>
#include <chrono>
#include <random>
#include <array>
#include <sstream>

class Game: public MainWindow{
private:

    std::mt19937_64 random_engine;

    void initVariables() override;
    void initText();
    void initItems();
    //Variables
    std::shared_ptr<Ship> ship;
    std::vector<std::shared_ptr<Alien>> aliens;
    Map map;
    std::vector<Text> graphicText = {};
    std::vector<Sprite> sprShipL = {};
    RectangleShape line;
    SoundBuffer shipBuffer;
    SoundBuffer alienBuffer1;
    SoundBuffer alienBuffer2;
    Sound shipSound;
    Sound alienSound1;
    Sound alienSound2;
    Texture t;
    Sprite s;
    int reloadTimer;
    int record;
    int score;
    int lives;
    int moveTimer;
    int timeAliens;
    float direction;
    bool changeMusic;
public:
    //Constructor and Destructor
    Game();
    ~Game() = default;

    //Functions
    void pollEvents() override;
    void render() override;
    void update() override;
    void run() override;
    void centerItem(Sprite& s, float height) override;
    void readRecord() override;
    void writeRecord() const;
    void updateScoreRecord();
    void moveAliens();
};

#endif //GAME_H
