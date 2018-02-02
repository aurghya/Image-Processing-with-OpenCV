//GIVE VIGNETTE EFFECT TO AN IMAGE
#include<iostream>
#include<cmath>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/core/core.hpp>
using namespace std;
using namespace cv;

int main()
{
	Mat img=imread("ImagesVideos/veg2.jpg",1);
	Mat img1(img.rows,img.cols,CV_8UC3,Scalar(0,0,0));
	int p=img.rows/2;int q=img.cols/2;
	for(int i=0;i<img.rows;i++)
	{
		for(int j=0;j<img.cols;j++)
		{
			double d=(i-p)*(i-p)+(j-q)*(j-q);
			double e=(p*p+q*q)/4;
			img1.at<Vec3b>(i,j)=img.at<Vec3b>(i,j)/(1+d/e);
		}
	}
	namedWindow("Vignette",WINDOW_NORMAL);
	imshow("Vignette",img1);
	waitKey(0);
}
