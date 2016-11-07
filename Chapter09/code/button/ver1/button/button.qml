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
      width: 100; height: 30
      gradient: Gradient {
        GradientStop { position: 0; color: "#eeeeee" }
        GradientStop { position: 1; color: "#777777" }
      }
    }
}

