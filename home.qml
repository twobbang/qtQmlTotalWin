import QtQuick 2.0
import QtQuick.Controls 2.12

Page {
    anchors.fill:parent
    Rectangle{
        id: bar
        width: parent.width
        height: parent.height * 0.1
        color: 'orange'

        Label{
            text : "Welcome to the Qt OpenCV app"
            color : "white"
            anchors.centerIn: parent
        }
    }

    Button{
        id : imageButton
        text:'Show Image'
        anchors.top: bar.bottom
        anchors.topMargin: 20
        anchors.horizontalCenter: parent.horizontalCenter
        onClicked: loader.push("qrc:/showImage");
    }

    Button{
        id: imageButton2
        text:'Show Video'
        anchors.top: imageButton.bottom
        anchors.topMargin: 20
        anchors.horizontalCenter: parent.horizontalCenter
        onClicked: loader.push("qrc:/showVideo");
    }

    Button{
        id: imageButton3
        text:'Show Camera'
        anchors.top: imageButton2.bottom
        anchors.topMargin: 20
        anchors.horizontalCenter: parent.horizontalCenter
        onClicked: loader.push("qrc:/showCamera");
    }
}
