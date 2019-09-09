#ifndef MATVIEW_H
#define MATVIEW_H

#include <QWidget>
#include <QOpenGLWidget>
#include <QImage>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>

using namespace cv;

class MatView : public QOpenGLWidget
{
    Q_OBJECT
public:
    explicit MatView(QWidget *parent = nullptr);
    virtual void paintEvent(QPaintEvent *event);

signals:

public slots:

private:
    Mat src;
};

#endif // MATVIEW_H
