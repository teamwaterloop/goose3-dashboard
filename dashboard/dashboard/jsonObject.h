#ifndef JSONOBJECT_H
#define JSONOBJECT_H

#include <QString>
#include <QJsonObject>


class jsonData;

class jsonData
{
    QJsonObject data;
    int velocity;
    int distance;
    int acceleration;
    int propulsion_temp;
    int braking_temp;
    int motherboard_temp;
    int pod_state;
    int time_since_start;

public:
    jsonData(QString str);
    ~jsonData();
    void updateModel(QString message);
};

#endif // JSONOBJECT_H
