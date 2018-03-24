/**
  Author: Jashan S. Shewakramani
  Description: Top-level window QML
  */
import QtQuick 2.10
import QtQuick.Window 2.10

Window {
    // specify dimensions for different components
    property int windowWidth: 1920;
    property int windowHeight: 1080;
    property int speedPaneWidth: 550;
    property int distancePaneHeight: 120;
    property int summaryPaneWidth: 384;



    id: root
    visible: true
    width: windowWidth
    height:windowHeight
    title: qsTr("Goose 3 Dashboard")
    color: "#347C8F"

    // left-most speed pane
    SpeedPane {
        id: speedPane
        width: speedPaneWidth
        height: windowHeight - distancePaneHeight
        x: 0
        y: 0
    }

    // right-most summary pane
    SummaryPane {
        id: summaryPane
        width: summaryPaneWidth
        height: windowHeight - distancePane.height
        x: root.width - this.width
        y: 0
    }

    // bottom-level distance pane (shows distance in pod)
    DistancePane {
        id: distancePane
        width: parent.width
        height: distancePaneHeight
        x: 0
        y: parent.height - this.height
    }
}
