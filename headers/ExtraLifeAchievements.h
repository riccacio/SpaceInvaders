#ifndef SPACEINVADERS_EXTRALIFEACHIEVEMENTS_H
#define SPACEINVADERS_EXTRALIFEACHIEVEMENTS_H
#include "Observer.h"

class ExtraLifeAchievements: public Observer {
private:
    int achievementsReached = 1500;
    bool drawable;
    bool reached;

    void displayAchievements();
public:
    ExtraLifeAchievements();
    ~ExtraLifeAchievements() = default;

    void update(int score);
    void draw(RenderTarget &target) const;
    bool isDrawable();
    bool isReached();
    void setReached(bool reached);
};


#endif //SPACEINVADERS_EXTRALIFEACHIEVEMENTS_H
