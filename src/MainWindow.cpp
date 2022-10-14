#include "../include/MainWindow.h"
#include <SFML/Graphics.hpp>
#include <fstream>

MainWindow::MainWindow():event() {}

//Private functions
void MainWindow::initVariables() {
    this->window = nullptr;
}

void MainWindow::initWindow() {
    this->videoMode.height = HEIGHT;
    this->videoMode.width = WIDTH;
    this->window = std::make_unique<RenderWindow>(this->videoMode, "Space Invaders", Style::Titlebar | Style::Close);
    this->window->setFramerateLimit(60);
}

//Functions
bool MainWindow::running() const {
    return this->window->isOpen();
}

void MainWindow::pollEvents() {
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
            default:
                break;
        }
    }
}

void MainWindow::update(){
    this->pollEvents();
}

void MainWindow::render(){}

void MainWindow::run(){
    while(running()){
        //Update
        update();
        //Render
        render();
    }
}

void MainWindow::centerItem(Text& text, float height){
    FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width/2.0f,textRect.top  + textRect.height/2.0f);
    text.setPosition(Vector2f(WIDTH/2.0f, height));
}

void MainWindow::centerItem(Sprite& sprite, float height){
    FloatRect textRect = sprite.getLocalBounds();
    sprite.setOrigin(textRect.left + textRect.width/2.0f,textRect.top  + textRect.height/2.0f);
    sprite.setPosition(Vector2f(WIDTH/2.0f, height));
}

void MainWindow::readRecord(){
    std::ifstream iFile("record.txt");
    if (iFile.is_open()){
        getline(iFile, recordS);
        iFile.close();
    }
}
