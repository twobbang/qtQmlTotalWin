#include "threadmanager.h"

threadManager::threadManager(QObject *parent) : QObject(parent)
{

}

void threadManager::runCapture(QString url)
{
    capture.setUrl( url );

    connect( &thread , &QThread::started, &capture, &FileCapture::openVideo   );
    connect( &thread2 , &QThread::started, &ccapture, &CameraCapture::openVideo   );
    connect( &thread , &QThread::finished, &capture, &FileCapture::deleteLater);
    connect( &thread2 , &QThread::finished, &ccapture, &CameraCapture::deleteLater);
    connect( &capture, &FileCapture::newFrameCaptured, this, &threadManager::receiveFrame);
    connect( &ccapture, &CameraCapture::newCameraCaptured, this, &threadManager::receiveFrame2);

    if(url == "")
    {
        ccapture.moveToThread(&thread2);
    }
    else
    {
        capture.moveToThread(&thread);
    }

    thread.start();

}

void threadManager::receiveFrame(Mat frame)
{
    emit updateView(frame);
}

void threadManager::receiveFrame2(Mat frame)
{
    emit updateView2(frame);
}
