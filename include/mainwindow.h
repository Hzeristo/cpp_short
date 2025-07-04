#pragma once

#include <QMainWindow>
#include <QStackedWidget>
#include "../include/viewmodel.h" // Assuming ViewModel is defined in this header

class GameView;
class StartPage;

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private:
    QStackedWidget* stack;
    StartPage* startPage;
    GameView* gameView;
    ViewModel* viewModel; // Assuming ViewModel is defined in the included headers

private slots:
    void switchToGame();
};
