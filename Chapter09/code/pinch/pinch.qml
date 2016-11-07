import QtQuick 2.3
import QtQuick.Window 2.2

Window {
    visible: true

    Image {
      id: image
      anchors.centerIn: parent
      source: "wilanow.jpg"
    }

    PinchArea {
      anchors.fill: parent
      pinch {
        target: image
        minimumScale: 0.2; maximumScale: 2.0
        minimumRotation: -90; maximumRotation: 90
      }
    }
}

