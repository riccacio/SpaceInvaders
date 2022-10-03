#include "Menu.h"
#include "../View/Info.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <memory>
#include <sstream>

using namespace sf;

Menu::Menu():record(6223), i(0),event(){
    this->initVariables();
    this->initWindow();
}

//Private functions
void Menu::initVariables() {
    this->window = nullptr;

}
void Menu::initWindow() {
    this->videoMode.height = HEIGHT;
    this->videoMode.width = WIDTH;
    this->window = std::make_unique<RenderWindow>(this->videoMode, "Space Invaders", Style::Titlebar | Style::Close);
}

//Functions
bool Menu::running() const {
    return this->window->isOpen();
}

void Menu::pollEvents() {
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
                if(event.key.code == Keyboard::H){
                    std::unique_ptr<Info> info(new Info);
                    info->run();
                }
                break;
            default:
                break;
        }
    }
}

void Menu::update(){
    this->pollEvents();
}
void Menu::render() {
    if(!buffer.loadFromFile("Sound/menu.wav")){
        std::cout << ("ERROR: sound not found!") << std::endl;
        this->window->close();
        exit(EXIT_SUCCESS);
    }
    if(!f1.loadFromFile("Font/arcade.TTF")){
        std::cout << ("ERROR: font not found!") << std::endl;
        this->window->close();
        exit(EXIT_SUCCESS);
    }
    if(!texShip.loadFromFile("Sprite/ship.png")){
        std::cout << ("ERROR: sprite ship not found!") << std::endl;
        this->window->close();
        exit(EXIT_SUCCESS);
    }

    sound.setBuffer(buffer);
    //sound.play();
    sound.setLoop(true);
    title.setFont(f1);
    text.setFont(f1);
    info.setFont(f1);
    hiScore.setFont(f1);
    recordText.setFont(f1);

    title.setString("SPACE INVADERS");
    text.setString("PRESS SPACE TO START");
    info.setString("HOW TO PLAY H (H)");
    hiScore.setString("HI-SCORE: ");
    std::stringstream ss;
    ss<<record;
    std::string s;
    ss>>s;
    recordText.setString(s);

    title.setFillColor(Color::White);
    info.setFillColor(Color::White);
    hiScore.setFillColor(Color::White);
    recordText.setFillColor(Color::White);

    title.setCharacterSize(60);
    text.setCharacterSize(30);
    info.setCharacterSize(25);
    hiScore.setCharacterSize(32);
    recordText.setCharacterSize(32);

    centerText(title, 370);
    centerText(info, 550);
    centerText(text, 750);
    centerSprite(sprShip, 950);

    hiScore.setPosition(30,20);
    recordText.setPosition(310,20);

    sprShip.setTexture(texShip);
    sprShip.setScale(7,7);

    //flashing text
    if(i==0){
        text.setFillColor(Color::White);
        i=1;
    }
    else{
        text.setFillColor(Color::Black);
        i=0;
    }
    this->window->clear();
    this->window->draw(title);
    this->window->draw(text);
    this->window->draw(info);
    this->window->draw(hiScore);
    this->window->draw(recordText);
    this->window->draw(sprShip);
    this->window->display();
}

void Menu::run(){
    //Menu loop
    while(running()){
        //Update
        update();
        //Render
        render();
    }
}

void Menu::centerText(Text& text, float height){
    FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width/2.0f,textRect.top  + textRect.height/2.0f);
    text.setPosition(Vector2f(WIDTH/2.0f, height));
}
void Menu::centerSprite(Sprite& sprite, float height){
    FloatRect textRect = sprite.getLocalBounds();
    sprite.setOrigin(textRect.left + textRect.width/2.0f,textRect.top  + textRect.height/2.0f);
    sprite.setPosition(Vector2f(WIDTH/2.0f, height));
}
