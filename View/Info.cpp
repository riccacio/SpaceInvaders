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
        mystS.setPosition(320,650);
        alien1.setPosition(520,780);
        alien1S.setPosition(330,750);
        alien2.setPosition(520,900);
        alien2S.setPosition(330,870);
        alien3.setPosition(520,1010);
        alien3S.setPosition(340,980);

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

void Info::centerText(Text& text, int height){
    FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width/2.0f,textRect.top  + textRect.height/2.0f);
    text.setPosition(Vector2f(1280/2.0f, height));
}