#include "../../../include/Model/components/player.h"

Player::Player(std::string name, int health, int maxHealth, int noHealHealth) {
  std::cout << "Player with name: " << name << " created" << std::endl;
}
Player::~Player() {
  std::cout << "Player destroyed" << std::endl;
}