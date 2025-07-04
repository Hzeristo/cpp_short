#include <iostream>
#include <QApplication>
#include "../include/mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MainWindow window;
    window.resize(1200, 750);
    window.show();    

    return app.exec();             
}
