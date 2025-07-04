#pragma once
/*
#include <QObject>
#include <QString>
#include <vector>
#include <memory>
#include "Model/event.h"

class ViewModel : public QObject {
    Q_OBJECT

public:
    ViewModel(EventBus& bus, QObject* parent = nullptr);

    Q_INVOKABLE void fireAtEnemy();  // View中点击“开枪”按钮时触发
    Q_INVOKABLE void useItem(int index); // 点击某个道具时触发

    // View可以通过绑定或信号连接这些信息更新
    int getPlayerHealth() const;
    int getEnemyHealth() const;
    QString getCurrentOperator() const;

signals:
    void playerHealthChanged(int newHealth);
    void enemyHealthChanged(int newHealth);
    void operatorChanged(const QString& name);
    void bulletInfoUpdated(const std::vector<bool>& bullets); // 仅在需要时

private:
    void subscribeToEvents();

    EventBus& bus;
    int playerHealth = 6;
    int enemyHealth = 6;
    QString currentOperator = "Player";

    std::vector<bool> bullets;  // 当前弹药信息（可用于展示枪膛）
};
*/

