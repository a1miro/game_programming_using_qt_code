import QtQuick 2.2

Canvas {
  id: canvas

  implicitWidth: 600
  implicitHeight: 300

  onPaint: {
    var ctx = canvas.getContext("2d")
    ctx.clearRect(0, 0, canvas.width, canvas.height)
  }
}
