import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import com.todolist

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    TodoItem{
        id: myTodoItem
    }

    ScrollView
    {
        anchors.top : parent.top
        anchors.left : parent.left
        anchors.right: parent.right
        anchors.bottom: addButton.top


        contentItem: ColumnLayout {
            id: columnLayout
            anchors.fill: parent

            Rectangle {
                id: addTaskPanel
                Layout.fillWidth: true
                //height: 75
                Layout.fillHeight: true
                color: "lightgreen"
                Text {
                    id: titleLabel
                    text: "Title"
                    anchors.right: titleTextField.left
                    anchors.verticalCenter: titleTextField.verticalCenter
                }
                TextField {
                    id: titleTextField
                    anchors.centerIn: parent
                    //text: "Item 2"
                }
            }

            Rectangle {
                Layout.fillWidth: true
                //height: 50
                Layout.fillHeight: true
                color: "lightblue"
                Text {
                    anchors.centerIn: parent
                    text: myTodoItem.title
                }
            }
        }
    }
    Button {
        id: addButton
        text: "Add Task"
        anchors.bottom: parent.bottom
        anchors.right : parent.right
        onClicked: {
            myTodoItem.title = titleTextField.text
            titleTextField.text = ""
        }
    }
}
