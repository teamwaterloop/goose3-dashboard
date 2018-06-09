#include "Commands.h"
#include <QDebug>

namespace wloop {

Commands::Commands(WSSClient &client) :
    _client(client)
{
    _frdrive_speed = 0;
    _magwheel_speed = 0;
    _lev = false;
}

void Commands::levChanged(const QVariant &v) {
    _lev = v.toBool();
    qDebug() << "Levitation changed to: "<< v.toString();
    sendCommand("levitation", v.toBool());
}

void Commands::frDriveChanged(const QVariant &v) {
    _frdrive_speed = v.toDouble();
    qDebug() << "Friction Drive changed to: "<< v.toString();
    sendCommand("fr_drive", v.toDouble());
}

void Commands::magWheelChanged(const QVariant &v) {
    _magwheel_speed = v.toDouble();
    qDebug() << "Mag Wheel Speed changed to: "<< v.toString();
    sendCommand("mag_speed", v.toDouble());
}


bool Commands::sendCommand(const QString cmd_type, const QVariant v) {
    QJsonObject commandObject;
    commandObject.insert(cmd_type, QJsonValue::fromVariant(v));

    QJsonDocument cmd(commandObject);
    bool sent = Commands::_client.sendMessage(cmd.toJson());
    return sent;
}

} //namespace wloop

