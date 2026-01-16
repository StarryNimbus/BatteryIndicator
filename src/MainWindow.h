#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
  bool m_isDarkMode;
};

#endif // MAINWINDOW_H
