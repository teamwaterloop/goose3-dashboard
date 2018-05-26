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
    Data() = default;
    Data(const QString& message);

    void update(const QString& message);

private:
    int _velocity;
    int _distance;
    int _acceleration;
    int _propulsionTemp;
    int _brakingTemp;
    int _motherboardTemp;
    int _podState;
    int _timeSinceStart;
};

} // namespace wloop

#endif // WLOOP_DATA_H
