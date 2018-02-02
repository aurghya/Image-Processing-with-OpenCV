//CREATE AN IMAGE CONTAINING AN ORIGINAL IMAGE AND REAL IMAGE
#include<iostream>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/core/core.hpp>
using namespace std;
using namespace cv;
int main()
{
	Mat img=imread("pic.jpg",1);
	int rows=img.rows;
	int cols=img.cols;
	Mat realmirror(rows,2*cols,CV_8UC3,Scalar(0,0,0));
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<cols;j++)
			realmirror.at<Vec3b>(i,j)=img.at<Vec3b>(i,j);
	}
	for(int i=0;i<rows;i++)
	{
		for(int j=cols;j<2*cols;j++)
		{
			realmirror.at<Vec3b>(i,j)=img.at<Vec3b>(i,2*cols-j);
		}
	}
	namedWindow("real mirror",WINDOW_NORMAL);
	imshow("real mirror",realmirror);
	imwrite("realmirror.jpg",realmirror);
	waitKey(0);
}
