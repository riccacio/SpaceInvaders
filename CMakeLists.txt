cmake_minimum_required(VERSION 3.20)
project(SpaceInvaders)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")
set(SOURCE_FILES main.cpp src/Menu.cpp "headers/Menu.h" src/Info.cpp "headers/Info.h" src/GameOver.cpp "headers/GameOver.h" src/MainWindow.cpp "headers/MainWindow.h" src/Game.cpp "headers/Game.h" src/Ship.cpp "headers/Ship.h" headers/Global.h src/Bullet.cpp headers/Bullet.h src/Map.cpp headers/Map.h src/Alien.cpp headers/Alien.h src/UFO.cpp headers/UFO.h src/PowerUp.cpp headers/PowerUp.h src/PowerUp.cpp)
set(EXECUTABLE_NAME SpaceInvaders)
add_executable(SpaceInvaders ${SOURCE_FILES})

include_directories(/usr/local/include)

# Unit test
add_subdirectory(tests)
add_library(core ${SOURCE_FILES})
target_link_libraries(SpaceInvaders core)

# Detect SFML library
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2 COMPONENTS system window graphics network audio REQUIRED)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()