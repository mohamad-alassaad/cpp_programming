////////////////////////////          How to setup Qt and openCV on Windows         ////////////////////////////////////////
credits: https://wiki.qt.io/How_to_setup_Qt_and_openCV_on_Windows

1- Download the Qt installer from www.qt.io, then choose "Download now". from the installer choose QT 5.x.x and qttools
2-open qt creator to test if it is installed 
3-Download cmake from cmake.org. In this guide, 3.7.2 is used. Start cmake-3.7.2-win64-x64.msi, then choose the following settinge:
		you need it to rebuild opencv project
4-Download openCV from sourceforge. In this guide, version 3.2.0 is used. Start opencv-3.2.0-vc14.exe and let it extract to d:\ . Now the folder d:\opencv is created.
5-Add minGW to the windows PATH variable
	Open the control panel, 
	System and Security, 
	System, 
	Advanced system settings,
	Environment Variables,
	System Variables,
	Variable Name: Path
	Variable value: ;D:\Qt\Tools\mingw530_32\bin
6-compiling opencv 
	C:\Program Files\CMake\bin\cmake-gui.exe 
7-Then click Configure, let cmake create the build directory, and choose the following settings:
	Specify the generator for this project: MinGW Makefiles
 	Specify native compilers, next
 	Compilers C: D:\Qt\Tools\mingw530_32\bin\gcc.exe
 	Compilers C++: D:\Qt\Tools\mingw530_32\bin\g++.exe
	Finish
 	Check the box [X]WITH_QT
 	Check the box [X]WITH_OPENGL
 	set Qt5_DIR to D:\Qt\5.9\mingw53_32\lib\cmake\Qt5
	Uncheck the box []ENABLE_PRECOMPILED_HEADERS
	 Set QT_MAKE_EXECUTABLE to D:\Qt\5.9\mingw53_32\bin\qmake.exe
	 Set Qt5Concurrent_DIR to D:\Qt\5.9\mingw53_32\lib\cmake\Qt5Concurrent
 	Set Qt5Core_DIR to D:\Qt\5.9\mingw53_32\lib\cmake\Qt5Core
 	Set Qt5Gui_DIR to D:\Qt\5.9\mingw53_32\lib\cmake\Qt5Gui
 	Set Qt5Test_DIR to D:\Qt\5.9\mingw53_32\lib\cmake\Qt5Test
 	Set Qt5Widgets_DIR to D:\Qt\5.9\mingw53_32\lib\cmake\Qt5Widgets
 	Set Qt5OpenGL_DIR to D:\Qt\5.9\mingw53_32\lib\cmake\Qt5OpenGL
 	Set CMAKE_BUILD_TYPE to Release or RelWithDebInfo
 	Set OPENCV_VS_VERSIONINFO_SKIP=1
8-Then click configure again Then click generate
9-Next open cmd, and type the following commands. 
	 d:
 	cd d:\
 	cd opencv-build  
 	mingw32-make -j 8
 	mingw32-make install
9-Add OpenCV compiled libraries to the windows PATH variable
	Open the control panel, 
	System and Security, 
	System, 
	Advanced system settings,
	Environment Variables,
	System Variables,
	Variable Name: Path
	Variable value: ;D:\opencv-build\install\x86\mingw\bin
10-Compile and run the example
	create a qt project->new project ->other projects->....
11-modify the .pro file like this:

#-------------------------------------------------
#
# Project created by QtCreator 2017-03-05T12:30:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = opencvtest
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

INCLUDEPATH += D:\opencv\build\include

LIBS += D:\opencv-build\bin\libopencv_core320.dll
LIBS += D:\opencv-build\bin\libopencv_highgui320.dll
LIBS += D:\opencv-build\bin\libopencv_imgcodecs320.dll
LIBS += D:\opencv-build\bin\libopencv_imgproc320.dll
LIBS += D:\opencv-build\bin\libopencv_features2d320.dll
LIBS += D:\opencv-build\bin\libopencv_calib3d320.dll

# more correct variant, how set includepath and libs for mingw
# add system variable: OPENCV_SDK_DIR=D:/opencv/opencv-build/install
# read http://doc.qt.io/qt-5/qmake-variable-reference.html#libs

#INCLUDEPATH += $$(OPENCV_SDK_DIR)/include

#LIBS += -L$$(OPENCV_SDK_DIR)/x86/mingw/lib \
#        -lopencv_core320        \
#        -lopencv_highgui320     \
#        -lopencv_imgcodecs320   \
#        -lopencv_imgproc320     \
#        -lopencv_features2d320  \
#        -lopencv_calib3d320



12- modify mainwindow.cpp like this:

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // read an image
    cv::Mat image = cv::imread("f://1.jpg", 1);
    // create image window named "My Image"
    cv::namedWindow("My Image");
    // show the image on window
    cv::imshow("My Image", image);
}

MainWindow::~MainWindow()
{
    delete ui;
}

