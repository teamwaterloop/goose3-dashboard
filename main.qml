import QtQuick 2.10
import QtQuick.Window 2.10

Window {
    // specify dimensions for different components
    property int windowWidth: 1920;
    property int windowHeight: 1080;


    id: root
    visible: true
    width: windowWidth;
    height: windowHeight
    title: qsTr("Waterloop Dashboard")

    color: "#347C8F"

    // left-most speed pane
    SpeedPane {
        id: speedPane
        width: 550 / 1920 * root.width
        height: 960 / 1080 * root.height;
        x: 0
        y: 0
    }

    // right-most summary pane
    SummaryPane {
        id: summaryPane
        width: 384 / 1920 * root.width
        height: 960 / 1080 * root.height
        x: root.width - this.width
        y: 0
    }

    // bottom-level distance pane (shows distance in pod)
    DistancePane {
        id: distancePane
        width: parent.width
        height: 120 / 1080 * root.height
        x: 0
        y: parent.height - this.height
    }
}
