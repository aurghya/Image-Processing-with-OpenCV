#include<iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

int main(int argc, char **argv){
    Mat img;
    img = imread("ImagesVideos/veg1.jpg", CV_LOAD_IMAGE_COLOR);
    int kernel_size = 3;
    float sumb, sumg, sumr;
    int i, j, x, y;
    float kernel[3][3]={{1.0/16.0, 1.0/8.0, 1.0/16.0},
                      {1.0/8.0, 1.0/4.0, 1.0/8.0},
                      {1.0/16.0, 1.0/8.0, 1.0/16.0}};

    for(i = 1; i < img.rows-1; i++){
        for(j = 1; j < img.cols-1; j++){
            sumb = sumg = sumr = 0.0;
            for(x = -1; x < kernel_size-1; x++){
                for(y = -1; y < kernel_size-1; y++){
                    sumb += (int)(img.at<Vec3b>(i + x, j + y)[0] * kernel[1+x][y+1]);
                    sumg += (int)(img.at<Vec3b>(i + x, j + y)[1] * kernel[1+x][1+y]);
                    sumr += (int)(img.at<Vec3b>(i + x, j + y)[2] * kernel[1+x][1+y]);
                }
            }
            img.at<Vec3b>(i, j)[0] = sumb;
            img.at<Vec3b>(i, j)[1] = sumg;
            img.at<Vec3b>(i, j)[2] = sumr;
        }
    }

    namedWindow("Filter", WINDOW_NORMAL);
    imshow("Filter", img);
    waitKey(0);
}
