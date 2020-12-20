QT       += core gui \
         multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/chickenmatrixgame.cpp \
    src/gift.cpp \
    src/meteor.cpp \
    src/meteorshowergame.cpp \
    src/projectile.cpp \
    src/planet.cpp \
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
    headers/chickenmatrixgame.h \
    headers/chooselevelwindow.h \
    headers/chicken.h \
    headers/egg.h \
    headers/gamewindow.h \
    headers/gift.h \
    headers/mainwindow.h \
    headers/meteor.h \
    headers/meteorshowergame.h \
    headers/sidemeteorshowergame.h \
    headers/spaceship.h \
    headers/usernamewindow.h \
    headers/optionswindow.h \
    headers/projectile.h \
    headers/sidespaceship.h \
    headers/planet.h

FORMS += \
    forms/chooselevelwindow.ui \
    forms/mainwindow.ui \
    forms/usernamewindow.ui \
    forms/gamewindow.ui \
    forms/optionswindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc \
    sounds.qrc \
