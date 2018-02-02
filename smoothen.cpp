#include<iostream>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/core/core.hpp>
using namespace std;
using namespace cv;
int main()
{
	int a[9];
	Mat img=imread("ImagesVideos/veg1.jpg",0);
	Mat img1(img.rows,img.cols,CV_8UC1,Scalar(0));
	for(int i=1;i<img.rows-1;i++)
	{
		for(int j=0;j<img.cols-1;j++)
		{
			a[0]=img.at<uchar>(i-1,j-1);
			a[1]=img.at<uchar>(i-1,j);
			a[2]=img.at<uchar>(i-1,j+1);
			a[3]=img.at<uchar>(i,j-1);
			a[4]=img.at<uchar>(i,j);
			a[5]=img.at<uchar>(i,j+1);
			a[6]=img.at<uchar>(i+1,j-1);
			a[7]=img.at<uchar>(i+1,j);
			a[8]=img.at<uchar>(i+1,j+1);
			img1.at<uchar>(i,j)=(a[0]+a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8])/9;
		}
	}
	namedWindow("Window",WINDOW_NORMAL);
	imshow("Window",img1);
	waitKey(0);
}

//KERNEL
/*
for(i=0 to rows)
for(j=0 to cols)
   for(k=-1 to 1)
   for(q=-1 to 1)
      if(isValid(i+k,j+q))

*/
