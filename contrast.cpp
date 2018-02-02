//CHANGE THE CONTRAST OF AN IMAGE
#include<iostream>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/core/core.hpp>
using namespace std;
using namespace cv;
int min(int a,int b)
{
	return (a<b)?a:b;
}
int main()
{
	Mat img=imread("ImagesVideos/pic.jpg",0);
	Mat image(img.rows,img.cols,CV_8UC1,Scalar(0));
	for(int i=0;i<img.rows;i++)
	{
		for(int j=0;j<img.cols;j++)
		{
			image.at<uchar>(i,j)=min(1.5*img.at<uchar>(i,j),255);
		}
	}
	namedWindow("window",WINDOW_NORMAL);
	imshow("window",image);
	waitKey(0);
}
