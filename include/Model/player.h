#pragma once

#include "../Common/common.h"
#include "event.h"

class Player;
using PlayerPtr = std::shared_ptr<Player>;
class Player : std::enable_shared_from_this<Player> {
public:
  Player(int maxHealth, int health, int noHealHealth, EventBus& bus);
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
  }

  void onTryItemUseEvent(const TryItemUseEvent& event);

private:
  int m_maxHealth;
  int m_health;
  int m_noHealHealth;
  bool cuffed = false;

  EventBus& bus;

  void subscribe();
};