#include <iostream>
#include <QApplication>
#include "View/mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MainWindow window;
    window.resize(1600, 1000);
    window.show();    

    return app.exec();             
}
