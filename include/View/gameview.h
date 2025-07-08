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
    void aidie();
    void playerdie();

public slots:
    void updateStatusText(const QString& text);  // 显示游戏信息
    void updateHealth(const QString& playerName, int health);
    void updateOperator(const QString& operatorName);
    void updateBulletInfo(const QString& bulletInfo);
    
private:
    QLabel* statusLabel;
    QPushButton* selfButton;
    QPushButton* opponentButton;
    QLabel* healthLabelSelf;   // 显示玩家生命值
    QLabel* healthLabelEnemy;  // 显示电脑生命值
    QLabel* bulletLabel;       // 显示子弹数量
};
