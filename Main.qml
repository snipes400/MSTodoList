import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import com.todo

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    TodoList{
        id: myTodoList
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
                height: 150
                color: "lightgreen"
                Column {
                    //anchors.fill: parent
                    spacing: 10
                    Repeater {
                        id: addTaskPanelRepeater
                        model: [
                            { text: "Title:"},
                            { text: "Description"},
                            { text: "Color (not implemented):"}
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
                Layout.fillHeight: true
                color: "lightblue"

                ListView {
                    id: todoItemListView
                    anchors.fill: parent

                    model: myTodoList

                    delegate: Column {

                        Text {
                            text: "Title: " + todoitem.title
                        }
                        Text {

                            text: "Description: " + todoitem.desc
                        }
                        Row {
                            Text {
                                text: "Done: "
                            }
                            CheckBox {
                                checked: todoitem.done
                                onCheckedChanged: {
                                    todoitem.done = checked
                                }
                            }
                        }

                        Button{
                            text: "Remove"
                            onClicked: {
                                myTodoList.removeItem(index)
                            }
                        }
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
            let newTodoItem = Qt.createQmlObject('import com.todo 1.0; TodoItem {}', parent);


            newTodoItem.title = addTaskPanelRepeater.itemAt(0).children[1].text
            addTaskPanelRepeater.itemAt(0).children[1].text = ""

            newTodoItem.desc = addTaskPanelRepeater.itemAt(1).children[1].text
            addTaskPanelRepeater.itemAt(1).children[1].text = ""

            myTodoList.addItem(newTodoItem)

        }
    }
}
