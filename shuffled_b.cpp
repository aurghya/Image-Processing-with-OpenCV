/*PROBLEM STATEMENT:
Given a 3 by 3 shuffled image with the top left  corner in the correct place.
Rearrange them to get the original image.
*/
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <cstdio>
#include<cmath>

using namespace std;
using namespace cv;

Mat img=imread("ImagesVideos/ps.jpg",1);
Mat shuffled(img.rows,img.cols,CV_8UC3,Scalar(0,0,0));
Mat assembled(img.rows,img.cols,CV_8UC3,Scalar(0,0,0));
Mat templ(img.rows/3,img.cols/3,CV_8UC3,Scalar(0,0,0));
Mat temp[8];int placed[8]={-1,-1,-1,-1,-1,-1,-1,-1},matchtemp;double matchval,curr;
int t_rows,t_cols,br,bc;
int a[9]={0,1,2,3,4,5,6,7,8};

void matchtop(int k)
{
	matchval=1e10;
	int pr=k/3,pc=k%3;
	for(int m=1;m<9;m++)
	{
		if(placed[m-1]==-1)
		{
			curr=0;
			for(int j1=pc*t_cols,j2=0;j1<(pc+1)*t_cols;j1++,j2++)
			{
				int a=temp[m-1].at<Vec3b>(0,j2)[0]+temp[m-1].at<Vec3b>(0,j2)[1]+temp[m-1].at<Vec3b>(0,j2)[2];
				int b=assembled.at<Vec3b>(pr*t_rows-1,j1)[0]+assembled.at<Vec3b>(pr*t_rows-1,j1)[1]+assembled.at<Vec3b>(pr*t_rows-1,j1)[2];
				curr+=abs(a-b);
			}
			if(curr<matchval)
			{
				matchval=curr;
				matchtemp=m;
			}

		}
	}
	int m=matchtemp;
	for(int i1=pr*t_rows,i2=0;i1<t_rows*(pr+1);i1++,i2++)
	{
		for(int j1=pc*t_cols,j2=0;j1<(pc+1)*t_cols;j1++,j2++)
		{
			assembled.at<Vec3b>(i1,j1)=temp[m-1].at<Vec3b>(i2,j2);
		}
	}
	placed[m-1]=1;
}

void matchleft(int k)
{
	matchval=1e10;
	int pr=k/3,pc=k%3;
	for(int m=1;m<9;m++)
	{
		if(placed[m-1]==-1)
		{
			curr=0;
			for(int i1=pr*t_rows,i2=0;i1<t_rows*(pr+1);i1++,i2++)
			{
				int a=temp[m-1].at<Vec3b>(i2,0)[0]+temp[m-1].at<Vec3b>(i2,0)[1]+temp[m-1].at<Vec3b>(i2,0)[2];
				int b=assembled.at<Vec3b>(i1,pc*t_cols-1)[0]+assembled.at<Vec3b>(i1,pc*t_cols-1)[1]+assembled.at<Vec3b>(i1,pc*t_cols-1)[2];
				curr+=abs(a-b);
			}
			if(curr<matchval)
			{
				matchval=curr;
				matchtemp=m;
			}
		}
	}
	int m=matchtemp;
	for(int i1=pr*t_rows,i2=0;i1<t_rows*(pr+1);i1++,i2++)
	{
		for(int j1=pc*t_cols,j2=0;j1<(pc+1)*t_cols;j1++,j2++)
		{
			assembled.at<Vec3b>(i1,j1)=temp[m-1].at<Vec3b>(i2,j2);
		}
	}
	placed[m-1]=1;
}


void assemble()
{

	for(int i=0;i<t_rows;i++)
	{
		for(int j=0;j<t_cols;j++)
		{
			assembled.at<Vec3b>(i,j)=shuffled.at<Vec3b>(i,j);
		}
	}

	for(int k=1;k<9;k++)
	{
		br=k/3;bc=k%3;
		temp[k-1].create(t_rows,t_cols,CV_8UC3);
		for(int i=br*t_rows,i2=0;i<(br+1)*t_rows;i++,i2++)
		{
			for(int j=bc*t_cols,j2=0;j<(bc+1)*t_cols;j2++,j++)
			{
				temp[k-1].at<Vec3b>(i2,j2)=shuffled.at<Vec3b>(i,j);
			}
		}
	}
	for(int k=1;k<9;k++)
	{
		if(k%3==0)matchtop(k);
		else matchleft(k);
	}
}

void gen_random()
{
	int idx,t;
	for(int i=1;i<9;i++)
	{
		idx=rand()%9;
		if(idx==0)continue;
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
