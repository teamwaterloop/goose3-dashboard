/*****************************************************
 * This file is part of Waterloop                    *
 * Copyright 2018 Mohammed Nafees <hello@mnafees.me> *
 *                                                   *
 * src/websockets/Data.cpp                           *
 *****************************************************/

// Self
#include "Data.h"

// Qt
#include <QJsonDocument>
#include <QJsonObject>
#include <QList>
#include <QString>
#include <QObject>
#include <QtWebSockets/QtWebSockets>

namespace wloop {

Data::Data() :
    _velocity(0),
    _distance(0),
    _acceleration(0),
    _propulsionTemp(0),
    _brakingTemp(0),
    _motherboardTemp(0),
    _podState("IDLE"),
    _lev(false),
    _mag_speed_l(0),
    _mag_speed_r(0),
    _fr_wheel(0)
{
}

void Data::update(const QString& str)
{
    QJsonDocument jsonDoc = QJsonDocument::fromJson(str.toUtf8());
    QJsonObject jsonObject = jsonDoc.object();
    _velocity = jsonObject["velocity"].toDouble();
    _distance = jsonObject["distance"].toDouble();
    _acceleration = jsonObject["acceleration"].toDouble();
    _propulsionTemp = jsonObject["propulsion_temp"].toInt();
    _brakingTemp = jsonObject["braking_temp"].toInt();
    _motherboardTemp = jsonObject["motherboard_temp"].toInt();
    _podState = jsonObject["pod_state"].toString();

    _lev = jsonObject["levitation"].toBool();
    _mag_speed_l = jsonObject["mag_l"].toDouble();
    _mag_speed_r = jsonObject["mag_r"].toDouble();
    _fr_wheel = jsonObject["fr_drive"].toDouble();
    //_timeSinceStart = jsonObject["time_since_start"].toInt();

    emit levChangedSignal();
    emit magSpeedRChangedSignal();
    emit magSpeedLChangedSignal();
    emit frWheelChangedSignal();
}

double Data::acceleration()
{
    return _acceleration;
}

double Data::distance()
{
    return _distance;
}

double Data::velocity()
{
    return _velocity;
}

int Data::propulsionTemp()
{
    return _propulsionTemp;
}

int Data::brakingTemp()
{
    return _brakingTemp;
}

int Data::motherboardTemp()
{
    return _motherboardTemp;
}
QString Data::podState()
{
    return _podState;
}

bool Data::lev()
{
    return _lev;
}
double Data::mag_speed_l()
{
    return _mag_speed_l;
}
double Data::mag_speed_r()
{
    return _mag_speed_r;
}
double Data::fr_wheel()
{
    return _fr_wheel;
}

} // namespace wloop
