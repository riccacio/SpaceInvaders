#include "../headers/GameOver.h"

using namespace sf;

GameOver::GameOver():i(0){
    initWindow();
    initFont();
    initText();
    music();
}

//Functions
void GameOver::render(){
    window->clear();
    window->draw(text);
    window->draw(exit);
    window->display();
}

void GameOver::run(){
    while(running()){
        //Update
        update();
        //Render
        render();
    }
}
void GameOver::music(){
    if(!buffer.loadFromFile("sound/game_over.wav")){
        std::cout << ("ERROR: sound not found!") << std::endl;
        window->close();
    }
    sound.setBuffer(buffer);
    sound.play();
}

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
void GameOver::update() {
    MainWindow::update();
    sleep(milliseconds(250)); // 0.25sec
    if(i==0){
        exit.setFillColor(Color::Green);
        i=1;
    }
    else{
        exit.setFillColor(Color::Black);
        i=0;
    }
}