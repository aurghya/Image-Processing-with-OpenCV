//CREATE A REFLECTED IMAGE OF A GIVEN IMAGE
#include<iostream>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/core/core.hpp>
using namespace std;
using namespace cv;
int main()
{
	Mat img=imread("pic.jpg",1);
	int rows=img.rows;
	int cols=img.cols;
	Mat reflection(rows,cols,CV_8UC3,Scalar(0,0,0));
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<cols;j++)
		{
			reflection.at<Vec3b>(i,j)=img.at<Vec3b>(rows-i-1,j);
		}
	}
	namedWindow("reflection",WINDOW_NORMAL);
	imshow("reflection",reflection);
	imwrite("reflection.jpg",reflection);
	waitKey(0);
}
