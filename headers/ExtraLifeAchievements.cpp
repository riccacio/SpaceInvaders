#include "ExtraLifeAchievements.h"

ExtraLifeAchievements::ExtraLifeAchievements(): drawable(false), reached(false) {}

void ExtraLifeAchievements::update(int score) {
    if(score>1600){
        reached = false;
    }
    else if(score>=achievementsReached){
        displayAchievements();
        drawable = true;
        reached = true;
    }
}

void ExtraLifeAchievements::displayAchievements() {
    title.setString("a new chance");
    description.setString("Earn an Extra Life with 1500 points");
    texture.loadFromFile("sprite/life.png");
    display.setSize(Vector2f(880, 155));

    display.setFillColor(Color::Black);
    display.setOutlineColor(Color::Green);
    display.setOutlineThickness(3);
    display.setPosition((1280/2)-display.getGlobalBounds().width/2 ,70);

    sprite.setPosition(display.getPosition().x+10, display.getPosition().y+10);
    sprite.setTexture(texture);
    sprite.setScale(2,2);

    title.setCharacterSize(28);
    title.setFillColor(Color::Green);
    title.setPosition(sprite.getPosition().x + sprite.getGlobalBounds().width+20, sprite.getPosition().y);
    title.setFont(textF);

    description.setCharacterSize(20);
    description.setFillColor(Color::White);
    description.setPosition(title.getPosition().x, title.getPosition().y+55);
    description.setFont(textF);
}

void ExtraLifeAchievements::draw(sf::RenderTarget &target) const {
    target.draw(display);
    target.draw(title);
    target.draw(description);
    target.draw(sprite);
}

bool ExtraLifeAchievements::isDrawable() {
    return drawable;
}

bool ExtraLifeAchievements::isReached(){
    return reached;
}

void ExtraLifeAchievements::setReached(bool reached) {
    this->reached = reached;
}