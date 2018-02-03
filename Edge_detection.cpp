#include<iostream>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/core/core.hpp>
using namespace std;
using namespace cv;

int u=0,l=0;
Mat img=imread("rubik.jpg",0);
Mat edge(img.rows,img.cols,CV_8UC1,Scalar(0));

void callback(int,void*)
{
	Canny(img,edge,l,u,3);
	for(int i=0;i<edge.rows;i++)
	{
		for(int j=0;j<edge.cols;j++)
		{
			edge.at<uchar>(i,j)=255-edge.at<uchar>(i,j);
		}
	}
	imshow("window",edge);
}

int main()
{
	namedWindow("window",WINDOW_NORMAL);
	createTrackbar("upper","window",&u,255,callback);
	createTrackbar("lower","window",&l,255,callback);
	waitKey(0);
}
