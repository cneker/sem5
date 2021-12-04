QT       += core gui
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    add.cpp \
    car.cpp \
    driver.cpp \
    fuel.cpp \
    main.cpp \
    garaj.cpp \
    shipping.cpp \
    updatedelete.cpp

HEADERS += \
    add.h \
    car.h \
    driver.h \
    fuel.h \
    garaj.h \
    shipping.h \
    updatedelete.h

FORMS += \
    add.ui \
    garaj.ui \
    updatedelete.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
