#ifndef SPACEINVADERS_GOODJOBACHIEVEMENT_H
#define SPACEINVADERS_GOODJOBACHIEVEMENT_H
#include "Observer.h"

class GoodJobAchievement: public Observer{
private:
    bool drawable;
    bool reached;
public:
    //constructor
    GoodJobAchievement();

    void update(bool life);

    //getter & setter
    bool isDrawable();
    bool isReached();
};

#endif //SPACEINVADERS_GOODJOBACHIEVEMENT_H