#include "include/viewmodel.h"
/*
ViewModel::ViewModel(EventBus& bus, QObject* parent)
    : QObject(parent), bus(bus) {
    subscribeToEvents();
}

void ViewModel::fireAtEnemy() {
    bus.publish(std::make_shared<FireEvent>("Player", "Enemy"));
}



void ViewModel::useItem(int index) {
    //
    bus.publish(std::make_shared<TryItemUseEvent>(type, "Player", "Enemy", index));
}

void ViewModel::subscribeToEvents() {
    bus.subscribe<Health2VMEvent>([this](EventPtr e) {
        auto evt = std::dynamic_pointer_cast<Health2VMEvent>(e);
        if (evt->getTarget() == "Player") {
            playerHealth = evt->getValue();
            emit playerHealthChanged(playerHealth);
        } else {
            enemyHealth = evt->getValue();
            emit enemyHealthChanged(enemyHealth);
        }
    });

    bus.subscribe<OperatorChangeEvent>([this](EventPtr e) {
        auto evt = std::dynamic_pointer_cast<OperatorChangeEvent>(e);
        currentOperator = QString::fromStdString(evt->getTargetname());
        emit operatorChanged(currentOperator);
    });

    // 也可以订阅 Bullet2VMEvent 等自定义事件
}

*/
