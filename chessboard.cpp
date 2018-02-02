//CREATE A CHESSBOARD PATTERN
#include<iostream>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/core/core.hpp>
using namespace std;
using namespace cv;
int main()
{
	Mat chessboard(8,8,CV_8UC1,Scalar(255));
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			if((i+j)%2==0)chessboard.at<uchar>(i,j)=0;
		}
	}
	namedWindow("window",WINDOW_NORMAL);
	imshow("window",chessboard);
	waitKey(0);
}
