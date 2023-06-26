#ifndef SPACEINVADERS_ALIENSDESTROYEDACHIEVEMENT_H
#define SPACEINVADERS_ALIENSDESTROYEDACHIEVEMENT_H
#include "Observer.h"

class AliensDestroyedAchievement: public Observer {
private:
    int aliensKilled = 0;
    int achievementKill = 250;
    int achievementReached = 0;
    bool drawable;
    bool achReached;

    void displayAchievements();
public:
    //constructor
    AliensDestroyedAchievement();

    //functions
    void update(int stage);
    void update() override;

    //getter & setter
    bool isDrawable();
    bool isAchReached();
    int getAliensKilled();
    void setAchReached(bool achReached);
    void setAliensKilled(int aliensKilled);
};

#endif //SPACEINVADERS_ALIENSDESTROYEDACHIEVEMENT_H