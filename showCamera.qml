import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import com.app.frame 1.0

Page {

    anchors.fill:parent

    Connections{
        // name of class reference defined in main.cpp
        target: videoThread
        // updateView signal should be referred as onUpdateView such as a slot name
        // frame is a name of Mat object from updateView signal
        // name of parameter should be the same with it's definition

        onUpdateView2 : selectedImage.setRawFrame(frame)
    }

    Rectangle{
        id: bar
        width: parent.width
        height: parent.height * 0.1
        color: 'orange'

        Label{
            text : "Show Camera"
            color : "white"
            anchors.centerIn: parent
        }
    }

    ColumnLayout{
        id: imageContainer
        width: 640
        height: 480
        anchors.top:bar.bottom
        anchors.topMargin: 20
        anchors.horizontalCenter: parent.horizontalCenter

        Image{
            id : picture
            source: "qrc:/logo"
            Layout.preferredWidth : imageContainer.width
            Layout.preferredHeight: imageContainer.height
            fillMode: Image.PreserveAspectFit
            //visible: false
        }

        Frame{
            id : selectedImage
            Layout.preferredWidth: imageContainer.width
            Layout.preferredHeight: imageContainer.height
            visible: false
        }
    }

    RowLayout{
        anchors.top: imageContainer.bottom
        anchors.topMargin: 10
        anchors.horizontalCenter: parent.horizontalCenter
        width: parent.width * 0.6
        spacing: width * 0.2

        Button{
            text : 'Open Camera'
            Layout.preferredWidth: parent.width * 0.4
            onClicked:
            {
                picture.visible = false;
                selectedImage.visible = true;
                videoThread.runCapture("");
            }
        }

        Button{
            text : 'Go Back'
            Layout.preferredWidth: parent.width * 0.4
            onClicked: loader.pop()
        }

    }

}
