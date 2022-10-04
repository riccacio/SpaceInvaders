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
}
void Info::initWindow() {
    this->videoMode.height = HEIGHT;
    this->videoMode.width = WIDTH;
    this->window = std::make_unique<RenderWindow>(this->videoMode, "Space Invaders - Info", Style::Titlebar | Style::Close);
}

bool Info::running() const {
    return this->window->isOpen();
}

void Info::pollEvents() {
    //Event polling
    while (this->window->pollEvent(this->event)){
        switch (this->event.type){
            case Event::Closed:
                this->window->close();
                break;
            case Event::KeyPressed:
                if (event.key.code == Keyboard::Escape) {
                    this->window->close();
                }else if (event.key.code == Keyboard::B)
                    this->window->close();
                break;
            default:
                break;
        }
    }
}

void Info::update(){
    this->pollEvents();
}
void Info::render(){
    if(!f.loadFromFile("Font/arcade.TTF")){
        std::cout << ("ERROR: font not found!") << std::endl;
        this->window->close();
    }
    if(!aliensT[0].loadFromFile("Sprite/mystery.png")){
        std::cout << ("ERROR: sprite not found!") << std::endl;
        this->window->close();
    }
    if(!aliensT[1].loadFromFile("Sprite/alien1_0.png")){
        std::cout << ("ERROR: sprite not found!") << std::endl;
        this->window->close();
    }
    if(!aliensT[2].loadFromFile("Sprite/alien2_0.png")){
        std::cout << ("ERROR: sprite not found!") << std::endl;
        this->window->close();
    }
    if(!aliensT[3].loadFromFile("Sprite/alien3_0.png")){
        std::cout << ("ERROR: sprite not found!") << std::endl;
        this->window->close();
    }

    title.setFont(f);
    shot.setFont(f);
    left.setFont(f);
    right.setFont(f);
    myst.setFont(f);
    alien1.setFont(f);
    alien2.setFont(f);
    alien3.setFont(f);
    back.setFont(f);

    title.setString("HOW TO PLAY");
    shot.setString("SHOT = PRESS SPACE");
    left.setString("LEFT = LEFT ARROW");
    right.setString("RIGHT = RIGHT ARROW");
    myst.setString("= ? MYSTERY");
    alien1.setString("= 30 POINTS");
    alien2.setString("= 20 POINTS");
    alien3.setString("= 10 POINTS");
    back.setString("PRESS B TO BACK TO MENU");

    aliensS[0].setTexture(aliensT[0]);
    aliensS[1].setTexture(aliensT[1]);
    aliensS[2].setTexture(aliensT[2]);
    aliensS[3].setTexture(aliensT[3]);

    aliensS[0].setScale(5,5);
    aliensS[1].setScale(4,4);
    aliensS[2].setScale(4,4);
    aliensS[3].setScale(4,4);

    title.setFillColor(Color::White);
    shot.setFillColor(Color::White);
    left.setFillColor(Color::White);
    right.setFillColor(Color::White);
    myst.setFillColor(Color::White);
    alien1.setFillColor(Color::White);
    alien2.setFillColor(Color::White);
    alien3.setFillColor(Color::White);
    back.setFillColor(Color::Green);

    title.setCharacterSize(55);
    shot.setCharacterSize(40);
    left.setCharacterSize(40);
    right.setCharacterSize(40);
    myst.setCharacterSize(40);
    alien1.setCharacterSize(40);
    alien2.setCharacterSize(40);
    alien3.setCharacterSize(40);
    back.setCharacterSize(30);

    centerItem(title, 150);
    centerItem(shot, 350);
    centerItem(back, 1200);

    left.setPosition(297,440);
    right.setPosition(297,550);
    myst.setPosition(520,660);
    aliensS[0].setPosition(320,650);
    alien1.setPosition(520,780);
    aliensS[1].setPosition(330,750);
    alien2.setPosition(520,900);
    aliensS[2].setPosition(330,870);
    alien3.setPosition(520,1010);
    aliensS[3].setPosition(340,980);

    this->window->clear();
    this->window->draw(title);
    this->window->draw(shot);
    this->window->draw(left);
    this->window->draw(right);
    this->window->draw(myst);
    this->window->draw(aliensS[0]);
    this->window->draw(alien1);
    this->window->draw(aliensS[1]);
    this->window->draw(alien2);
    this->window->draw(aliensS[2]);
    this->window->draw(alien3);
    this->window->draw(aliensS[3]);
    this->window->draw(back);
    this->window->display();
}

void Info::run(){
    //Info loop
    while(running()){
        //Update
        update();
        //Render
        render();
    }
}

void Info::centerItem(Text& text, float height){
    FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width/2.0f,textRect.top  + textRect.height/2.0f);
    text.setPosition(Vector2f(1280/2.0f, height));
}