QT       += core gui sql
QT += core gui testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
QT += core testlib

CONFIG += console
CONFIG -= app_bundle
SOURCES += \
    build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/debug/form.cpp \
    build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/debug/loginform.cpp \
    gameconfiguration.cpp \
    main.cpp \
    testgameconfiguration.cpp \
    tictactoewidget.cpp \
    titlewindow.cpp

HEADERS += \
    build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/debug/form.h \
    build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/debug/loginform.h \
    gameconfiguration.h \
    sessionmanager.h \
    testgameconfiguration.h \
    tictactoewidget.h \
    titlewindow.h

FORMS += \
    build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/debug/form.ui \
    build/Desktop_Qt_6_7_0_MinGW_64_bit-Debug/debug/loginform.ui \
    gameconfiguration.ui \
    tictactoewidget.ui \
    titlewindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

    DEFINES += RUN_TESTS

DISTFILES += \
    tst_ex.qml \
    tst_new.qml \
    tst_tester.qml \
    tst_trew.qml
