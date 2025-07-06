#pragma once

#include "Common/common.h"
#include "components/gun.h"
#include "components/item.h"
#include "components/player.h"

class App {
public: 
  App();

  bool getOperator() const;
  void switchOperator();

  void init();

  bool gunEmpty() const;
  bool getBulletType(int index) const;
  bool getCut() const;

  const std::vector<char>& getBullets() const;
  
  bool invertCurrentBullet();
  bool reload(int num);
  
  int getHealth(std::string name) const;
  int getMaxHealth(std::string name) const; 
  int getNoHealHealth(std::string name) const;
  bool getCuffed(std::string name) const;
  
  bool shoot(std::string username, std::string targetname);

  bool checkEnd();

  void initItems(std::string name, int num);

  ItemType getItemType(std::string name, int pos) const;
  const Item& getItem(std::string name, int pos) const;

  bool useItem(std::string username, std::string targetname, int pos);

private: 
  std::unique_ptr<Gun> gun;
  std::unique_ptr<Player> player_ai;
  std::unique_ptr<Player> player_user;

  std::vector<std::shared_ptr<Item>> ai_items;
  std::vector<std::shared_ptr<Item>> user_items;

  bool is_me;
  int same_round = 0;
};