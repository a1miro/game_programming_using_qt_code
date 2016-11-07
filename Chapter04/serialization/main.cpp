#include <QDataStream>
#include <QPoint>
#include <QString>
#include <QBuffer>
#include <QtDebug>

struct Player {
  QString name;
  qint64 experience;
  QPoint position;
  QChar direction;
};

QDataStream& operator<<(QDataStream &stream, const Player &p) {
  stream << p.name;
  stream << p.experience;
  stream << p.position;
  stream << p.direction;
  return stream;
}

QDataStream& operator>>(QDataStream &stream, Player &p) {
  stream >> p.name;
  stream >> p.experience;
  stream >> p.position;
  stream >> p.direction;
  return stream;
}

int main(int, char**) {
  Player p;
  p.name = "John Doe";
  p.experience = 1234;
  p.position = QPoint(1,2);
  p.direction = 'n';

  QBuffer buffer;
  buffer.open(QIODevice::WriteOnly);
  QDataStream s(&buffer);
  s << p;
  qDebug() << buffer.data().toHex();
  return 0;
}
