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

Data::Data(const QString& message)
{
    update(message);
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
    _timeSinceStart = jsonObject["time_since_start"].toInt();
}

} // namespace wloop
