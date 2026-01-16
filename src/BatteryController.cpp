#include "BatteryController.h"
#include <QDebug>
#include <QTimer>

namespace {
// Helper function to convert BatteryDrainRate to QString for logging
QString DrainRateConverter(BatteryDrainRate rate) {
  switch (rate) {
  case BatteryDrainRate::SLOW:
    return "SLOW";
  case BatteryDrainRate::MEDIUM:
    return "MEDIUM";
  case BatteryDrainRate::FAST:
    return "FAST";
  default:
    return "UNKNOWN";
  }
}
} // namespace

BatteryController::BatteryController() : QObject() {
  qDebug() << "BatteryController instantiated";

  qRegisterMetaType<BatteryDrainRate>();

  // Simulate battery level updates based on the drain rate
  QTimer *timer = new QTimer(this);
  connect(timer, &QTimer::timeout, this, [this]() {
    qDebug() << "emitting updateBatteryLevel";
    emit updateBatteryLevel(m_batteryDrainRate);
  });
  timer->start(1000); // Update every 1 second
}

void BatteryController::updateBatteryDrainRate(BatteryDrainRate rate) {
  if (m_batteryDrainRate == rate) {
    return;
  }
  qDebug() << "Battery drain rate updated to: " << DrainRateConverter(rate);
  m_batteryDrainRate = rate;
}
