#include <jsonObject.h>
#include<QJsonDocument>
#include<QJsonObject>
#include <QList>
#include <QString>
#include <QtWebSockets/QtWebSockets>


jsonData::jsonData(QString str) {
    QJsonDocument jsonDoc = QJsonDocument::fromJson(str.toUtf8());
    QJsonObject jsonObject = jsonDoc.object();
    velocity = jsonObject["velocity"].toInt();
    distance = jsonObject["distance"].toInt();
    acceleration = jsonObject["acceleration"].toInt();
    propulsion_temp = jsonObject["propulsion_temp"].toInt();
    braking_temp = jsonObject["braking_temp"].toInt();
    motherboard_temp = jsonObject["motherboard_temp"].toInt();
    pod_state = jsonObject["pod_state"].toInt();
    time_since_start = jsonObject["time_since_start"].toInt();
}

void jsonData::updateModel(QString str) {
    QJsonDocument jsonDoc = QJsonDocument::fromJson(str.toUtf8());
    QJsonObject jsonObject = jsonDoc.object();
    velocity = jsonObject["velocity"].toInt();
    distance = jsonObject["distance"].toInt();
    acceleration = jsonObject["acceleration"].toInt();
    propulsion_temp = jsonObject["propulsion_temp"].toInt();
    braking_temp = jsonObject["braking_temp"].toInt();
    motherboard_temp = jsonObject["motherboard_temp"].toInt();
    pod_state = jsonObject["pod_state"].toInt();
    time_since_start = jsonObject["time_since_start"].toInt();
}

jsonData::~jsonData(){}
