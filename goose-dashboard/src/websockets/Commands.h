#ifndef WLOOP_COMMANDS_H
#define WLOOP_COMMANDS_H

#include "WSSClient.h"
#include "logger.h"

#include <QString>
#include <QJsonObject>
#include <QJsonDocument>
#include <QDebug>
#include <QObject>


namespace wloop {

class Commands : public QObject
{
    Q_OBJECT

public:
    explicit Commands(WSSClient &socket, Logger &log);

public slots:
    void levChanged(const QVariant &v);
    void frDriveChanged(const QVariant &v);
    void magWheelChanged(const QVariant &v);


private:
    //    double _frdrive_speed;
    //    double _magwheel_speed;
    //    bool _lev;
    WSSClient &_client;
    Logger &_log;
    //Data &_data;

    bool sendCommand(QString cmd_type, const QVariant v);

};

} //namespace wloop

#endif // COMMANDS_H
