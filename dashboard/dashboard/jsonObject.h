#ifndef JSONOBJECT_H
#define JSONOBJECT_H

#include <QString>

class jsonObject : public QString
{
    QJsonObject jsonObject;
    int velocity;
    int distance;
    int acceleration;
    int propulsion_temp;
    int braking_temp;
    int motherboard_temp;
    int pod_state;
    int time_since_start;

public:
    jsonObject(QString str);
    ~jsonObject();
    updateModel();
};

#endif // JSONOBJECT_H
