#include "../headers//Menu.h"

Menu::Menu(): i(0){
    initVariables();
    initWindow();
    initFont();
    readRecord();
    initText();
    music();
}

//functions
void Menu::initVariables() {
    window = nullptr;
    for (int j = 0; j<=5; j++)
        graphicText.emplace_back();
}

void Menu::initText() {
    texShip.loadFromFile("sprite/ship0.png");

    sprShip.setTexture(texShip);
    sprShip.setScale(7,7);

    graphicText[0].setString("SPACE INVADERS");
    graphicText[1].setString("HOW TO PLAY (H)");
    graphicText[2].setString("PRESS ENTER TO START");
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
}

void Menu::pollEvents() {
    while (window->pollEvent(event)){
        switch (event.type){
            case Event::Closed:window->close();
                break;
            case Event::KeyPressed:
                keyboardEvent(event.key.code);
            default:
                break;
        }
    }
}

void Menu::keyboardEvent(auto& e){
    switch (e) {
        case Keyboard::Escape:
            window->close();
            break;
        case Keyboard::H:{
            std::unique_ptr<Info> info(new Info);
            info->run();
            break;
        }
        case Keyboard::Enter:{
            window->close();
            sound.stop();
            std::unique_ptr<Game> game(new Game(0,3, ALIEN_CHANGE, 0));
            game->run();
            break;
        }
        default:
            break;
    }
}


void Menu::update() {
    pollEvents();
    //flashing text
    sleep(milliseconds(100)); // 0.1sec
    if(i == 0){
        graphicText[2].setFillColor(Color::White);
        i = 1;
    }
    else{
        graphicText[2].setFillColor(Color::Black);
        i = 0;
    }
}

void Menu::render() {
    window->clear();
    for (int j = 0; j<=5; j++)
        window->draw(graphicText[j]);
    window->draw(sprShip);
    window->display();
}

void Menu::music(){
    buffer.loadFromFile("sound/menu.wav");
    sound.setBuffer(buffer);
    sound.play();
    sound.setLoop(true);
}