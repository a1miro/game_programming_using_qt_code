import QtQuick 2.0
import RegularPolygon 1.0
import QtQuick.Controls 1.2

Rectangle {
    width: 600
    height: 600

    RegularPolygon {
        id: poly
        anchors.fill: parent
        vertices: slider.value
        color: "blue"
        anchors.bottomMargin: 20
    }
    Row {
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        spacing: 5

        Repeater {
            model: ["red", "blue", "green"]

            Rectangle {
                width: 20
                height: width
                color: modelData
                MouseArea {
                    anchors.fill: parent
                    onClicked: poly.color = color
                }
            }
        }

        Slider {
            id: slider
            minimumValue: 3
            maximumValue: 100
            width: 100
            value: 6
        }

    }

}

