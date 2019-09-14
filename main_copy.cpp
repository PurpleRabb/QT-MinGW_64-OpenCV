#include "mainwindow.h"
#include <QApplication>
#include <opencv2/opencv.hpp>
#include <QDebug>
#include <sys/time.h>
#include <opencv2/video.hpp>

using namespace cv;

int main(int argc, char *argv[])
{
    //---------VideoCapture打开播放视频Start------
//    VideoCapture video;
//    video.open("D:\\BaiduNet\\shudazhaofeng.mp4");
//    if(!video.isOpened())
//    {
//        return -1;
//    }
//    Mat frame;
//    qDebug() << video.get(CAP_PROP_FPS) << video.get(CAP_PROP_FRAME_COUNT);
//    namedWindow("display");
//    for(;;)
//    {
////        if(!video.read(frame))
////        {
////            break;
////        }
//        //另一种方法
//        if(!video.grab()) //读帧，解码
//        {
//            break;
//        }
//        if(!video.retrieve(frame))//转换颜色空间
//        {
//            break;
//        }
//        int cur = video.get(CAP_PROP_POS_FRAMES);
//        if(cur > 90)
//        {
//            video.set(CAP_PROP_POS_FRAMES,0);
//            continue;
//        }
//        imshow("display",frame);
//        waitKey(30);
//    }
//    getchar();
    //---------VideoCapture打开播放视频End------

    //打开摄像头
    VideoCapture cam(0);
    cam.open(0);
    if(!cam.isOpened())
    {
        return -1;
    }
    Mat frame;
    int width = cam.get(CAP_PROP_FRAME_WIDTH);
    int height = cam.get(CAP_PROP_FRAME_HEIGHT);
    qDebug() << cam.get(CAP_PROP_FPS); // maybe 0,here is 0
    qDebug() << width << height;
    namedWindow("cam");
    Mat frame_l;
    for(;;)
    {
        cam.read(frame);
        resize(frame,frame_l,Size(width*2,height*2));
        imshow("cam",frame_l);
        if(waitKey(30) == 'q')
        {
            cam.release();
            return 0;
        }
    }
    return 0;
}

