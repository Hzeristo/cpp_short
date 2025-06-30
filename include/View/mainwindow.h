#pragma once

#include <QMainWindow>

class GameView;

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private:
    GameView* gameView;
};
