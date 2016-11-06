import QtQuick 2.3
import OutlineTextItem 1.0

Rectangle {
    width: 800; height: 400
    OutlineTextItem {
        anchors.centerIn: parent
        text: "This is outlined text"
        fontFamily: "Arial"
        fontPixelSize: 64
        color: "#33ff0000"
        antialiasing: true
        border {
            color: "blue"
            width: 2
            style: Qt.DotLine
        }
    }
}
