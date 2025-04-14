import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    ColumnLayout {
        anchors.top : parent.top
        anchors.left : parent.left
        anchors.right: parent.right
        anchors.bottom: addButton.top

        Rectangle {
            Layout.fillWidth: true
            //height: 50
            Layout.fillHeight: true
            color: "lightblue"
            Text {
                anchors.centerIn: parent
                text: "Item 1"
            }
        }

        Rectangle {
            Layout.fillWidth: true
            //height: 75
            Layout.fillHeight: true
            color: "lightgreen"
            Text {
                anchors.centerIn: parent
                text: "Item 2"
            }
        }
    }

    Button {
        id: addButton
        text: "Add Task"
        anchors.bottom: parent.bottom
        anchors.right : parent.right
    }
}
