#include<iostream>
#include<cmath>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/core/core.hpp>
using namespace std;
using namespace cv;

int t=0;
Mat img=imread("ImagesVideos/rubik.jpg",0);
Mat img1(img.rows,img.cols,CV_8UC1,Scalar(255));

void callback(int,void*)
{
	int val1,val2;
	int g1[3][3]={{-1,0,1},
                 {-1,0,1},
                 {-1,0,1}};
    int g2[3][3]={{-1,-1,-1},
                 {0,0,0},
                 {1,1,1}};
	for(int i=0;i<img.rows;i++)
	{
		for(int j=0;j<img.cols;j++)
		{
			val1=0;val2=0;
			for(int k=-1;k<2;k++)
			{
				for(int p=-1;p<2;p++){
					val1=val1+g1[k+1][p+1]*(img.at<uchar>(i+k,j+p));
					val2=val2+g2[k+1][p+1]*(img.at<uchar>(i+k,j+p));
				}
		    }
		    if((abs(val1)+abs(val2))>t)img1.at<uchar>(i,j)=0;
		    else img1.at<uchar>(i,j)=255;
		}
	}
	imshow("Edge",img1);
}

int main()
{
	namedWindow("Edge",WINDOW_NORMAL);
	createTrackbar("track","Edge",&t,255,callback);
	waitKey(0);
}
