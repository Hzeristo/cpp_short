#pragma once
#pragma once
#pragma once

#include <QObject>
#include <QString>
#include "Common/common.h"

class ViewModel : public QObject {
    Q_OBJECT

public:
    ViewModel(QObject* parent = nullptr);

    void init();  // 订阅所有感兴趣的事件

public slots:
    void playerShootSelf();
    void playerShootOpponent();

signals:
    void healthChanged(const QString& playerName, int newHealth);
    void operatorChanged(const QString& currentOperator);
    void statusChanged(const QString& statusText);

private:

};


