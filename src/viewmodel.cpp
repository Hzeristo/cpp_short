#include "../include/viewmodel.h"

ViewModel::ViewModel(EventBus& bus, QObject* parent)
    : QObject(parent), m_bus(bus) {}

void ViewModel::init() {
    // 订阅生命值变化事件
    m_bus.subscribe<Health2VMEvent>([this](EventPtr e) {
        auto event = std::static_pointer_cast<Health2VMEvent>(e);
        emit healthChanged(QString::fromStdString(event->getTarget()), event->getValue());
    });

    // 订阅操作者变化事件
    m_bus.subscribe<OperatorChangeEvent>([this](EventPtr e) {
        auto event = std::static_pointer_cast<OperatorChangeEvent>(e);
        emit operatorChanged(QString::fromStdString(event->getTargetname()));
    });

    // TODO：根据需要添加更多订阅
}

void ViewModel::playerShootSelf() {
    // 玩家射击自己 -> 发布 FireEvent
    m_bus.publish(std::make_shared<FireEvent>("player", "player"));
    emit statusChanged("You shot yourself!");
}

void ViewModel::playerShootOpponent() {
    // 玩家射击对手 -> 发布 FireEvent
    m_bus.publish(std::make_shared<FireEvent>("player", "opponent"));
    emit statusChanged("You shot your opponent!");
}

