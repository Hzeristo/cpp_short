#pragma once

#include <QMainWindow>
#include <QStackedWidget>
#include "../include/View/endpage1.h"
#include "../include/View/endpage2.h"

class GameView;
class StartPage;

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

public:
    QStackedWidget* stack;
    StartPage* startPage;
    GameView* gameView;
    EndPage1* endpage1;
    EndPage2* endpage2;

private slots:
    void switchToGame();
    void switchToEndPage1();
    void switchToEndPage2();
};
