#include "Menu.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <unistd.h>
#include <sstream>

using namespace sf;
using namespace std;

void Menu::run(){
    RenderWindow window(VideoMode(1280, 1400), "Space Invaders");
    SoundBuffer buffer;
    buffer.loadFromFile("Sound/menu.wav");
    Sound sound;
    sound.setBuffer(buffer);
    //sound.play();
    sound.setLoop(true);
    while (window.isOpen())
    {
        Event event;

        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        Font f1;
        f1.loadFromFile("Font/ARCADE_N.TTF");
        Text title;
        Text text;
        Text info;
        Text hiScore;
        Text recordText;
        Texture texShip;
        Sprite sprShip;

        title.setFont(f1);
        text.setFont(f1);
        info.setFont(f1);
        hiScore.setFont(f1);
        recordText.setFont(f1);

        title.setString("SPACE INVADERS");
        text.setString("PRESS SPACE TO START");
        info.setString("HOW TO PLAY H (H)");
        hiScore.setString("HI-SCORE: ");
        stringstream ss;
        ss<<record;
        string s;
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

        title.setPosition(240,370);
        text.setPosition(340,750);
        info.setPosition(430,550);
        hiScore.setPosition(30,20);
        recordText.setPosition(350,20);
        sprShip.setPosition(550,900);

        texShip.loadFromFile("Sprite/ship.png");
        sprShip.setTexture(texShip);
        sprShip.setScale(7,7);

        //flashing text
        int i;
        usleep(120000); //1 sec
        if(i==0){
            text.setFillColor(Color::White);
            i=1;
        }
        else{
            text.setFillColor(Color::Black);
            i=0;
        }

        window.clear();
        window.draw(title);
        window.draw(text);
        window.draw(info);
        window.draw(hiScore);
        window.draw(recordText);
        window.draw(sprShip);
        window.display();
    }
}