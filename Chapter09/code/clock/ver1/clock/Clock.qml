import QtQuick 2.0

Item {
  id: clock

  property color color: "lightgray"

  Rectangle {
    id: plate

    anchors.centerIn: parent
    width: Math.min(clock.width, clock.height)
    height: width
    radius: width/2
    color: clock.color
    border.color: Qt.darker(color)
    border.width: 2

    Repeater {
        model: 12

        Item {
          id: hourContainer

          property int hour: index
          height: plate.height/2
          transformOrigin: Item.Bottom
          rotation: index * 30
          x: plate.width/2
          y: 0

          Rectangle {
            width: 2
            height: (hour % 3 == 0) ? plate.height*0.1 : plate.height*0.05
            color: plate.border.color
            antialiasing: true
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: 4
          }
        }
    }

  }
}
