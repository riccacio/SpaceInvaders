#include "../include/GameOver.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;

GameOver::GameOver():i(0){
    this->initWindow();
}

//Functions
void GameOver::render(){
    if(!f.loadFromFile("font/arcade.TTF")) {
        std::cout << ("ERROR: font not found!") << std::endl;
        this->window->close();
    }
    text.setString("G A M E  O V E R");
    exit.setString("PRESS ESC TO EXIT");
    text.setFont(f);
    exit.setFont(f);
    text.setFillColor(Color::White);
    sleep(milliseconds(250)); // 0.25sec
    if(i==0){
        exit.setFillColor(Color::Green);
        i=1;
    }
    else{
        exit.setFillColor(Color::Black);
        i=0;
    }

    text.setCharacterSize(70);
    exit.setCharacterSize(30);
    centerItem(text, 570);
    centerItem(exit, 1200);
    this->window->clear();
    this->window->draw(text);
    this->window->draw(exit);
    this->window->display();
}

void GameOver::run(){
    music();
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
        this->window->close();
    }
    sound.setBuffer(buffer);
    sound.play();
}