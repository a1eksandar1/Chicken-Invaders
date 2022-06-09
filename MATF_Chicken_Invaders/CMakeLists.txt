cmake_minimum_required(VERSION 3.10.2)
project(ChickenInvaders VERSION 1.0.0 LANGUAGES CXX)

include_directories(headers)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC OFF)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Sql REQUIRED)
find_package(Qt5Multimedia REQUIRED)
find_package(Qt5Widgets REQUIRED)

set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -std=c++0x")

set(SOURCES
    src/enemies/balloonchicken.cpp
    src/enemies/bigchicken.cpp
    src/enemies/bigegg.cpp
    src/enemies/bigeggbullets.cpp
    src/enemies/chicken.cpp
    src/enemies/egg.cpp
    src/enemies/eggchicken.cpp
    src/enemies/meteor.cpp
    src/enemies/planetchicken.cpp
    src/enemies/sideChicken.cpp
    src/enemies/wavechicken.cpp
    src/games/balloonGame.cpp 
    src/games/bossgame.cpp 
    src/games/chickenmatrixgame.cpp 
    src/games/eggchickengame.cpp 
    src/games/meteorshowergame.cpp 
    src/games/planetchickengame.cpp 
    src/games/sideChickenGame.cpp 
    src/games/sidemeteorshowergame.cpp 
    src/games/wavechickengame.cpp 
    src/main/chooselevelwindow.cpp 
    src/main/hofwindow.cpp 
    src/main/main.cpp 
    src/main/maingamewindow.cpp 
    src/main/mainwindow.cpp 
    src/main/optionswindow.cpp 
    src/main/planet.cpp 
    src/main/player.cpp 
    src/main/quitgamewindow.cpp 
    src/main/score.cpp 
    src/main/usernamewindow.cpp 
    src/main/winwindow.cpp 
    src/spaceship/projectile.cpp 
    src/spaceship/sidespaceship.cpp 
    src/spaceship/spaceship.cpp 
    src/treets/drumstick.cpp 
    src/treets/gift.cpp 
    src/treets/roastChicken.cpp 
)

set(HEADERS
    headers/enemies_h/balloonchicken.h 
    headers/enemies_h/bigchicken.h 
    headers/enemies_h/bigegg.h 
    headers/enemies_h/bigeggbullets.h 
    headers/enemies_h/chicken.h 
    headers/enemies_h/egg.h 
    headers/enemies_h/eggchicken.h 
    headers/enemies_h/meteor.h 
    headers/enemies_h/planetchicken.h 
    headers/enemies_h/sideChicken.h 
    headers/enemies_h/wavechicken.h 
    headers/games_h/balloongame.h 
    headers/games_h/bossgame.h 
    headers/games_h/chickenmatrixgame.h 
    headers/games_h/eggchickengame.h 
    headers/games_h/meteorshowergame.h 
    headers/games_h/planetchickengame.h 
    headers/games_h/sideChickenGame.h 
    headers/games_h/sidemeteorshowergame.h 
    headers/games_h/wavechickengame.h 
    headers/main_h/chooselevelwindow.h 
    headers/main_h/hofwindow.h 
    headers/main_h/maingamewindow.h 
    headers/main_h/mainwindow.h 
    headers/main_h/optionswindow.h 
    headers/main_h/planet.h 
    headers/main_h/player.h 
    headers/main_h/quitgamewindow.h 
    headers/main_h/score.h 
    headers/main_h/usernamewindow.h 
    headers/main_h/winwindow.h 
    headers/spaceship_h/projectile.h 
    headers/spaceship_h/sidespaceship.h 
    headers/spaceship_h/spaceship.h 
    headers/treets_h/drumstick.h 
    headers/treets_h/gift.h 
    headers/treets_h/roastChicken.h 
)

set(UI_FILES
    forms/chooselevelwindow.ui 
    forms/mainwindow.ui 
    forms/usernamewindow.ui 
    forms/optionswindow.ui 
    forms/maingamewindow.ui 
    forms/hofwindow.ui 
    forms/quitgamewindow.ui 
    forms/winwindow.ui
)
    
qt5_add_resources(images.qrc)

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES} ${UI_HEADERS})
qt5_use_modules(${PROJECT_NAME} Core Gui Sql Multimedia Widgets)

