#include "Commands.h"
#include <QHash>
#include <QDateTime>
#include <QDebug>

namespace wloop {

Commands::Commands(WSSClient &client, Logger &log) :
    _client(client),
    _log(log)
{
    _hash["mag_speed"] = 0;
    _hash["fr_drive"] = 1;
    _hash["levitation"] = 2;
}

void Commands::levChanged(const QVariant &v) {
    qDebug() << "Levitation changed to: "<< v.toString();
    sendCommand("levitation", v);
}

void Commands::frDriveChanged(const QVariant &v) {
    qDebug() << "Friction Drive changed to: "<< v.toString();
    sendCommand("fr_drive", v.toDouble()*100);
}

void Commands::magWheelChanged(const QVariant &v) {
    qDebug() << "Mag Wheel Speed changed to: "<< v.toString();
    sendCommand("mag_speed", v.toDouble()*100);
}


bool Commands::sendCommand(const QString cmd_type, const QVariant v) {
    QJsonArray dataArray = {v.toInt(), 0, 0};
    qint64 time = QDateTime::currentMSecsSinceEpoch();

    QJsonObject commandObject
    {
        {"time", time},
        {"PacketType", "command"},
        {"PacketId", _hash[cmd_type]},
        {"Data1", dataArray.at(0)},
        {"Data2", dataArray.at(1)},
        {"Data3", dataArray.at(2)}
    };

    QJsonDocument cmd_doc(commandObject);
    int name = commandObject.value("name").toInt();

    QString text;
    text.sprintf("%lld, %s, %d, %d, %d, %d", time, "command", name, dataArray.at(0).toInt(), dataArray.at(1).toInt(), dataArray.at(2).toInt());
    _log.write(text);
    qDebug() << text;

    return _client.sendMessage(cmd_doc.toJson());
}

} //namespace wloop
