#include <QGuiApplication>
#include <QQmlApplicationEngine>


// include thease to expose my thread to qml
#include <QQmlContext>
#include <QQmlComponent>

//include frame because we want to render something from
// Frame object otherwise we just connect signal and slot to the object
#include <frame.h>

//I didn't registered video related objects
//Since I just wanna connect signal and slot from them

#include "threadmanager.h"


int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    threadManager videoThread;
    // register my class
    qmlRegisterType<Frame>("com.app.frame", 1, 0, "Frame");

    //register object so Mat can be transfered throgh signal and slot
    qRegisterMetaType<cv::Mat>("Mat");

    // pass my context to qml as named videoThread( any class can be passed this way too )
    engine.rootContext()->setContextProperty("videoThread", &videoThread);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
