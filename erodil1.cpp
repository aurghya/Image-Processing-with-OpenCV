#include<iostream>
#include<algorithm>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/core/core.hpp>
using namespace std;
using namespace cv;

int main()
{
	int f=0;
	Mat img=imread("ImagesVideos/filter2.png",0);
	Mat img1=imread("ImagesVideos/filter2.png",0);
	for(int i=1;i<img.rows-1;i++)
	{
		for(int j=1;j<img.cols-1;j++)
		{
			f=0;
			if(img.at<uchar>(i-1,j-1)==255)f=1;
			if(img.at<uchar>(i-1,j)==255)f=1;
			if(img.at<uchar>(i-1,j+1)==255)f=1;
			if(img.at<uchar>(i,j-1)==255)f=1;
			if(img.at<uchar>(i,j)==255)f=1;
			if(img.at<uchar>(i,j+1)==255)f=1;
			if(img.at<uchar>(i+1,j-1)==255)f=1;
			if(img.at<uchar>(i+1,j)==255)f=1;
			if(img.at<uchar>(i+1,j+1)==255)f=1;
			if(f==1)
			{
				for(int p=-1;p<=1;p++)
				{
					for(int q=-1;q<=1;q++)
					{
						img1.at<uchar>(i,j)=255;
					}
				}
			}
		}
	}
	namedWindow("win",WINDOW_NORMAL);
	imshow("win",img1);
	waitKey(0);
}
