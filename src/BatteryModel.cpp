#include "BatteryModel.h"
#include <QDebug>

BatteryModel::BatteryModel() : QObject() {
  qDebug() << "BatteryModel instantiated";

  connect(this, &BatteryModel::batteryLevelChanged, this,
          [this](BatteryDrainRate rate) {
            if (m_batteryLevel <= 0) {
              qDebug() << "Battery depleted, resetting to 100%";
              m_batteryLevel = 100;
              return;
            }

            if (rate == BatteryDrainRate::SLOW) {
              m_batteryLevel -= 1;
            } else if (rate == BatteryDrainRate::MEDIUM) {
              m_batteryLevel -= 5;
            } else if (rate == BatteryDrainRate::FAST) {
              m_batteryLevel -= 10;
            }
            qDebug() << "Battery level:" << m_batteryLevel << "%";
          });
};

void BatteryModel::OnUpdateBatteryLevel(BatteryDrainRate rate) {
  emit batteryLevelChanged(rate);
}
