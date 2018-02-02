//MORPHING TWO IMAGES
#include<iostream>
#include<cmath>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/core/core.hpp>
using namespace std;
using namespace cv;

int t=0;
Mat img1=imread("ImagesVideos/scene1.jpg",1);
Mat img2=imread("ImagesVideos/scene2.jpg",1);
Mat img3(img1.rows,img1.cols,CV_8UC3,Scalar(255,255,255));

void callback(int,void *)
{
	for(int i=0;i<img3.rows;i++)
	{
		for(int j=0;j<img3.cols;j++)
		{
			img3.at<Vec3b>(i,j)=0.01*t*img1.at<Vec3b>(i,j)+0.01*(100-t)*img2.at<Vec3b>(i,j);
		}
	}
	imshow("M",img3);
}

int main()
{
	cout<<" "<<img1.rows<<" "<<img2.rows<<" "<<img1.cols<<" "<<img2.cols;
	namedWindow("M",WINDOW_NORMAL);
	createTrackbar("trackbar","M",&t,100,callback);
	waitKey(0);
}
