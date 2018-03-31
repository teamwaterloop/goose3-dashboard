/**
  Author: Jashan S. Shewakramani
  Description: Reusable Label component with common styles
  */
import QtQuick 2.9

Text {
    id: root
    font.family: 'Open Sans'
    property string label: 'OFF'
    property int size: 12
    text: label
    color: 'white'
    font.pixelSize: size
}
