#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>

using namespace cv;
using namespace std;



/*
* This cpp source file contains all the functions needed in opencv from beginner to advanced levels. 
* I choosed to write each functionality as a void function in the developement process instead of multiple cpp files to keep the 
* sequential flow of the course and also to avoid ambiguity. Each function can be used independantly by calling it from the main function.
*/

/*
* /////////////////  Contents  /////////////////////////////
1-read images, videos, webcams 
2-Basic functions 
	bgr_to_gray
	Gaussian_bluring
	Canny_edge_detector
	dilate
	erode
3-Resize and crop
4-Draw shapes and text on image
	circle
	rectangle
	line
	text
5-Wrap Perspective
6-Color detection
7-shapes detection
8-face detection


*/







void read_image()
{
	// read images
	string path = "C:\\Users\\md_al\\Desktop\\lena.jpg";
	Mat img = imread(path);
	imshow("Image", img); 
	waitKey(0);
}

void read_video()
{
	// read video
	string path = "C:\\Users\\md_al\\Desktop\\turtle.mp4";
	VideoCapture cap(path);
	Mat img;
	while (true)
	{
		cap.read(img);
		imshow("Image", img);
		waitKey(20);    //10 is very fast. 
	}

}


void read_webcam()
{
	// read webcam
	VideoCapture cap(1);  // 1 is the id of my camera
	Mat img;
	while (true)
	{
		cap.read(img);
		imshow("Image", img);
		waitKey(1);   
	}

}


// Basic functions
void bgr_to_gray()
{	//color to gray 
	string path = "C:\\Users\\md_al\\Desktop\\lena.jpg";
	Mat img = imread(path);
	Mat imgGray;
	cvtColor(img, imgGray, COLOR_BGR2GRAY);
	imshow("Original Image", img);
	imshow("Gray Image", imgGray);
	waitKey(0);
}

void Gaussianblur()
{
	//blur image
	string path = "C:\\Users\\md_al\\Desktop\\lena.jpg";
	Mat img = imread(path);
	Mat imgGray, imgBlur;
	GaussianBlur(img, imgBlur, Size(7, 7), 5, 0);  // to know what a function do, hover on it or press control and press on it's name to go to read it.

	imshow("Original Image", img);
	imshow("Blur Image", imgBlur);

	waitKey(0);
}

void Gaussian_bluring()
{
	//blur image
	string path = "C:\\Users\\md_al\\Desktop\\lena.jpg";
	Mat img = imread(path);
	Mat imgGray, imgBlur;
	GaussianBlur(img, imgBlur, Size(7, 7), 5, 0);  // to know what a function do, hover on it or press control and press on it's name to go to read it.

	imshow("Original Image", img);
	imshow("Blur Image", imgBlur);

	waitKey(0);
}

void Canny_edge_detector()
{
	// Canny edge detector
	string path = "C:\\Users\\md_al\\Desktop\\lena.jpg";
	Mat img = imread(path);
	Mat imgGray, imgBlur,imgCanny;
	GaussianBlur(img, imgBlur, Size(7, 7), 5, 0);  // to know what a function do, hover on it or press control and press on it's name to go to read it.
	Canny(imgBlur, imgCanny, 50, 150);

	imshow("Original Image", img);
	//imshow("Blur Image", imgBlur);
	imshow("Canny edge detector Image", imgCanny);
	waitKey(0);
}



void dilate_image()
{
	//dilate image
	string path = "C:\\Users\\md_al\\Desktop\\lena.jpg";
	Mat img = imread(path);
	Mat imgGray, imgBlur, imgCanny,imgDia;
	GaussianBlur(img, imgBlur, Size(7, 7), 5, 0);  // to know what a function do, hover on it or press control and press on it's name to go to read it.
	Canny(imgBlur, imgCanny, 50, 150);
	Mat kernel = getStructuringElement(MORPH_RECT, Size(5, 5));
	dilate(imgCanny, imgDia, kernel);
	imshow("Original Image", img);
	//imshow("Blur Image", imgBlur);
	imshow("dilate Image", imgDia);
	waitKey(0);
}



void erode_image()
{
	//erode image
	string path = "C:\\Users\\md_al\\Desktop\\lena.jpg";
	Mat img = imread(path);
	Mat imgGray, imgBlur, imgCanny,imgDia,imgErode;
	GaussianBlur(img, imgBlur, Size(7, 7), 5, 0);  // to know what a function do, hover on it or press control and press on it's name to go to read it.
	Canny(imgBlur, imgCanny, 50, 150);
	Mat kernel = getStructuringElement(MORPH_RECT, Size(5, 5));
	dilate(imgCanny, imgDia, kernel);
	erode(imgDia, imgErode, kernel);
	imshow("Original Image", img);
	//imshow("Blur Image", imgBlur);
	imshow("dilate then erode Image", imgErode);
	waitKey(0);
}
void Resize_image()
{
	// resize images
	string path = "C:\\Users\\md_al\\Desktop\\lena.jpg";
	Mat img = imread(path);
	Mat imgResize;
	cout << img.size() << endl;   // 1200x822
	resize(img, imgResize, Size(640, 480));
	imshow("Image", img);
	imshow("Image Resized", imgResize);
	waitKey(0);
}


