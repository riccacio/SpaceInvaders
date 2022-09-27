#include "Info.h"
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

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
        f1.loadFromFile("Font/ARCADE_N.TTF");
        Text title;
        Text shot;
        Text left;
        Text right;
        Text myst;
        Text alien1;
        Text alien2;
        Text alien3;
        Text back;
        Texture mystT;
        Texture alien1T;
        Texture alien2T;
        Texture alien3T;
        Sprite mystS;
        Sprite alien1S;
        Sprite alien2S;
        Sprite alien3S;

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

        mystT.loadFromFile("Sprite/mystery.png");
        alien1T.loadFromFile("Sprite/alien1_0.png");
        alien2T.loadFromFile("Sprite/alien2_0.png");
        alien3T.loadFromFile("Sprite/alien3_0.png");
        mystS.setTexture(mystT);
        alien1S.setTexture(alien1T);
        alien2S.setTexture(alien2T);
        alien3S.setTexture(alien3T);
        mystS.setScale(5,5);
        alien1S.setScale(4,4);
        alien2S.setScale(4,4);
        alien3S.setScale(4,4);

        title.setFillColor(Color::White);
        shot.setFillColor(Color::White);
        left.setFillColor(Color::White);
        right.setFillColor(Color::White);
        myst.setFillColor(Color::White);
        alien1.setFillColor(Color::White);
        alien2.setFillColor(Color::White);
        alien3.setFillColor(Color::White);
        back.setFillColor(Color::Green);

        title.setCharacterSize(45);
        shot.setCharacterSize(35);
        left.setCharacterSize(35);
        right.setCharacterSize(35);
        myst.setCharacterSize(35);
        alien1.setCharacterSize(35);
        alien2.setCharacterSize(35);
        alien3.setCharacterSize(35);
        back.setCharacterSize(25);

        title.setPosition(420,150);
        shot.setPosition(320,350);
        left.setPosition(320,450);
        right.setPosition(320,550);
        myst.setPosition(570,660);
        mystS.setPosition(370,650);
        alien1.setPosition(570,780);
        alien1S.setPosition(380,750);
        alien2.setPosition(570,900);
        alien2S.setPosition(380,870);
        alien3.setPosition(570,1010);
        alien3S.setPosition(390,980);
        back.setPosition(360,1170);

        window.clear();
        window.draw(title);
        window.draw(shot);
        window.draw(left);
        window.draw(right);
        window.draw(myst);
        window.draw(mystS);
        window.draw(alien1);
        window.draw(alien1S);
        window.draw(alien2);
        window.draw(alien2S);
        window.draw(alien3);
        window.draw(alien3S);
        window.draw(back);
        window.display();
    }
}