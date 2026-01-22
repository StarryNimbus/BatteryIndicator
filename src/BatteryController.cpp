#include "BatteryController.h"
#include <QDebug>
#include <QTimer>

BatteryController::BatteryController() : QObject() {
  // Simulate battery level updates based on the drain rate
  QTimer *timer = new QTimer(this);
  connect(timer, &QTimer::timeout, this,
          [this]() { emit updateBatteryLevel(); });
  timer->start(1000); // Update every 1 second
}
