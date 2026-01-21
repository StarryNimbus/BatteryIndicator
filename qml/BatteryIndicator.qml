import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

Rectangle {
    id: root
    color: "transparent"

    RowLayout {
        id: container

        anchors {
            centerIn: parent
        }

        Layout.alignment: Qt.AlignVCenter | Qt.AlignHCenter
        spacing: 25

        Image {
            id: batteryImage
            source: {
                let level = batteryModel.batteryLevel
                if (level > 75) {
                    return "qrc:/images/battery_100.svg"
                } else if (level <= 75 && level > 50) {
                    return "qrc:/images/battery_75.svg"
                } else if (level <= 50 && level > 25) {
                    return "qrc:/images/battery_50.svg"
                } else if (level <= 25 && level > 0) {
                    return "qrc:/images/battery_25.svg"
                } else {
                    return "qrc:/images/battery_0.svg"
                }
            }
            sourceSize.width: 100
            sourceSize.height: 100
            fillMode: Image.PreserveAspectFit
            rotation: 90
        }

        Label {
            id: batteryLabel
            text: batteryModel.batteryLevel + "%"

            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignLeft

            color: "white"
            font.pixelSize: 25
            font.weight: Font.ExtraBold
        }
    }
}
