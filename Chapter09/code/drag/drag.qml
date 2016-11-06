import QtQuick 2.3
import QtQuick.Window 2.2

Window {
    visible: true
    Rectangle {
        id: circle
        width: 60; height: width
        radius: width/2
        color: "red"

        MouseArea {
            anchors.fill: parent
            drag.target: circle
        }
    }
}

