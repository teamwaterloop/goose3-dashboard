#include "Commands.h"

namespace wloop {

Commands::Commands(WSSClient &socket) :
    _socket(socket)
{
    _frdrive_speed = 0;
    _magwheel_speed = 0;
    _lev = false;
}

bool Commands::sendCommands(bool levitation, int mag_speed, int fr_speed) {
    _lev = levitation;
    _magwheel_speed = mag_speed;
    _frdrive_speed = fr_speed;
    QJsonObject commandObject;
    commandObject.insert("levitation", QJsonValue::fromVariant(_lev));
    commandObject.insert("mag_speed", QJsonValue::fromVariant(_magwheel_speed));
    commandObject.insert("fr_speed", QJsonValue::fromVariant(_frdrive_speed));

    QJsonDocument cmd(commandObject);
    bool sent = _socket.sendMessage(cmd.toJson());
    return sent;

}

} //namespace wloop

