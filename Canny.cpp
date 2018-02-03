#include<iostream>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/core/core.hpp>
using namespace std;
using namespace cv;
int main()
{
	Mat img=imread("ImagesVideos/pic.jpg",0);
	Mat edge(img.rows,img.cols,CV_8UC1,Scalar(0));
	Canny(img,edge,100,200,3);
	namedWindow("window",WINDOW_NORMAL);
	imshow("window",edge);
	waitKey(0);
}
