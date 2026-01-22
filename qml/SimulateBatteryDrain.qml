import Battery 1.0
import QtQuick.Layouts
import QtQuick
import QtQuick.Controls

Item {
    id: root

    Rectangle {
        id: background
        anchors.fill: parent
        color: "white"
    }

    ButtonGroup {
        id: drainGroup
        onCheckedButtonChanged: {
            if (!checkedButton) {
                return;
            }
            batteryModel.updateBatteryDrainRate(checkedButton.drainRate);
        }
    }

    RowLayout {
        anchors {
            centerIn: parent
        }
        spacing: 50
        Repeater {
            model: batteryModel.batteryDrainRates()
            RadioButton {
                id: control

                property var drainRate: modelData
                ButtonGroup.group: drainGroup
                checked: batteryModel.drainRate === modelData

                text: {
                    switch (modelData) {
                    case BatteryModel.SLOW:
                        return "Slow";
                    case BatteryModel.MEDIUM:
                        return "Medium";
                    case BatteryModel.FAST:
                        return "Fast";
                    }
                }
                font.pixelSize: 16
                font.weight: Font.DemiBold
            }
        }
    }
}
