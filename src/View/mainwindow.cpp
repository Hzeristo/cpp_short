// mainwindow.cpp
#include "View/mainwindow.h"
#include "View/gameview.h"
#include "View/startpage.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
    stack = new QStackedWidget(this);
    startPage = new StartPage(this);
    gameView = new GameView(this);

    stack->addWidget(startPage);
    stack->addWidget(gameView);
    setCentralWidget(stack);
    stack->setCurrentWidget(startPage); // start with the start page
    setWindowTitle("DemonRoulette");
    resize(800, 600);

    connect(startPage, &StartPage::startGameClicked, this, &MainWindow::switchToGame);
}
MainWindow::~MainWindow() {}


void MainWindow::switchToGame() {
    stack->setCurrentWidget(gameView); //switch to game view
}
