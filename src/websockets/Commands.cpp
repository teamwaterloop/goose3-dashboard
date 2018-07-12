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
        {"timesincespoch", time},
        {"type", "command"},
        {"name", _hash[cmd_type]},
        {"data", dataArray},
        //{"Data2", dataArray.at(1)},
        //{"Data3", dataArray.at(2)}
    };

    QJsonDocument cmd_doc(commandObject);

    QString text;
    text = QString("%1, %2, %3, %4, %5, %6, %7").arg(time).arg("0").arg("command").arg(_hash[cmd_type]).arg(dataArray.at(0).toDouble());//.arg(_data.at(1).toDouble()).arg(_data.at(2).toDouble());
    _log.write(text);
    qDebug() << text;

    return _client.sendMessage(cmd_doc.toJson());
}

} //namespace wloop
