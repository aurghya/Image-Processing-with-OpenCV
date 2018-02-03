#include<iostream>
#include<algorithm>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/core/core.hpp>
using namespace std;
using namespace cv;

void erosion(Mat &img,Mat &img1)
{
	int f=0;
	for(int i=1;i<img.rows-1;i++)
	{
		for(int j=1;j<img.cols-1;j++)
		{
			f=0;
			for(int p=-1;p<=1;p++)
			{
				for(int q=-1;q<=1;q++)
				{
					if(img.at<uchar>(i+p,j+q)==0)f=1;
				}
			}
			if(f==1)
			{
				for(int p=-1;p<=1;p++)
				{
					for(int q=-1;q<=1;q++)
					{
						img1.at<uchar>(i,j)=0;
					}
				}
			}
		}
	}
}
void dilation(Mat &img,Mat &img1)
{
	int f=0;
	for(int i=1;i<img.rows-1;i++)
	{
		for(int j=1;j<img.cols-1;j++)
		{
			f=0;
			for(int p=-1;p<=1;p++)
			{
				for(int q=-1;q<=1;q++)
				{
					if(img.at<uchar>(i+p,j+q)==255)f=1;
				}
			}
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
}
int main()
{
	Mat img=imread("ImagesVideos/filter4.png",0);
	Mat img1=img.clone();
	erosion(img,img1);
	img=img1.clone();
	dilation(img1,img);
	img1=img.clone();
	dilation(img,img1);
	namedWindow("win",WINDOW_NORMAL);
	imshow("win",img1);
	waitKey(0);
}
