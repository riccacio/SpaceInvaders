#include "Menu.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <unistd.h>
#include <sstream>

using namespace sf;

Menu::Menu():record(6223), i(0),event(){
    unique_ptr<MenuController> mc(new MenuController);
}

void Menu::run(){
    RenderWindow window(VideoMode(WIDTH, HEIGHT), "Space Invaders");
    if(!buffer.loadFromFile("Sound/menu.wav")){
        std::cout << ("ERROR: sound not found!") << std::endl;
        window.close();
    }
    if(!f1.loadFromFile("Font/arcade.TTF")){
        std::cout << ("ERROR: font not found!") << std::endl;
        window.close();
    }
    if(!texShip.loadFromFile("Sprite/ship.png")){
        std::cout << ("ERROR: sprite ship not found!") << std::endl;
        window.close();
    }

    sound.setBuffer(buffer);
    //sound.play();
    sound.setLoop(true);
    while (window.isOpen()) {
        while (window.pollEvent(event)){
            if (event.type == Event::Closed)
                window.close();
        }
        title.setFont(f1);
        text.setFont(f1);
        info.setFont(f1);
        hiScore.setFont(f1);
        recordText.setFont(f1);

        title.setString("SPACE INVADERS");
        text.setString("PRESS SPACE TO START");
        info.setString("HOW TO PLAY H (H)");
        hiScore.setString("HI-SCORE: ");
        std::stringstream ss;
        ss<<record;
        std::string s;
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

        centerText(title, 370);
        centerText(info, 550);
        centerText(text, 750);
        centerSprite(sprShip, 950);

        hiScore.setPosition(30,20);
        recordText.setPosition(310,20);

        sprShip.setTexture(texShip);
        sprShip.setScale(7,7);

        //flashing text
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

void Menu::centerText(Text& text, float height){
    FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width/2.0f,textRect.top  + textRect.height/2.0f);
    text.setPosition(Vector2f(WIDTH/2.0f, height));
}
void Menu::centerSprite(Sprite& sprite, float height){
    FloatRect textRect = sprite.getLocalBounds();
    sprite.setOrigin(textRect.left + textRect.width/2.0f,textRect.top  + textRect.height/2.0f);
    sprite.setPosition(Vector2f(WIDTH/2.0f, height));
}