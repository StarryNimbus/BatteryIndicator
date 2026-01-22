#ifndef BATTERYCONTROLLER_H
#define BATTERYCONTROLLER_H

#include <QObject>

class BatteryController : public QObject {
  Q_OBJECT
public:
  BatteryController();
  ~BatteryController() = default;

signals:
  void updateBatteryLevel();

private:
};
#endif // BATTERYCONTROLLER_H
