QT       += core gui \
         multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/hofwindow.cpp \
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
    headers/chooselevelwindow.h \
    headers/chicken.h \
    headers/egg.h \
    headers/gamewindow.h \
    headers/mainwindow.h \
    headers/spaceship.h \
    headers/usernamewindow.h \
    headers/optionswindow.h \
    headers/hofwindow.h
    headers/spaceship.h

FORMS += \
    forms/chooselevelwindow.ui \
    forms/mainwindow.ui \
    forms/usernamewindow.ui \
    forms/gamewindow.ui \
    forms/optionswindow.ui \
    forms/hofwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc \
    sounds.qrc
