import QtQuick 2.7
import QtQuick.Controls 2.1
import QtQuick.Controls.Material 2.1
import QtQuick.Extras 1.4
import QtQuick.Layouts 1.3

ApplicationWindow {
    id: mainWindow
    width: 1280
    height: 800
    color: "#000000"
    title: "Goose 2 Showcase "
    visible: true
    //visibility: "Maximized"

    Shortcut {
        context: Qt.ApplicationShortcut
        sequence: "Ctrl+Q"
        onActivated: {
            Qt.quit()
        }
    }

    Frame {
        id: frame
        width: 1280
        height: 800
        visible: true
        anchors.top: mainWindow.top
        spacing: 0

        ColumnLayout {
            x: 500
            y: 78
            anchors.verticalCenterOffset: -38
            anchors.horizontalCenterOffset: -137
            anchors.centerIn: parent
            spacing: 50

            ColumnLayout {
                CircularGauge {
                    id: leftMagWheelGauge
                    objectName: "leftMagWheelGauge"
                    value: maglval
                    anchors.centerIn: parent
                    property double maglval: 0.0
                }
                Label {
                    anchors.horizontalCenter: parent.horizontalCenter
                    text: "Left Mag Wheel"
                    font.pixelSize: 20
                }
            }

            ColumnLayout {
                CircularGauge {
                    id: rightMagWheelGauge
                    objectName: "rightMagWheelGauge"
                    value: magrval
                    anchors.centerIn: parent
                    property double magrval: 0.0
                }
                Label {
                    anchors.horizontalCenter: parent.horizontalCenter
                    text: "Right Mag Wheel"
                    font.pixelSize: 20
                }
            }

        }

        ColumnLayout {
            x: 32
            y: 233
            width: 298
            height: 309
            scale: 1
            CircularGauge {
                id: fricGauge
                objectName: "fricGauge"
                value: fricval
                anchors.horizontalCenter: parent.rightMargin
                property double fricval: 0.0
                x: 100
                scale: 1
                enabled: true
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.columnSpan: 5
            }
            Label {
                x: 100
                y: 225
                anchors.horizontalCenter: parent.horizontalCenter
                text: "Friction Wheel"
                font.pixelSize: 20
            }
        }

        RowLayout {
            x: 335
            y: 349
            anchors.verticalCenterOffset: 1
            anchors.horizontalCenterOffset: 335
            transformOrigin: Item.Center
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            anchors.centerIn: parent
            spacing: 50

            ColumnLayout {
                Switch {
                    id: levSwitch
                    objectName: "levSwitch"
                    anchors.horizontalCenter: parent.horizontalCenter
                    signal levitationChanged(var check)
                    checked: false
                    onCheckedChanged: levSwitch.levitationChanged(checked)
                }
                Label {
                    anchors.horizontalCenter: parent.horizontalCenter
                    text: "Levitation"
                    font.pixelSize: 20
                }
            }

            ColumnLayout {
                Slider {
                    id: magWheelsSlider
                    objectName: "magWheelsSlider"
                    anchors.horizontalCenter: parent.horizontalCenter
                    signal magWheelChanged(var val)
                    onValueChanged: magWheelsSlider.magWheelChanged(value)
                    value: 0.0
                    stepSize: 0.05

                }
                Label {
                    anchors.horizontalCenter: parent.horizontalCenter
                    text: "Magnetic Wheels"
                    font.pixelSize: 20
                }
            }

            ColumnLayout {
                Slider {
                    id: fricWheelsSlider
                    objectName: "fricWheelSlider"
                    signal fricWheelChanged(var val)
                    onValueChanged: fricWheelsSlider.fricWheelChanged(value)
                    value: 0.0
                    anchors.horizontalCenter: parent.horizontalCenter
                    stepSize: 0.05

                }
                Label {
                    anchors.horizontalCenter: parent.horizontalCenter
                    text: "Friction Wheels"
                    font.pixelSize: 20
                }
            }
        }

        ColumnLayout {
            x: 583
            y: 697
            anchors.horizontalCenterOffset: 1
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 0

            Image {
                id: logo
                x: 2
                width: 84
                height: 50
                Layout.fillHeight: false
                Layout.fillWidth: false
                anchors.horizontalCenter: parent.horizontalCenter
                source: "qrc:///res/Icon_Yellow.svg"
                Layout.preferredHeight: 40
                Layout.preferredWidth: 60
            }

            Label {
                width: 70
                height: 26
                text: "Waterloop UI \n      ver 1.2"
            }

        }

    }

}
