//READ A VIDEO AND DISPLAY ITS FRAMES
#include<iostream>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/core/core.hpp>
using namespace std;
using namespace cv;
int main()
{
	VideoCapture vid("ImagesVideos/video.mp4");
	Mat img,edge;
	namedWindow("window",WINDOW_NORMAL);
	while(1)
	{
		vid>>img;
		imshow("window",img);
		waitKey(25);
	}
	waitKey(0);
}