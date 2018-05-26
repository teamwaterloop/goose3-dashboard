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
#include <QtWebSockets/QtWebSockets>

namespace wloop {

Data::Data() :
    _velocity(0),
    _distance(0),
    _acceleration(0),
    _propulsionTemp(0),
    _brakingTemp(0),
    _motherboardTemp(0),
    _podState(0)
{
}

void Data::update(const QString& str)
{
    QJsonDocument jsonDoc = QJsonDocument::fromJson(str.toUtf8());
    QJsonObject jsonObject = jsonDoc.object();
    _velocity = jsonObject["velocity"].toInt();
    _distance = jsonObject["distance"].toInt();
    _acceleration = jsonObject["acceleration"].toInt();
    _propulsionTemp = jsonObject["propulsion_temp"].toInt();
    _brakingTemp = jsonObject["braking_temp"].toInt();
    _motherboardTemp = jsonObject["motherboard_temp"].toInt();
    _podState = jsonObject["pod_state"].toInt();
    //_timeSinceStart = jsonObject["time_since_start"].toInt();
}

int Data::acceleration()
{
    return _acceleration;
}

int Data::distance()
{
    return _distance;
}

int Data::velocity()
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
int Data::podState()
{
    return _podState;
}

} // namespace wloop
