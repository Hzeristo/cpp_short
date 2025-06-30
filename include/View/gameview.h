// gameview.h
#pragma once

#include <QWidget>

class QPushButton;
class QLabel;

class GameView : public QWidget {
    Q_OBJECT

public:
    GameView(QWidget* parent = nullptr);

signals:
    void shootSelf();
    void shootOpponent();

public slots:
    void updateStatusText(const QString& text);  // 显示游戏信息

private:
    QLabel* statusLabel;
    QPushButton* selfButton;
    QPushButton* opponentButton;
};
