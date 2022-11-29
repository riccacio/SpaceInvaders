#ifndef GAME_H
#define GAME_H
#include "../headers/MainWindow.h"
#include "../headers/Ship.h"
#include "../headers/Map.h"
//#include "../headers/GameOver.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <sstream>
#include <fstream>

using namespace sf;

class Game: public MainWindow{
private:
    void initVariables() override;
    void initText();
    //Variables
    std::shared_ptr<Ship> ship;
    Map map;
    std::vector<Text> graphicText = {};
    std::vector<Sprite> sprShipL = {};
    RectangleShape line;
    SoundBuffer buffer;
    Sound sound;
    int reloadTimer;
    int record;
    int score;
    int lives;
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
    void music();
    void readRecord() override;
    void writeRecord() const;
};

#endif //GAME_H
