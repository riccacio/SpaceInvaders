#include "../include/GameOver.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;

GameOver::GameOver():event(){
    this->initVariables();
    this->initWindow();
}

//Private functions
void GameOver::initVariables() {
    this->window = nullptr;
    close=false;
    for (int i = 0; i<=9; i++)
        text.emplace_back();
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

    int posX=0;
    text[0].setString("G");
    text[1].setString("A");
    text[2].setString("M");
    text[3].setString("E");
    text[4].setString(" ");
    text[5].setString("O");
    text[6].setString("V");
    text[7].setString("E");
    text[8].setString("R");
    for(int i=0; i<text.size(); i++,posX+=100){
        text[i].setFont(f);
        text[i].setFillColor(Color::White);
        text[i].setCharacterSize(70);
        text[i].setPosition(200+(float)posX,570);
    }

    //FIXME resolve sleep and stamp game over
    for(int i=0; i<text.size(); i++){
        for(int j=0;j<i+1;j++){
            this->window->draw(text[j]);
        }
        sleep(milliseconds(200));
        this->window->display();
    }
    this->window->display();
    sleep(milliseconds(4000));
    close=true;

    //TODO
    /*
     * da sistemare la chiusura di game over
     * guardare la condizione di uscita
     * cercare di stampare la scritta e far chiudere la finestra
     * di gameover in automatico
     */

}

void GameOver::run(){
    music();
    //Menu loop
    while(!close){
        //Update
        update();
        //Render
        render();
    }
}
void GameOver::music(){
    if(!buffer.loadFromFile("Sound/game_over.wav")){
        std::cout << ("ERROR: sound not found!") << std::endl;
        this->window->close();
    }
    sound.setBuffer(buffer);
    sound.play();
}
void GameOver::centerItem(Text& text, float height){
    FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width/2.0f,textRect.top  + textRect.height/2.0f);
    text.setPosition(Vector2f(WIDTH/2.0f, height));
}
