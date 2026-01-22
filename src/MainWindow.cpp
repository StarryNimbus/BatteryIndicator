#include "MainWindow.h"
#include <QQmlContext>
#include <QQmlEngine>
#include <QSize>
#include <QSizePolicy>
#include <Qt>

MainWindow::MainWindow() : QObject(nullptr), m_view(nullptr) {
  connect(&m_controller, &BatteryController::updateBatteryLevel, &m_model,
          &BatteryModel::onUpdateBatteryLevel);

  m_view = Build();

  // Context properties must be set before setSource()
  m_view->rootContext()->setContextProperty("batteryModel", &m_model);

  m_view->loadFromModule("com.BatteryIndicator", "Main");
  m_view->setGeometry(0, 0, 1000, 600); // default size when launched

  // Allow width to expand but set the minimum and maximum height to 600.
  m_view->setMinimumSize(QSize(600, 600));
  m_view->setMaximumHeight(600);
}

void MainWindow::show() const { m_view->show(); }

QQuickView *MainWindow::Build() const {
  QQuickView *view = new QQuickView(nullptr, nullptr);
  QQmlEngine *engine = view->engine();

  // For importing QML modules directly from QRC
  // see https://stackoverflow.com/a/49326965
  engine->addImportPath(QString("qrc:///"));

  view->setColor(Qt::transparent);
  view->setFlags(Qt::Widget);
  view->setResizeMode(QQuickView::SizeRootObjectToView);
  view->setPosition(0, 0);

  return view;
}
