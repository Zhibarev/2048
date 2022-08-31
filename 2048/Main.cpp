#include "MainWindow.hh"
#include <QApplication>
#include <QDebug>
#include <stdexcept>
#include <cstdlib>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
