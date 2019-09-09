#-------------------------------------------------
#
# Project created by QtCreator 2019-09-09T08:22:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Qt-OpenCV-Test
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp

HEADERS += \
        mainwindow.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
LIBS += -LD:/workspace/opencv-4.1.1/build/install/x64/mingw/bin \
-lopencv_calib3d411 \
-lopencv_features2d411 \
-lopencv_highgui411 \
-lopencv_ml411 \
-lopencv_stitching411 \
-lopencv_core411 \
-lopencv_flann411 \
-lopencv_imgcodecs411 \
-lopencv_objdetect411 \
-lopencv_video411 \
-lopencv_dnn411 \
-lopencv_gapi411 \
-lopencv_imgproc411 \
-lopencv_photo411 \
-lopencv_videoio411

INCLUDEPATH += D:/workspace/opencv-4.1.1/build/install/include
DEPENDPATH += D:/workspace/opencv-4.1.1/build/install/include
