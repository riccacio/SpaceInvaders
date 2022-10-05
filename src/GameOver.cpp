#include "../include/GameOver.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;

GameOver::GameOver():event(), i(0){
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
    this->window->draw(text);
    this->window->draw(exit);
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
