#ifndef THREADMANAGER_H
#define THREADMANAGER_H

#include <QObject>
#include <QThread>
#include "filecapture.h"
#include "cameracapture.h"

class threadManager : public QObject
{
    Q_OBJECT

    QThread thread;
    QThread thread2;
    FileCapture capture;
    CameraCapture ccapture;

public:
    explicit threadManager(QObject *parent = nullptr);
    Q_INVOKABLE void runCapture(QString url);


signals:

    void updateView(Mat frame);
    void updateView2(Mat frame);

public slots:
    void receiveFrame(Mat frame);
    void receiveFrame2(Mat frame);


};

#endif // THREADMANAGER_H
