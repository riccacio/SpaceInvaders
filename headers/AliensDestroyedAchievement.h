#ifndef SPACEINVADERS_ALIENSDESTROYEDACHIEVEMENT_H
#define SPACEINVADERS_ALIENSDESTROYEDACHIEVEMENT_H
#include "Observer.h"

class AliensDestroyedAchievement: public Observer {
private:
    int aliensKilled=0;
    int achievementKill = 250;
    int achievementReached = 0;
    bool drawable;
    bool achReached;

    void displayAchievements();
public:
    AliensDestroyedAchievement();
    ~AliensDestroyedAchievement() = default;

    void update(int stage);
    void update() override;
    void draw(RenderTarget &target) const;
    bool isDrawable();
    bool isAchReached();
    void setAchReached(bool achReached);
    void setAliensKilled(int aliensKilled);
    int getAliensKilled();
};


#endif //SPACEINVADERS_ALIENSDESTROYEDACHIEVEMENT_H
