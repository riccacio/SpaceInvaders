#include "../headers/AchievementDataHandler.h"

void AchievementDataHandler::saveAchievementData(const std::string& filename, int data) {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << data;
        file.close();
    }
}

int AchievementDataHandler::loadAchievementData(const std::string& filename) {
    int data = 0;
    std::ifstream file(filename);
    if (file.is_open()) {
        file >> data;
        file.close();
    }
    return data;
}

void AchievementDataHandler::resetAchievementData(const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << 0;
        file.close();
    }
}