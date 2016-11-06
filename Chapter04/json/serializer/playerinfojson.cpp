#include "playerinfojson.h"
#include <QJsonDocument>

PlayerInfoJSON::PlayerInfoJSON()
{

}

QByteArray PlayerInfoJSON::writePlayerInfo(const PlayerInfo &pinfo) const
{
    QJsonDocument doc = QJsonDocument::fromVariant(toVariant(pinfo));
    return doc.toJson();
}

QVariant PlayerInfoJSON::toVariant(const PlayerInfo &pinfo) const {
  QVariantList players;
  foreach(const Player &p, pinfo.players) players << toVariant(p);
  return players;
}

QVariant PlayerInfoJSON::toVariant(const Player &player) const {
  QVariantMap map;
  map["name"]          = player.name;
  map["password"]    = player.password;
  map["experience"] = player.experience;
  map["hitpoints"]     = player.hitPoints;
  map["location"]       = player.location;
  map["position"]       = QVariantMap({ {"x", player.position.x()},
                                        {"y", player.position.y()} });
  map["inventory"]     = toVariant(player.inventory);
  return map;
}

QVariant PlayerInfoJSON::toVariant(const QList<InventoryItem> &items) const {
  QVariantList list;
  foreach(const InventoryItem &item, items) list << toVariant(item);
  return list;
}

QVariant PlayerInfoJSON::toVariant(const InventoryItem &item) const {
  QVariantMap map;
  map["type"] = (int)item.type;
  map["subtype"] = item.subType;
  map["durability"] = item.durability;
  return map;
}
