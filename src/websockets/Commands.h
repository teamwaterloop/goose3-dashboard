#ifndef WLOOP_COMMANDS_H
#define WLOOP_COMMANDS_H

#include "WSSClient.h"

#include <QString>
#include <QJsonObject>
#include <QJsonDocument>


namespace wloop {

class Commands : public QObject
{
    Q_OBJECT

public:
    explicit Commands(WSSClient &socket);
    bool sendCommands(bool levitation, int mag_speed, int fr_drive);

private:
    int _frdrive_speed;
    int _magwheel_speed;
    bool _lev;
    WSSClient &_socket;

};

} //namespace wloop

#endif // COMMANDS_H
