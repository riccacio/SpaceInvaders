#include "../headers/ExtraLifeAchievements.h"

ExtraLifeAchievements::ExtraLifeAchievements(): drawable(false), reached(false) {}

void ExtraLifeAchievements::update(int score) {
    if(score>1580){
        reached = false;
    }
    else if(score>=achievementsReached){
        displayAchievements("A new chance", "Earn an Extra lifeLost with 1500 points", "sprite/life.png", Vector2f{880, 155});
        drawable = true;
        reached = true;
    }
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