#include "../headers/Info.h"
#include <SFML/Graphics.hpp>

using namespace sf;

Info::Info(){
    initVariables();
    initWindow();
    initFont();
    initText();
}

//Private functions
void Info::initVariables() {
    window = nullptr;
    for (int i = 0; i<=4; i++){
        aliensT.emplace_back();
        aliensS.emplace_back();
    }
    for (int i = 0; i<=9; i++)
        graphicText.emplace_back();
}

void Info::pollEvents() {
    //Event polling
    while (window->pollEvent(event)){
        switch (event.type){
            case Event::Closed:
                window->close();
                break;
            case Event::KeyPressed:
                if (event.key.code == Keyboard::Escape ||
                        event.key.code == Keyboard::B) {
                    window->close();
                }
                break;
            default:
                break;
        }
    }
}

void Info::render() {
    window->clear();
    for(int i=0; i<4; i++)
        window->draw(aliensS[i]);
    for(int i=0; i<9; i++)
        this->window->draw(graphicText[i]);
    window->display();
}

void Info::initText() {
    aliensT[0].loadFromFile("sprite/mystery.png");
    aliensT[1].loadFromFile("sprite/alien1_0.png");
    aliensT[2].loadFromFile("sprite/alien2_0.png");
    aliensT[3].loadFromFile("sprite/alien3_0.png");

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
}

