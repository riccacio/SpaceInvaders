#include "../headers/Game.h"
//#include "../headers/GameOver.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <fstream>

using namespace sf;

Game::Game(): record(0),lives(3), score(0){
    this->initVariables();
    this->initWindow();
}

//Functions
void Game::initVariables() {
    this->window = nullptr;
    for(int j=0; j<lives; j++)
        sprShip.emplace_back();
    for(int j=0; j<5; j++)
        graphicText.emplace_back();
    this->ship = std::make_unique<Ship>();
    centerItem(ship->getSprShip(), ship->getY());
    readRecord();
}

void Game::pollEvents() {
    ship->update();
    //Event polling
    while (this->window->pollEvent(this->event)){
        switch (this->event.type){
            case Event::Closed:
                this->window->close();
                break;
            default:
                break;
        }
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

    graphicText[0].setString("HI-SCORE: ");
    graphicText[1].setString("SCORE: ");
    graphicText[2].setString("LIVES: ");
    std::stringstream ss2;
    std::string s2;
    graphicText[3].setString(recordS);
    ss2<<score;
    ss2>>s2;
    graphicText[4].setString(s2);

    line.setSize(Vector2f(1240, 10));
    line.setFillColor(Color::Green);
    line.setPosition(20, 1270);

    for(int j=0; j<5; j++){
        graphicText[j].setFont(f);
        graphicText[j].setCharacterSize(32);
    }

    graphicText[0].setPosition(30,20);//HISCORE
    graphicText[3].setPosition(310,20);//RECORD
    graphicText[1].setPosition(900,20);//SCORE
    graphicText[4].setPosition(1100,20);//SCORE NUM
    graphicText[2].setPosition(20, 1315);//LIVES

    float p=215;
    for(int j=0; j<lives; j++){
        sprShip[j].setTexture(texShip);
        sprShip[j].setScale(3,3);
        sprShip[j].setPosition(p,1290);
        p+=120;
    }

    this->window->clear();
    if(record<score)
        writeRecord();
    for(int j=0; j<5; j++)
        this->window->draw(graphicText[j]);
    for(int j=0; j<lives; j++)
        this->window->draw(sprShip[j]);
    this->window->draw(line);
    this->window->draw(ship->getSprShip());
    this->window->display();
}

void Game::run(){
    //music();
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

void Game::writeRecord() const {
    std::ofstream oFile("record.txt");
    if (oFile.is_open())
    {
        std::stringstream ss;
        std::string str;
        ss << score;
        str = ss.str();
        oFile << str;
        oFile.close();
    }
}
void Game::readRecord() {
    std::ifstream iFile("record.txt");
    if (iFile.is_open()){
        getline(iFile, recordS);
        record = std::stoi(recordS);//convert string to int
        iFile.close();
    }
}

void Game::centerItem(Sprite& sprite, float height){
    FloatRect textRect = sprite.getLocalBounds();
    sprite.setOrigin(textRect.left + textRect.width/2.0f,textRect.top  + textRect.height/2.0f);
    sprite.setPosition(Vector2f((WIDTH/2.0f)-(static_cast<float>(ship->getWidth())/2.0f), height));
    ship->setX((WIDTH/2.0f)-(static_cast<float>(ship->getWidth())/2.0f));
}
