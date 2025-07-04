#pragma once

#include "../Common/common.h"
#include "event.h"

class Player;
using PlayerPtr = std::shared_ptr<Player>;
class Player : std::enable_shared_from_this<Player> {
public:
  Player(std::string name, int maxHealth, int health, int noHealHealth, std::shared_ptr<EventBus> bus);
  ~Player() {}

  void takeDamage(int damage) {
    if(damage > m_health - m_noHealHealth) {
      m_health = m_noHealHealth;
    } else {
      m_health -= damage;
    }
  };

  void heal(int health) {
    if(m_health > m_noHealHealth) {
      m_health += health;
    }
  }

  void onHealthEvent(int delta) {
    if (delta > 0) {
      this->heal(delta);
    } else {
      this->takeDamage(-delta);
    }
    bus->publish(std::make_shared<Health2VMEvent>(m_health, this->m_username));
  }

  void onTryItemUseEvent(const TryItemUseEvent& event);

private:
  std::string m_username;
  int m_maxHealth;
  int m_health;
  int m_noHealHealth;
  bool cuffed = false;

  std::shared_ptr<EventBus> bus;

  void subscribe();
};
