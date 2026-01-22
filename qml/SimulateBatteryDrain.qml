import Battery 1.0
import QtQuick
import QtQuick.Controls

Item {
    id: root

    Rectangle {
        id: test
        anchors.fill: parent
        color: "green"
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

    Column {
        anchors {
            centerIn: parent
        }
        Repeater {
            model: batteryModel.batteryDrainRates()
            RadioButton {
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
                property var drainRate: modelData
                ButtonGroup.group: drainGroup
                checked: batteryModel.drainRate === modelData
            }
        }
    }
}
