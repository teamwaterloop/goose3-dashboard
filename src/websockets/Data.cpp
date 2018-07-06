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

Data::Data(QObject *parent) :
    QObject(parent),
    _time(0),
    _type("none"),
    _name(0),
//    _data(0),
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
    qDebug() << str;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(str.toUtf8());
    QJsonObject jsonObject = jsonDoc.object();

    _time = jsonObject.value("time").toInt();
    _type = jsonObject.value("type").toString();
    _name = jsonObject.value("name").toInt();
    QJsonArray _data = jsonObject.value("data").toArray();

    qDebug() << _time;
    qDebug() << _type;
    qDebug() << _name;
    qDebug() << _data;

    if (_name == 0) {
        _mag_speed_l = _mag_speed_r = average(_data.at(0).toDouble(), _data.at(1).toDouble(), _data.at(2).toDouble());
        emit magSpeedChangedSignal();
    } else if (_name == 1) {
        _fr_wheel = average(_data.at(0).toDouble(), _data.at(1).toDouble(), _data.at(2).toDouble());
        emit frWheelChangedSignal();
    } else if (_name == 2) {
        _lev = _data.at(0).toBool();
        emit levChangedSignal();
    } else {
        qDebug() << "Unknown sensor data";
    }
}

double Data::average(double x, double y, double z) {
    return (x+y+z)/3;
}

int Data::time() {
    return _time;
}
QString Data::type() {
    return _type;
}
int Data::name() {
    return _name;
}
//double Data::data() {
//    return _data;
//}
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
