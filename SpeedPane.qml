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
        id: line1
        x: lineMarginSize
        y: 170 / intendedRootHeight * root.height
        length: root.width - (2 * lineMarginSize)
    }

    SeparatingLine {
        id: line2
        x: lineMarginSize
        y: 668 / intendedRootHeight * root.height
        width: root.width - (2 * lineMarginSize)
    }

    SeparatingLine {
        id: line3
        x: lineMarginSize
        y: 940 / intendedRootHeight * root.height
        width: root.width - (2 * lineMarginSize)
    }

    Rectangle {
        id: topSection
        anchors.top: parent.top
        anchors.left: line1.left
        anchors.right: line1.right
        anchors.bottom: line1.top
        color: root.color

        DataLabel {
            id: speedLabel
            anchors.horizontalCenter: parent.horizontalCenter
            dataText: '197'
            labelText: 'kph'
            size: 64
        }

        DataLabel {
            id: accelerationLabel
            anchors.right: parent.right
            anchors.rightMargin: 5
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 0
            dataText: '18.3'
            labelText: 'm/s²'
            labelSize: 12
            size: 32
        }

        DataLabel {
            id: maxSpeedLabel
            anchors.left: parent.left
            anchors.leftMargin: 5
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 0
            dataText: '243'
            labelText: 'max speed'
            labelSize: 12
            size: 32
        }


    }

    // TODO: create sub-components for yaw, pitch and roll dials here

    // TODO: show connection state, emergency stop, systems check here
}
