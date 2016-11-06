print("Player HP:", player.hp)
print("Creature HP:", self.hp)
var val = Math.random() * 100
if(val < 50) {
  print("Attack!")
  self.attack(player)
} else {
  print("Dodge!");
  self.dodge();
}
