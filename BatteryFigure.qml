/**
  Author: Jashan S. Shewakramani
  Description:
    battery figure with adjustable charge level
    */
import QtQuick 2.9

Item {
    property double chargeLevel: 0.73 // between 0 and 1
    id: root
    Rectangle {
        id: outerRect
        width: 42
        height: 18
        color: 'transparent'
        border.color: '#979797'
        border.width: 1
    }

    Rectangle {
        id: innerRect
        width: chargeLevel * outerRect.width
        height: outerRect.height
    }

    Rectangle {
        id: tipRect
        anchors.left: outerRect.right
        anchors.verticalCenter: outerRect.verticalCenter
        width: 3
        height: outerRect.height / 2
        color: 'white'
    }
}
