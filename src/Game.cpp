# include "../headers/Game.h"

Game::Game(int score, int lives, int speedAlienLevel, int stage) : record(0), lives(lives), score(score), stage(stage), reloadTimer(0), moveTimer(0), direction(1), timeAliens(0), changeMusic(true), ufoPlayingMusic(0), speedAlienLevel(speedAlienLevel), speedAlien(speedAlienLevel), powerupDuration(300), livesIncremented(false){
    std::chrono::microseconds lag(0);
    std::chrono::steady_clock::time_point previous_time;
    initVariables();
    initFont();
    initItems();
    initWindow();
    initText();
    killObserver->update(stage);
}

//functions
void Game::initVariables() {
    window = nullptr;
    srand(time(NULL));

    //init arrays
    for(int j=0; j<10; j++)
        sprShipL.emplace_back();
    for(int j=0; j<7; j++)
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
        map.createAliens(Alien::Type::ALIEN1, Vector2f (alienX, alienY));
        alienX+=150;
    }
    alienX=55;
    alienY+=100;
    for(int i=0; i<8; i++){
        map.createAliens(Alien::Type::ALIEN2, Vector2f(alienX, alienY));
        alienX+=150;
    }
    alienX=55;
    alienY+=100;
    for(int i=0; i<8; i++){
        map.createAliens(Alien::Type::ALIEN2, Vector2f(alienX, alienY), false);
        alienX+=150;
    }
    alienX=55;
    alienY+=100;
    for(int i=0; i<8; i++){
        map.createAliens(Alien::Type::ALIEN3, Vector2f(alienX, alienY));
        alienX+=150;
    }
    alienX=55;
    alienY+=100;
    for(int i=0; i<8; i++){
        map.createAliens(Alien::Type::ALIEN3, Vector2f(alienX, alienY), false);
        alienX+=150;
    }
    aliens = map.getAliens();

    //create shields
    int x0 = 100;
    int y0 = 950;
    for(int i = 0; i<3; i++){
        int shieldWidth = 70;
        int shieldHeight = 40;
        map.createShields(Shield::Type::LeftUp, Vector2f(x0, y0));
        map.createShields(Shield::Type::LeftBot, Vector2f(x0, (y0 + (2*shieldHeight))));
        map.createShields(Shield::Type::RightUp, Vector2f((x0 + (2*shieldWidth)), y0));
        map.createShields(Shield::Type::RightBot, Vector2f((x0 + (2*shieldWidth)), (y0 + (2*shieldHeight))));
        map.createShields(Shield::Type::Unique, Vector2f((x0 + shieldWidth), y0));
        int shieldX = x0;
        for(int i=0; i<3; i++){
            map.createShields(Shield::Type::Unique, Vector2f(shieldX, (y0 + shieldHeight)));
            shieldX+=shieldWidth;
        }
        x0+=425;
    }

    shields = map.getShields();

    centerItem(ship->getSprite(), 1180.f);

    map.createUFO();
    ufo = map.getUFO();
    ufo->getSprite().setPosition(WIDTH-ufo->getSprite().getGlobalBounds().width, 150);

    powerUpBar.setOutlineThickness(2);
    powerUpBar.setOutlineColor(Color::White);
    powerUpBar.setPosition(900, 1315);
    powerUpBar.setSize(Vector2f(300,30));

    killObserver = std::make_shared<AliensDestroyedAchievement>();
    killObserver->setAliensKilled(handler.loadAchievementData("achievements.txt"));

    lifeObserver = std::make_shared<ExtraLifeAchievements>();
}

