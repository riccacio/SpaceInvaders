#include "Info.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <unistd.h>
#include <iostream>
#include <sstream>

using namespace sf;
using namespace std;

Info::Info(){}
Info::~Info(){}


void Info::run(){
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

        title.setFont(f1);

        title.setString("HOW TO PLAY");

        title.setFillColor(Color::White);

        title.setCharacterSize(40);

        title.setPosition(420,150);

        window.clear();
        window.draw(title);
        window.display();
    }
}