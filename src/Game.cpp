#include "../headers/Game.h"
#include <iostream>

Game::Game(): record(0), lives(3), score(0), reloadTimer(0), moveTimer(0), direction(1), timeAliens(0), changeMusic(true), speedAlien(ALIEN_CHANGE){
    std::chrono::microseconds lag(0);
    std::chrono::steady_clock::time_point previous_time;
    initVariables();
    initFont();
    initItems();
    initWindow();
    initText();
}

//functions
void Game::initVariables() {

    window = nullptr;

    for(int j=0; j<lives; j++)
        sprShipL.emplace_back();
    for(int j=0; j<5; j++)
        graphicText.emplace_back();
    readRecord();
    shipBuffer.loadFromFile("sound/ship_shoot.wav");
    shipSound.setBuffer(shipBuffer);
    shipExpBuffer.loadFromFile("sound/explosion.wav");
    shipExpSound.setBuffer(shipExpBuffer);
    alienBuffer1.loadFromFile("sound/fastinvader1.wav");
    alienSound1.setBuffer(alienBuffer1);
    alienBuffer2.loadFromFile("sound/fastinvader2.wav");
    alienSound2.setBuffer(alienBuffer2);
    alienExpBuffer.loadFromFile("sound/alien_death.wav");
    alienExpSound.setBuffer(alienExpBuffer);
}

void Game::initItems() {
    createShip();
    float x=55;
    for(int i=0; i<8; i++){
        map.createAliens(0, Vector2f(x, 120));
        x+=150;
    }
    x=55;
    for(int i=0; i<8; i++){
        map.createAliens(1, Vector2f(x, 220));
        x+=150;
    }
    x=55;
    for(int i=0; i<8; i++){
        map.createAliens(1, Vector2f(x, 320), false);
        x+=150;
    }
    x=55;
    for(int i=0; i<8; i++){
        map.createAliens(2, Vector2f(x, 420));
        x+=150;
    }
    x=55;
    for(int i=0; i<8; i++){
        map.createAliens(2, Vector2f(x, 520), false);
        x+=150;
    }
    aliens = map.getAliens();
    ship->getSprShip().setPosition(0,0);
    centerItem(ship->getSprShip(), ship->getPosition().y);
    map.createUFO();
    ufo = map.getUFO();
    ufo->getSprite().setPosition(WIDTH-ufo->getSprite().getGlobalBounds().width, 150);
}

void Game::initText() {
    graphicText[0].setString("HI-SCORE: ");
    graphicText[1].setString("SCORE: ");
    graphicText[2].setString("LIVES: ");
    std::stringstream ss2;
    std::string s2;
    ss2<<score;
    ss2>>s2;
    graphicText[4].setString(s2);
    graphicText[3].setString(recordS);

    line.setSize(Vector2f(1240, 10));
    line.setFillColor(Color::Green);
    line.setPosition(20, 1270);

    for(int j=0; j<5; j++){
        graphicText[j].setFont(f);
        graphicText[j].setCharacterSize(32);
    }

    graphicText[0].setPosition(30,20);//HISCORE
    graphicText[3].setPosition(310,20);//RECORD NUM
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

void Game::run(){
    while(running()){
        update();
        render();
    }
}

void Game::pollEvents() {
    while (window->pollEvent(event)){
        switch (event.type){
            case Event::Closed:
                window->close();
                break;
            default:
                break;
        }
    }

    if(!ship->isHitted()){
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
            if (Keyboard::isKeyPressed(Keyboard::Space)) {
                if (ship->getCurrentPower() == 2)
                    reloadTimer = FAST_RELOAD_DURATION;
                else {
                    reloadTimer = RELOAD_DURATION;
                }
                ship->shoot();
                shipSound.play();
            }
        }
        else{
            reloadTimer--;
        }
    }
}

