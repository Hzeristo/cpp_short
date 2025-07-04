// mainwindow.cpp
#include "../include/Model/event.h"
#include "../include/mainwindow.h"
#include "../include/View/startpage.h"
#include "../include/View/gameview.h"
#include "../include/viewmodel.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
    stack = new QStackedWidget(this);
    startPage = new StartPage(this);
    gameView = new GameView(this);
    EventBus bus;
    viewModel = new ViewModel(bus, this); // Create ViewModel with the EventBus
    viewModel->init(); // Initialize the ViewModel by subscribing to events

    stack->addWidget(startPage);
    stack->addWidget(gameView);
    setCentralWidget(stack);
    stack->setCurrentWidget(startPage); // start with the start page
    setWindowTitle("DemonRoulette");
    resize(1200, 750);

    connect(startPage, &StartPage::startGameClicked, this, &MainWindow::switchToGame);
    QObject::connect(gameView, &GameView::shootSelf,
                     viewModel, &ViewModel::playerShootSelf);
    QObject::connect(gameView, &GameView::shootOpponent,
                     viewModel, &ViewModel::playerShootOpponent);
                     
    QObject::connect(viewModel, &ViewModel::statusChanged,
                     gameView, &GameView::updateStatusText);
    QObject::connect(viewModel, &ViewModel::healthChanged,
                     gameView, &GameView::updateHealth);
    QObject::connect(viewModel, &ViewModel::operatorChanged,
                     gameView, &GameView::updateOperator);
}
MainWindow::~MainWindow() {}


void MainWindow::switchToGame() {
    stack->setCurrentWidget(gameView); //switch to game view
}
