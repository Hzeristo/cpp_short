// gameview.cpp
#include <iostream>
#include "View/gameview.h"
#include <QPushButton>
#include <QLabel>

GameView::GameView(QWidget* parent) : QWidget(parent) {

    resize(1600, 1200);
    QLabel* backgroundLabel = new QLabel(this);
    QPixmap background("../assets/images/gameview_bak.png");
    if (!background.isNull()) {
        backgroundLabel->setPixmap(background);
    backgroundLabel->setScaledContents(true);  // 自动缩放图像以适配 QLabel 大小
    backgroundLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);  // 防止保留原图尺寸
    backgroundLabel->resize(1600,1200);     // 初始大小设为窗口大小
    }
    backgroundLabel->lower(); // 确保背景在最底层
    //statusLabel = new QLabel("Game Start", this);

    selfButton = new QPushButton("Shoot yourself", this);
    selfButton->setGeometry(100, 700, 200, 50); // Set position and size
    opponentButton = new QPushButton("Shoot  your opponent", this);
    opponentButton->setGeometry(1300, 700, 200, 50); // Set position and size


    connect(selfButton, &QPushButton::clicked, this, &GameView::shootSelf);
    connect(opponentButton, &QPushButton::clicked, this, &GameView::shootOpponent);
}

void GameView::updateStatusText(const QString& text) {
    statusLabel->setText(text);
}
