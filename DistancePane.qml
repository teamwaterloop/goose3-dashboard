/**
  Author: Jashan S. Shewakramani
  Description:
    Bottom-most distance pane in the pod
    Visualizes pod distance in view and shows upcoming states
  */
import QtQuick 2.9

Rectangle {
    id: root
    color: "#4A4A4A"

    // how far has the pod gone in the tube (in metres)
    property int podDistance: 0;
    property int trackLength: 2000;

    property int intendedWidth: 1920
    property int intendedHeight: 120

    // TODO: replace with actual pod image
    Rectangle {
        id: podFigure
        color: '#F3F3F3'
        border.width: 1
        border.color: '#979797'
        anchors.left: distanceSeparatingLine.left
        anchors.top: parent.top
        anchors.topMargin: 25 / intendedHeight * root.height
        width: 120 / intendedWidth * root.width
        height: 37 / intendedHeight * root.height
        radius: 7
    }


    SeparatingLine {
        id: distanceSeparatingLine
        anchors.top: podFigure.bottom
        anchors.topMargin: 10 / intendedHeight * root.height
        anchors.left: parent.left
        anchors.leftMargin: lineMarginSize
        anchors.right: parent.right
        anchors.rightMargin: lineMarginSize
    }

    Label {
        id: offLabel
        anchors.top: distanceSeparatingLine.bottom
        anchors.topMargin: 10 / intendedHeight * root.height
        anchors.left: distanceSeparatingLine.left
        text: 'OFF'
        size: 14
    }

    Label {
        anchors.verticalCenter: offLabel.verticalCenter
        text: 'ARMING'
        size: 14
        x: 127 / intendedWidth * root.width
    }

    Label {
        anchors.verticalCenter: offLabel.verticalCenter
        text: 'ARMED'
        size: 14
        x: 283 / intendedWidth * root.width
    }

    Label {
        anchors.verticalCenter: offLabel.verticalCenter
        text: 'ACCELERATING'
        size: 14
        x: 652 / intendedWidth * root.width
    }

    Label {
        anchors.verticalCenter: offLabel.verticalCenter
        text: 'COASTING'
        size: 14
        x: 1157 / intendedWidth * root.width
    }

    Label {
        anchors.verticalCenter: offLabel.verticalCenter
        text: 'BRAKING'
        size: 14
        x: 1583 / intendedWidth * root.width
    }

    Label {
        anchors.verticalCenter: offLabel.verticalCenter
        text: 'STOP'
        anchors.right: distanceSeparatingLine.right
        size: 14
    }
}
