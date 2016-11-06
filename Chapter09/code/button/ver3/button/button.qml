import QtQuick 2.3
import QtQuick.Window 2.2

Window {
    visible: true

    MouseArea {
        anchors.fill: parent
        onClicked: {
            Qt.quit();
        }
    }

    Rectangle {
        id: button
        anchors.centerIn: parent
        border { width: 1; color: "black" }
        radius: 5

        gradient: Gradient {
            GradientStop { position: 0; color: "#eeeeee" }
            GradientStop { position: 1; color: "#777777" }
        }

        clip: true
        implicitWidth: Math.max(buttonContent.implicitWidth+8, 80)
        implicitHeight: buttonContent.implicitHeight+8

        Row {
            id: buttonContent
            anchors.centerIn: parent
            spacing: 4

            Image {
                id: buttonIcon
                source: "edit-undo.png"
            }
            Text {
                id: buttonText
                text: "ButtonText"
            }
        }
    }
}

