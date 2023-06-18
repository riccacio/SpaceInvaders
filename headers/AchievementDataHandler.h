#ifndef SPACEINVADERS_ACHIEVEMENTDATAHANDLER_H
#define SPACEINVADERS_ACHIEVEMENTDATAHANDLER_H
#include <iostream>
#include <fstream>

class AchievementDataHandler {
public:
    void saveAchievementData(std::string filename, int data);
    int loadAchievementData(std::string filename);
    void resetAchievementData(std::string filename);
};

#endif //SPACEINVADERS_ACHIEVEMENTDATAHANDLER_H



