#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;

Mat img; Mat templ; Mat result;

void MatchingMethod( int, void* )
{
  Mat img_display;
  img.copyTo( img_display );

  int result_cols =  img.cols - templ.cols + 1;
  int result_rows = img.rows - templ.rows + 1;

  result.create( result_rows, result_cols, CV_32FC1 );

  matchTemplate( img, templ, result, CV_TM_CCOEFF );
  normalize( result, result, 0, 1, NORM_MINMAX, -1, Mat() );

  double minVal; double maxVal; Point minLoc; Point maxLoc;
  Point matchLoc;

  minMaxLoc( result, &minVal, &maxVal, &minLoc, &maxLoc, Mat() );

  matchLoc=maxLoc;

  rectangle( img_display, matchLoc, Point( matchLoc.x + templ.cols , matchLoc.y + templ.rows ), Scalar::all(0), 2, 8, 0 );
  rectangle( result, matchLoc, Point( matchLoc.x + templ.cols , matchLoc.y + templ.rows ), Scalar::all(0), 2, 8, 0 );

  imshow( "image window", img_display );
  imshow( "result window", result );

  return;
}

int main( int argc, char** argv )
{
  img = imread( "ImagesVideos/coins.jpg", 1 );
  templ = imread( "ImagesVideos/coin.jpg", 1 );

  namedWindow( "image window", CV_WINDOW_AUTOSIZE );
  namedWindow( "result window", CV_WINDOW_AUTOSIZE );

  MatchingMethod( 0, 0 );

  waitKey(0);
  return 0;
}
