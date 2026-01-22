#include "BatteryModel.h"
#include <QDebug>
#include <qqml.h>

namespace {
// Helper function to convert BatteryModel::BatteryDrainRate to QString for
// logging
QString DrainRateConverter(BatteryModel::BatteryDrainRate rate) {
  switch (rate) {
  case BatteryModel::BatteryDrainRate::SLOW:
    return "SLOW";
  case BatteryModel::BatteryDrainRate::MEDIUM:
    return "MEDIUM";
  case BatteryModel::BatteryDrainRate::FAST:
    return "FAST";
  default:
    return "UNKNOWN";
  }
}

} // anonymous namespace

BatteryModel::BatteryModel() : QObject() {
  qRegisterMetaType<BatteryDrainRate>();
  qmlRegisterType<BatteryModel>("Battery", 1, 0, "BatteryModel");

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

QVariantList BatteryModel::batteryDrainRates() const {
  QVariantList list;
  const QMetaEnum metaEnum = QMetaEnum::fromType<BatteryDrainRate>();

  for (int i = 0; i < metaEnum.keyCount(); ++i) {
    list.append(metaEnum.value(i));
  }
  return list;
}

void BatteryModel::updateBatteryDrainRate(BatteryDrainRate rate) {
  if (m_batteryDrainRate == rate) {
    return;
  }
  qDebug() << "Battery drain rate updated to: " << DrainRateConverter(rate);
  m_batteryDrainRate = rate;
}

void BatteryModel::onUpdateBatteryLevel() {
  emit batteryLevelChanged(m_batteryDrainRate);
}
