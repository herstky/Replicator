import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Window 2.2

ApplicationWindow {
    width: 800
    height: 600
    visible: true
    visibility: "Maximized"

    title: qsTr("EcoSim")

    Page {
        id: page
        property alias container: container
        property alias element2: element2
        property alias element1: element1
        property alias element: element
        property alias row: row
        contentHeight: 8
        property alias board: board
        property alias page: page
        anchors.fill: parent

        Rectangle {
            id: container
            color: "#ffffff"
            anchors.fill: parent
            objectName: "container"

            Column {
                id: column
                x: 143
                y: -61

                width: 600
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 0
                anchors.top: parent.top
                anchors.topMargin: 0
                anchors.horizontalCenter: parent.horizontalCenter
                objectName: "column"

                Row {
                    id: row
                    y: 50
                    height: 50
                    transformOrigin: Item.Top
                    objectName: "textRow"

                    Label {
                        id: element2
                        width: 130
                        height: 36
                        text: qsTr("Text")
                        anchors.left: parent.left
                        anchors.leftMargin: 0
                        fontSizeMode: Text.HorizontalFit
                        wrapMode: Text.NoWrap
                        font.pixelSize: 18
                        anchors.bottom: parent.bottom
                        verticalAlignment: Text.AlignBottom
                        anchors.bottomMargin: 0
                        objectName: "redCountText"
                    }

                    Label {
                        id: element1
                        width: 130
                        height: 36
                        text: qsTr("Text")
                        anchors.left: element2.right
                        anchors.leftMargin: 0
                        fontSizeMode: Text.HorizontalFit
                        wrapMode: Text.WordWrap
                        font.pixelSize: 18
                        anchors.bottom: parent.bottom
                        verticalAlignment: Text.AlignBottom
                        anchors.bottomMargin: 0
                        objectName: "greenCountText"
                    }

                    Label {
                        id: element
                        width: 130
                        height: 36
                        text: qsTr("Text")
                        anchors.left: element1.right
                        anchors.leftMargin: 0
                        fontSizeMode: Text.HorizontalFit
                        wrapMode: Text.WordWrap
                        anchors.bottom: parent.bottom
                        anchors.bottomMargin: 0
                        verticalAlignment: Text.AlignBottom
                        font.pixelSize: 18
                        objectName: "blueCountText"
                    }
                }

                Rectangle {
                    id: board
                    height: 400
                    color: "#2e8b57"
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.right: parent.right
                    anchors.rightMargin: 0
                    anchors.left: parent.left
                    anchors.leftMargin: 0
                    border.width: 0
                    objectName: "board"
                }

                Row {
                    id: buttonRow
                    height: 50
                    anchors.top: board.bottom
                    anchors.topMargin: 0
                    anchors.right: parent.right
                    anchors.rightMargin: 0
                    anchors.left: parent.left
                    anchors.leftMargin: 0
                    objectName: "buttonRow"


                    Button {
                        id: playPauseButton
                        text: qsTr("Play")
                        anchors.left: parent.left
                        anchors.leftMargin: 0
                        anchors.bottom: parent.bottom
                        anchors.bottomMargin: 10
                        anchors.top: parent.top
                        anchors.topMargin: 0
                        font.pointSize: 14
                        objectName: "playPauseButton"
                    }

                    Column {
                        id: column1
                        anchors.bottom: parent.bottom
                        anchors.bottomMargin: 0
                        anchors.top: parent.top
                        anchors.topMargin: 0
                        anchors.right: animateCheckBox.left
                        anchors.rightMargin: 0
                        anchors.left: playPauseButton.right
                        anchors.leftMargin: 0

                        ProgressBar {
                            id: progressBar
                            height: 36
                            anchors.bottom: parent.bottom
                            anchors.bottomMargin: 0
                            anchors.top: progressBarLabel.bottom
                            anchors.topMargin: 0
                            anchors.horizontalCenter: parent.horizontalCenter
                            value: 0
                            objectName: "progressBar"
                        }

                        Text {
                            id: progressBarLabel
                            text: qsTr("Generation Progress")
                            font.weight: Font.Normal
                            anchors.top: parent.top
                            anchors.topMargin: 0
                            anchors.horizontalCenter: parent.horizontalCenter
                            font.pixelSize: 16
                        }
                    }

                    CheckBox {
                        id: animateCheckBox
                        text: qsTr("Animate")
                        anchors.right: parent.right
                        anchors.rightMargin: 0
                        anchors.bottom: parent.bottom
                        anchors.bottomMargin: 10
                        anchors.top: parent.top
                        anchors.topMargin: 0
                        font.pointSize: 14
                        checkState: Qt.Checked
                        objectName: "animateCheckBox"
                    }


                }
            }
        }
    }
}


/*##^##
Designer {
    D{i:11;anchors_height:400;anchors_width:200}
}
##^##*/
