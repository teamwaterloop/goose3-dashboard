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

namespace wloop {

class Data
{
public:
    Data();

    void update(const QString& message);

    int acceleration();
    int distance();
    int velocity();
    int propulsionTemp();
    int brakingTemp();
    int motherboardTemp();
    int podState();
    int timeSinceStart();

private:
    int _velocity;
    int _distance;
    int _acceleration;
    int _propulsionTemp;
    int _brakingTemp;
    int _motherboardTemp;
    int _podState;
};

} // namespace wloop

#endif // WLOOP_DATA_H