void Resize_byscale_image()
{
	// resize images
	string path = "C:\\Users\\md_al\\Desktop\\lena.jpg";
	Mat img = imread(path);
	Mat imgResize;
	cout << img.size() << endl;   // 1200x822
	resize(img, imgResize, Size(),0.5,0.5);
	imshow("Image", img);
	imshow("Image Resized by scale", imgResize);
	waitKey(0);
}


void crop_image()
{
	// resize images
	string path = "C:\\Users\\md_al\\Desktop\\lena.jpg";
	Mat img = imread(path);
	Mat imgCrop;
	cout << img.size() << endl;   // 1200x822
	Rect roi(100, 100, 300, 250);
	imgCrop = img(roi);
	imshow("Image", img);
	imshow("cropped image", imgCrop);
	waitKey(0);
}

void circle_draw_on_image()
{
	//blank image
	Mat img(512, 512, CV_8UC3, Scalar(255, 255, 255));

	//unfilled_circle
	//circle(img, Point(256, 256), 155, Scalar(0, 69, 255), 10);
	//filled circle
	circle(img, Point(256, 256), 155, Scalar(0, 69, 255), FILLED);

	imshow("Image", img);
	waitKey(0);
}

void rectangle_draw_on_image()
{
	//blank image
	Mat img(512, 512, CV_8UC3, Scalar(255, 255, 255));

	//unfilled rectangle
//	rectangle(img, Point(130, 226), Point(382, 286), Scalar(0, 69, 255), 3);
	//filled rectangle
	rectangle(img, Point(130, 226), Point(382, 286),Scalar(0,69,255),FILLED);


	imshow("Image", img);
	waitKey(0);
}

void line_draw_on_image()
{
	//blank image
	Mat img(512, 512, CV_8UC3, Scalar(255, 255, 255));

	line(img, Point(130, 226), Point(382, 286), Scalar(0, 69, 255), 4);


	imshow("Image", img);
	waitKey(0);
}



void text_on_image()
{
	//blank image
	Mat img(512, 512, CV_8UC3, Scalar(255, 255, 255));

	putText(img, "Mohamad's workshop", Point(20, 286),FONT_HERSHEY_DUPLEX,2, Scalar(0, 69, 255), 1);


	imshow("Image", img);
	waitKey(0);
}



void wrap_image_perspective()
{
	// this function will wrap perspective to a card on talbe to be
	// like we are looking from the top, instead of angled position.
	// this is used in scan documents for example


	//card image
	string path = "C:\\Users\\md_al\\Desktop\\card.jpg";
	Mat img = imread(path);
	imshow("Image", img);
	// open the image in Nxview or paint to detect the 4 corners pixels of the card.
	Point2f src[4] = { {152,107},{340,37},{293,345},{503,269} };
	//now open the image with paint and draw find points of rectange from top view
	// and get the size of the image 
	float w = 250, h = 350;
	Point2f dst[4] = { {0.0f,0.0f},{w,0.0f},{0.0f,h},{w,h} };
	
	Mat matrix, imgWarp;
	matrix = getPerspectiveTransform(src, dst);
	std::cout << matrix;
	warpPerspective(img, imgWarp, matrix, Point(w, h));

	//(optional) create circle around the points that we selected 
	for (int i = 0; i < 4; i++)
	{
		circle(img, src[i], 10, Scalar(0, 0, 255), FILLED);
	}

	imshow("Image", img);
	imshow("Image wraped", imgWarp);
	waitKey(0);
}


void color_detection()
{
	// to detect a specific color in a image
	// in this example, I am detecting the white color in the image
	//lena image
	string path = "C:\\Users\\md_al\\Desktop\\card.jpg";
	Mat img = imread(path);
	Mat imgHSV, mask;
	int hmin = 0, smin = 0, vmin = 200;
	int hmax = 50, smax = 50, vmax = 255;

	namedWindow("Track bars", (640, 200));  // using track bar, you can find the perfect values to detect the specific color in the image
	createTrackbar("Hue Min", "Track bars", &hmin, 255);
	createTrackbar("Hue Max", "Track bars", &hmax, 255);
	createTrackbar("sat Min", "Track bars", &smin, 255);
	createTrackbar("sat Max", "Track bars", &smax, 255);
	createTrackbar("val Min", "Track bars", &vmin, 255);
	createTrackbar("val Max", "Track bars", &vmax, 255);
	while(true) {
	cvtColor(img, imgHSV, COLOR_BGR2HSV);
	Scalar lower(hmin, smin, vmin);
	Scalar upper(hmax, smax, vmax);
	inRange(imgHSV, lower, upper, mask);
	imshow("Image", img);
	imshow("Image HSV ", imgHSV);
	imshow("Image Mask ", mask);
	waitKey(1);
	}
}


