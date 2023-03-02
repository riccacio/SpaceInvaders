#include "../headers/Game.h"
#include <iostream>

Game::Game(): record(0), lives(3), score(0), reloadTimer(0), moveTimer(0), direction(1), timeAliens(0), changeMusic(true), ufoPlayingMusic(0), speedAlien(ALIEN_CHANGE), powerupDuration(300){
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
    srand(time(NULL));

    //init arrays
    for(int j=0; j<lives; j++)
        sprShipL.emplace_back();
    for(int j=0; j<5; j++)
        graphicText.emplace_back();
    for(int j=0; j<7; j++)
        soundBuffers.emplace_back();
    for(int j=0; j<7; j++)
        sounds.emplace_back();

    readRecord();

    //sounds loading
    soundBuffers[0].loadFromFile("sound/ship_shoot.wav"); //ship shot
    soundBuffers[1].loadFromFile("sound/explosion.wav"); //ship explosion
    soundBuffers[2].loadFromFile("sound/fastinvader1.wav"); //alien sound 1
    soundBuffers[3].loadFromFile("sound/fastinvader2.wav"); //alien sound 2
    soundBuffers[4].loadFromFile("sound/alien_death.wav"); //alien death
    soundBuffers[5].loadFromFile("sound/ufo_lowpitch.wav"); //ufo sound
    soundBuffers[6].loadFromFile("sound/ufo_highpitch.wav"); //ufo death

    for(int j=0; j<7; j++){
        sounds[j].setBuffer(soundBuffers[j]);
    }
}

