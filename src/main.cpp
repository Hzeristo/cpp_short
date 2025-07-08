#include <iostream>
#include <QApplication>
#include "../include/mainwindow.h"
#include "../include/App/app.h"


int main(int argc, char *argv[]) {

    QApplication application(argc, argv);
    MainWindow window;
    App app(window);
    window.resize(1200, 750);
    window.show();

    return application.exec();             
}
