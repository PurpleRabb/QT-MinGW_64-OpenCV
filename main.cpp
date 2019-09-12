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

void myresize(Mat &src,Mat &dst, Size st)
{
    dst.create(st,src.type());
    float fx = (float)src.cols/dst.cols;
    float fy = (float)src.rows/dst.rows;
    int sx,sy = 0;

    for (int x = 0; x < dst.cols; x++)
    {
        sx = fx*x + 0.5; //加0.5是为了四舍五入
        sx >= src.cols ? sx = src.cols-1: sx;
        for (int y=0; y < dst.rows; y++)
        {
            sy = fy*y + 0.5;
            //qDebug() << x << y ;
            sy >= src.rows ? sy = src.rows-1: sy;
            dst.at<Vec3b>(y,x) = src.at<Vec3b>(sy,sx);
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
    //-----灰度图转换End-----------

    //-----图像二值化（针对灰度图）Start------
//    Mat src = imread("1.jpg");
//    Mat gray;
//    Mat bin;
//    cvtColor(src,gray,COLOR_BGR2GRAY);
//    cv::threshold(gray,bin,100,255,THRESH_BINARY);//反二值化THRESH_BINARY_INV
//    namedWindow("binay");
//    imshow("binay",bin);
    //-----图像二值化（针对灰度图）End--------

    //-------图像缩放Start------------
//    Mat src = imread("1.jpg");
//    Mat dst;
//    Size st(3200,1800);
//    //myresize(src,dst,st);//自行实现的近邻算法
//    resize(src,dst,st,0,0,INTER_NEAREST);//近邻算法
//    resize(src,dst,st,0,0,INTER_LINEAR);//线性插值算法
//    namedWindow("dst");
//    imshow("dst",dst);
    //-------图像缩放End--------------

    //高斯金字塔和拉普拉斯金字塔
//    Mat src = imread("1.jpg");
//    Mat gsrc;
//    pyrDown(src,gsrc);//高斯金字塔，下采样
//    namedWindow("gsrc");
//    imshow("gsrc",gsrc);

//    Mat usrc;
//    pyrUp(src,usrc);//拉普拉斯金字塔，上采样
//    namedWindow("usrc");
//    imshow("usrc",usrc);

    //--------图像的混合，旋转，镜像Start--------
    Mat red;
    Mat src = imread("1.jpg");
    red.create(src.rows,src.cols,src.type());
    Mat dst;
    for(int i=0;i<red.rows;i++)
    {
        for(int j=0;j<red.cols;j++)
        {
            Vec3b &bgr = red.at<Vec3b>(i,j);
            bgr[0] = 0;
            bgr[1] = 0;
            bgr[2] = 255;
        }
    }
    //addWeighted(src,0.5,red,0,0,dst);//混合
    //rotate(src,dst,1);旋转
    flip(src,dst,1);
    namedWindow("dst");
    imshow("dst",dst);
    //--------图像的混合，旋转，镜像End----------
    waitKey(0);
    return 0;
}

