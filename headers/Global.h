#ifndef SPACEINVADERS_GLOBAL_H
#define SPACEINVADERS_GLOBAL_H

constexpr unsigned int WIDTH = 1280;
constexpr unsigned int HEIGHT = 1400;
constexpr unsigned char FAST_RELOAD_DURATION = 7;
constexpr float BULLET_SPEED = 2.5;
constexpr unsigned char SHIP_MOVE_SPEED = 2;
constexpr unsigned char RELOAD_DURATION = 75;
constexpr unsigned int ALIEN_CHANGE = 200;
constexpr unsigned int SPAN = 4; //sottrarre da ALIEN_CHANGE per ogni morte alieno
constexpr float ALIEN_SPEED = 15;
constexpr unsigned short ENEMY_SHOOT_CHANCE = 4096;
constexpr unsigned short ENEMY_SHOOT_CHANCE_INCREASE = 64;
constexpr unsigned short ENEMY_SHOOT_CHANCE_MIN = 1024;
constexpr unsigned char OFFSET = 20;

#endif //SPACEINVADERS_GLOBAL_H
