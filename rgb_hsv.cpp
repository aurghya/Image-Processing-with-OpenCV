#include<iostream>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/core/core.hpp>
using namespace std;
using namespace cv;

int main()
{
	Mat img=imread("pic.jpg",1);
	Mat img2;
	cvtColor(img,img2,CV_BGR2HSV);
	namedWindow("HSV",WINDOW_NORMAL);
	imshow("HSV",img2);
	waitKey(0);
}
