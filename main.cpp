#include "mainwindow.h"
#include"hotel.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    int result =a.exec();

    delete Hotel::getInstance();
    return result;
}
