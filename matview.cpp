#include "matview.h"
#include <QImage>
#include <QPainter>
#include <QDebug>

MatView::MatView(QWidget *parent) : QOpenGLWidget(parent)
{
    //connect(this,SIGNAL(resize()),this,SLOT(update()));
}

void MatView::paintEvent(QPaintEvent *event)
{
    Mat src = imread("1.jpg");
    QImage img(src.data,src.cols,src.rows,QImage::Format_RGB888);//BGR
    cvtColor(src,src,COLOR_BGR2RGB);
    QPainter painter;
    painter.begin(this);
    painter.drawImage(QPoint(0,0),img);
    qDebug() << "MatView::paintEvent";
    //QOpenGLWidget::paintEvent(event);
}
