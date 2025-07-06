// mainwindow.cpp
#include "../include/Model/event.h"
#include "../include/mainwindow.h"
#include "../include/View/startpage.h"
#include "../include/View/gameview.h"
#include "../include/viewmodel.h"
#include "../include/Model/player.h"
#include "../include/Model/gun.h"
#include "../include/Model/item.h"
#include "../include/Model/game.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
    stack = new QStackedWidget(this);
    startPage = new StartPage(this);
    gameView = new GameView(this);
    std::shared_ptr<EventBus> bus = std::make_shared<EventBus>();
    viewModel = new ViewModel(bus, this); // Create ViewModel with the EventBus
    viewModel->init(); // Initialize the ViewModel by subscribing to events

    auto player_me = std::make_shared<Player>("me", 5, 5, 1, bus);
    player_me->subscribe();

    auto player_ai = std::make_shared<Player>("ai", 5, 5, 1, bus);
    player_ai->subscribe();

    auto gun = std::make_shared<Gun>(bus);
    gun->subscribe();

    auto game = std::make_shared<Game>(bus);
    game->subscribe();


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
