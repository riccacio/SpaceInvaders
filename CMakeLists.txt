cmake_minimum_required(VERSION 3.20)
project(SpaceInvaders)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")
set(SOURCE_FILES main.cpp src/Menu.cpp "headers/Menu.h" src/Info.cpp "headers/Info.h" src/GameOver.cpp "headers/GameOver.h" src/MainWindow.cpp "headers/MainWindow.h" src/Game.cpp "headers/Game.h" src/Ship.cpp "headers/Ship.h" headers/Global.h src/Bullet.cpp headers/Bullet.h src/Map.cpp headers/Map.h)

add_executable(SpaceInvaders ${SOURCE_FILES})

include_directories(/usr/local/include)
find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(SpaceInvaders sfml-system sfml-window sfml-graphics sfml-audio sfml-network)