#ifndef FRAME_H
#define FRAME_H

#include <QObject>
#include <QQuickPaintedItem>
#include <QImage>
#include <QPainter>
#include <QDebug>

#include <opencv2/core.hpp>
#include <opencv2/core/utility.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;

class Frame : public QQuickPaintedItem
{
    Q_OBJECT

    // passing frame as Qimage and writh with setFrame function and so on..
    //Q_PROPERTY(type name READ getfunction WRITE setFunction NOTIFY notifySignal)
    //QImage frame ->
    //READ getFrame -> qml내에서 지정된 cpp내의 특정 변수의 값을 얻어오려 할ㄸㅐ cpp 함수
    //WRITW setFframe ->qml 내에서 지정된 cpp내의 특정 변수 ㅅㅔ팅
    //NOTYFY frameChange ->cpp 내의 함수 호출
    Q_PROPERTY( QImage frame READ getFrame WRITE setFrame NOTIFY frameChanged )

    Mat rawFrame;
    QImage frame;

public:
    Frame(QQuickItem *parent = nullptr );
    void paint(QPainter *painter);


    Mat getRawFrame() const;
    QImage getFrame() const;
    void setFrame(const QImage &value);

    Q_INVOKABLE void setRawFrame(const Mat &value);
    Q_INVOKABLE void openImage(QString url);


signals:
    void frameChanged();

public slots:
    void convert2QImage();

};

#endif // FRAME_H
