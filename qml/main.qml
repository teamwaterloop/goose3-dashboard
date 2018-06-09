import QtQuick 2.7
import QtQuick.Controls 2.1
import QtQuick.Controls.Material 2.1
import QtQuick.Extras 1.4
import QtQuick.Layouts 1.3

ApplicationWindow {
    id: mainWindow
    visible: true
    visibility: "Maximized"

    Shortcut {
        context: Qt.ApplicationShortcut
        sequence: "Ctrl+Q"
        onActivated: {
            Qt.quit()
        }
    }

    Frame {
        anchors.top: mainWindow.top
        width: mainWindow.width
        height: mainWindow.height
        spacing: 0

        ColumnLayout {
            anchors.fill: parent

            ColumnLayout {
                anchors.centerIn: parent
                spacing: 50

                ColumnLayout {
                    CircularGauge {
                        value: accelerating ? maximumValue : 0
                        anchors.centerIn: parent

                        property bool accelerating: false

                        Keys.onSpacePressed: accelerating = true
                        Keys.onReleased: {
                            if (event.key === Qt.Key_Space) {
                                accelerating = false;
                                event.accepted = true;
                            }
                        }

                        Component.onCompleted: forceActiveFocus()

                        Behavior on value {
                            NumberAnimation {
                                duration: 1000
                            }
                        }
                    }
                    Label {
                        anchors.horizontalCenter: parent.horizontalCenter
                        text: "Left Mag Wheel"
                        font.pixelSize: 20
                    }
                }

                ColumnLayout {
                    CircularGauge {
                        value: accelerating ? maximumValue : 0
                        anchors.centerIn: parent

                        property bool accelerating: false

                        Keys.onSpacePressed: accelerating = true
                        Keys.onReleased: {
                            if (event.key === Qt.Key_Space) {
                                accelerating = false;
                                event.accepted = true;
                            }
                        }

                        //Component.onCompleted: forceActiveFocus()

                        Behavior on value {
                            NumberAnimation {
                                duration: 1000
                            }
                        }
                    }
                    Label {
                        anchors.horizontalCenter: parent.horizontalCenter
                        text: "Right Mag Wheel"
                        font.pixelSize: 20
                    }
                }

            }

            RowLayout {
                anchors.centerIn: parent
                spacing: 50

                Item {
                    Layout.fillWidth: true
                }

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
                        anchors.horizontalCenter: parent.horizontalCenter
                        value: 0.0
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
                        value: 0.0
                        anchors.horizontalCenter: parent.horizontalCenter
                    }
                    Label {
                        anchors.horizontalCenter: parent.horizontalCenter
                        text: "Friction Wheels"
                        font.pixelSize: 20
                    }
                }
            }

            Item {
                Layout.fillHeight: true
            }

            ColumnLayout {
                anchors.horizontalCenter: parent.horizontalCenter

                Image {
                    id: logo
                    anchors.horizontalCenter: parent.horizontalCenter
                    source: "qrc:///res/Icon_Yellow.svg"
                    Layout.preferredHeight: 50
                    Layout.preferredWidth: 84
                }

                Label {
                    text: "Waterloop UI \n      ver 1.2"
                }

            }

        }

    }

}
