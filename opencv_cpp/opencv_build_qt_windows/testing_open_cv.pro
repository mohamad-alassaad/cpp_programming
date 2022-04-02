QT += core
QT -= gui
TARGET = testing_open_cv
CONFIG += console
TEMPLATE = app

INCLUDEPATH += C:/Users/md_al/Desktop/fix_martin_code/CodePythonWithData/lib/GetCorrespondences/opencv/build/include    #  hayda okay le2an eder ye2ra.

LIBS += C:/Users/md_al/Desktop/fix_martin_code/CodePythonWithData/lib/GetCorrespondences/opencv-build/bin/libopencv_core453.dll
LIBS += C:/Users/md_al/Desktop/fix_martin_code/CodePythonWithData/lib/GetCorrespondences/opencv-build/bin/libopencv_highgui453.dll
LIBS += C:/Users/md_al/Desktop/fix_martin_code/CodePythonWithData/lib/GetCorrespondences/opencv-build/bin/libopencv_imgcodecs453.dll
LIBS += C:/Users/md_al/Desktop/fix_martin_code/CodePythonWithData/lib/GetCorrespondences/opencv-build/bin/libopencv_imgproc453.dll
LIBS += C:/Users/md_al/Desktop/fix_martin_code/CodePythonWithData/lib/GetCorrespondences/opencv-build/bin/libopencv_features2d453.dll
LIBS += C:/Users/md_al/Desktop/fix_martin_code/CodePythonWithData/lib/GetCorrespondences/opencv-build/bin/libopencv_calib3d453.dll





# more correct variant, how set includepath and libs for mingw
# add system variable: OPENCV_SDK_DIR=D:/opencv/opencv-build/install
# read http://doc.qt.io/qt-5/qmake-variable-reference.html#libs

#INCLUDEPATH += $$(OPENCV_SDK_DIR)/include

#LIBS += -L$$(OPENCV_SDK_DIR)/x64/mingw/lib \
#        -lopencv_core453       \
#        -lopencv_highgui453     \
#        -lopencv_imgcodecs453  \
#        -lopencv_imgproc453     \
#        -lopencv_features2d453  \
#        -lopencv_calib3d453


SOURCES += main.cpp
HEADERS += test.h




