#include "frame.h"

Frame::Frame(QQuickItem *parent) : QQuickPaintedItem (parent)
{
    qDebug() <<__func__;

}

Mat Frame::getRawFrame() const
{
    qDebug() <<__func__;
    return rawFrame;
}

void Frame::setRawFrame(const Mat &value)
{
    qDebug() <<__func__;
    rawFrame = value;
    convert2QImage();
}

QImage Frame::getFrame() const
{
    qDebug() <<__func__;
    return frame;
}

void Frame::setFrame(const QImage &value)
{
    qDebug() <<__func__;
    frame = value;
    Frame::update();
    emit frameChanged();
}

void Frame::openImage(QString url)
{
    qDebug() <<__func__;
    url.remove("file://");
    rawFrame = imread(url.toStdString());
    convert2QImage();
}

void Frame::convert2QImage()
{
    qDebug() <<__func__;
    Mat tempMat;

//  this may be bgr to rgb
    cvtColor( rawFrame, tempMat, COLOR_RGB2BGR );

//  constructor with the buffer and width, height, byte per line, format
    QImage tempImage( (uchar*)tempMat.data, tempMat.cols, tempMat.rows, tempMat.step, QImage::Format_RGB888);

    frame = tempImage;

//  in my opinion this disconnect mamory sharing with tempImage so we can chaenge tempImage without effecting on frame
    frame.detach();

    Frame::update();

    emit frameChanged();

}

void Frame::paint(QPainter *painter)
{
    //qDebug() <<__func__;
    frame.scaled(1280,720, Qt::IgnoreAspectRatio, Qt::FastTransformation);
    painter->drawImage(0, 0, frame, 0, -1, -1, Qt::AutoColor );

}
