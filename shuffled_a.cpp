/*PROBLEM STATEMENT:
Given an image, divide it into 9 parts, shuffle it and again put them back together,
taking help from the original image. 
*/
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <cstdio>

using namespace std;
using namespace cv;

Mat result;
Mat img=imread("ImagesVideos/ps.jpg",1);
Mat shuffled(img.rows,img.cols,CV_8UC3,Scalar(0,0,0));
Mat assembled(img.rows,img.cols,CV_8UC3,Scalar(0,0,0));
Mat templ(img.rows/3,img.cols/3,CV_8UC3,Scalar(0,0,0));
int t_rows,t_cols,br,bc;
int a[9]={0,1,2,3,4,5,6,7,8};

void MatchingMethod( int, void* )
{
  Mat img_display;
  img.copyTo( img_display );

  int result_cols =  img.cols - templ.cols + 1;
  int result_rows = img.rows - templ.rows + 1;

  result.create( result_rows, result_cols, CV_32FC1 );

  matchTemplate( img, templ, result, CV_TM_CCOEFF_NORMED );
  normalize( result, result, 0, 1, NORM_MINMAX, -1, Mat() );

  double minVal; double maxVal; Point minLoc; Point maxLoc;
  Point matchLoc;

  minMaxLoc( result, &minVal, &maxVal, &minLoc, &maxLoc, Mat() );

  matchLoc=maxLoc;

  for(int i=0;i<templ.rows;i++)
  {
  	for(int j=0;j<templ.cols;j++)
  	{
  		assembled.at<Vec3b>(i+matchLoc.y,j+matchLoc.x)=templ.at<Vec3b>(i,j);
  	}
  }

  return;
}

void assemble()
{
	int pr,pc;
	for(int k=0;k<9;k++)
	{
		br=k/3;bc=k%3;
		for(int i=t_rows*br,i2=0;i<t_rows*(br+1);i++,i2++)
		{
			for(int j=t_cols*bc,j2=0;j<t_cols*(bc+1);j++,j2++)
			{
				templ.at<Vec3b>(i2,j2)=shuffled.at<Vec3b>(i,j);
			}
		}
		MatchingMethod(0,0);
	}
}

void gen_random()
{
	int idx,t;
	for(int i=0;i<9;i++)
	{
		idx=rand()%9;
		t=a[i];a[i]=a[idx];a[idx]=t;
	}
}

int main()
{
	gen_random();
	t_rows=img.rows/3;
	t_cols=img.cols/3;

    int pr,pc;
    for(int k=0;k<9;k++)
    {
    	pr=a[k]/3;pc=a[k]%3;
    	br=k/3;bc=k%3;
    	for(int i1=t_rows*br,i2=t_rows*pr;i2<t_rows*(pr+1);i1++,i2++)
    	{
    		for(int j1=t_cols*bc,j2=t_cols*pc;j2<t_cols*(pc+1);j1++,j2++)
    		{
    			shuffled.at<Vec3b>(i2,j2)=img.at<Vec3b>(i1,j1);
    		}
    	}
    }
    namedWindow("shuffled",WINDOW_NORMAL);
    imshow("shuffled",shuffled);
    namedWindow("original",WINDOW_NORMAL);
    imshow("original",img);

    assemble();
    namedWindow("assembled",WINDOW_NORMAL);
    imshow("assembled",assembled);


    waitKey(0);
}
