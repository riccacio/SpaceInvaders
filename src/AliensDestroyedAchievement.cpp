#include "../headers/AliensDestroyedAchievement.h"

AliensDestroyedAchievement::AliensDestroyedAchievement():drawable(false), achReached(false) {}

void AliensDestroyedAchievement::update(int stage) {
    if(stage >= 1 && stage !=6){
        achievementReached = stage;
        displayAchievements();
        drawable=true;
    }
}

void AliensDestroyedAchievement::update() {
    aliensKilled++;
    if(aliensKilled == achievementKill){
        achievementReached = 6;
        displayAchievements();
        drawable=true;
        achReached = true;
    }
}

void AliensDestroyedAchievement::displayAchievements() {
    switch(achievementReached){
        case 1:
            title.setString("Welcome, Rookie!");
            description.setString("Clear 1 board of aliens");
            texture.loadFromFile("sprite/clear1.png");
            display.setSize(Vector2f(650, 155));
            break;
        case 2:
            title.setString("This is War!");
            description.setString("Clear 2 boards of aliens");
            texture.loadFromFile("sprite/clear2.png");
            display.setSize(Vector2f(650, 155));
            break;
        case 3:
            title.setString("As Much As It Takes");
            description.setString("Clear 3 boards of aliens");
            texture.loadFromFile("sprite/clear3.png");
            display.setSize(Vector2f(700, 155));
            break;
        case 5:
            title.setString("Master Defender of earth");
            description.setString("Clear 5 boards of aliens");
            texture.loadFromFile("sprite/clear5.png");
            display.setSize(Vector2f(850, 155));
            break;
        case 6:
            title.setString("Exterminator");
            description.setString("Kill 250 invaders");
            texture.loadFromFile("sprite/ext.png");
            display.setSize(Vector2f(550, 155));
            break;
        default:
            break;
    }
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


bool AliensDestroyedAchievement::isDrawable() const {
    return drawable;
}

bool AliensDestroyedAchievement::isAchReached() const {
    return achReached;
}

int AliensDestroyedAchievement::getAliensKilled() const {
    return aliensKilled;
}

void AliensDestroyedAchievement::setAchReached(bool achReached) {
    this->achReached = achReached;
}

void AliensDestroyedAchievement::setAliensKilled(int aliensKilled){
    this->aliensKilled = aliensKilled;
}