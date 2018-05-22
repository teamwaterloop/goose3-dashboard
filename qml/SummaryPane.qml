import QtQuick 2.9

Rectangle {
    id: root
    color: "#4A4A4A"

    // dimension properties
    property int intendedWidth: 384
    property int intendedHeight: 960


    // propulsion data
    property int distanceInTube: 923
    property int driveRPM: 3840
    property bool frictionBrakesEngaged: false
    property int frictionBrakesTemperature: 42
    property bool ecBrakesEngaged: true
    property int ecBrakesTemperature: 57

    // battery data
    property double primaryBatteryChargeLevel: 0.43 // between 0 and 1
    property double primaryBatteryVoltage: 47.3
    property double primaryBatteryCurrent: 27.2
    property int primaryBatteryTemperature: 49

    property double secondaryBatteryChargeLevel: 0.85 // between 0 and 1
    property double secondaryBatteryVoltage: 24.1
    property double secondaryBatteryCurrent: 8.3
    property int secondaryBatteryTemperature: 36


    Label {
        id: propulsionSummaryHeading
        text: 'PROPULSION'
        size: 18
        anchors.top: parent.top
        anchors.topMargin: 20 / intendedHeight * root.height
        anchors.left: parent.left
        anchors.leftMargin: 20
        font.weight: Font.Light
    }

    Row {
        id: distanceRow
        anchors.left: propulsionSummaryHeading.left
        anchors.top: propulsionSummaryHeading.bottom
        anchors.topMargin: 20

        Label {
            text: 'Distance'
            size: 14
        }

        Label {
            font.bold: Font.Bold
            text: distanceInTube.toString() + ' m'
            size: 14
            x: 172 / intendedWidth * root.width
        }
    }

    Row {
        id: driveRPMRow
        anchors.left: propulsionSummaryHeading.left
        anchors.top: distanceRow.bottom
        anchors.topMargin: 10

        Label {
            text: 'Drive RPM'
            size: 14
        }

        Label {
            font.bold: Font.Bold
            text: driveRPM.toString()
            size: 14
            x: 172 / intendedWidth * root.width
        }
    }

    Row {
        id: frictionBrakesRow
        anchors.left: propulsionSummaryHeading.left
        anchors.top: driveRPMRow.bottom
        anchors.topMargin: 10

        Label {
            text: 'Friction Brakes'
            size: 14
        }

        Label {
            font.bold: Font.Bold
            text: if (frictionBrakesEngaged) 'ENGAGED'; else 'DISENGAGED';
            size: 14
            x: 172 / intendedWidth * root.width
        }

        Label {
            text: frictionBrakesTemperature.toString() + ' °C'
            size: 14
            x: 306 / intendedWidth * root.width
        }
    }

    Row {
        id: ecBrakesRow
        anchors.left: propulsionSummaryHeading.left
        anchors.top: frictionBrakesRow.bottom
        anchors.topMargin: 10

        Label {
            text: 'EC Brakes'
            size: 14
        }

        Label {
            font.bold: Font.Bold
            text: if (ecBrakesEngaged) 'ENGAGED'; else 'DISENGAGED';
            size: 14
            x: 172 / intendedWidth * root.width
        }

        Label {
            text: ecBrakesTemperature.toString() + ' °C'
            size: 14
            x: 306 / intendedWidth * root.width
        }
    }

    SeparatingLine {
        id: line1
        x: lineMarginSize
        y: 750 / intendedHeight * root.height
        length: root.width - 2 * lineMarginSize
    }

    SeparatingLine {
        id: line2
        anchors.left: parent.left
        anchors.leftMargin: lineMarginSize
        anchors.right: parent.right
        anchors.rightMargin: lineMarginSize
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 20
    }

    /**
      TODO: Display Battery Summary State
        1. Primary battery voltage, current, temperature
        2. Secondary battery voltage, current, temperature
    */

    Label {
        id: batterySectionHeading
        text: 'BATTERY'
        size: 18
        anchors.top: line1.top
        anchors.topMargin: 20 / intendedHeight * root.height
        anchors.left: parent.left
        anchors.leftMargin: 20
        font.weight: Font.Light
    }

    Row {
        id: primaryBatteryRow
        anchors.left: batterySectionHeading.left
        anchors.top: batterySectionHeading.bottom
        anchors.topMargin: 20

        Label {
            id: primaryLabel
            text: 'Primary'
            size: 14
        }

        BatteryFigure {
            id: primaryBatteryFigure
            anchors.left: primaryLabel.right
            anchors.leftMargin: 20
            chargeLevel: primaryBatteryChargeLevel
        }

        Label {
            id: primaryBatteryVoltageLabel
            x: primaryBatteryFigure.x + primaryBatteryFigure.width + 20
            size: 14
            text: Math.round(primaryBatteryVoltage * 100) / 100 + ' V'
        }

        Label {
            id: primaryBatteryCurrentLabel
            anchors.right: parent.right
            anchors.rightMargin: 20
            text: Math.round(primaryBatteryCurrentLevel * 100) / 100 + ' A'
        }

    }
}
