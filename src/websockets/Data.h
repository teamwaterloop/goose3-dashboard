/*****************************************************
 * This file is part of Waterloop                    *
 * Copyright 2018 Mohammed Nafees <hello@mnafees.me> *
 *                                                   *
 * src/websockets/Data.h                             *
 *****************************************************/

#ifndef WLOOP_DATA_H
#define WLOOP_DATA_H

//Qt
#include <QString>
#include <QObject>
#include "logger.h"

namespace wloop {

class Data : public QObject
{
    Q_OBJECT

public:
    explicit Data(const QObject *rootObject, Logger *log);

    void update(const QString& message);

    int time();
    QString type();
    int name();
    double data();

    double acceleration();
    double distance();
    double velocity();
    int propulsionTemp();
    int brakingTemp();
    int motherboardTemp();
    QString podState();
    int timeSinceStart();

    //Added levitation, mag wheel speed left and right and friction drive speed for goose2 showcase event
    bool lev();
    double mag_speed_l();
    double mag_speed_r();
    double fr_wheel();

signals:
    void velocityChangedSignal();
    void distanceChangedSignal();
    void accelerationChangedSignal();
    void propulsionTempChangedSignal();
    void brakingTempChangedSignal();
    void motherboardTempChangedSignal();
    void podStateChangedSignal();
    void levChangedSignal();
    //void magSpeedLChangedSignal(QVariant mag_l);
    //void magSpeedRChangedSignal(QVariant mag_r);
    void frWheelChangedSignal();

private:
    const QObject *_root;
    Logger *_log;

    qint64 _timesinceepoch;
    int _time;
    QString _type;
    int _name;
    double _data1;
    double _data2;
    double _data3;
    //QJsonArray _data;
    double _velocity;
    double _distance;
    double _acceleration;
    int _propulsionTemp;
    int _brakingTemp;
    int _motherboardTemp;
    QString _podState;
    bool _lev;
    double _mag_speed_l;
    double _mag_speed_r;
    double _fr_wheel;

    void sendSignals(double, double);
    void sendSignals(double);

    double average(double x, double y, double z);
};

} // namespace wloop

#endif // WLOOP_DATA_H
