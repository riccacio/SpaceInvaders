#ifndef GAMEOVER_H
#define GAMEOVER_H
#include "../headers/MainWindow.h"
#include <SFML/Audio.hpp>


class GameOver: public MainWindow {
private:
    void initText();
    //Variables
    Text text;
    Text exit;
    SoundBuffer buffer;
    Sound sound;
    int i;
public:
    //Constructor & Destructor
    GameOver();
    ~GameOver() = default;

    //Functions
    void render() override;
    void update() override;
    void run() override;
    void music();
};

#endif //GAMEOVER_H
