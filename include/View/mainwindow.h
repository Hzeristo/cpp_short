#pragma once

#include <QMainWindow>
#include <QStackedWidget>

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

private slots:
    void switchToGame();
};
