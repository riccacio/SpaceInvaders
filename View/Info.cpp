#include "Info.h"
#include <SFML/Graphics.hpp>
#include <iostream>


using namespace sf;

void Info::run(){
    RenderWindow window(VideoMode(1280, 1400), "Space Invaders-Info");
    if(!f1.loadFromFile("Font/arcade.TTF")){
        std::cout << ("ERROR: font not found!") << std::endl;
        window.close();
    }
    if(!aliensT[0].loadFromFile("Sprite/mystery.png")){
        std::cout << ("ERROR: sprite not found!") << std::endl;
        window.close();
    }
    if(!aliensT[1].loadFromFile("Sprite/alien1_0.png")){
        std::cout << ("ERROR: sprite not found!") << std::endl;
        window.close();
    }
    if(!aliensT[2].loadFromFile("Sprite/alien2_0.png")){
        std::cout << ("ERROR: sprite not found!") << std::endl;
        window.close();
    }
    if(!aliensT[3].loadFromFile("Sprite/alien3_0.png")){
        std::cout << ("ERROR: sprite not found!") << std::endl;
        window.close();
    }
    while (window.isOpen()){
        while (window.pollEvent(event)){
            if (event.type == Event::Closed)
                window.close();
        }

        title.setFont(f1);
        shot.setFont(f1);
        left.setFont(f1);
        right.setFont(f1);
        myst.setFont(f1);
        alien1.setFont(f1);
        alien2.setFont(f1);
        alien3.setFont(f1);
        back.setFont(f1);

        title.setString("HOW TO PLAY");
        shot.setString("SHOT = PRESS SPACE");
        left.setString("LEFT = LEFT ARROW");
        right.setString("RIGHT = RIGHT ARROW");
        myst.setString("= ? MYSTERY");
        alien1.setString("= 30 POINTS");
        alien2.setString("= 20 POINTS");
        alien3.setString("= 10 POINTS");
        back.setString("PRESS B TO BACK TO MENU");

        aliensS[0].setTexture(aliensT[0]);
        aliensS[1].setTexture(aliensT[1]);
        aliensS[2].setTexture(aliensT[2]);
        aliensS[3].setTexture(aliensT[3]);

        aliensS[0].setScale(5,5);
        aliensS[1].setScale(4,4);
        aliensS[2].setScale(4,4);
        aliensS[3].setScale(4,4);

        title.setFillColor(Color::White);
        shot.setFillColor(Color::White);
        left.setFillColor(Color::White);
        right.setFillColor(Color::White);
        myst.setFillColor(Color::White);
        alien1.setFillColor(Color::White);
        alien2.setFillColor(Color::White);
        alien3.setFillColor(Color::White);
        back.setFillColor(Color::Green);

        title.setCharacterSize(55);
        shot.setCharacterSize(40);
        left.setCharacterSize(40);
        right.setCharacterSize(40);
        myst.setCharacterSize(40);
        alien1.setCharacterSize(40);
        alien2.setCharacterSize(40);
        alien3.setCharacterSize(40);
        back.setCharacterSize(30);

        centerText(title, 150);
        centerText(shot, 350);
        centerText(back, 1200);

        left.setPosition(297,440);
        right.setPosition(297,550);
        myst.setPosition(520,660);
        aliensS[0].setPosition(320,650);
        alien1.setPosition(520,780);
        aliensS[1].setPosition(330,750);
        alien2.setPosition(520,900);
        aliensS[2].setPosition(330,870);
        alien3.setPosition(520,1010);
        aliensS[3].setPosition(340,980);

        window.clear();
        window.draw(title);
        window.draw(shot);
        window.draw(left);
        window.draw(right);
        window.draw(myst);
        window.draw(aliensS[0]);
        window.draw(alien1);
        window.draw(aliensS[1]);
        window.draw(alien2);
        window.draw(aliensS[2]);
        window.draw(alien3);
        window.draw(aliensS[3]);
        window.draw(back);
        window.display();
    }
}

void Info::centerText(Text& text, float height){
    FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width/2.0f,textRect.top  + textRect.height/2.0f);
    text.setPosition(Vector2f(1280/2.0f, height));
}