#pragma once

#include "../Common/common.h"
#include "../event.h"

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

class HealthEvent : public Event {
public:
  HealthEvent(int value, std::string target) : m_value(value), m_target(target) {};
  ~HealthEvent() {};
  
  int getValue() const { return m_value; };
  std::string getTarget() const { return m_target; };
  const std::string name() override { return m_name; };
private:
  int m_value;
  std::string m_target;
  const std::string m_name = "HealthEvent";
};

class Health2VMEvent : public Event {
public:
  Health2VMEvent(int value, std::string target) : m_value(value), m_target(target) {};
  ~Health2VMEvent() {};
  
  int getValue() const { return m_value; };
  std::string getTarget() const { return m_target; };
  const std::string name() override { return m_name; };
private:
  int m_value;
  std::string m_target;
  const std::string m_name = "Health2VMEvent";
};