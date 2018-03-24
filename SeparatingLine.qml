import QtQuick 2.0

Rectangle {
    id: root
    property alias length: root.width
    property int lineMarginSize: 30
    property int lineThickness: 2
    property color lineColor: "#9B9B9B"

    height: lineThickness
    color: lineColor
}
