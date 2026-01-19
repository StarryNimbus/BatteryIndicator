import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

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
}
