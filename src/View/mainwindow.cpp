// mainwindow.cpp
#include "View/mainwindow.h"
#include "View/gameview.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
    gameView = new GameView(this);
    setCentralWidget(gameView);
    setWindowTitle("DemonRoulette");
    resize(800, 600);
}
MainWindow::~MainWindow() {}
