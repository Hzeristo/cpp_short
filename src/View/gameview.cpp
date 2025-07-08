// gameview.cpp
#include <iostream>
#include "../../include/View/gameview.h"
#include <QPushButton>
#include <QLabel>

GameView::GameView(QWidget* parent) : QWidget(parent) {

    resize(1200, 750);
    QLabel* backgroundLabel = new QLabel(this);
    QPixmap background("../assets/images/gameview_bak.png");
    if (!background.isNull()) {
        backgroundLabel->setPixmap(background);
    backgroundLabel->setScaledContents(true);  // 自动缩放图像以适配 QLabel 大小
    backgroundLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);  // 防止保留原图尺寸
    backgroundLabel->resize(1200,750);     // 初始大小设为窗口大小
    }
    backgroundLabel->lower(); // 确保背景在最底层
    //statusLabel = new QLabel("Game Start", this);

    selfButton = new QPushButton("Shoot yourself", this);
    selfButton->setGeometry(100, 500, 200, 50); // Set position and size

    opponentButton = new QPushButton("Shoot  your opponent", this);
    opponentButton->setGeometry(900, 500, 200, 50); // Set position and size

    connect(selfButton, &QPushButton::clicked, this, &GameView::shootSelf);
    connect(opponentButton, &QPushButton::clicked, this, &GameView::shootOpponent);

     // 状态栏标签（显示回合、提示信息等）
    statusLabel = new QLabel("Game Start", this);
    statusLabel->setGeometry(500, 50, 400, 50);
    statusLabel->setStyleSheet("color: white; font-size: 24px;");

    // 玩家血量显示
    healthLabelSelf = new QLabel("Your HP: 4", this);
    healthLabelSelf->setGeometry(100, 200, 200, 50);
    healthLabelSelf->setStyleSheet("color: white; font-size: 18px;");

    // 对手血量显示
    healthLabelEnemy = new QLabel("Enemy HP: 4", this);
    healthLabelEnemy->setGeometry(900, 200, 200, 50);
    healthLabelEnemy->setStyleSheet("color: white; font-size: 18px;");
}

void GameView::updateStatusText(const QString& text) {
    statusLabel->setText(text);
}


void GameView::updateHealth(const QString& playerName, int health) {
    if (playerName == "me") {
        healthLabelSelf->setText("Your HP: " + QString::number(health));
    } else if (playerName == "ai") {
        healthLabelEnemy->setText("Enemy HP: " + QString::number(health));
    }
}

void GameView::updateOperator(const QString& operatorName) {
    statusLabel->setText("Current turn: " + operatorName);
}