#include "../include/Menu.h"
#include "../include/Info.h"
#include "../include/Game.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;

Menu::Menu():record(6223), i(0){
    this->initVariables();
    this->initWindow();
}

//Functions
void Menu::initVariables() {
    this->window = nullptr;
    for (int j = 0; j<=5; j++)
        graphicText.emplace_back();
}

void Menu::pollEvents() {
    //Event polling
    while (this->window->pollEvent(this->event)){
        switch (this->event.type){
            case Event::Closed:
                this->window->close();
                break;
            case Event::KeyPressed:
                checkEvent(event.key.code);
            default:
                break;
        }
    }
}

void Menu::checkEvent(auto& e){
    switch (e) {
        case Keyboard::Escape:
            this->window->close();
            break;
        case Keyboard::H:{
            std::unique_ptr<Info> info(new Info);
            info->run();
            break;
        }
        case Keyboard::Space:{
            this->window->close();
            sound.stop();
            std::unique_ptr<Game> game(new Game);
            game->run();
            break;
        }
        default:
            break;
    }
}

void Menu::render() {
    if(!f.loadFromFile("font/arcade.TTF")){
        std::cout << ("ERROR: font not found!") << std::endl;
        this->window->close();
    }
    if(!texShip.loadFromFile("sprite/ship.png")){
        std::cout << ("ERROR: sprite ship not found!") << std::endl;
        this->window->close();
    }

    graphicText[0].setString("SPACE INVADERS");
    graphicText[1].setString("HOW TO PLAY (H)");
    graphicText[2].setString("PRESS SPACE TO START");
    graphicText[3].setString("HI-SCORE: ");
    graphicText[4].setString(recordS);

    for (int j = 0; j<=5; j++){
        graphicText[j].setFont(f);
        graphicText[j].setFillColor(Color::White);
    }

    graphicText[0].setCharacterSize(60);
    graphicText[1].setCharacterSize(25);
    graphicText[2].setCharacterSize(30);
    graphicText[3].setCharacterSize(32);
    graphicText[4].setCharacterSize(32);

    centerItem(graphicText[0], 370);
    centerItem(graphicText[1], 550);
    centerItem(graphicText[2], 750);
    centerItem(sprShip, 950);

    graphicText[3].setPosition(30,20);
    graphicText[4].setPosition(310,20);

    sprShip.setTexture(texShip);
    sprShip.setScale(7,7);

    //flashing text
    sleep(milliseconds(100)); // 0.1sec
    if(i==0){
        graphicText[2].setFillColor(Color::White);
        i=1;
    }
    else{
        graphicText[2].setFillColor(Color::Black);
        i=0;
    }
    this->window->clear();
    readRecord();
    for (int j = 0; j<=5; j++)
        this->window->draw(graphicText[j]);
    this->window->draw(sprShip);
    this->window->display();
}

void Menu::run(){
    music();
    while(running()){
        //Update
        update();
        //Render
        render();
    }
}

void Menu::music(){
    if(!buffer.loadFromFile("sound/menu.wav")){
        std::cout << ("ERROR: sound not found!") << std::endl;
        this->window->close();
    }
    sound.setBuffer(buffer);
    sound.play();
    sound.setLoop(true);
}