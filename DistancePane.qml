/**
  Author: Jashan S. Shewakramani
  Description:
    Bottom-most distance pane in the pod
    Visualizes pod distance in view and shows upcoming states
  */
import QtQuick 2.0

Rectangle {
    id: root
    color: "#4A4A4A"

    // how far has the pod gone in the tube (in metres)
    property int podDistance: 0;
    property int trackLength: 2000;

    /**
      TODO: Draw a line and create labels for the pod states:
        OFF, ARMING, ARMED, ACCELERATING, COASTING, BRAKING, STOP

        Also import a drawing of the pod to animate in the tube
    */
}
