#pragma once

#include <QMainWindow>
#include <QStackedWidget>
#include "../include/ViewModel/viewmodel.h" // Assuming ViewModel is defined in this header
#include "../include/View/endpage1.h"
#include "../include/View/endpage2.h"

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
    EndPage1* endpage1;
    EndPage2* endpage2;
    //ViewModel* viewModel; 

private slots:
    void switchToGame();
    void switchToEndPage1();
    void switchToEndPage2();
};
