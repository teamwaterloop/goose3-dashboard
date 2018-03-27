import QtQuick 2.0

Text {
    id: root
    font.family: 'Open Sans'
    property string label: 'OFF'
    property int size: 12
    text: label
    color: 'white'
    font.pixelSize: size
}
