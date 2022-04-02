
cmake_minimum_required(VERSION 3.16.3)
project(CPPTutorial)


option(BUILD_TESTS "Turn on build for tests of CPPTutorial" OFF)



file(GLOB SRC_FILES 
	"src/*.cpp"
		) 
set(INC_FILES_DIR
	include/)


if (BUILD_TESTS)
	add_subdirectory(test)
endif()


include_directories(${INC_FILES_DIR})																	
add_executable(CPPTutorial ${SRC_FILES})
