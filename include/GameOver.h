#ifndef GAMEOVER_H
#define GAMEOVER_H
#include "../include/MainWindow.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;

class GameOver: public MainWindow {
public:
    //Constructor & Destructor
    GameOver();
    ~GameOver() = default;

    //Functions
    void render() override;
    void run() override;
    void music();
private:
    //Variables
    Font f;
    Text text;
    Text exit;
    SoundBuffer buffer;
    Sound sound;
    int i;
};

#endif //GAMEOVER_H
