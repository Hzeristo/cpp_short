#pragma once

#include "../../Common/common.h"

class Player;
using PlayerPtr = std::shared_ptr<Player>;
class Player {
public:
  Player(std::string name, int health, int maxHealth, int noHealHealth);
  ~Player();

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

  int getHealth() {
    return m_health;
  }

  int getMaxHealth() {
    return m_maxHealth;
  }

  int getNoHealHealth() {
    return m_noHealHealth;
  }

  bool getCuffed() {
    return m_cuffed;
  }

private:
  std::string m_name;
  int m_health;
  int m_maxHealth;
  int m_noHealHealth;

  bool m_cuffed = false;
};