// helper function to shapes_detection function
void getContours(Mat imgDia, Mat img)
{
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;
	findContours(imgDia,contours,hierarchy,RETR_EXTERNAL,CHAIN_APPROX_SIMPLE);
	//drawContours(img, contours, -1, Scalar(255, 0, 255), 2);  // draw all the contours detected -1


	vector<vector<Point>> conPoly(contours.size());//conPoly is a vector that have different values
	vector<Rect>boundRect(contours.size());
	string objectType;
	// filter the noise detected
	for (int i = 0; i < contours.size(); i++)
	{
		int area = contourArea(contours[i]);
		cout << area << endl;  
		if (area > 1000)
		{
			float peri = arcLength(contours[i], true);// finding the bounding box arround these objects or shapes.
			approxPolyDP(contours[i], conPoly[i],0.02*peri,true);  // conPoly is the output.
			//drawContours(img, contours, i, Scalar(255, 0, 255), 2);    // Here I draw the contours. (by points not lines)
			drawContours(img, conPoly, i, Scalar(255, 0, 255), 2);  // here I draw  polygone, no difference from the contours drawing because I don't have circle shape for example in here.
			cout << conPoly[i].size() << endl;// if we check the length on of conPoly, it will give us approximation of the kind of the shape
			boundRect[i] = boundingRect(conPoly[i]);// finding the bounding rectangle arround it.
			rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 69, 255), 3);   // ploting the rectangles arround the shapes
			int objCor = (int)conPoly[i].size();// which object is which
			if (objCor == 3) { objectType = "Triangle"; }
			else if (objCor == 4) {
				float aspRatio = (float)boundRect[i].width / (float)boundRect[i].height;
				if (aspRatio > 0.95 && aspRatio < 1.05) { objectType = "Square"; }
				else { objectType = "Rectangle"; }
				
			}
			else if (objCor == 5) { objectType = "pentagon"; }
			else if (objCor == 6) { objectType = "hexagon "; }
			else if (objCor == 7) { objectType = "heptagon"; }
			else if (objCor == 8) { objectType = "octagon "; }
			else { objectType = "circle "; }
			putText(img, objectType, { boundRect[i].x,boundRect[i].y -5}, FONT_HERSHEY_DUPLEX, 0.75, Scalar(0, 69, 255), 1);

		}	
	}

}



void shapes_detection()
{
	// to detect shapes in a image
	//shapes image
	string path = "C:\\Users\\md_al\\Desktop\\shapes.png";
	Mat img = imread(path);
	Mat imgGray, imgBlur, imgCanny, imgDia;
	GaussianBlur(img, imgBlur, Size(3, 3), 3, 0); 
	Canny(imgBlur, imgCanny, 25, 75);
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	dilate(imgCanny, imgDia, kernel);

	getContours(imgDia,img);


	imshow("Original Image", img);
	//imshow("Blur Image", imgBlur);
	imshow("dilate Image", imgDia);
	waitKey(0);

}

void detect_faces()
{
	// you need #include <opencv2/objdetect.hpp>
	// use pretrained .xml classifiers, I already have them. If you don't have them, download them
	string path = "C:\\Users\\md_al\\Desktop\\lena.jpg";
	Mat img = imread(path);
	CascadeClassifier faceCascade;
	faceCascade.load("C:\\Users\\md_al\\Desktop\\haarcascade_frontalface_default.xml");
	if (faceCascade.empty()) { cout << "XML file not loaded " << endl; };
	vector<Rect> faces;
	faceCascade.detectMultiScale(img, faces, 1.1, 10);
	for (int i = 0; i < faces.size(); i++)
	{
		rectangle(img, faces[i].tl(), faces[i].br(), Scalar(0, 69, 255), 3);
	}
	imshow("Image", img);
	waitKey(0);
}




int main()
{

	////////////// read images, videos, webcams ////////////
	//read_image();
	//read_video();
	//read_webcam();
	// 
	// 
	////////////// Basic functions /////////////////////////
	//bgr_to_gray();
	//Gaussian_bluring();
	//Canny_edge_detector();
	//dilate_image();
	//erode_image();
	// 
	// 
	////////////// Resize and crop ////////////////////////
	//Resize_image();
	//Resize_byscale_image();
	//crop_image();
	// 
	// 
	//////////////  Draw shapes and text on image //////////////
	//circle_draw_on_image();
	//rectangle_draw_on_image();
	//line_draw_on_image();
	//text_on_image();

	/////////////   Wrap Perspective     //////////////////
	//wrap_image_perspective();


	/// ////////   Color detection    /////////////////////
	//color_detection();

	/// ////////   shapes/contours detection    /////////////////////
	//shapes_detection();
	////////////   Face detection ////////////////////////
	//detect_faces();



	return 0;
}