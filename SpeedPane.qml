/**
  Author: Jashan S. Shewakramani
  Description:
    This the the left-most speed pane. It shows the speed, acceleration
    along with pod visualizations and other very important things.
  */
import QtQuick 2.0

Rectangle {
    id: root
    color: "#4A4A4A"

    // design coordinates; lets us use relative positioning
    property int intendedRootWidth: 550;
    property int intendedRootHeight: 960;

    property int lineMarginSize: 30
    property int lineThickness: 2
    property color lineColor: "#9B9B9B"

    // draw separating lines
    SeparatingLine {
        x: lineMarginSize
        y: 170 / intendedRootHeight * root.height
        length: root.width - (2 * lineMarginSize)
    }

    SeparatingLine {
        x: lineMarginSize
        y: 668 / intendedRootHeight * root.height
        width: root.width - (2 * lineMarginSize)
    }

    SeparatingLine {
        x: lineMarginSize
        y: 940 / intendedRootHeight * root.height
        width: root.width - (2 * lineMarginSize)
    }

    // TODO: display speed, max speed, and acceleration here

    // TODO: create sub-components for yaw, pitch and roll dials here

    // TODO: show connection state, emergency stop, systems check here
}