void Game::update() {
    pollEvents();
    invincibilityTime = clock.getElapsedTime();
    spawnUfoTime = clockUFO.getElapsedTime();

    if(timeAliens==0){
        timeAliens = speedAlien;
        if(changeMusic){
            if(!aliens->empty()){
                alienSound1.play();
                changeMusic = !changeMusic;
            }
        }
        else{
            if(!aliens->empty()){
                alienSound2.play();
                changeMusic = !changeMusic;
            }
        }
        for(auto& a : *aliens){
            a->changeSprite();
        }
    }
    else
        timeAliens--;

    for(auto& a : *aliens){
        a->update(random_engine);
        if(a != nullptr && !ship->isInvincible()){
            if (a->checkCollision(ship->getHitBox())) {
                ship->setDead(true);
                ship->setInvincible(true);
                ship->setHitted(true);
                ship->setTimeRestart(); //time animation
                invincibilityTime = clock.restart(); //time invincibility
                ship->setPositionExp1(Vector2f(ship->getSprShip().getPosition().x - ship->getSprShip().getGlobalBounds().width/2, 1150));
                ship->setPositionExp2(Vector2f(ship->getSprShip().getPosition().x - ship->getSprShip().getGlobalBounds().width/2, 1150));
                lives--;
                shipExpSound.play();
            }
        }
    }
    //invincibility
    if(ship->isInvincible()){
        if(invincibilityTime.asSeconds() > 5.0f){
            invincibilityTime = clock.restart();
            ship->setInvincible(false);
        }
    }
    //ship animation
    if (ship->getTime().asSeconds() > 1.f) {
        ship->setTimeRestart();
        ship->setDead(false);
        ship->setHitted(false);
    }
    else
        ship->changeSprite();

    ship->update();
    checkDeadAliens();
    moveAliens();
    if(spawnUfoTime.asSeconds() > 12){
        ufo->update();
    }
    if(ufo->getSprite().getPosition().x+ufo->getSprite().getGlobalBounds().width <= 0){
        clockUFO.restart();
        ufo->getSprite().setPosition(WIDTH-ufo->getSprite().getGlobalBounds().width, 150);
    }
    updateScoreRecord();
    checkGameOver();
    std::cout << spawnUfoTime.asSeconds() << std::endl;
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
    for(auto& a : aliens){
        a->draw(*window);
    }
    ship->draw(*window);
    if(spawnUfoTime.asSeconds() > 12){
        ufo->draw(*window);
    }
    window->display();
}

void Game::createShip() {
    map.createShip();
    ship = map.getShip();
    ship->setTime();
}

void Game::centerItem(Sprite& sprite, float height){
    FloatRect textRect = sprite.getLocalBounds();
    sprite.setOrigin(textRect.width/2.0f,textRect.height/2.0f);
    sprite.setPosition(Vector2f((WIDTH/2.0f), height));
    ship->setPosition(Vector2f ((WIDTH/2.0f),1180.0f));
}

void Game::updateScoreRecord() {
    std::stringstream ss2;
    std::string s2;
    ss2<<score;
    ss2>>s2;
    graphicText[4].setString(s2);
    if(score>=record){
        readRecord();
        graphicText[3].setString(recordS);
    }
}

void Game::moveAliens() {
    if(moveTimer == 0) {
        moveTimer = speedAlien;
        for (auto &a: *aliens) {
            if ((a->getPositionA().x + a->getSpriteA().getGlobalBounds().width) >= WIDTH) {
                for (auto &b: *aliens) {
                    b->getSpriteA().move(0.0f, OFFSET);
                    b->getSpriteB().move(0.0f, OFFSET);
                }
                direction = -1;
            }
            if (a->getPositionA().x <= 0) {
                for (auto &b: *aliens) {
                    b->getSpriteA().move(0.0f, OFFSET);
                    b->getSpriteB().move(0.0f, OFFSET);
                }
                direction = 1;
            }
            a->getSpriteA().move(ALIEN_SPEED * direction, 0.0f);
            a->getSpriteB().move(ALIEN_SPEED * direction, 0.0f);
        }
    }
    else
        moveTimer --;
}

void Game::moveAliens() {
    if(moveTimer==0) {
        moveTimer = ALIEN_CHANGE;
        for (auto &a: aliens) {
            if ((a->getPositionA().x + a->getSpriteA().getGlobalBounds().width) >= WIDTH) {
                for (auto &b: aliens) {
                    b->getSpriteA().move(0.0f, OFFSET);
                    b->getSpriteB().move(0.0f, OFFSET);
                    b->getSpriteExp().move(0.0f, OFFSET);
                }
                direction = -1;
            }
            if (a->getPositionA().x <= 0) {
                for (auto &b: aliens) {
                    b->getSpriteA().move(0.0f, OFFSET);
                    b->getSpriteB().move(0.0f, OFFSET);
                    b->getSpriteExp().move(0.0f, OFFSET);
                }
                direction = 1;
            }
            a->getSpriteA().move(ALIEN_SPEED * direction, 0.0f);
            a->getSpriteB().move(ALIEN_SPEED * direction, 0.0f);
            a->getSpriteExp().move(ALIEN_SPEED * direction, 0.0f);
        }
    }
    else
        moveTimer --;
}

void Game::checkGameOver() {
    for(auto& a : *aliens){
        if(a != nullptr && a->checkCollisionAlienShip(ship->getHitBox())){
            window->close();
            std::unique_ptr<GameOver> go(new GameOver);
            go->run();
        }
    }
    if(lives == 0 && ship->getTime().asSeconds() > 1.0f){
        window->close();
        std::unique_ptr<GameOver> go(new GameOver);
        go->run();
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