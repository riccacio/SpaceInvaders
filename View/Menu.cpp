#include "Menu.h"
#include <SFML/Graphics.hpp>
#include <unistd.h>
#include <iostream>

using namespace sf;

Menu::Menu(){}
Menu::~Menu(){}


void Menu::run(){
    RenderWindow window(VideoMode(1280, 1400), "Space Invaders");
    while (window.isOpen())
    {
        Event event;

        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        Font f1;
        f1.loadFromFile("../Font/ARCADE_N.TTF");
        Text title;
        Text text;
        Text info;

        title.setFont(f1);
        text.setFont(f1);
        info.setFont(f1);

        title.setString("SPACE INVADERS");
        text.setString("PRESS SPACE TO START");

        info.setString("HOW TO PLAY H (H)");
        title.setFillColor(Color::White);
        info.setFillColor(Color::White);
        title.setCharacterSize(60);
        text.setCharacterSize(30);
        info.setCharacterSize(25);

        title.setPosition(250,370);
        text.setPosition(350,750);
        info.setPosition(440,550);

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
        window.display();
    }
}