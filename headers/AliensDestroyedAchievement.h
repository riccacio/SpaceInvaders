#ifndef SPACEINVADERS_ALIENSDESTROYEDACHIEVEMENT_H
#define SPACEINVADERS_ALIENSDESTROYEDACHIEVEMENT_H
#include "Observer.h"

class AliensDestroyedAchievement: public Observer {
private:
    int aliensKilled=0;
    int achievementKill = 10;
    int achievementReached = 0;
    bool drawable;
    RectangleShape display;

    void displayAchievements();
public:
    AliensDestroyedAchievement();
    ~AliensDestroyedAchievement() = default;

    void update(int stage);
    void update() override;
    void draw(RenderTarget &target) const;
    bool isDrawable();
    void setDrawable(bool drawable);
};


#endif //SPACEINVADERS_ALIENSDESTROYEDACHIEVEMENT_H
