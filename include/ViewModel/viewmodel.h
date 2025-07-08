#pragma once

#include <QObject>
#include <QString>
#include "Common/common.h"
#include "Model/model.h"

class ViewModel : public QObject {
    Q_OBJECT

public:
    explicit ViewModel(QObject* parent = nullptr);

    void init();  

public slots:
    void playerShootSelf();
    void playerShootOpponent();

signals:
    void healthChanged(const QString& playerName, int newHealth);
    void operatorChanged(const QString& currentOperator);
    void statusChanged(const QString& statusText);
    void userDead();
    void aiDead();
    void turnDone();
    void reloaded(const QString& bulletinfo);
    void bulletType(const QString& bulletinfo);

private:
    std::unique_ptr<Model> app;
};


