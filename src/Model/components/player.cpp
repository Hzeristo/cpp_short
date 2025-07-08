#include "../../../include/Model/components/player.h"

Player::Player(std::string name, int health, int maxHealth, int noHealHealth) 
  : m_name(name), m_health(health), m_maxHealth(maxHealth), m_noHealHealth(noHealHealth) {
  std::cout << "Player with name: " << name << " and health: " << health << " created" << std::endl;
}
Player::~Player() {
  std::cout << "Player destroyed" << std::endl;
}