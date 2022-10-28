QT += quick

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

HEADERS += \
    cameracapture.h \
    filecapture.h \
    frame.h \
    threadmanager.h

SOURCES += \
        cameracapture.cpp \
        filecapture.cpp \
        frame.cpp \
        main.cpp \
        threadmanager.cpp

RESOURCES += qml.qrc

INCLUDEPATH += 'C:/opencv343/build/include'

#LIBS += -L'C:/opencv451/build/x64/vc15/lib/'\
#       -lopencv_world451d

LIBS += -L'C:/opencv343/build/x64/vc15/lib' \
  -lopencv_core343 \
  -lopencv_imgproc343 \
  -lopencv_imgcodecs343 \
  -lopencv_videoio343 \
  -lopencv_flann343 \
  -lopencv_highgui343 \
  -lopencv_features2d343 \
  -lopencv_photo343 \
  -lopencv_video343 \
  -lopencv_calib3d343 \
  -lopencv_objdetect343 \
  -lopencv_stitching343 \
  -lopencv_dnn343 \
  -lopencv_ml343 \
 -lopencv_imgproc343 \
 -lopencv_imgcodecs343 \
 -lopencv_videoio343 \
 -lopencv_flann343 \
 -lopencv_highgui343 \
 -lopencv_features2d343 \
 -lopencv_photo343 \
 -lopencv_video343 \
 -lopencv_calib3d343 \
 -lopencv_objdetect343 \
 -lopencv_stitching343 \
 -lopencv_dnn343 \
 -lopencv_ml343


# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
