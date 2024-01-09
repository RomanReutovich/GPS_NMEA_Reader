#include "mainwindow.h"

#include <QApplication>
#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
    // QGuiApplication app(argc, argv);
   QApplication a(argc, argv);

   // QQmlApplicationEngine engine;
   // engine.load(QUrl(QStringLiteral("qrc:/new/prefix1/map.qml")));
    MainWindow w;
    w.show();
    return a.exec();
}