void Game::initItems() {
    createShip();

    //aliens creation
    int alienX=55;
    int alienY=120;
    for(int i=0; i<8; i++){
        map.createAliens(0, Vector2f (alienX, alienY));
        alienX+=150;
    }
    alienX=55;
    alienY+=100;
    for(int i=0; i<8; i++){
        map.createAliens(1, Vector2f(alienX, alienY));
        alienX+=150;
    }
    alienX=55;
    alienY+=100;
    for(int i=0; i<8; i++){
        map.createAliens(1, Vector2f(alienX, alienY), false);
        alienX+=150;
    }
    alienX=55;
    alienY+=100;
    for(int i=0; i<8; i++){
        map.createAliens(2, Vector2f(alienX, alienY));
        alienX+=150;
    }
    alienX=55;
    alienY+=100;
    for(int i=0; i<8; i++){
        map.createAliens(2, Vector2f(alienX, alienY), false);
        alienX+=150;
    }
    aliens = map.getAliens();

    centerItem(ship->getSprShip(), 1180.f);

    map.createUFO();
    ufo = map.getUFO();
    ufo->getSprite().setPosition(WIDTH-ufo->getSprite().getGlobalBounds().width, 150);

    powerUpBar.setOutlineThickness(2);
    powerUpBar.setOutlineColor(Color::White);
    powerUpBar.setPosition(900, 1315);
    powerUpBar.setSize(Vector2f(300,30));
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
    line.setPosition(20, BOTTOM_LIMIT);

    for(int j=0; j<5; j++){
        graphicText[j].setFont(f);
        graphicText[j].setCharacterSize(32);
    }

    graphicText[0].setPosition(30,20);//HISCORE
    graphicText[3].setPosition(310,20);//RECORD NUM
    graphicText[1].setPosition(900,20);//SCORE
    graphicText[4].setPosition(1100,20);//SCORE NUM
    graphicText[2].setPosition(20, 1315);//LIVES

    int offset=215;
    for(int j=0; j<lives; j++){
        sprShipL[j].setTexture(ship->getTexShip());
        sprShipL[j].setScale(3, 3);
        sprShipL[j].setPosition(offset, 1290);
        offset+=120;
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
            if(ship->getCurrentPower() == 3){
                if(ship->getPosition().x < WIDTH - ship->getSprShip().getGlobalBounds().width/2.0f - OFFSET){
                    ship->getSprShip().move(SHIP_MOVE_SPEED * 1.0f ,0.0f);
                    ship->getSprShip3().move(SHIP_MOVE_SPEED * 1.0f ,0.0f);
                    ship->getSprShipShield().move(SHIP_MOVE_SPEED * 1.0f ,0.0f);
                }
            }
            else{
                if(ship->getPosition().x > ship->getSprShip().getGlobalBounds().width/2.0f + OFFSET){
                    ship->getSprShip().move(SHIP_MOVE_SPEED * -1.0f ,0.0f);
                    ship->getSprShip3().move(SHIP_MOVE_SPEED * -1.0f ,0.0f);
                    ship->getSprShipShield().move(SHIP_MOVE_SPEED * -1.0f ,0.0f);
                }
            }

        }
        if (Keyboard::isKeyPressed(Keyboard::Right)) {
            if(ship->getCurrentPower() == 3){
                if(ship->getPosition().x > ship->getSprShip().getGlobalBounds().width/2.0f + OFFSET){
                    ship->getSprShip().move(SHIP_MOVE_SPEED * -1.0f ,0.0f);
                    ship->getSprShip3().move(SHIP_MOVE_SPEED * -1.0f ,0.0f);
                    ship->getSprShipShield().move(SHIP_MOVE_SPEED * -1.0f ,0.0f);
                }
            }
            else{
                if(ship->getPosition().x < WIDTH - ship->getSprShip().getGlobalBounds().width/2.0f - OFFSET){
                    ship->getSprShip().move(SHIP_MOVE_SPEED * 1.0f ,0.0f);
                    ship->getSprShip3().move(SHIP_MOVE_SPEED * 1.0f ,0.0f);
                    ship->getSprShipShield().move(SHIP_MOVE_SPEED * 1.0f ,0.0f);
                }
            }
        }
        if (reloadTimer == 0){
            if (Keyboard::isKeyPressed(Keyboard::Space)) {
                if (ship->getCurrentPower() == 1)
                    reloadTimer = FAST_RELOAD_DURATION;
                else {
                    reloadTimer = RELOAD_DURATION;
                }
                ship->shoot();
                sounds[0].play();
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

    //aliens animation
    if(timeAliens==0){
        timeAliens = speedAlien;
        if(changeMusic){
            if(!aliens->empty()){
                sounds[2].play();
                changeMusic = !changeMusic;
            }
        }
        else{
            if(!aliens->empty()){
                sounds[3].play();
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
        //alien bullet collision check alien bullet vs ship
        if(a != nullptr){
            if(!ship->isInvincible()){
                if (a->checkCollision(ship->getHitBox())) {
                    if(ship->getCurrentPower() == 0){
                        powerupDuration = 0;
                        ship->setCurrentPower(-1);
                    }
                    else{
                        ship->setDead(true);
                        ship->setInvincible(true);
                        ship->setHitted(true);
                        ship->setTimeRestart(); //time animation
                        invincibilityTime = clock.restart(); //time invincibility
                        ship->setPositionExp1(Vector2f(ship->getSprShip().getPosition().x - ship->getSprShip().getGlobalBounds().width/2, 1150));
                        ship->setPositionExp2(Vector2f(ship->getSprShip().getPosition().x - ship->getSprShip().getGlobalBounds().width/2, 1150));
                        lives--;
                        sounds[1].play();
                    }
                }
            }
        }
    }

    //5 sec invincibility after being hit
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
    moveAliens();

    //ship bullets collision check vs aliens
    checkDeadAliens();

    //end of effects power-up
    if(powerupDuration == 0){
        ship->setCurrentPower(-1);
        ship->setPowerUpHitted(false);
        powerUpBar.setSize(Vector2f(300,30));
        powerupDuration = 300;
    }

    //power-up bar decrease
    if(ship->isPowerUpHitted()){
        powerupDuration-=0.25f;
        powerUpBar.setSize(Vector2f(powerupDuration, 30));
    }

    //every 15 sec spawns ufo
    if(spawnUfoTime.asSeconds() > 10){
        ufo->setDead(false);
        ufo->update();
        ufoPlayingMusic++;
    }

    if(ufoPlayingMusic == 1){
        sounds[5].play();
    }

    //ship collision check ship bullet vs ufo
    int i=0;
    for(auto& b: *ship->getBullets()){
            if(ufo->checkCollision(b.getHitBox())) {
                clockUFO.restart();
                ufo->setDead(true);
                sounds[5].stop();
                ufoPlayingMusic = 0;
                sounds[6].play();
                ship->getBullets()->erase(ship->getBullets()->begin() + i);
                score+=200;
                ufo->setType(rand()%4);
                ufo->dropPowerUp(Vector2f(ufo->getSprite().getPosition().x + ufo->getSprite().getGlobalBounds().width/2.f, ufo->getSprite().getPosition().y+ufo->getSprite().getGlobalBounds().height));
                ufo->getSprite().setPosition(WIDTH+ufo->getSprite().getGlobalBounds().width, 150);
            }
            i++;
    }

    //power-up update
    if(ufo->isDead()){
        ufo->updatePowerUp();
        if(ufo->checkCollisionPU(ship->getHitBox())){
            ship->setPowerUpHitted(true);
            ship->setCurrentPower(ufo->getType());
            switch(ufo->getType()){
                case 0:
                    powerUpBar.setFillColor(Color(64,144,247)); // shield
                    break;
                case 1:
                    powerUpBar.setFillColor(Color(234,51,35)); // fast reloading
                    break;
                case 2:
                    powerUpBar.setFillColor(Color(249,220,74)); // 3 bullets
                    break;
                case 3:
                    powerUpBar.setFillColor(Color(201,42,246)); // mirrored controls
                    break;
                default:
                    break;
            }
            ship->setPosition3(Vector2f(ship->getSprShip().getPosition().x-ship->getSprShip().getGlobalBounds().width/2.f, ship->getSprShip().getPosition().y-ship->getSprShip().getGlobalBounds().height/2));
            ship->setPositionShield(Vector2f(ship->getSprShip().getPosition().x-ship->getSprShip().getGlobalBounds().width/2.f, ship->getSprShip().getPosition().y-ship->getSprShip().getGlobalBounds().height/2));
        }
    }

    //ufo collision check vs left border
    if(ufo->getSprite().getPosition().x+ufo->getSprite().getGlobalBounds().width <= 0){
        clockUFO.restart();
        ufoPlayingMusic = 0;
        ufo->getSprite().setPosition(WIDTH+ufo->getSprite().getGlobalBounds().width, 150);
        ufo->setDead(false);
    }

    updateScoreRecord();
    checkGameOver();
}

void Game::render() {
    window->clear();
    //record
    if(record < score)
        writeRecord();

    //texts
    for(int j=0; j<5; j++)
        window->draw(graphicText[j]);

    //life sprites
    for(int j=0; j<lives; j++)
        window->draw(sprShipL[j]);

    //bottom green line
    window->draw(line);

    //aliens
    for(auto& a : *aliens)
        a->draw(*window);

    //ship
    ship->draw(*window);

    //ufo after 10 sec
    if(spawnUfoTime.asSeconds() > 10)
        ufo->draw(*window);

    //power-up
    if(ufo->isDead())
        ufo->drawPowerUp(*window);

    //power-up bar duration
    if(ship->isPowerUpHitted())
        window->draw(powerUpBar);

    window->display();
}

void Game::createShip() {
    map.createShip();
    ship = map.getShip();
}

void Game::centerItem(Sprite& sprite, float height){
    FloatRect textRect = sprite.getLocalBounds();
    sprite.setOrigin(textRect.width/2.0f,textRect.height/2.0f);
    sprite.setPosition(Vector2f((WIDTH/2.0f), height));
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

void Game::checkDeadAliens(){
    int i, j=0;
    for(auto& b: *ship->getBullets()){
        i=0;
        for(auto& a:*aliens){
            if(a != nullptr && a->checkCollision(b)){
                switch (a->getType()){
                    case 0:
                        score += 30;
                        break;
                    case 1:
                        score += 20;
                        break;
                    case 2:
                        score += 10;
                        break;
                    default:
                        break;
                }
                //speed increase
                speedAlien = speedAlien - SPAN;
                ship->getBullets()->erase(ship->getBullets()->begin() + j);
                sounds[4].play();
                aliens->erase(aliens->begin() + i);
            }
            i++;
        }
        j++;
    }
}

void Game::stopMusic() {
    for(int i=0; i<7; i++){
        sounds[i].stop();
    }
}

void Game::checkGameOver() {
    for(auto& a : *aliens){
        if(a != nullptr && a->checkCollisionAlienShip(ship->getHitBox())){
            stopMusic();
            window->close();
            std::unique_ptr<GameOver> go(new GameOver);
            go->run();
        }
    }
    if(lives == 0 && ship->getTime().asSeconds() > 1.0f){
        stopMusic();
        window->close();
        std::unique_ptr<GameOver> go(new GameOver);
        go->run();
    }
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