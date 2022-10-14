#include "../include/Game.h"
//#include "../include/GameOver.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <fstream>

using namespace sf;

Game::Game(): lives(3), score(0), leftLimit(0), rightLimit(static_cast<float>(WIDTH-ship->getWidth())), keyTime(25){
    this->initVariables();
    this->initWindow();
}

//Functions
void Game::initVariables() {
    this->window = nullptr;
    for(int j=0; j<lives; j++)
        sprShip.emplace_back();
    this->ship = std::make_unique<Ship>();
}

void Game::pollEvents() {
    //Event polling
    while (this->window->pollEvent(this->event)){
        switch (this->event.type){
            case Event::Closed:
                this->window->close();
                break;
                //se metto qui lo spazio funziona
            default:
                break;
        }
    }
    if(keyTime <= ship->getShotFrequency())
        keyTime++;
    checkEvent(event.key.code);
}

void Game::checkEvent(auto& e){
    switch (this->event.type){
        case Event::KeyPressed:
            checkKey(e);
            break;
        default:
            break;
    }
}

void Game::checkKey(auto &e) {
    switch (e){
        case Keyboard::Escape:
            this->window->close();
            break;
        //FIXME spazio non va
        case Keyboard::Space:
            if(keyTime >= ship->getShotFrequency()){
                keyTime=0;
                //shoot
                std::cout << "sparo" << std::endl;
                score+=10;
            }
            break;
        case Keyboard::Left:
            if(ship->getX()>=leftLimit){
                ship->setDirection(-1);
                Game::moveShip();
                ship->setX(ship->getX()-ship->getSpeed());
            }
            break;
        case Keyboard::Right:
            if(ship->getX()<=rightLimit){
                ship->setDirection(1);
                Game::moveShip();
                ship->setX(ship->getX()+ship->getSpeed());
            }
            break;
        default:
            break;
    }
}
void Game::render() {
    if(!f.loadFromFile("font/arcade.TTF")){
        std::cout << ("ERROR: font not found!") << std::endl;
        this->window->close();
    }
    if(!texShip.loadFromFile("sprite/ship.png")){
        std::cout << ("ERROR: sprite ship not found!") << std::endl;
        this->window->close();
    }
    ship->setTexShip(texShip);
    ship->getSprShip().setTexture(texShip);
    ship->getSprShip().setScale(4,4);

    hiscore.setString("HI-SCORE: ");
    scoreText.setString("SCORE: ");
    livesText.setString("LIVES: ");
    std::stringstream ss2;
    std::string s2;
    recordText.setString(recordS);
    ss2<<score;
    ss2>>s2;
    scoreTextNum.setString(s2);

    line.setSize(Vector2f(1240, 10));
    line.setFillColor(Color::Green);
    line.setPosition(20, 1270);

    hiscore.setFont(f);
    recordText.setFont(f);
    scoreText.setFont(f);
    scoreTextNum.setFont(f);
    livesText.setFont(f);

    hiscore.setCharacterSize(32);
    recordText.setCharacterSize(32);
    scoreText.setCharacterSize(32);
    scoreTextNum.setCharacterSize(32);
    livesText.setCharacterSize(32);
    hiscore.setPosition(30,20);
    recordText.setPosition(310,20);
    scoreText.setPosition(900,20);
    scoreTextNum.setPosition(1100,20);
    livesText.setPosition(20, 1315);
    float p=215;
    for(int j=0; j<lives; j++){
        sprShip[j].setTexture(texShip);
        sprShip[j].setScale(3,3);
        sprShip[j].setPosition(p,1290);
        p+=120;
    }

    this->window->clear();
    readRecord();
    writeRecord();
    this->window->draw(hiscore);
    this->window->draw(recordText);
    this->window->draw(scoreText);
    this->window->draw(scoreTextNum);
    this->window->draw(livesText);
    this->window->draw(line);
    this->window->draw(ship->getSprShip());
    for(int j=0; j<lives; j++)
        this->window->draw(sprShip[j]);
    this->window->display();
}

void Game::run(){
    //music();
    centerItem(ship->getSprShip(), ship->getY());
    while(running()){
        //Update
        update();
        //Render
        render();
    }
}

void Game::music(){
    if(!buffer.loadFromFile("sound/menu.wav")){
        std::cout << ("ERROR: sound not found!") << std::endl;
        this->window->close();
    }
    sound.setBuffer(buffer);
    sound.play();
    sound.setLoop(true);
}
void Game::moveShip(){
    ship->getSprShip().move(ship->getSpeed()*static_cast<float>(ship->getDirection()),0.0f);
}

void Game::writeRecord() {
    std::ofstream oFile("record.txt");
    if (oFile.is_open())
    {
        std::stringstream ss;
        ss << score;
        std::string line = ss.str();
        oFile << line;
        oFile.close();
    }
}

void Game::centerItem(Sprite& sprite, float height){
    FloatRect textRect = sprite.getLocalBounds();
    sprite.setOrigin(textRect.left + textRect.width/2.0f,textRect.top  + textRect.height/2.0f);
    sprite.setPosition(Vector2f((WIDTH/2.0f)-(static_cast<float>(ship->getWidth())/2.0f), height));
    ship->setX((WIDTH/2.0f)-(static_cast<float>(ship->getWidth())/2.0f));
}