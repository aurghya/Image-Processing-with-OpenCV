//CREATE AN YELLOW  IMAGE SCREEN
#include "iostream"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
using namespace std;
using namespace cv;
int main()
{
	Mat img(50,50,CV_8UC3,Scalar(0,255,255));   //creates a img class with 50*50 CV_8UC3 (for rgb image)
	namedWindow("yellow",WINDOW_AUTOSIZE);    //creating a window and make it autosize. It can also be NORMAL which allows resizing.
	imshow("yellow",img);
	waitKey(0);
}