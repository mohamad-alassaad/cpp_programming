cmake_minimum_required(VERSION 2.8)
project( DisplayImage )


set(OpenCV_INCLUDE_DIRS_test
  /usr/local/include
  /usr/local/include/opencv4
)

set(OpenCV_LIB_DIR_test
  /usr/local/lib
)

set(OpenCV_LIBS_test
  opencv_core
  opencv_highgui
  opencv_imgcodecs
)



include_directories(${OpenCV_INCLUDE_DIRS_test})
link_directories(${OpenCV_LIB_DIR_test})



add_executable( DisplayImage DisplayImage.cpp )
target_link_libraries( DisplayImage ${OpenCV_LIBS_test} )