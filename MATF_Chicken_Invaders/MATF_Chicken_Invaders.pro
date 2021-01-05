QT       += core gui sql \
         multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/enemies/balloonchicken.cpp \
    src/enemies/bigchicken.cpp \
    src/enemies/bigegg.cpp \
    src/enemies/bigeggbullets.cpp \
    src/enemies/chicken.cpp \
    src/enemies/egg.cpp \
    src/enemies/eggchicken.cpp \
    src/enemies/meteor.cpp \
    src/enemies/planetchicken.cpp \
    src/enemies/sideChicken.cpp \
    src/enemies/wavechicken.cpp \
    src/games/balloonGame.cpp \
    src/games/bossgame.cpp \
    src/games/chickenmatrixgame.cpp \
    src/games/eggchickengame.cpp \
    src/games/meteorshowergame.cpp \
    src/games/planetchickengame.cpp \
    src/games/sideChickenGame.cpp \
    src/games/sidemeteorshowergame.cpp \
    src/games/wavechickengame.cpp \
    src/main/chooselevelwindow.cpp \
    src/main/hofwindow.cpp \
    src/main/main.cpp \
    src/main/maingamewindow.cpp \
    src/main/mainwindow.cpp \
    src/main/optionswindow.cpp \
    src/main/planet.cpp \
    src/main/player.cpp \
    src/main/quitgamewindow.cpp \
    src/main/score.cpp \
    src/main/usernamewindow.cpp \
    src/main/winwindow.cpp \
    src/spaceship/projectile.cpp \
    src/spaceship/sidespaceship.cpp \
    src/spaceship/spaceship.cpp \
    src/treets/drumstick.cpp \
    src/treets/gift.cpp \
    src/treets/roastChicken.cpp \


HEADERS += \
    headers/enemies_h/balloonchicken.h \
    headers/enemies_h/bigchicken.h \
    headers/enemies_h/bigegg.h \
    headers/enemies_h/bigeggbullets.h \
    headers/enemies_h/chicken.h \
    headers/enemies_h/egg.h \
    headers/enemies_h/eggchicken.h \
    headers/enemies_h/meteor.h \
    headers/enemies_h/planetchicken.h \
    headers/enemies_h/sideChicken.h \
    headers/enemies_h/wavechicken.h \
    headers/games_h/balloongame.h \
    headers/games_h/bossgame.h \
    headers/games_h/chickenmatrixgame.h \
    headers/games_h/eggchickengame.h \
    headers/games_h/meteorshowergame.h \
    headers/games_h/planetchickengame.h \
    headers/games_h/sideChickenGame.h \
    headers/games_h/sidemeteorshowergame.h \
    headers/games_h/wavechickengame.h \
    headers/main_h/chooselevelwindow.h \
    headers/main_h/hofwindow.h \
    headers/main_h/maingamewindow.h \
    headers/main_h/mainwindow.h \
    headers/main_h/optionswindow.h \
    headers/main_h/planet.h \
    headers/main_h/player.h \
    headers/main_h/quitgamewindow.h \
    headers/main_h/score.h \
    headers/main_h/usernamewindow.h \
    headers/main_h/winwindow.h \
    headers/spaceship_h/projectile.h \
    headers/spaceship_h/sidespaceship.h \
    headers/spaceship_h/spaceship.h \
    headers/treets_h/drumstick.h \
    headers/treets_h/gift.h \
    headers/treets_h/roastChicken.h \

FORMS += \
    forms/chooselevelwindow.ui \
    forms/mainwindow.ui \
    forms/usernamewindow.ui \
    forms/optionswindow.ui \
    forms/maingamewindow.ui \
    forms/hofwindow.ui \
    forms/quitgamewindow.ui \
    forms/winwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc \
    sounds.qrc \

DISTFILES += \
    database.db
