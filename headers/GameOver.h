#ifndef GAMEOVER_H
#define GAMEOVER_H
#include "../headers/MainWindow.h"
#include <SFML/Audio.hpp>

class GameOver: public MainWindow {
private:
    Text text;
    Text exit;
    SoundBuffer buffer;
    Sound sound;

    int i;

    void initText();
public:
    //constructor & destructor
    GameOver();

    //functions
    void run() override;
    void update() override;
    void render() override;
    void music();
};

#endif //GAMEOVER_H