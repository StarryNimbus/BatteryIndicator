
#ifndef BATTERYMODEL_H
#define BATTERYMODEL_H

#include <QMetaEnum>
#include <QObject>
#include <QVariant>

class BatteryModel : public QObject {
  Q_OBJECT

  Q_PROPERTY(int batteryLevel READ getBatteryLevel NOTIFY batteryLevelChanged);

public:
  BatteryModel();
  ~BatteryModel() = default;

  enum class BatteryDrainRate { SLOW, MEDIUM, FAST };
  Q_ENUM(BatteryDrainRate)

  // Data is static (does not change over time) and does not need bindings to
  // reevaluate. Therefore, it does not need to be a Q_PROPERTY.
  Q_INVOKABLE QVariantList batteryDrainRates() const;

  Q_INVOKABLE void updateBatteryDrainRate(BatteryDrainRate rate);

  int getBatteryLevel() const { return m_batteryLevel; };

signals:
  void batteryLevelChanged(BatteryDrainRate rate);

public slots:
  void onUpdateBatteryLevel();

private:
  int m_batteryLevel{100};
  BatteryDrainRate m_batteryDrainRate{BatteryDrainRate::MEDIUM};
};

Q_DECLARE_METATYPE(BatteryModel::BatteryDrainRate)

#endif // BATTERYMODEL_H
