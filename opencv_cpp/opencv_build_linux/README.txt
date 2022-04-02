OpenCV (Open Source Computer Vision Library) is an open-source computer vision library and has bindings for C++, Python, and Java. It is used for a very wide range of applications, including medical image analysis, stitching street view images, surveillance video, detecting and recognizing faces, tracking moving objects, extracting 3D models, and much more. OpenCV can take advantage of multi-core processing and features GPU acceleration for real-time operation.

This tutorial explains how to install OpenCV on Ubuntu 18.04.
For most people, the easiest way to install OpenCV on Ubuntu is to install it using the apt package management tool. If you want to install the latest stable version of OpenCV from source, scroll down to the Installing OpenCV from the Source section of this tutorial.
Choose one of the installation options that works best for you.

Install OpenCV from the Ubuntu Repository
The OpenCV package is available from the Ubuntu 18.04 distribution repository. At the time of writing, the version in the repositories is 3.2, which is not the latest version.
To install OpenCV from the Ubuntu 18.04 repositories, follow these steps:
1-Refresh the packages index and install the OpenCV package by typing:
$sudo apt update
$sudo apt install python3-opencv

The command above will install all packages necessary to run OpenCV.

2-To verify the installation, import the cv2 module and print the OpenCV version:
$python3 -c "import cv2; print(cv2.__version__)"
							3.2.0

The default Python version in Ubuntu 18.04 LTS is version 3.6. If you want to install OpenCV with python 2 bindings install the python-opencv package



Installing OpenCV from the Source
Building the OpenCV library from source is the recommended way of installing OpenCV. 
It will be optimized for your particular system and you will have complete control over the build options.
To install the latest OpenCV version from the source, perform the following steps:
1-Install the required dependencies:
$sudo apt install build-essential cmake git pkg-config libgtk-3-dev \
    libavcodec-dev libavformat-dev libswscale-dev libv4l-dev \
    libxvidcore-dev libx264-dev libjpeg-dev libpng-dev libtiff-dev \
    gfortran openexr libatlas-base-dev python3-dev python3-numpy \
    libtbb2 libtbb-dev libdc1394-22-dev

2-Clone the OpenCV’s and OpenCV contrib repositories:
$mkdir ~/opencv_build && cd ~/opencv_build                      // ~ (tilde) means the home directory of the logged on user. ex: /home/username/.somedirectory is the same as ~/.somedirectory  (check by cd ~ and then ls or pwd )
$git clone https://github.com/opencv/opencv.git
$git clone https://github.com/opencv/opencv_contrib.git

At the time of writing, the default version in the github repositories is version 4.2.0. If you want to install an older version of OpenCV,
cd to both opencv and opencv_contrib directories and run git checkout <opencv-version>

3-Once the download is complete, create a temporary build directory, and switch to it:
$cd ~/opencv_build/opencv
$mkdir build && cd build

Set up the OpenCV build with CMake:

$cmake -D CMAKE_BUILD_TYPE=RELEASE \
-D CMAKE_INSTALL_PREFIX=/usr/local \
-D INSTALL_C_EXAMPLES=ON \
-D INSTALL_PYTHON_EXAMPLES=ON \
-D OPENCV_GENERATE_PKGCONFIG=ON \
-D OPENCV_EXTRA_MODULES_PATH=~/opencv_build/opencv_contrib/modules \
-D BUILD_EXAMPLES=ON ..

When the CMake build system is finalized, you will see something like below:


4-Start the compilation process:
$make -j8
Modify the -j flag according to your processor. 
If you do not know the number of cores in your processor, you can find it by typing nproc ($nproc) me I have 8.
The compilation may take several minutes or more, depending on your system configuration. 
Once it is completed you will see something like below:

5-Install OpenCV with:
$sudo make install



note:
{ why "make" before "make install" ?
When you run make, you're instructing it to essentially follow a set of build steps for a particular target. 
When make is called with no parameters, it runs the first target, which usually simply compiles the project. 
make install maps to the install target, which usually does nothing more than copy binaries into their destinations.
Frequently, the install target depends upon the compilation target, so you can get the same results by just running make install. 
However, I can see at least one good reason to do them in separate steps: privilege separation.
Ordinarily, when you install your software, it goes into locations for which ordinary users do 
not have write access (like /usr/bin and /usr/local/bin). Often, then, you end up actually having to run make and then sudo make install, 
as the install step requires a privilege escalation. This is a "Good Thing™", because it allows your software to be compiled as a normal 
user (which actually makes a difference for some projects), limiting the scope of potential damage for a badly-behaving build procedure, and only obtains root privileges for the install step.

make without parameters takes the ./Makefile (or ./makefile) and builds the first target. 
By convention, this may be the all target, but not necessarily. make install builds the special target, install. 
By convention, this takes the results of make all, and installs them on the current computer.
Not everybody needs make install. For example, if you build some a web app to be deployed on a different server, 
or if you use a cross-compiler (e.g. you build an Android application on a Linux machine), it makes no sense to run make install.
In most cases, the single line ./configure && make all install will be equivalent to the three-step process you describe, but this depends on the product, on your specific needs, and again, this is only by a convention.


Make is a general purpose workflow program, usually used for compilation. But it can be used for anything.
When you do something like "make all", the make program executes a rule named "all" from a file in current directory named "Makefile".
This rule usually calls the compiler to compile some source code into binaries.
When you do "make install", the make program takes the binaries from the previous step and copies them into some appropriate locations so that they can be accessed. 
Unlike on Windows, installation just requires copying some libraries and executables and there is no registry requirement as such. In short, "make install" just copies compiled files into appropriate locations.
make install does nothing less then executing the install function / section in your Makefile
}



6-To verify whether OpenCV has been installed successfully, 
type the following command and you should see the OpenCV version:
$pkg-config --modversion opencv4
						4.2.0
$python3 -c "import cv2; print(cv2.__version__)"
						4.2.0-dev

Conclusion
We have shown you two different ways to install OpenCV on your Ubuntu 18.04 server. 
The method you choose depends on your requirements and preferences. Even though installing the packaged version from the Ubuntu repository is easier, 
building OpenCV from source gives you more flexibility, and it should be your first option when installing OpenCV.
If you have any questions or feedback, feel free to comment below.




to test you opencv installation 

1-downlaod lena.jpg image to the current directory 
2-create DisplayImage.cpp file 
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main( int argc, char** argv )
{
    if( argc != 2)
    {
     cout <<" Usage: " << argv[0] << " ImageToLoadAndDisplay" << endl;
     return -1;
    }
    Mat image;
    image = imread(argv[1], IMREAD_COLOR); // Read the file
    if( image.empty() ) // Check for invalid input
    {
        cout << "Could not open or find the image" << std::endl ;
        return -1;
    }
    namedWindow( "Display window", WINDOW_AUTOSIZE ); // Create a window for display.
    imshow( "Display window", image ); // Show our image inside it.
    waitKey(0); // Wait for a keystroke in the window
    return 0;
}

3-create CMakeLists.txt file 
cmake_minimum_required(VERSION 2.8)
project( DisplayImage )
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable( DisplayImage DisplayImage.cpp )
target_link_libraries( DisplayImage ${OpenCV_LIBS} )





$mkdir build 
$cd build 
$cmake ..
$make 
 
go and launch Xlaunch

$export | DISPLAY     // to check the display eza mawjudi sa7 3al :0
			Lezem tkun :0
$export | opencv    // just to check opencv eza mawjud bl path
			mafrud tle2i shi 5asso bl opencv bl mawdu3 
$./DisplayImage ../lena.jpg