#ifndef BATTERYCONTROLLER_H
#define BATTERYCONTROLLER_H

#include <QObject>

enum class BatteryDrainRate { SLOW, MEDIUM, FAST };
Q_DECLARE_METATYPE(BatteryDrainRate)

class BatteryController : public QObject {
  Q_OBJECT
public:
  BatteryController();
  ~BatteryController() = default;

  Q_INVOKABLE void updateBatteryDrainRate(BatteryDrainRate rate);

signals:
  void updateBatteryLevel(BatteryDrainRate rate);

private:
  BatteryDrainRate m_batteryDrainRate{BatteryDrainRate::MEDIUM};
};
#endif // BATTERYCONTROLLER_H
