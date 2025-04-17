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
                Column {
                    //anchors.fill: parent
                    spacing: 10
                    Repeater {
                        id: addTaskPanelRepeater
                        model: [
                            { text: "Title:"},
                            { text: "Description"},
                            { text: "Color:"}
                        ]
                        delegate: Row {
                            id: repeaterDelegate
                            spacing: 10
                            //color: modelData.color

                            Text {
                                id: label
                                text: modelData.text
                            }

                            TextField {
                                id: addItemField
                            }
                        }
                    }
                }
            }

            Rectangle {
                Layout.fillWidth: true
                //height: 50
                Layout.fillHeight: true
                color: "lightblue"

                Column {
                    spacing: 10
                    Text {

                        text: "Title: " + myTodoItem.title
                    }
                    Text {

                        text: "Description: "// + myTodoItem.desc
                    }
                    Row {
                        Text {
                            text: "Done: "
                        }
                        CheckBox {

                        }
                    }

                    Button{
                        text: "Remove"
                    }
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
            myTodoItem.title = addTaskPanelRepeater.itemAt(0).children[1].text
            //myTodo
            //titleTextField.text = ""
        }
    }
}
