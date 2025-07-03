#pragma once

#include <QWidget>
#include <QPushButton>

class StartPage : public QWidget {
    Q_OBJECT
public:
    StartPage(QWidget* parent = nullptr);

signals:
    void startGameClicked();
};