#ifndef CAMERACAPTURE_H
#define CAMERACAPTURE_H

#include <QObject>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;

class CameraCapture : public QObject
{
    Q_OBJECT

    VideoCapture *videoCapture;
    QString url;
    bool stopVideo;

public:
    explicit CameraCapture(QObject *parent = nullptr);
    void setUrl(QString &value);

signals:
    void newCameraCaptured(Mat frame);

public slots:

    bool openVideo();


};

#endif // FILECAPTURE_H
