//CREATE AN IMAGE WHOSE ONE HALF ABOVE THE DIAGONAL IS OF ONE COLOR AND THE OTHER HALF IS OF ANOTHER COLOR
#include<iostream>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/core/core.hpp>
using namespace std;
using namespace cv;
int main()
{
	Mat diag(100,100,CV_8UC3,Scalar(0,0,0));
	for(int i=0;i<100;i++)
	{
		for(int j=0;j<100;j++)
		{
			if(i>j)diag.at<Vec3b>(i,j)[1]=255;
			else diag.at<Vec3b>(i,j)[2]=255;
		}
	}
	namedWindow("w",WINDOW_NORMAL);
	imshow("w",diag);
	waitKey(0);
}
