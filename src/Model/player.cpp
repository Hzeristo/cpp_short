#include "../../include/Common/common.h"
#include "../../include/Model/player.h"

Player::Player(std::string name, int maxHealth, int health, int noHealHealth, std::shared_ptr<EventBus> bus) :
    m_username(name), m_maxHealth(maxHealth), m_health(maxHealth), m_noHealHealth(maxHealth), bus(bus) {
  this->subscribe();
}

void Player::onTryItemUseEvent(const TryItemUseEvent &event) {
  throw std::runtime_error("Not implemented for the first demo");
}

void Player::subscribe(){
  std::weak_ptr<Player> w_self = shared_from_this();
  bus->subscribe<HealthEvent>([w_self](EventPtr e) {
    if (auto self = w_self.lock()) { 
      auto healthEvent = std::static_pointer_cast<HealthEvent>(e);
      self->onHealthEvent(healthEvent->getValue());
    } 
  });
  
  bus->subscribe<TryItemUseEvent>([w_self](EventPtr e) {
    if (auto self = w_self.lock()) { 
      auto tryItemUseEvent = std::static_pointer_cast<TryItemUseEvent>(e);
      self->onTryItemUseEvent(*tryItemUseEvent);
    } 
  });
}