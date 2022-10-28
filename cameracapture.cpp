#include "cameracapture.h"


CameraCapture::CameraCapture(QObject *parent) : QObject(parent)
{
    stopVideo = false;
}

void CameraCapture::setUrl(QString &value)
{
    value.remove("file://");
    url = value;
}

bool CameraCapture::openVideo()
{
    Mat rawFrame;
    videoCapture = new VideoCapture;
    //videoCapture->open( url.toStdString() );
    videoCapture->open( 0 );

    if(!videoCapture->isOpened()){
        return false;
    }

    while(videoCapture->read(rawFrame) && !stopVideo){
        emit(newCameraCaptured(rawFrame));
    }

    return true;

}
