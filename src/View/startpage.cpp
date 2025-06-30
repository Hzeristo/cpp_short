#include "../../include/View/startpage.h"
#include <iostream>
#include <QVBoxLayout>
#include <QLabel>
#include <QPixmap>
#include <QPushButton>

StartPage::StartPage(QWidget* parent) : QWidget(parent) {
    // Set background image
    resize(1600, 1200);
    QLabel* backgroundLabel = new QLabel(this);
    QPixmap background("../assets/images/startpage_background.jpg");
    if (!background.isNull()) {
        backgroundLabel->setPixmap(background);
    backgroundLabel->setScaledContents(true);  // 自动缩放图像以适配 QLabel 大小
    backgroundLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);  // 防止保留原图尺寸
    backgroundLabel->resize(1600,1200);     // 初始大小设为窗口大小
    }
    backgroundLabel->lower(); // 确保背景在最底层


    //QLabel* titleLabel = new QLabel("Welcome to DemonRoulette", this);
    //titleLabel->setAlignment(Qt::AlignCenter);
    //layout->addWidget(titleLabel);
    QPushButton* startButton = new QPushButton(this);
    startButton->move(700, 600);
    startButton->setFixedSize(200, 100);
    QPixmap buttonIcon("../assets/images/startbutton.png"); 
    if (!buttonIcon.isNull()) {
        startButton->setIcon(QIcon(buttonIcon));       // 设置按钮图标
        startButton->setIconSize(QSize(240, 120));      // 设置图标大小
        startButton->raise(); // 确保按钮在背景之上
        startButton->setFlat(true);
    }

    connect(startButton, &QPushButton::clicked, this, &StartPage::startGameClicked);
    setWindowTitle("DemonRoulette - Start Page");

}