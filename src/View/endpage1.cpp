#include "../../include/View/endpage1.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPixmap>
#include <QPushButton>


EndPage1::EndPage1(QWidget* parent) : QWidget(parent) {
    // Set background image
    resize(1200, 750);
    QLabel* backgroundLabel = new QLabel(this);
    QPixmap background("../assets/images/endpage1.jpg");
    if (!background.isNull()) {
        backgroundLabel->setPixmap(background);
    backgroundLabel->setScaledContents(true);  // 自动缩放图像以适配 QLabel 大小
    backgroundLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);  // 防止保留原图尺寸
    backgroundLabel->resize(1200,750);     // 初始大小设为窗口大小
    }
    backgroundLabel->lower(); // 确保背景在最底层


    //QLabel* titleLabel = new QLabel("Welcome to DemonRoulette", this);
    //titleLabel->setAlignment(Qt::AlignCenter);
    //layout->addWidget(titleLabel);

    //connect(startButton, &QPushButton::clicked, this, &StartPage::startGameClicked);

}