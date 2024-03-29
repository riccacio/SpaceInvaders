#include "../headers/MainWindow.h"

MainWindow::MainWindow():event() {}

//functions
void MainWindow::initVariables() {
    window = nullptr;
}

void MainWindow::initWindow() {
    videoMode.height = HEIGHT;
    videoMode.width = WIDTH;

    window = std::make_unique<RenderWindow>(videoMode, "Space Invaders", Style::Titlebar | Style::Close);
    window->setFramerateLimit(265);
}

void MainWindow::initFont() {
    f.loadFromFile("font/arcade.TTF");
}

bool MainWindow::running() const {
    return window->isOpen();
}

void MainWindow::pollEvents() {
    while (window->pollEvent(event)){
        switch (event.type){
            case Event::Closed:
                window->close();
                break;
            case Event::KeyPressed:
                if(event.key.code == Keyboard::Escape){
                    window->close();
                }
            default:
                break;
        }
    }
}

void MainWindow::update(){
    pollEvents();
}

void MainWindow::render(){}

void MainWindow::run(){
    while(running()){
        update();
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