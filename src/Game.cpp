#include "../headers/Game.h"

using namespace sf;

Game::Game(): record(0), lives(3), score(0), reloadTimer(0){
    initVariables();
    initFont();
    initWindow();
    initText();
    //music();
}

//Functions
void Game::initVariables() {
    window = nullptr;
    for(int j=0; j<lives; j++)
        sprShipL.emplace_back();
    for(int j=0; j<5; j++)
        graphicText.emplace_back();
    map.createShip();
    ship = map.getShip();
    centerItem(ship->getSprShip(), ship->getPosition().y);
    readRecord();
}

void Game::pollEvents() {
    //Event polling
    while (window->pollEvent(event)){
        switch (event.type){
            case Event::Closed:
                window->close();
                break;
            default:
                break;
        }
    }

    if (Keyboard::isKeyPressed(Keyboard::Left)){
        if(ship->getPosition().x > ship->getSprShip().getGlobalBounds().width/2.0f + OFFSET){
            ship->getSprShip().move(SHIP_MOVE_SPEED * -1.0f ,0.0f);
        }
    }
    if (Keyboard::isKeyPressed(Keyboard::Right)) {
        if(ship->getPosition().x < WIDTH - ship->getSprShip().getGlobalBounds().width/2.0f - OFFSET){
            ship->getSprShip().move(SHIP_MOVE_SPEED * 1.0f ,0.0f);
        }
    }
    if (reloadTimer == 0){
        if (Keyboard::isKeyPressed(Keyboard::Space)){
            if (ship->getCurrentPower()== 2)
                reloadTimer = FAST_RELOAD_DURATION;
            else{
                reloadTimer = RELOAD_DURATION;
            }
            ship->shoot();
        }
    }
    else
        reloadTimer--;
}

void Game::render() {
    window->clear();
    if(record<score)
        writeRecord();
    for(int j=0; j<5; j++)
        window->draw(graphicText[j]);
    for(int j=0; j<lives; j++)
        window->draw(sprShipL[j]);
    window->draw(line);
    ship->draw(*window);
    window->display();
}

void Game::run(){
    while(running()){
        //Update
        update();
        //Render
        render();
    }
}

void Game::music(){
    buffer.loadFromFile("sound/menu.wav");
    sound.setBuffer(buffer);
    sound.play();
    sound.setLoop(true);
}

void Game::writeRecord() const {
    std::ofstream oFile("record.txt");
    if (oFile.is_open()){
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
        record = std::stoi(recordS); //convert string to int
        iFile.close();
    }
}

void Game::centerItem(Sprite& sprite, float height){
    FloatRect textRect = sprite.getLocalBounds();
    sprite.setOrigin(textRect.width/2.0f,textRect.height/2.0f);
    sprite.setPosition(Vector2f((WIDTH/2.0f), height));
    ship->setPosition(Vector2f ((WIDTH/2.0f),1180.0f));
}

void Game::initText() {
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
        sprShipL[j].setTexture(ship->getTexShip());
        sprShipL[j].setScale(3, 3);
        sprShipL[j].setPosition(p, 1290);
        p+=120;
    }
}

void Game::update() {
    pollEvents();
    ship->update();
}
