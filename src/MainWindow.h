#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "BatteryController.h"
#include "BatteryModel.h"
#include <QObject>
#include <QQuickView>

class MainWindow : public QObject {
  Q_OBJECT

public:
  MainWindow();
  void show() const;

private:
  QQuickView *Build() const;

  QQuickView *m_view;
  BatteryModel m_model;
  BatteryController m_controller;
};

#endif // MAINWINDOW_H
