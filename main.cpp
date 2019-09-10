#include "mainwindow.h"
#include <QApplication>
#include <opencv2/opencv.hpp>
#include <QDebug>
#include <sys/time.h>

using namespace cv;

void printMs(char *str)
{
    static double timeStart = clock();
    if(str == nullptr)
    {
        timeStart = clock();
    }
    else
    {
        qDebug() << str <<(clock() - timeStart) << "ms";
    }
}

void RGB2GRAY(Mat &src,Mat &gray)
{
    gray.create(src.rows,src.cols,CV_8UC1);
    //转灰度图公式:Gray = (R*30 + G*59 + B*11 + 50)/100
    for(int i=0;i<src.rows;i++)
    {
        for(int j=0;j<src.cols;j++)
        {
            Vec3b &bgr = src.at<Vec3b>(i,j);
            int gray_value = (bgr[2]*30 + bgr[1]*59 + bgr[0]*11 + 50)/100;
            gray.at<uchar>(i,j) = gray_value;
        }
    }
}

int main(int argc, char *argv[])
{
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

//    return a.exec();

//-------图像的裁剪Start--------
//    Mat src = imread("1.jpg");
//    namedWindow("src");
//    imshow("src",src);

//    Rect roi(100,100,500,500);
//    Mat _roi = src(roi);
//    namedWindow("roi");
//    imshow("roi",_roi);
//    waitKey(0);
//-------图像的裁剪End-----------

    //-----灰度图转换Start---------
//    Mat src = imread("1.jpg");
//    Mat dst;

//    printMs(nullptr);
//    cvtColor(src,dst,COLOR_BGR2GRAY);
//    printMs("cvtColor");

//    printMs(nullptr);
//    cvtColor(src,dst,COLOR_BGR2GRAY);
//    printMs("cvtColor2");

//    namedWindow("gray");
//    imshow("gray",dst);

//    Mat src2 = imread("1.jpg");
//    Mat gray;

//    printMs(nullptr);
//    RGB2GRAY(src2,gray);
//    printMs("RGB2GRAY");

//    namedWindow("mygray");
//    imshow("mygray",gray);
//    waitKey(0);
    //-----灰度图转换End-----------

    //-----图像二值化（针对灰度图）Start------
    Mat src = imread("1.jpg");
    Mat gray;
    Mat bin;
    cvtColor(src,gray,COLOR_BGR2GRAY);
    cv::threshold(gray,bin,100,255,THRESH_BINARY);//反二值化THRESH_BINARY_INV
    namedWindow("binay");
    imshow("binay",bin);
    waitKey(0);
    //-----图像二值化（针对灰度图）End--------
    return 0;
}

