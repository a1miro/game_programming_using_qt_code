import QtQuick 2.2

Canvas {
  id: canvas

  property int lineWidth: 2
  property var points: []
  property real arg: -Math.PI

  implicitWidth: 600
  implicitHeight: 300

  function func(argument) {
      var a=(2*Math.PI/10); var b=4*Math.PI/5
      return Math.sin(20*argument) * (
            Math.exp(-Math.pow(argument/a, 2)) +
            Math.exp(-Math.pow((argument-b)/a,2)) +
            Math.exp(-Math.pow((argument+b)/a,2))
      )
  }

  Timer {
      interval: 10
      repeat: true
      running: true
      onTriggered: {
          arg += Math.PI/180
          while(arg >= Math.PI) arg -= 2*Math.PI
      }
  }

  onArgChanged: {
    points.push(func(arg))
    points = points.slice(-canvas.width)
    canvas.requestPaint()
  }

  onPaint: {
      var ctx = canvas.getContext("2d")
      ctx.reset()
      ctx.clearRect(0, 0, canvas.width, canvas.height)
      var pointsToDraw = points.slice(-canvas.width)
      ctx.translate(0, canvas.height/2)
      ctx.beginPath()
      ctx.moveTo(0, -pointsToDraw[0]*canvas.height/2)
      for(var i=1; i<pointsToDraw.length; i++)
          ctx.lineTo(i, -pointsToDraw[i]*canvas.height/2)
      ctx.lineWidth = canvas.lineWidth
      ctx.stroke()
  }
}
