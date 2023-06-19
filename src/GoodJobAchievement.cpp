#include "../headers/GoodJobAchievement.h"

GoodJobAchievement::GoodJobAchievement(): drawable(false), reached(false) {}

void GoodJobAchievement::update(bool lifeLost) {
    if(!lifeLost){
        displayAchievements("A job well done", "Clear the board without losing a life Lost", "sprite/job.png", Vector2f{1050,155});
        drawable= true;
        reached=true;
    }
}

bool GoodJobAchievement::isDrawable() {
    return drawable;
}
bool GoodJobAchievement::isReached() {
    return reached;
}
