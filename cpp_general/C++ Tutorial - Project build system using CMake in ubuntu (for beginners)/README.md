
/////////////// C++ Tutorial - Project build system using CMake in ubuntu (for beginners) ////////////////////////////////////


This project, will help you build and create a c++ project (with include, src, test, readme) using cmake, it will be ready to be put on the github
first download the project from github
$ls 
	include, src, test, README.md

check cmake $ cmake --version 
if it is not installed $ sudo apt install cmake
in order to run the cmake configuration file (CMakeLists.txt) , you need to run the cmake binary: $cmake ./
create the CMakeLists.txt file $touch CMakeList.txt

you can now try the cmake with the empty configuration file $cmake ./CMakeLists.txt 
this will create additional files (CMakeCache.txt, CMakeFiles)
$ls 
	CMakeCache.txt CMakeFiles CMakeLists.txt include README.md src test
cd CMakeFiles 
$ls
	3.16.3 cmake.check_cache CMakeError.log CMakeOutput.log CMakeTmp
you can check the error when we try to run cmake $vim CMakeError.log
$cd ../
$rm -r -f CMakeFiles/
$rm CMakeCache.txt
$clear
$ls
CMakeLists.txt include README.md src test
configure the CMakeLists.txt file 
$vim CMakeLists.txt
	cmake_minimum_required(VERSION 3.16.3) // check your system cmake --version and set this one to it.
	project(CPPTutorial) //this is the project name. 
	file(GLOB SRC_FILES    //set the source files (the cpp files)
			"src/*.cpp"  // ex: SRC_FILES="src/main.cpp src/someclass.cpp src/anotherclass.cpp"
	)    // all these files will be added to the list of cpp files. 
	set(INC_FILES_DIR    // here I set the header files directory .h files
		include/       // it just takes the include directory.
		)
	include_directories(
			${INC_FILES_DIR}
			)

	// tell cmake to take all the scr files and include files and create executable 
	add_executable(CPPTutorial  // name of the executable to create
		${SRC_FILES}		

	:wq

$ls
CMakeLists.txt include README.md src test 
$mkdir build // create a build directory because you don't want your build files to be in the same directory with your source code. 
$ls 
build CMakeLists.txt include README.md src test 
$cd build // call cmake from here
$cmake ../  cmake only generates the make file for the actual build, so you also need to hold make here, also make have to be called
$ls
CMakeCache.txt CMakeFiles Cmake_install.cmake Makefile
$ make
$ls 
CMakeCache.txt CMakeFiles Cmake_install.cmake Makefile CPPTutotrial
./CPPTutorial
		Hello World ! 


// here I only created an executale, so in order to learn, we will create a test, which is a library
$ cd ../
$ vim CMakeLists.txt

	cmake_minimum_required(VERSION 3.16.3) // check your system cmake --version and set this one to it.
	project(CPPTutorial) //this is the project name. 
	
	
	option(BUILD_TESTS "Turn on build for tests of CPPTutorial" OFF) // for test code binary 


	file(GLOB SRC_FILES    //set the source files (the cpp files)
			"src/*.cpp"  // ex: SRC_FILES="src/main.cpp src/someclass.cpp src/anotherclass.cpp"
	)    // all these files will be added to the list of cpp files. 
	set(INC_FILES_DIR    // here I set the header files directory .h files
		include/       // it just takes the include directory.
		)


	if (BUILD_TESTS)  //if test is ON
		add_subdirectory(test)  // it also tries to find in the subdirectory the CMakeLists.txt and if it finds it, it will also run the rules in there 
	endif()                       // so I should also create CMakeLists.txt in the test directory.

	include_directories(
			${INC_FILES_DIR}
			)

	// tell cmake to take all the scr files and include files and create executable 
	add_executable(CPPTutorial  // name of the executable to create
		${SRC_FILES}		

	:wq

$ ls
CMakeLists.txt include README.md src test build
$cd test
$touch CMakeLists.txt
$vim CMakeLists.txt 
	// not necessary for cmakeversion and other stuff
	file(GLOB SRC_TEST_FILES
		"*.cpp") // include all the cpp files from this directory 
	//at the moment we don't need include files
	//we change this later. 
	
	add_executable(CPPTutotrial-test
			${SRC_TEST_FILES}
	)

	:wq

$ls 
CMakeLists.txt dummy_test.cpp
$mv dummy_test.cpp main.cpp  // we want executable for the test, so we should name it main.cpp, every executable should have main.cpp
$ vim main.cpp
	#include <iostream>
	int main()
	{
	std::cout <<"\n The test binary is working! \n";
	return 0;
	}
	:wq

$cd ../
build CMakeLists.txt include README.md src test 
$rm -r -f build   //clean it to have everything clear
$ mkdir build 
$ cd build 
$ cmake ..
$ make 
$ls 
CMakeCache.txt CMakeFiles cmake_install.cmake CPPTutorial Makefile  // we only have the binary for our main project, we don't have the CCPTutorial-test
$ vim ../CMakeLists.txt // that is because I set the option of BUILD_TESTS to OFF 
$ cmake .. -DBUILD_TESTS=ON    // -D to tell the cmake that I am giving option 
$make
$ls 
CMakeCache.txt CMakeFiles cmake_install.cmake CPPTutorial Makefile test
$cd test
$ls
CMakeFiles cmake_install.cmake CPPTutorial-test Makefile
$./CPPTutorial-test
	The test binary is working
$cd ../../


////////////////// now commit and push changes in the git repository   /////////
$ rm -r -f build // delete the build directory because you don't put the build at the server
$git status   //basically baddi zid kel shi t8ayyar w bdal 3al shayek bl status ta shuf everything is commited
$git rm test/dummy_test.cpp
$git status 
$git commit -a -m "adding cmake build system"       // -a commit every single new change -m is the message to add
$git add CMakeLists.txt   
$git add test 
$git status 
$git commit -m "adding cmake build system"
$git status // everything is commited
$git push // push every changes to the github repesitory
$git status // branches is up to date


