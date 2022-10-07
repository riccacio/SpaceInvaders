cmake_minimum_required(VERSION 3.20)
project(SpaceInvaders)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")
set(SOURCE_FILES main.cpp src/Menu.cpp include/Menu.h src/Info.cpp include/Info.h src/GameOver.cpp include/GameOver.h src/MainWindow.cpp include/MainWindow.h)

add_executable(SpaceInvaders ${SOURCE_FILES})

include_directories(/usr/local/include)
find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(SpaceInvaders sfml-system sfml-window sfml-graphics sfml-audio sfml-network)