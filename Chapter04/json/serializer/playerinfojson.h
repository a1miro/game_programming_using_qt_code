#ifndef PLAYERINFOJSON_H
#define PLAYERINFOJSON_H

#include "playerinfo.h"
#include <QByteArray>
#include <QVariant>

class PlayerInfoJSON {
public:
  PlayerInfoJSON();
  QByteArray writePlayerInfo(const PlayerInfo &pinfo) const;
protected:
  QVariant toVariant(const PlayerInfo &pinfo) const;
  QVariant toVariant(const Player &player) const;
  QVariant toVariant(const QList<InventoryItem> &items) const;
  QVariant toVariant(const InventoryItem &item) const;
};

#endif // PLAYERINFOJSON_H
