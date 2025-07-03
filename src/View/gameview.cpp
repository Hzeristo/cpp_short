// gameview.cpp
#include <iostream>
#include "../../include/View/gameview.h"
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

     // 状态栏标签（显示回合、提示信息等）
    statusLabel = new QLabel("Game Start", this);
    statusLabel->setGeometry(700, 50, 400, 50);
    statusLabel->setStyleSheet("color: white; font-size: 24px;");

    // 玩家血量显示
    healthLabelSelf = new QLabel("Your HP: 3", this);
    healthLabelSelf->setGeometry(100, 200, 200, 50);
    healthLabelSelf->setStyleSheet("color: white; font-size: 18px;");

    // 对手血量显示
    healthLabelEnemy = new QLabel("Enemy HP: 3", this);
    healthLabelEnemy->setGeometry(1300, 200, 200, 50);
    healthLabelEnemy->setStyleSheet("color: white; font-size: 18px;");

    // “对自己开枪”按钮
    selfButton = new QPushButton("Shoot Yourself", this);
    selfButton->setGeometry(100, 700, 200, 50);
    connect(selfButton, &QPushButton::clicked, this, &GameView::shootSelf);

    // “对对手开枪”按钮
    opponentButton = new QPushButton("Shoot Opponent", this);
    opponentButton->setGeometry(1300, 700, 200, 50);
    connect(opponentButton, &QPushButton::clicked, this, &GameView::shootOpponent);
}

void GameView::updateStatusText(const QString& text) {
    statusLabel->setText(text);
}


void GameView::updateHealth(const QString& playerName, int health) {
    if (playerName == "player") {
        healthLabelSelf->setText("Your HP: " + QString::number(health));
    } else if (playerName == "enemy") {
        healthLabelEnemy->setText("Enemy HP: " + QString::number(health));
    }
}

void GameView::updateOperator(const QString& operatorName) {
    statusLabel->setText("Current turn: " + operatorName);
}