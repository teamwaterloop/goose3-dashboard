#include "Commands.h"
#include <QHash>
#include <QDateTime>
#include <QDebug>

namespace wloop {

Commands::Commands(WSSClient &client) :
    _client(client)
{
    _hash["magwheel_right"] = 0;
    _hash["magwheel_left"] = 1;
    _hash["drivetrain"] = 2;
    _hash["levitation"] = 3;
}

void Commands::levChanged(const QVariant &v) {
    // _lev = v.toBool();
    qDebug() << "Levitation changed to: "<< v.toString();
    sendCommand("levitation", v);
}

void Commands::frDriveChanged(const QVariant &v) {
    //_frdrive_speed = v.toDouble();
    qDebug() << "Friction Drive changed to: "<< v.toString();
    sendCommand("fr_drive", v.toDouble());
}

void Commands::magWheelChanged(const QVariant &v) {
    //_magwheel_speed = v.toDouble();
    qDebug() << "Mag Wheel Speed changed to: "<< v.toString();
    sendCommand("mag_speed", v.toDouble());
}


bool Commands::sendCommand(const QString cmd_type, const QVariant v) {
    QJsonArray dataArray = {(int)v.toBool(), 0, 0};
    QJsonObject commandObject
    {
        {"time", QDateTime::currentMSecsSinceEpoch()},
        {"type", "command"},
        {"name", _hash[cmd_type]},
        {"data", dataArray}
    };

    qDebug() << commandObject;

    return _client.sendMessage(QJsonDocument(commandObject).toBinaryData());
}

} //namespace wloop
