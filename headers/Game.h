#ifndef GAME_H
#define GAME_H
#include "../headers/MainWindow.h"
#include "../headers/Ship.h"
#include "../headers/Alien.h"
#include "../headers/Map.h"
//#include "../headers/GameOver.h"
#include <SFML/Audio.hpp>
#include <sstream>

class Game: public MainWindow{
private:
    void initVariables() override;
    void initText();
    //Variables
    std::shared_ptr<Ship> ship;
    std::vector<std::shared_ptr<Alien>> aliens;

private:
    Map map;
    std::vector<Text> graphicText = {};
    std::vector<Sprite> sprShipL = {};
    RectangleShape line;
    SoundBuffer shipBuffer;
    Sound shipSound;
    Texture t;
    Sprite s;
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
    void shipSoundShoot();
    void readRecord() override;
    void writeRecord() const;
};

#endif //GAME_H
