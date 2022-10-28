import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Window {
    visible: true
    width: 1024
    height: 720
    title: qsTr("app")

    StackView{
        id: loader
        anchors.fill: parent
        initialItem: 'qrc:/home'
    }
}
