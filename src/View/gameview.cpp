// gameview.cpp
#include "View/gameview.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>

GameView::GameView(QWidget* parent) : QWidget(parent) {
    QVBoxLayout* layout = new QVBoxLayout(this);

    statusLabel = new QLabel("Game Start", this);
    layout->addWidget(statusLabel);

    selfButton = new QPushButton("Shoot on yourself", this);
    opponentButton = new QPushButton("Shoot on your opponent", this);

    layout->addWidget(selfButton);
    layout->addWidget(opponentButton);

    connect(selfButton, &QPushButton::clicked, this, &GameView::shootSelf);
    connect(opponentButton, &QPushButton::clicked, this, &GameView::shootOpponent);
}

void GameView::updateStatusText(const QString& text) {
    statusLabel->setText(text);
}
