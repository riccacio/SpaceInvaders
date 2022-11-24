#ifndef GAME_H
#define GAME_H
#include "../headers/MainWindow.h"
#include "../headers/Ship.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <sstream>

using namespace sf;

class Game: public MainWindow{
private:
    void initVariables() override;

    //Variables
    Font f;
    std::unique_ptr<Ship> ship;
    std::vector<Text> graphicText = {};
    std::vector<Sprite> sprShip = {};
    Texture texShip;
    RectangleShape line;
    SoundBuffer buffer;
    Sound sound;
    int record;
    int score;
    int lives;
    float rightLimit;
    float leftLimit;
    int keyTime;
public:
    //Constructor and Destructor
    Game();
    ~Game() = default;

    //Functions
    void pollEvents() override;
    void render() override;
    void run() override;
    void centerItem(Sprite& s, float height) override;
    void music();
    void checkEvent(auto& e);
    void checkKey(auto& e);
    void moveShip();
    void readRecord() override;
    void writeRecord() const;
};

#endif //GAME_H
