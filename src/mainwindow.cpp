// mainwindow.cpp
#include "../include/mainwindow.h"
#include "../include/View/startpage.h"
#include "../include/View/gameview.h"
#include "../include/ViewModel/viewmodel.h"
#include "../include/Model/components/player.h"
#include "../include/Model/components/gun.h"
#include "../include/Model/components/item.h"
#include "../include/Model/app.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
    stack = new QStackedWidget(this);
    startPage = new StartPage(this);
    gameView = new GameView(this);



    // stack->addWidget(startPage);
    // stack->addWidget(gameView);
    // setCentralWidget(stack);
    // stack->setCurrentWidget(startPage); // start with the start page
    // setWindowTitle("DemonRoulette");
    // resize(1200, 750);

    // connect(startPage, &StartPage::startGameClicked, this, &MainWindow::switchToGame);
    // QObject::connect(gameView, &GameView::shootSelf,
    //                  viewModel, &ViewModel::playerShootSelf);
    // QObject::connect(gameView, &GameView::shootOpponent,
    //                  viewModel, &ViewModel::playerShootOpponent);
                     
    // QObject::connect(viewModel, &ViewModel::statusChanged,
    //                  gameView, &GameView::updateStatusText);
    // QObject::connect(viewModel, &ViewModel::healthChanged,
    //                  gameView, &GameView::updateHealth);
    // QObject::connect(viewModel, &ViewModel::operatorChanged,
    //                  gameView, &GameView::updateOperator);
}
MainWindow::~MainWindow() {}


void MainWindow::switchToGame() {
    stack->setCurrentWidget(gameView); //switch to game view
}
