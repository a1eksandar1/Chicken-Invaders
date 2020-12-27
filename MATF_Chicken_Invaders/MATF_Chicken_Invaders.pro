QT       += core gui \
         multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/quitgamewindow.cpp \
    src/balloonGame.cpp \
    src/balloonchicken.cpp \
    src/bigchicken.cpp \
    src/bossgame.cpp \
    src/lives.cpp \
    src/score.cpp \
    src/drumstick.cpp \
    src/maingamewindow.cpp \
    src/chickenmatrixgame.cpp \
    src/bigeggbullets.cpp \
    src/bigegg.cpp \
    src/gift.cpp \
    src/meteor.cpp \
    src/meteorshowergame.cpp \
    src/projectile.cpp \
    src/planet.cpp \
    src/roastChicken.cpp \
    src/sideChicken.cpp \
    src/sideChickenGame.cpp \
    src/sidemeteorshowergame.cpp \
    src/sidespaceship.cpp \
    src/chooselevelwindow.cpp \
    src/chicken.cpp \
    src/egg.cpp \
    src/optionswindow.cpp \
    src/spaceship.cpp \
    src/gamewindow.cpp \
    src/main.cpp \
    src/mainwindow.cpp \
    src/usernamewindow.cpp

HEADERS += \
    headers/balloonchicken.h \
    headers/balloongame.h \
    headers/bigchicken.h \
    headers/bossgame.h \
    headers/lives.h \
    headers/score.h \
    headers/chickenmatrixgame.h \
    headers/bigeggbullets.h \
    headers/bigegg.h \
    headers/chooselevelwindow.h \
    headers/chicken.h \
    headers/drumstick.h \
    headers/egg.h \
    headers/gamewindow.h \
    headers/gift.h \
    headers/mainwindow.h \
    headers/meteor.h \
    headers/meteorshowergame.h \
    headers/roastChicken.h \
    headers/sideChicken.h \
    headers/sideChickenGame.h \
    headers/sidemeteorshowergame.h \
    headers/spaceship.h \
    headers/usernamewindow.h \
    headers/optionswindow.h \
    headers/projectile.h \
    headers/sidespaceship.h \
    headers/planet.h \
    headers/maingamewindow.h \
    headers/quitgamewindow.h

FORMS += \
    forms/chooselevelwindow.ui \
    forms/mainwindow.ui \
    forms/usernamewindow.ui \
    forms/gamewindow.ui \
    forms/optionswindow.ui \
    forms/maingamewindow.ui \
    forms/quitgamewindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc \
    sounds.qrc \
