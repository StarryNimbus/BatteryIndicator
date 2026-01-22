import QtQuick
import QtQuick.Layouts
import QtQuick.Controls
import Battery 1.0

Rectangle {
    id: root
    width: 1000
    height: 600
    color: '#000000'

    BatteryIndicator {
        id: battery
        anchors {
            fill: parent
        }
    }

    SimulateBatteryDrain {
        id: simulator

        implicitWidth: parent.width
        implicitHeight: 50

        anchors {
            left: parent.left
            bottom: parent.bottom
        }
    }
}
