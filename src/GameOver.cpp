#include "../headers/GameOver.h"

GameOver::GameOver() : i(0){
    initWindow();
    initFont();
    initText();
    music();
}

//functions
void GameOver::initText() {
    text.setString("G A M E  O V E R");
    exit.setString("PRESS ESC TO EXIT");
    text.setFont(f);
    exit.setFont(f);
    text.setFillColor(Color::White);
    text.setCharacterSize(70);
    exit.setCharacterSize(30);
    centerItem(text, 570);
    centerItem(exit, 1200);
}

void GameOver::run(){
    while(running()){
        update();
        render();
    }
}

void GameOver::update() {
    MainWindow::update();
    sleep(milliseconds(200)); // 0.2sec
    if(i==0){
        exit.setFillColor(Color::Green);
        i=1;
    }
    else{
        exit.setFillColor(Color::Black);
        i=0;
    }
}
void GameOver::render(){
    window->clear();
    window->draw(text);
    window->draw(exit);
    window->display();
}

void GameOver::music(){
    buffer.loadFromFile("sound/game_over.wav");
    sound.setBuffer(buffer);
    sound.play();
}

