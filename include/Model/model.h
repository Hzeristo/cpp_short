#pragma once

#include "Common/common.h"
#include "components/gun.h"
#include "components/item.h"
#include "components/player.h"

class Model {
public: 
  using IsUserAliveCallback = std::function<void(bool)>;
  using IsAiAliveCallback = std::function<void(bool)>;
  using StringCallback = std::function<void(std::string)>;
  using TurnDoneCallback = std::function<void()>;
  using ReloadCallback = std::function<void(int)>;
  using healthCallback = std::function<void(std::string, int)>;
  using bulletInfoCallback = std::function<void(std::string)>;
  using aiActionCallback = std::function<void(bool)>;

  void addIsUserAliveListener(IsUserAliveCallback cb) {
    isUserAliveListeners.push_back(std::move(cb));
  }

  void addIsAiAliveListener(IsAiAliveCallback cb) {
    isAiAliveListeners.push_back(std::move(cb));
  }

  void addStringCallback(StringCallback cb) {
    stringListeners.push_back(std::move(cb));
  }

  void addTurnDoneCallback(TurnDoneCallback cb) {
    turnDoneListeners.push_back(std::move(cb));
  }

  void addReloadCallback(ReloadCallback cb) {
    reloadListeners.push_back(std::move(cb));
  }

  void addHealthCallback(healthCallback cb) {
    healthListeners.push_back(std::move(cb));
  }

  void addBulletInfoCallback(std::function<void(std::string)> cb) {
    bulletInfoListeners.push_back(std::move(cb));
  }

  void addAiActionCallback(aiActionCallback cb) {
    aiActionListeners.push_back(std::move(cb));
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

  void aiShoot(std::string username, std::string targetname);

  bool checkEnd() const;
  void setAlive();

  void initItems(std::string name, int num);

  ItemType getItemType(std::string name, int pos) const;
  const Item& getItem(std::string name, int pos) const;

  bool useItem(std::string username, std::string targetname, int pos);

  void aiTurn();
  
  void nextTurn();

private: 

  std::unique_ptr<Gun> gun;
  std::unique_ptr<Player> player_ai;
  std::unique_ptr<Player> player_user;

  std::vector<std::shared_ptr<Item>> ai_items;
  std::vector<std::shared_ptr<Item>> user_items;

  std::vector<IsUserAliveCallback> isUserAliveListeners;
  std::vector<IsAiAliveCallback> isAiAliveListeners;
  std::vector<StringCallback> stringListeners;
  std::vector<TurnDoneCallback> turnDoneListeners;
  std::vector<ReloadCallback> reloadListeners;
  std::vector<healthCallback> healthListeners;
  std::vector<bulletInfoCallback> bulletInfoListeners;
  std::vector<aiActionCallback> aiActionListeners;

  bool running = false;
  bool isAlive_ai = true;
  bool isAlive_user = true;
  int turn = 0;

  bool is_me;
  int same_turn = 0;
};