#include "../../include/View/startpage.h"

#include <QVBoxLayout>
#include <QLabel>

StartPage::StartPage(QWidget* parent) : QWidget(parent) {
    QVBoxLayout* layout = new QVBoxLayout(this);
    QLabel* titleLabel = new QLabel("Welcome to DemonRoulette", this);
    titleLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(titleLabel);
    QPushButton* startButton = new QPushButton("Start Game", this);
    layout->addWidget(startButton);
    connect(startButton, &QPushButton::clicked, this, &StartPage::startGameClicked);
    setLayout(layout);
    setWindowTitle("DemonRoulette - Start Page");
    resize(400, 300);
}