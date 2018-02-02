//
#include<iostream>
#include<cmath>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/core/core.hpp>
using namespace std;
using namespace cv;

int t=0;
Mat img=imread("ImagesVideos/pic.jpg",0);
int p=img.rows/2;int q=img.cols/2;

void callback(int,void*)
{
	int d=img.rows+img.cols;
	Mat img1(d,d,CV_8UC1,Scalar(255));
	double x=t*3.14/180;
	for(int i=0;i<img.rows;i++)
	{
		for(int j=0;j<img.cols;j++)
		{
			img1.at<uchar>((i-p)*cos(x)-(j-q)*sin(x)+d/2,(i-p)*sin(x)+(j-q)*cos(x)+d/2)=img.at<uchar>(i,j);
		}
	}
	imshow("Rotate",img1);
}

int main()
{
	namedWindow("Rotate",WINDOW_NORMAL);
	createTrackbar("angle","Rotate",&t,360,callback);
	waitKey(0);
}
