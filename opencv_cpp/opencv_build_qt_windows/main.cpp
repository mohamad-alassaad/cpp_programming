#include <iostream>
#include "test.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

int main()
{
    std::cout <<"Hello OpenCV !" << std::endl;

    // read an image
    Mat image = imread("C:\\Users\\md_al\\Desktop\\lena.jpg");
    // create image window named "My Image"
    //cv::namedWindow("My Image");
    // show the image on window
    cv::imshow("My Image", image);
    waitKey();
    return 0;
}
