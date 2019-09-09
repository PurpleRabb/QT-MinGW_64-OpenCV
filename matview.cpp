#include "matview.h"
#include <QImage>
#include <QPainter>

MatView::MatView(QWidget *parent) : QOpenGLWidget(parent)
{
    src = imread("1.jpg");
}

void MatView::paintEvent(QPaintEvent *event)
{
    QImage img(src.data,src.cols,src.rows,QImage::Format_RGB888);//BGR
    cvtColor(src,src,COLOR_BGR2RGB);
    QPainter painter;
    painter.begin(this);
    painter.drawImage(QPoint(0,0),img);
}