void Game::initText() {
    graphicText[0].setString("HI-SCORE: ");
    graphicText[1].setString("SCORE: ");
    graphicText[2].setString("LIVES: ");
    graphicText[5].setString("STAGE: ");
    std::stringstream ss2, ss3;
    std::string s2, s3;
    ss2<<score;
    ss2>>s2;
    ss3<<stage;
    ss3>>s3;
    graphicText[6].setString(s3);
    graphicText[3].setString(recordS);

    line.setSize(Vector2f(1240, 10));
    line.setFillColor(Color::Green);
    line.setPosition(20, BOTTOM_LIMIT);

    for(int j=0; j<7; j++){
        graphicText[j].setFont(f);
        graphicText[j].setCharacterSize(32);
    }

    graphicText[0].setPosition(30,20);//HISCORE
    graphicText[3].setPosition(310,20);//RECORD NUM
    graphicText[1].setPosition(900,20);//SCORE
    graphicText[4].setPosition(1100,20);//SCORE NUM
    graphicText[2].setPosition(20, 1315);//LIVES
    graphicText[5].setPosition(550, 20);//STAGE
    graphicText[6].setPosition(750, 20);//STAGE NUM

    int offset=215;
    for(int j=0; j<10; j++){
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
            if(ship->getCurrentPower() == Ship::CurrentPower::CHANGE_MOV){
                if(ship->getPosition().x < WIDTH - ship->getSprite().getGlobalBounds().width/2.0f - OFFSET){
                    ship->getSprite().move(SHIP_MOVE_SPEED * 1.0f ,0.0f);
                }
            }
            else{
                if(ship->getPosition().x > ship->getSprite().getGlobalBounds().width/2.0f + OFFSET){
                    ship->getSprite().move(SHIP_MOVE_SPEED * -1.0f ,0.0f);
                }
            }

        }
        if (Keyboard::isKeyPressed(Keyboard::Right)) {
            if(ship->getCurrentPower() == Ship::CurrentPower::CHANGE_MOV){
                if(ship->getPosition().x > ship->getSprite().getGlobalBounds().width/2.0f + OFFSET){
                    ship->getSprite().move(SHIP_MOVE_SPEED * -1.0f ,0.0f);
                }
            }
            else{
                if(ship->getPosition().x < WIDTH - ship->getSprite().getGlobalBounds().width/2.0f - OFFSET){
                    ship->getSprite().move(SHIP_MOVE_SPEED * 1.0f ,0.0f);
                }
            }
        }
        if (reloadTimer == 0){
            if (Keyboard::isKeyPressed(Keyboard::Space)) {
                if (ship->getCurrentPower() == Ship::CurrentPower::FAST)
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
    timerAch = clockAch.getElapsedTime();

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
                    if(ship->getCurrentPower() == Ship::CurrentPower::SHIELD){
                        powerupDuration = 0;
                        ship->setCurrentPower(Ship::CurrentPower::NORMAL);
                    }
                    else{
                        ship->setDead(true);
                        ship->setInvincible(true);
                        ship->setHitted(true);
                        ship->setTimeRestart(); //time animation
                        invincibilityTime = clock.restart(); //time invincibility
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

    //ship bullets collision check vs shields
    checkHitShields();

    //aliens bullets check collision vs shields
    checkHitAlienBulletShields();

    //aliens check collision vs shields
    checkHitAlienShields();

    //end of effects power-up
    if(powerupDuration == 0){
        ship->setCurrentPower(Ship::CurrentPower::NORMAL);
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

    //check collision ship bullet vs ufo
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
            switch(ufo->getType()){
                case 0:
                    ship->setCurrentPower(Ship::CurrentPower::SHIELD);
                    powerUpBar.setFillColor(Color(64,144,247));
                    break;
                case 1:
                    ship->setCurrentPower(Ship::CurrentPower::FAST);
                    powerUpBar.setFillColor(Color(234,51,35));
                    break;
                case 2:
                    ship->setCurrentPower(Ship::CurrentPower::THREE_BUL);
                    powerUpBar.setFillColor(Color(249,220,74));
                    break;
                case 3:
                    ship->setCurrentPower(Ship::CurrentPower::CHANGE_MOV);
                    powerUpBar.setFillColor(Color(201,42,246));
                    break;
                default:
                    break;
            }
        }
    }

    //ufo collision check vs left border
    if(ufo->getSprite().getPosition().x+ufo->getSprite().getGlobalBounds().width <= 0){
        clockUFO.restart();
        ufoPlayingMusic = 0;
        ufo->getSprite().setPosition(WIDTH+ufo->getSprite().getGlobalBounds().width, 150);
        ufo->setDead(false);
    }

    lifeObserver->update(score);

    if(lifeObserver->isReached()){
        clockAch.restart();
        if(!livesIncremented){
            lives++;
            livesIncremented=true;
        }
        lifeObserver->setReached(false);
    }

    checkEndLevel();
    updateScoreRecord();
    checkGameOver();
}

void Game::render() {
    window->clear();
    //record
    if(record < score)
        writeRecord();

    //texts
    for(int j=0; j<7; j++)
        window->draw(graphicText[j]);

    //life sprites
    for(int j=0; j<lives; j++)
        window->draw(sprShipL[j]);

    //bottom green line
    window->draw(line);

    //aliens
    for(auto& a : *aliens)
        a->draw(*window);

    for(auto& s : *shields)
        s->draw(*window);

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

    //achievements
    if(killObserver->isDrawable()){
        if(timerAch.asSeconds()<3){
            killObserver->draw(*window);
            killObserver->setAchReached(false);
        }
    }

    if(lifeObserver->isDrawable()){
        if(timerAch.asSeconds()<3){
            lifeObserver->draw(*window);
        }
    }

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
            if ((a->getPosition().x + a->getSprite().getGlobalBounds().width + PADDING) >= WIDTH) {
                for (auto &b: *aliens) {
                    b->getSprite().move(0.0f, OFFSET);
                }
                direction = -1;
            }
            if ((a->getPosition().x - PADDING) <= 0) {
                for (auto &b: *aliens) {
                    b->getSprite().move(0.0f, OFFSET);
                }
                direction = 1;
            }
            a->getSprite().move(ALIEN_SPEED * direction, 0.0f);
        }
    }
    else
        moveTimer --;
}

