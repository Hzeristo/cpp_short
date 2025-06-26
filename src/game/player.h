#pragma once

#include "common.h"
#include "event.h"
#include "item.h"

class Player {

private:
  int m_maxHealth;
  int m_health;
  int m_noHealHealth;

};

class HealthEvent : public Event {
public:
  HealthEvent(int value) : m_value(value) {};
  ~HealthEvent() {};
  int value() const;
  const std::string name() override { return m_name; };
private:
  int m_value;
  const std::string m_name = "HealthEvent";
};