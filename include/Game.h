#ifndef GAME_H
#define GAME_H
#include "../include/MainWindow.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <sstream>

using namespace sf;

class Game: public MainWindow{
public:
    //Constructor and Destructor
    Game();
    ~Game() = default;

    //Functions
    void pollEvents() override;
    void render() override;
    void run() override;
    void music();
    void checkEvent(auto& e);
private:
    void initVariables() override;

    //Variables
    Font f;
    Text hiscore;
    Text recordText;
    Text scoreText;
    Text scoreTextNum;
    Text livesText;
    Texture texShip;
    RectangleShape line;
    std::vector<Sprite> sprShip = {};
    SoundBuffer buffer;
    Sound sound;
    int record;
    int score;
    int lives;
};

#endif //GAME_H
