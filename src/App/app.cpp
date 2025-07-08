#include "../../include/App/app.h"
#include "../../include/View/gameview.h"

App::App(MainWindow& window) : mainWindow(window) {
    viewModel = new ViewModel();
    QObject::connect(mainWindow.gameView, &GameView::shootSelf,
                    viewModel, &ViewModel::playerShootSelf);
    QObject::connect(mainWindow.gameView, &GameView::shootOpponent,
                    viewModel, &ViewModel::playerShootOpponent);
                     
    QObject::connect(viewModel, &ViewModel::statusChanged,
                    mainWindow.gameView, &GameView::updateStatusText);
    QObject::connect(viewModel, &ViewModel::healthChanged,
                    mainWindow.gameView, &GameView::updateHealth);
    QObject::connect(viewModel, &ViewModel::operatorChanged,
                    mainWindow.gameView, &GameView::updateOperator);
    QObject::connect(viewModel, &ViewModel::userDead,
                     mainWindow.gameView, &GameView::playerdie);
    QObject::connect(viewModel, &ViewModel::aiDead,
                     mainWindow.gameView, &GameView::aidie);
}