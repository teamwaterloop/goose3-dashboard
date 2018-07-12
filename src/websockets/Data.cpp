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
#include <QDateTime>
#include <QVariant>
#include <QtWebSockets/QtWebSockets>

namespace wloop {

Data::Data(const QObject *rootObject, Logger *log)
{
    _root = rootObject;
    _log = log;
    _time = 0;
    _name = 0;
    _velocity = 0;
    _distance = 0;
    _acceleration = 0;
    _propulsionTemp = 0;
    _brakingTemp = 0;
    _motherboardTemp = 0;
    _podState = "IDLE";
    _lev = 0;
    _mag_speed_l = 0;
    _mag_speed_r = 0;
    _fr_wheel = 0;
}

//Data::Data(QObject *parent) :
//    QObject(parent),
//    _time(0),
//    _type("none"),
//    _name(0),
//    _data(0),
//    _velocity(0),
//    _distance(0),
//    _acceleration(0),
//    _propulsionTemp(0),
//    _brakingTemp(0),
//    _motherboardTemp(0),
//    _podState("IDLE"),
//    _lev(false),
//    _mag_speed_l(0),
//    _mag_speed_r(0),
//    _fr_wheel(0)
//{
//}

void Data::update(const QString& str)
{
    qDebug() << str;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(str.toUtf8());
    QJsonObject jsonObject = jsonDoc.object();

    _timesinceepoch = QDateTime::currentMSecsSinceEpoch();
    _time = jsonObject.value("time").toInt();
    _type = jsonObject.value("type").toString();
    _name = jsonObject.value("name").toInt();
    //QJsonArray _data = {jsonObject.value("Data1"), jsonObject.value("Data2"), jsonObject.value("Data3")};
    QJsonArray _data = jsonObject.value("data").toArray();

    qDebug() << _timesinceepoch;
    qDebug() << _time;
    qDebug() << _type;
    qDebug() << _name;
    qDebug() << _data;

    QString text;
    text = QString("%1, %2, %3, %4, %5, %6, %7").arg(_timesinceepoch).arg(_time).arg(_type).arg(_name).arg(_data.at(0).toDouble());//.arg(_data.at(1).toDouble()).arg(_data.at(2).toDouble());
    //text.sprintf("%lld, %d, %s, %d, %d, %d, %d", _time, _type, _name, _data.at(0).toInt(), _data.at(1).toInt(), _data.at(2).toInt());
    _log->write(text);

    if (_name == 0) {
        //_mag_speed_l = _mag_speed_r = average(_data.at(0).toDouble(), _data.at(1).toDouble(), _data.at(2).toDouble());
        _mag_speed_l = _mag_speed_r = _data.at(0).toDouble();
        sendSignals(_mag_speed_r, _mag_speed_l);
    } else if (_name == 1) {
        //_fr_wheel = average(_data.at(0).toDouble(), _data.at(1).toDouble(), _data.at(2).toDouble());
        _fr_wheel = _data.at(0).toDouble();
        sendSignals(_fr_wheel);
    } else if (_name == 2) {
        _lev = _data.at(0).toBool();
        emit levChangedSignal();
    } else {
        qDebug() << "Unknown sensor data";
    }
}

void Data::sendSignals(double magr, double magl)
{
    QObject *magGaugeLObject = _root->findChild<QObject *>("leftMagWheelGauge");
    QObject *magGaugeRObject = _root->findChild<QObject *>("rightMagWheelGauge");
    if (magGaugeLObject && magGaugeRObject){
        magGaugeLObject->setProperty("value", magl);
        magGaugeRObject->setProperty("value", magr);
    }
}

void Data::sendSignals(double fric_speed)
{
    QObject *frGaugeObject = _root->findChild<QObject *>("fricGauge");
    if(frGaugeObject) {
        frGaugeObject->setProperty("value", fric_speed);
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
