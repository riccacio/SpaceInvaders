#include "../headers/Info.h"

Info::Info(){
    initVariables();
    initWindow();
    initFont();
    initText();
}

void Info::initVariables() {
    window = nullptr;
    for (int i = 0; i<=8; i++){
        textures.emplace_back();
        sprites.emplace_back();
    }
    for (int i = 0; i<=13; i++)
        graphicText.emplace_back();
}


void Info::initText() {
    textures[0].loadFromFile("sprite/ufo.png");
    textures[1].loadFromFile("sprite/alien1_0.png");
    textures[2].loadFromFile("sprite/alien2_0.png");
    textures[3].loadFromFile("sprite/alien3_0.png");
    textures[4].loadFromFile("sprite/powerup00.png");
    textures[5].loadFromFile("sprite/powerup10.png");
    textures[6].loadFromFile("sprite/powerup20.png");
    textures[7].loadFromFile("sprite/powerup30.png");

    for(int i=0; i<13; i++)
        graphicText[i].setFont(f);

    graphicText[0].setString("HOW TO PLAY"); // title
    graphicText[1].setString("SHOT = PRESS SPACE"); // shot
    graphicText[2].setString("LEFT = LEFT ARROW"); // left
    graphicText[3].setString("RIGHT = RIGHT ARROW"); // right
    graphicText[4].setString("= ? MYSTERY"); // mysterious
    graphicText[5].setString("= 30 POINTS"); // alien1
    graphicText[6].setString("= 20 POINTS"); // alien2
    graphicText[7].setString("= 10 POINTS"); // alien3
    graphicText[8].setString("= SHIELD");
    graphicText[9].setString("= FAST RELOADING");
    graphicText[10].setString("= THREE BULLETS");
    graphicText[11].setString("= MIRRORED CONTROLS");
    graphicText[12].setString("PRESS B TO BACK TO MENU");

    for (int i = 0; i<8; i++) {
        sprites[i].setTexture(textures[i]);
        sprites[i].setScale(4, 4);
    }
    for(int i=0; i<8; i++)
        graphicText[i].setFillColor(Color::White);
    graphicText[12].setFillColor(Color::Green);

    graphicText[0].setCharacterSize(45);
    for(int i=1; i<12; i++)
        graphicText[i].setCharacterSize(25);
    graphicText[12].setCharacterSize(25);

    centerItem(graphicText[0], 150);
    centerItem(graphicText[1], 340);
    centerItem(graphicText[12], 1200);

    graphicText[2].setPosition(425, 430);
    graphicText[3].setPosition(425, 540);

    graphicText[4].setPosition(220, 670);
    sprites[0].setPosition(90, 665);
    graphicText[5].setPosition(220, 790);
    sprites[1].setPosition(90, 760);
    graphicText[6].setPosition(220, 910);
    sprites[2].setPosition(90, 880);
    graphicText[7].setPosition(220, 1020);
    sprites[3].setPosition(90, 990);

    graphicText[8].setPosition(720, 670);
    sprites[4].setPosition(635, 660);
    graphicText[9].setPosition(720, 790);
    sprites[5].setPosition(635, 780);
    graphicText[10].setPosition(720, 910);
    sprites[6].setPosition(635, 900);
    graphicText[11].setPosition(720, 1020);
    sprites[7].setPosition(635, 1010);
}

void Info::pollEvents() {
    while (window->pollEvent(event)){
        switch (event.type){
            case Event::Closed:
                window->close();
                break;
            case Event::KeyPressed:
                if (event.key.code == Keyboard::Escape ||
                        event.key.code == Keyboard::B) {
                    window->close();
                }
                break;
            default:
                break;
        }
    }
}

void Info::render() {
    window->clear();
    for(int i=0; i<8; i++)
        window->draw(sprites[i]);
    for(int i=0; i<13; i++)
        window->draw(graphicText[i]);
    window->display();
}