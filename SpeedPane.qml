/**
  Author: Jashan S. Shewakramani
  Description:
    This the the left-most speed pane. It shows the speed, acceleration
    along with pod visualizations and other very important things.
  */
import QtQuick 2.9
import QtQuick.Layouts 1.3

Rectangle {
    id: root
    color: "#4A4A4A"

    // design coordinates; lets us use relative positioning
    property int intendedRootWidth: 550;
    property int intendedRootHeight: 960;

    property int lineMarginSize: 30
    property int lineThickness: 2
    property color lineColor: "#9B9B9B"

    property int subLabelSize: 12

    width: intendedRootWidth
    height: intendedRootHeight

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

    // top section for speed, max speed and acceleration
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
            dataSize: 64
        }

        DataLabel {
            id: accelerationLabel
            anchors.right: parent.right
            anchors.rightMargin: 5
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 0
            dataText: '18.3'
            labelText: 'm/s²'
            labelSize: subLabelSize
            dataSize: 32
        }

        DataLabel {
            id: maxSpeedLabel
            anchors.left: parent.left
            anchors.leftMargin: 5
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 0
            dataText: '243'
            labelText: 'max speed'
            labelSize: subLabelSize
            dataSize: 32
        }


    }

    // TODO: create sub-components for yaw, pitch and roll dials here

    // section for connection state, emergency stop, and systems check
    // TODO: fix indenting and spacing
    RowLayout {
        anchors.left: line2.left
        anchors.top: line2.bottom
        anchors.right: line2.right
        anchors.bottom: line3.top
        Layout.alignment: Qt.AlignVCenter

        ColumnLayout {
            id: bottomSection1
            Layout.alignment: Qt.AlignHCenter

            DataLabel {
                subLabelOnTop: true
                dataSize: 26
                property string podState: 'ARMED'
                dataText: podState.toUpperCase()
                labelText: 'state'
                labelSize: 12
                anchors.horizontalCenter: parent.horizontalCenter
            }

            DataLabel {
                subLabelOnTop: true
                dataSize: 16
                property string systemsCheckState: 'NORMAL'
                dataText: systemsCheckState
                labelText: 'systems check'
                labelSize: 12
                anchors.horizontalCenter: parent.horizontalCenter
            }

            Text {
                id: connectionStateLabel
                font.pixelSize: 16
                property string connectionState: 'connected'
                text: connectionState.toUpperCase()
                font.family: 'Open Sans'
                color: 'white'
                anchors.horizontalCenter: parent.horizontalCenter
            }
        }

        ColumnLayout {
            id: bottomSection2
            Layout.alignment: Qt.AlignHCenter

            Rectangle {
                id: stopButton
                border.width: 2
                border.color: '#979797'
                radius: this.height / 2
                color: 'transparent'
                width: 140 / intendedRootWidth * root.width
                height: 70 / intendedRootHeight * root.height

                Text {
                    color: 'white'
                    font.family: 'Open Sans'
                    font.weight: Font.ExtraBold
                    text: 'STOP'
                    anchors.centerIn: parent
                    font.pixelSize: 32
                }
            }

        }
    }
}
