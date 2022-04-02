$sudo apt-get update
$sudo apt-get install vim g++ codelite cmake
$mkdir src // contains all the src files
$touch src/Main.cpp
$vim CMakeLists.txt  // cmake file 
	cmake_minimum_required(VERSION 3.5)
	project (HelloWorld)
	set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++14")
	set (source_dir "${PROJECT_SOURCE_DIR}/src/")
	file (GLOB source_files "${source_dir}/*.cpp")
	add_executable (HelloWorld ${source_files})

	:wq
$vim build.sh // this script will run the Cmake for us
	#!/bin/sh 
	cmake -G "CodeLite - Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug
	
	:wq

$chmod +x build.sh // to run a script in linux, you must mark it as executable (we added the executable flag to the build.sh file)
$./build.sh  // it will written some file for us. 
$ls
$codelite HelloWorld.workspace &
	open Main.cpp in codelite and write this
		#include <iostream>

		int main()
		{
			std::cout << "Hello World !" << std::endl;
			std::cin.get();
		}
	
	then you build the project in codelite

$ls 
	you should have the "HelloWorld" executable
$./HelloWorld

