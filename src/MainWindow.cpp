#include "../include/MainWindow.h"
#include <SFML/Graphics.hpp>

MainWindow::MainWindow():event(){
    this->initVariables();
    this->initWindow();
}

//Private functions
void MainWindow::initVariables() {
    this->window = nullptr;
}

void MainWindow::initWindow() {
    this->videoMode.height = HEIGHT;
    this->videoMode.width = WIDTH;
    this->window = std::make_unique<RenderWindow>(this->videoMode, "Space Invaders", Style::Titlebar | Style::Close);
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

