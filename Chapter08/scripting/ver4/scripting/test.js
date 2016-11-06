function init() {
  print("This is init function")
  this.distance = function(p1, p2) {
    // Manhattan distance
    return Math.abs(p1.x-p2.x)+Math.abs(p1.y-p2.y)
  }
  this.actionHistory = []
}

function heartbeat(person) {
  person.attack(this.enemy)
  this.actionHistory.push("ATTACK")
}

function defend() {
  print("This is defend function")
}
