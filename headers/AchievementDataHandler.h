#ifndef SPACEINVADERS_ACHIEVEMENTDATAHANDLER_H
#define SPACEINVADERS_ACHIEVEMENTDATAHANDLER_H
#include <iostream>
#include <fstream>

class AchievementDataHandler {
public:
    //functions
    static void saveAchievementData(const std::string& filename, int data);
    static int loadAchievementData(const std::string& filename);
    static void resetAchievementData(const std::string& filename);
};

#endif //SPACEINVADERS_ACHIEVEMENTDATAHANDLER_H