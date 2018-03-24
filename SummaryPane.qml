/**
  Author: Jashan S. Shewakramani
  Description:
    Right-most summary pane displaying propulsion,
    brakes, and battery state
  */
import QtQuick 2.0

Rectangle {
    id: root
    color: "#4A4A4A"

    property int intendedHeight: 960

    SeparatingLine {
        x: lineMarginSize
        y: 750 / intendedHeight * root.height
        length: root.width - 2 * lineMarginSize
    }

    /**
      TODO: Display Propolusion Summary Stats
        1. Distance in tube
        2. Drive RPM
        3. Friction Brakes (engaged/disenganged) + temperature
        4. EC Brakes (engaged/disengaged) + temperature
      */

    /**
      TODO: Display Battery Summary State
        1. Primary battery voltage, current, temperature
        2. Secondary battery voltage, current, temperature
      */
}
