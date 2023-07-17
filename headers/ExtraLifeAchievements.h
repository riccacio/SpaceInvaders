#ifndef SPACEINVADERS_EXTRALIFEACHIEVEMENTS_H
#define SPACEINVADERS_EXTRALIFEACHIEVEMENTS_H
#include "Observer.h"

class ExtraLifeAchievements: public Observer {
private:
    int achievementsReached = 1500;
    bool drawable;
    bool reached;
public:
    ExtraLifeAchievements();

    void update(int score);
    bool isDrawable() const;
    bool isReached() const;
    void setReached(bool reached);
};

#endif //SPACEINVADERS_EXTRALIFEACHIEVEMENTS_H