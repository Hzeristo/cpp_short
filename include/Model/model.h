#pragma once

#include "Common/common.h"
#include "components/gun.h"
#include "components/item.h"
#include "components/player.h"

class Model {
public: 
  using IsUserAliveCallback = std::function<void(bool)>;
  using IsAiAliveCallback = std::function<void(bool)>;
  using OperatorCallback = std::function<void(std::string)>;
  using TurnDoneCallback = std::function<void()>;
  using ReloadCallback = std::function<void(int)>;

  void addIsUserAliveListener(IsUserAliveCallback cb) {
    isUserAliveListeners.push_back(std::move(cb));
  }

  void addIsAiAliveListener(IsAiAliveCallback cb) {
    isAiAliveListeners.push_back(std::move(cb));
  }

  void addOperatorCallback(OperatorCallback cb) {
    operatorListeners.push_back(std::move(cb));
  }

  void addTurnDoneCallback(TurnDoneCallback cb) {
    turnDoneListeners.push_back(std::move(cb));
  }

  void addReloadCallback(ReloadCallback cb) {
    reloadListeners.push_back(std::move(cb));
  }

  Model();

  bool getOperator() const;
  void switchOperator();

  void init();

  void restart();

  bool gunEmpty() const;
  bool getBulletType(int index) const;
  bool getCut() const;
  int getGunSize() const;

  const std::vector<char>& getBullets() const;
  
  bool invertCurrentBullet();
  bool reload(int num);
  
  int getHealth(std::string name) const;
  int getMaxHealth(std::string name) const; 
  int getNoHealHealth(std::string name) const;
  bool getCuffed(std::string name) const;
  //包括子弹减少，击中受伤，交换操作方，通知轮次结束的功能
  void shoot(std::string username, std::string targetname);

  bool checkEnd() const;
  void setAlive();

  void initItems(std::string name, int num);

  ItemType getItemType(std::string name, int pos) const;
  const Item& getItem(std::string name, int pos) const;

  bool useItem(std::string username, std::string targetname, int pos);

private: 
  void aiTurn();

  std::unique_ptr<Gun> gun;
  std::unique_ptr<Player> player_ai;
  std::unique_ptr<Player> player_user;

  std::vector<std::shared_ptr<Item>> ai_items;
  std::vector<std::shared_ptr<Item>> user_items;

  std::vector<IsUserAliveCallback> isUserAliveListeners;
  std::vector<IsAiAliveCallback> isAiAliveListeners;
  std::vector<OperatorCallback> operatorListeners;
  std::vector<TurnDoneCallback> turnDoneListeners;
  std::vector<ReloadCallback> reloadListeners;

  bool running = false;
  bool isAlive_ai = true;
  bool isAlive_user = true;
  int turn = 0;

  bool is_me;
  int same_turn = 0;
};