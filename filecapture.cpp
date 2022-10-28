#include "filecapture.h"

FileCapture::FileCapture(QObject *parent) : QObject(parent)
{
    stopVideo = false;
}

void FileCapture::setUrl(QString &value)
{
    value.remove("file://");
    url = value;
}

bool FileCapture::openVideo()
{
    Mat rawFrame;
    videoCapture = new VideoCapture;

    videoCapture->open( url.toStdString() );
    //videoCapture->open( 0 );

    if(!videoCapture->isOpened()){
        return false;
    }

    //qDebug() << CV_CAP_PROP_FRAME_WIDTH;
    //videoCapture->set(CAP_PROP_FRAME_WIDTH, 1280.0);
    //videoCapture->set(CAP_PROP_FRAME_HEIGHT, 720.0);

    while(videoCapture->read(rawFrame) && !stopVideo){
        emit(newFrameCaptured(rawFrame));
    }

    return true;

}


