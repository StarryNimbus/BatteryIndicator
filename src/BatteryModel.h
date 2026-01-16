
#ifndef BATTERYMODEL_H
#define BATTERYMODEL_H

#include "BatteryController.h"
#include <QObject>

class BatteryModel : public QObject {
  Q_OBJECT

  Q_PROPERTY(int batteryLevel READ GetBatteryLevel NOTIFY batteryLevelChanged);

public:
  BatteryModel();
  ~BatteryModel() = default;

  int GetBatteryLevel() const { return m_batteryLevel; };

signals:
  void batteryLevelChanged(BatteryDrainRate rate);

public slots:
  void OnUpdateBatteryLevel(BatteryDrainRate rate);

private:
  int m_batteryLevel{100};
};

#endif // BATTERYMODEL_H
