#ifndef SPACEINVADERS_GOODJOBACHIEVEMENT_H
#define SPACEINVADERS_GOODJOBACHIEVEMENT_H
#include "Observer.h"

class GoodJobAchievement: public Observer{
private:
    bool drawable;
    bool reached;
public:
    GoodJobAchievement();
    ~GoodJobAchievement() = default;

    void update(bool life);
    bool isDrawable();
    bool isReached();
    void setReached(bool reached);
};


#endif //SPACEINVADERS_GOODJOBACHIEVEMENT_H
