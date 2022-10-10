#include "../include/Info.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

Info::Info(){
    this->initVariables();
    this->initWindow();
}

//Private functions
void Info::initVariables() {
    this->window = nullptr;
    for (int i = 0; i<=4; i++){
        aliensT.emplace_back();
        aliensS.emplace_back();
    }
    for (int i = 0; i<=9; i++)
        graphicText.emplace_back();
}

void Info::pollEvents() {
    //Event polling
    while (this->window->pollEvent(this->event)){
        switch (this->event.type){
            case Event::Closed:
                this->window->close();
                break;
            case Event::KeyPressed:
                if (event.key.code == Keyboard::Escape ||
                        event.key.code == Keyboard::B) {
                    this->window->close();
                }
                break;
            default:
                break;
        }
    }
}

void Info::render() {
    if (!f.loadFromFile("font/arcade.TTF")) {
        std::cout << ("ERROR: font not found!") << std::endl;
        this->window->close();
    }
    if (!aliensT[0].loadFromFile("sprite/mystery.png")) {
        std::cout << ("ERROR: sprite not found!") << std::endl;
        this->window->close();
    }
    if (!aliensT[1].loadFromFile("sprite/alien1_0.png")) {
        std::cout << ("ERROR: sprite not found!") << std::endl;
        this->window->close();
    }
    if (!aliensT[2].loadFromFile("sprite/alien2_0.png")) {
        std::cout << ("ERROR: sprite not found!") << std::endl;
        this->window->close();
    }
    if (!aliensT[3].loadFromFile("sprite/alien3_0.png")) {
        std::cout << ("ERROR: sprite not found!") << std::endl;
        this->window->close();
    }

    for(int i=0; i<9; i++)
        graphicText[i].setFont(f);

    graphicText[0].setString("HOW TO PLAY"); // title
    graphicText[1].setString("SHOT = PRESS SPACE"); // shot
    graphicText[2].setString("LEFT = LEFT ARROW"); // left
    graphicText[3].setString("RIGHT = RIGHT ARROW"); // right
    graphicText[4].setString("= ? MYSTERY"); // mysterious
    graphicText[5].setString("= 30 POINTS"); // alien1
    graphicText[6].setString("= 20 POINTS"); // alien2
    graphicText[7].setString("= 10 POINTS"); // alien3
    graphicText[8].setString("PRESS B TO BACK TO MENU"); // back

    for (int i = 0; i < 4; i++) {
        aliensS[i].setTexture(aliensT[i]);
        aliensS[i].setScale(4, 4);
    }
    for(int i=0; i<8; i++)
        graphicText[i].setFillColor(Color::White);
    graphicText[8].setFillColor(Color::Green);

    graphicText[0].setCharacterSize(55);
    for(int i=1; i<8; i++)
        graphicText[i].setCharacterSize(40);
    graphicText[8].setCharacterSize(30);

    centerItem(graphicText[0], 150);
    centerItem(graphicText[1], 350);
    centerItem(graphicText[8], 1200);

    graphicText[2].setPosition(297, 440);
    graphicText[3].setPosition(297, 550);
    graphicText[4].setPosition(520, 660);
    aliensS[0].setPosition(330, 655);
    graphicText[5].setPosition(520, 780);
    aliensS[1].setPosition(330, 750);
    graphicText[6].setPosition(520, 900);
    aliensS[2].setPosition(330, 870);
    graphicText[7].setPosition(520, 1010);
    aliensS[3].setPosition(330, 980);

    this->window->clear();
    for(int i=0; i<4; i++)
        this->window->draw(aliensS[i]);
    for(int i=0; i<9; i++)
        this->window->draw(graphicText[i]);
    this->window->display();
}