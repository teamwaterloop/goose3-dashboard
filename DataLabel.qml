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
    property alias size: mainLabel.font.pixelSize
    property alias labelSize: subLabel.font.pixelSize
    property alias labelText: subLabel.text

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
    }

    Text {
        id: subLabel
        width: contentWidth
        height: contentHeight
        text: 'kph'
        font.family: 'Open Sans'
        font.pixelSize: 18 / 64 * size
        color: 'white'
        anchors.top: mainLabel.bottom
        anchors.topMargin: - font.pixelSize
        anchors.horizontalCenter: mainLabel.horizontalCenter
    }
}
