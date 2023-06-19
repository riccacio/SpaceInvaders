#include "../headers/Observer.h"

Observer::Observer() {
    initFont();
}

void Observer::update() {}

void Observer::initFont() {
    textF.loadFromFile("font/arcade.TTF");
}

void Observer::displayAchievements(std::string title, std::string description, std::string textureName, Vector2f size) {
    this->title.setString(title);
    this->description.setString(description);
    texture.loadFromFile(textureName);
    display.setSize(size);

    display.setFillColor(Color::Black);
    display.setOutlineColor(Color::Green);
    display.setOutlineThickness(3);
    display.setPosition((1280/2)-display.getGlobalBounds().width/2 ,70);

    sprite.setPosition(display.getPosition().x+10, display.getPosition().y+10);
    sprite.setTexture(texture);
    sprite.setScale(2,2);

    this->title.setCharacterSize(28);
    this->title.setFillColor(Color::Green);
    this->title.setPosition(sprite.getPosition().x + sprite.getGlobalBounds().width+20, sprite.getPosition().y);
    this->title.setFont(textF);

    this->description.setCharacterSize(20);
    this->description.setFillColor(Color::White);
    this->description.setPosition(this->title.getPosition().x, this->title.getPosition().y+55);
    this->description.setFont(textF);
}

void Observer::draw(RenderTarget &target) const {
    target.draw(display);
    target.draw(title);
    target.draw(description);
    target.draw(sprite);
}

