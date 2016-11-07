#include "playerinforeader.h"
#include <QCoreApplication>
#include <QFile>
#include <QtDebug>

int main(int argc, char **argv) {
    QCoreApplication app(argc, argv);
    QStringList args = app.arguments();
    args.removeFirst(); // remove application name
    QFile file(args.isEmpty() ? "playerinfo.xml" : args.at(0));
    file.open(QFile::ReadOnly|QFile::Text);
    PlayerInfoReader reader(&file);
    if(reader.read()) {
        PlayerInfo playerInfo = reader.result();
        qDebug() << "Count:" << playerInfo.players.count();
        qDebug() << "Size of inventory:" << playerInfo.players.first().inventory.size();
        qDebug() << "Room: " << playerInfo.players.first().location << playerInfo.players.first().position;
    }
    return 0;
}
