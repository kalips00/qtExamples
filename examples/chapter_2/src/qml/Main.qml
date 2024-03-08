import QtQuick
import QtQuick.Controls.Basic
import QtQuick.Window

import chapter_2

Window {
    id: root
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    color: root.grey0

    Component.onCompleted: console.log("Model c++:", ctx_model)

    readonly property color grey0: "#000000"
    readonly property color grey1: "#1F1F1F"
    readonly property color grey2: "#383838"
    readonly property color grey3: "#515151"
    readonly property color grey4: "#6B6B6B"
    readonly property color grey5: "#858585"
    readonly property color grey6: "#F6F6F6"
    readonly property color grey7: "#EBEBEB"
    readonly property color grey8: "#D0D0D0"
    readonly property color grey9: "#B6B6B6"

//    RecipeManager {
//        id: manager
//    }

    ListView {
        anchors {
            fill: parent
            margins: 24
        }
//        model: manager.recipeModel
        model: ctx_model
        spacing: 24

        delegate: Rectangle {
            id: delegate

            required property int index
            required property string title
            required property string content
            required property string difficulty
            required property string preparationDuration
            required property OvenConfiguration ovenConfiguration

            anchors {
                left: parent.left
                right: parent.right
                margins: 16
            }
            height: 200
            color: root.grey2
            radius: 5

            Column {
                anchors {
                    top: parent.top
                    left: parent.left
                    margins: 16
                }
                spacing: 8

                Text {
                    text: delegate.title
                    color: root.grey6
                    font {
                        pixelSize: 24
                        bold: true
                    }
                }

                Text {
                    leftPadding: 8
                    text: delegate.content
                    color: root.grey6
                    font.pixelSize: 18
                }

                Text {
                    leftPadding: 8
                    text: "Difficulté " + delegate.difficulty + "/5"
                    color: root.grey6
                    font {
                        pixelSize: 16
                        bold: true
                    }
                }

                Text {
                    leftPadding: 8
                    text: !!delegate.ovenConfiguration ?
                              "Four <br>" + delegate.ovenConfiguration.duration + "min<br>" + delegate.ovenConfiguration.temperature + "°C"
                            : "Four : non"
                    color: root.grey6
                    font {
                        pixelSize: 16
                        bold: true
                    }
                }
            }

//            Button {
//                id: removeButton
//                anchors {
//                    top: parent.top
//                    right: parent.right
//                    margins: 8
//                }
//                width: 32
//                height: 32
//                padding: 0
//                scale: removeButton.pressed ? 0.9 : 1


//                contentItem: Text {
//                    horizontalAlignment: Text.AlignHCenter
//                    verticalAlignment: Text.AlignVCenter
//                    text: "+"
//                    rotation: 45
//                    font {
//                        pixelSize: 24
//                        bold: true
//                    }
//                    color: root.grey6
//                }

//                background: Rectangle {
//                    color: removeButton.hovered ? root.grey4 : root.grey3
//                    radius: 5
//                }

//                onClicked: manager.remove(delegate.index);
//            }
        }
    }
}
