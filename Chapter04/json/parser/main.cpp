#include "playerinfojson.h"
#include <QtDebug>

int main(int, char**) {
    PlayerInfo playerInfo;
    Player player;
    player.name = "Gandalf";
    player.password = "mithrandir";
    player.experience = 23456;
    player.hitPoints = 40;
    player.location = "room1";
    player.position = QPoint(1,0);

    InventoryItem item;
    item.type = InventoryItem::Weapon;
    item.durability = 3;
    item.subType = "Long sword";
    player.inventory << item;
    item.type = InventoryItem::Armor;
    item.durability = 10;
    item.subType = "Chain mail";
    playerInfo.players << player;
    PlayerInfoJSON jsonSerializer;
    QByteArray result = jsonSerializer.writePlayerInfo(playerInfo);

    PlayerInfo playerInfo2 = jsonSerializer.readPlayerInfo(result);
    if(!playerInfo2.players.isEmpty()) {
        qDebug() << playerInfo2.players.first().name;
    }
    return 0;
}
