/**
  Author: Jashan Shewakramani
  Description:
    label + sub-label to display speed acceleration etc.
  */
import QtQuick 2.0

Rectangle {
    id: root
    color: 'transparent'
    property alias dataText: mainLabel.text
    property alias dataSize: mainLabel.font.pixelSize
    property alias labelSize: subLabel.font.pixelSize
    property alias labelText: subLabel.text
    property bool subLabelOnTop: false

    width: mainLabel.width
    height: mainLabel.height + subLabel.height

    Text {
        id: mainLabel
        text: "197"
        font.weight: Font.Bold
        font.letterSpacing: 0
        font.wordSpacing: 0
        horizontalAlignment: Text.AlignHCenter
        font.family: 'Open Sans'
        font.pixelSize: 64
        color: 'white'
        anchors.top:
            if (subLabelOnTop) subLabel.bottom;
            else root.top;
        anchors.topMargin:
            if (subLabelOnTop) -labelSize/2;
            else 0;
    }

    Text {
        id: subLabel
        text: 'kph'
        font.family: 'Open Sans'
        font.pixelSize: 18 / 64 * dataSize
        color: 'white'
        anchors.top:
            if (subLabelOnTop) root.top;
            else mainLabel.bottom;
        anchors.topMargin:
            if (!subLabelOnTop) -font.pixelSize;
            else 0;
        anchors.horizontalCenter: mainLabel.horizontalCenter
    }
}
