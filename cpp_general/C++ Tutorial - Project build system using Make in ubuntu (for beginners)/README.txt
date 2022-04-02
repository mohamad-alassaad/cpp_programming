
/////////////// C++ Tutorial - Project build system using Make in ubuntu (for beginners) ////////////////////////////////////


in order to understand our makefile, we need to see how we would actually build our code without using any type
of build tools (cmake or make or anything related to build)
so we want to us compiler in our programming language, 
in this case, since it is c++, we are going to use the g++ compiler (if it would been in the c code, we would use the gcc compiler)


$g++ --version
$g++ src/main.cpp -Iinclude/ -o CPPTutorial
$ls 
	CMakeLists.txt  CPPTutorial  README.txt  include  src  test
$./CPPTutorial 
	Hello World !
//same thing can be done for the test file 
$g++ test/main.cpp -o CPPTutorial-test // we don't have include files here 
$ls
	CMakeLists.txt  CPPTutorial  CPPTutorial-test  README.txt  include  src  test
$./CPPTutorial-test
	The test binary is working!

// That's how cpp is built, we need compiler (g++ or gcc:  they are not the only compilers) to compile and create the executables for us
// now, instead, we will create make file, that will do what we want to do (create the exectuables we need)

$rm CPPTutorial CPPTutorial-test

// the same as the case we did with cmake, where we create the CMakeLists.txt, 
//for make we need to create a make file. (doesnt have any extention)
$touch Makefile
$ls 
// we need to edit the Makefile in order to add the rules so make knows how to create our project
$vim Makefile 

CXX := g++    // set the compiler variable name
SRC := $(wildcard src/*.cpp)    // set the list of cpp source codes names path
TESTS := $(wildcard test/*.cpp)  // set the list of cpp source codes names path 
INCL_DIR := include/             // set the include directory

TARGET_NAME := CPPTutorial        // set the executable target name
TARGET_NAME_TESTS := CPPTutorial-test   // set the other executable target name

$(TARGET_NAME):
	$(CXX) -I$(INCL_DIR) $(SRC) -o CPPTutorial    // this looks the same as the command we used using only the compiler
$(TARGET_NAME_TESTS):
	$(CXX) $(TESTS) -o CPPTutorial-test           // this will create the executable with the name TARGET_NAME_TESTS

:wq

$ make CPPTutorial
	g++ -Iinclude/ src/main.cpp -o CPPTutorial

$ make CPPTutorial-test
	g++ test/main.cpp -o CPPTutorial-test    //shakli medtar 7added l target name 
$ls 
	CMakeLists.txt  CPPTutorial  CPPTutorial-test  Makefile  README.txt  include  src  test
$./CPPTutorial 
	Hello World !
$ ./CPPTutorial-test
	 The test binary is working!


// Now we need to make some changes in the Makefile 
$vim Makefile 
CXX := g++
SRC := $(wildcard src/*.cpp)
TESTS := $(wildcard test/*.cpp)
INCL_DIR := include/

TARGET_NAME := CPPTutorial
TARGET_NAME_TESTS := CPPTutorial-test

$(TARGET_NAME):
	mkdir build 							  // create build directory to save executables in it
	@$(CXX) -I$(INCL_DIR) $(SRC) -o build/CPPTutorial      // added the @, this will not print to the user what I am doing in the background
$(TARGET_NAME_TESTS):
	mkdir build/test
	@$(CXX) $(TESTS) -o build/test/CPPTutorial-test

clean:                                                      // if I do later $make clean, it will delete the build directory
	rm -r -f build && rm -r -f build/test 




// another note, that if we do only $make without specifying the target, it will create the first target file only.
// add @ also ma7al ma baddak to hide the results ex: @mkdir build


and finally 
CXX := g++
SRC := $(wildcard src/*.cpp)
TESTS := $(wildcard test/*.cpp)
INCL_DIR := include/

TARGET_NAME := CPPTutorial
TARGET_NAME_TESTS := CPPTutorial-test

$(TARGET_NAME):
	@mkdir build 
	@$(CXX) -I$(INCL_DIR) $(SRC) -o build/CPPTutorial
$(TARGET_NAME_TESTS):
	@mkdir build/test
	@$(CXX) $(TESTS) -o build/test/CPPTutorial-test

clean:
	@rm -r -f build && rm -r -f build/test




//////////////////////////////// Commit your changes to github /////////////////////////////////////////



         