void Game::checkDeadAliens() {
    for (int j = ship->getBullets()->size() - 1; j >= 0; j--) {
        Bullet& b = ship->getBullets()->at(j);
        for (int i = aliens->size() - 1; i >= 0; i--) {
            std::shared_ptr<Alien>& a = aliens->at(i);
            if (a->checkCollision(b)) {
                switch (a->getType()) {
                    case Alien::Type::ALIEN1:
                        score += 30;
                        break;
                    case Alien::Type::ALIEN2:
                        score += 20;
                        break;
                    case Alien::Type::ALIEN3:
                        score += 10;
                        break;
                    default:
                        break;
                }
                // speed increase
                if(speedAlien>20)
                    speedAlien = speedAlien - SPAN;
                killObserver->update();
                if(killObserver->isAchReached()){
                    clockAch.restart();
                }
                ship->getBullets()->erase(ship->getBullets()->begin() + j);
                sounds[4].play();
                aliens->erase(aliens->begin() + i);
            }
        }
    }
}

void Game::checkHitShields() {
    for (int i = shields->size() - 1; i >= 0; i--) {
        std::shared_ptr<Shield>& s = shields->at(i);
        for(int j = ship->getBullets()->size() - 1; j >= 0; j--) {
            Bullet &b = ship->getBullets()->at(j);
            if (s->checkCollision(b.getHitBox())) {
                ship->getBullets()->erase(ship->getBullets()->begin() + j);
                s->setHitted(true);
                if (s->isDeletable())
                    shields->erase(shields->begin() + i);
            }
            if (s->isHitted())
                s->setDeletable(true);
        }
    }
}

void Game::checkHitAlienBulletShields(){
    for (int i = shields->size() - 1; i >= 0; i--) {
        std::shared_ptr<Shield>& s = shields->at(i);

        for(auto& a : *aliens){
            if(a != nullptr){
                for(int j = a->getBullets().size() - 1; j >= 0; j--) {
                    Bullet &b = a->getBullets().at(j);
                    if (s->checkCollision(b.getHitBox())) {
                        a->getBullets().erase(a->getBullets().begin() + j);
                        s->setHitted(true);
                        if (s->isDeletable())
                            shields->erase(shields->begin() + i);
                    }
                    if (s->isHitted())
                        s->setDeletable(true);
                }
            }
        }
    }
}

void Game::checkHitAlienShields() {
    for (int i = shields->size() - 1; i >= 0; i--) {
        std::shared_ptr<Shield>& s = shields->at(i);

        for(auto& a : *aliens){
            if(a != nullptr){
                    if (s->checkCollision(a->getHitBox())) {
                        s->setHitted(true);
                        if (s->isDeletable())
                            shields->erase(shields->begin() + i);
                    }
                    if (s->isHitted())
                        s->setDeletable(true);
            }
        }

    }
}

void Game::stopMusic() {
    for(int i=0; i<7; i++){
        sounds[i].stop();
    }
}

void Game::checkEndLevel(){
    if(aliens->empty()){
        window->close();
        speedAlienLevel-=10;
        stage++;
        handler.saveAchievementData("achievements.txt", killObserver->getAliensKilled());
        std::unique_ptr<Game> game(new Game(score, lives, speedAlienLevel, stage));
        game->run();
    }
}

void Game::checkGameOver() {
    for(auto& a : *aliens){
        if(a != nullptr && a->checkCollisionAlienShip(ship->getHitBox())){
            stopMusic();
            handler.resetAchievementData("achievements.txt");
            window->close();
            std::unique_ptr<GameOver> go(new GameOver);
            go->run();
        }
    }
    if(lives == 0 && ship->getTime().asSeconds() > 1.0f){
        stopMusic();
        handler.resetAchievementData("achievements.txt");
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

const std::shared_ptr<std::vector<std::shared_ptr<Alien>>> &Game::getAliens() const {
    return aliens;
}

const std::shared_ptr<Ship> &Game::getShip() const {
    return ship;
}