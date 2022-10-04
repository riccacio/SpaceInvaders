#include "../include/GameOver.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <unistd.h>

using namespace sf;

GameOver::GameOver(){
    this->initVariables();
    this->initWindow();
}

//Private functions
void GameOver::initVariables() {
    this->window = nullptr;

}
void GameOver::initWindow() {
    this->videoMode.height = HEIGHT;
    this->videoMode.width = WIDTH;
    this->window = std::make_unique<RenderWindow>(this->videoMode, "Space Invaders - Game Over", Style::Titlebar | Style::Close);
}

//Functions
bool GameOver::running() const {
    return this->window->isOpen();
}

void GameOver::pollEvents() {
    //Event polling
    while (this->window->pollEvent(this->event)){
        switch (this->event.type){
            case Event::Closed:
                this->window->close();
                break;
            case Event::KeyPressed:
                if(event.key.code == Keyboard::Escape){
                    this->window->close();
                }
                break;
            default:
                break;
        }
    }
}

void GameOver::update(){
    this->pollEvents();
}

void GameOver::render(){
    if(!f.loadFromFile("Font/arcade.TTF")) {
        std::cout << ("ERROR: font not found!") << std::endl;
        this->window->close();
    }
    int posx=0;
    title[0].setString("G");
    title[1].setString("A");
    title[2].setString("M");
    title[3].setString("E");
    title[4].setString(" ");
    title[5].setString("O");
    title[6].setString("V");
    title[7].setString("E");
    title[8].setString("R");
    for(int i=0; i<9; i++,posx+=100){
        title[i].setFont(f);
        title[i].setFillColor(Color::White);
        title[i].setCharacterSize(70);
        title[i].setPosition(200+posx,370);
    }

    //FIXME resolve sleep and stamp game over
    //sleep(milliseconds(1000));
    sleep(milliseconds(100)); // 0.1sec
    int i;
    if(i==0){
        title[0].setFillColor(Color::White);
        i=1;
    }
    else{
        title[0].setFillColor(Color::Black);
        i=0;
    }
    this->window->clear();

    for(int i=0; i<9; i++){
        this->window->draw(title[i]);
    }
    this->window->display();
}

void GameOver::run(){
    music();
    //Menu loop
    while(running()){
        //Update
        update();
        //Render
        render();
    }
}
void GameOver::centerItem(Text& text, float height){
    FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width/2.0f,textRect.top  + textRect.height/2.0f);
    text.setPosition(Vector2f(WIDTH/2.0f, height));
}
void GameOver::music(){
    if(!buffer.loadFromFile("Sound/game_over.wav")){
        std::cout << ("ERROR: sound not found!") << std::endl;
        this->window->close();
    }
    sound.setBuffer(buffer);
    sound.play();
}