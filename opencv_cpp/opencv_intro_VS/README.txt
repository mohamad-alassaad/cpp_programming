/////////////////////////////////////        ADD opencv to visual studio                  /////////////////////////////////////////////////
Credits: https://subwaymatch.medium.com/opencv-410-with-vs-2019-3d0bc0c81d96


1-downlaod visual studio with c++ developement kit 
2-Download and extract the pre-built library  (Download the latest binary from opencv’s Github repository. The latest version as of October 17, 2019 is 4.1.2 (opencv-4.1.2-vc14_vc15.exe))
3-Step 2: Add to path (edit system environment virables -> Add opencv’s bin directory to path. (ex: C:\Users\md_al\Desktop\opencv\build\x64\vc15\bin)
4-open new VS project
	create empty c++ project
	Set platform target to x64  (Pre-built binaries are built for x64 Windows platforms.)
	Add to Include Directories (Tell the compiler how the OpenCV library looks. This is done by providing a path to the header files (build/include) (ex:C:\Users\md_al\Desktop\opencv\build\include)
	Add to Library Directories — Tell the linker where it can find the lib files for different modules. (ex:C:\Users\md_al\Desktop\opencv\build\x64\vc15\lib)
	Add Additional Dependencies — List .lib files for different modules. Note that we’re only going to list a single all-in-one file named opencv_world.  (ex: opencv_world455d.lib;)
 	
5-Step 4: Check out demo code!
	#include <opencv2/core/core.hpp>
	#include <opencv2/highgui/highgui.hpp>
	#include <opencv2/imgproc.hpp>
	#include <iostream>

	using namespace cv;
	using namespace std;

	int main()
	{
		Mat image = Mat::zeros(300, 600, CV_8UC3);
		circle(image, Point(250, 150), 100, Scalar(0, 255, 128), -100);
		circle(image, Point(350, 150), 100, Scalar(255, 255, 255), -100);
		imshow("Display Window", image);
		waitKey(0);
		return 0;
	}