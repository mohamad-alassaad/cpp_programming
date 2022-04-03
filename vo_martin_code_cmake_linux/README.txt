//////////////////////////////////       running marting code with Cmake directly instead of qtcreator interface               //////////////////////////////



1-delete all unncessary qt files and folder (.pro .pro.user build.....)
2-create CMakeLists.txt file 

cmake_minimum_required(VERSION 2.8)
project( GetCorrespondence )

#include opencv
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} 
			  )

#include local files
file(GLOB SRC_FILES 
	"*.cpp"
	) 
set(INC_FILES_DIR
	./)
include_directories(${INC_FILES_DIR})	


#add the executable and the linked libraries													
add_executable( GetCorrespondence ${SRC_FILES})
target_link_libraries( GetCorrespondence ${OpenCV_LIBS} )

#instruction to the complier
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++14 -mpopcnt")
set (CMAKE_CXXFLAGS_RELEASE "${CMAKE_CXXFLAGS_RELEASE} -Ofast")


3-$mkdir build && cd build 

4-$cmake ../

5-$make -j8

6-$./GetCorrespondences
	Espace de ... tu ne me files pas assez de données !!!!


