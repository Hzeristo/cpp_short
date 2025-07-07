#include "../../../include/Model/app.h"

App::App() {
  std::cout << "App initializing..." << std::endl;
  init();
  std::cout << "App initialized" << std::endl;
}

bool App::getOperator() const {
  return is_me;
}

void App::switchOperator() {
  is_me = !is_me;
  for (const auto& cb : operatorListeners) {
    cb(is_me ? "me" : "ai");
  }
}

void App::init() {
  std::cout << "New Game initializing..." << std::endl;
  gun = std::make_unique<Gun>();
  gun->initBullets(6);
  player_ai = std::make_unique<Player>("me", 4, 4, 1);
  player_user = std::make_unique<Player>("ai", 4, 4, 1);
  running = true;
  turn = 0;
  is_me = true;
  same_turn = 0;
  std::cout << "New Game initialized" << std::endl;
}

void App::restart() {
  init();
}

bool App::gunEmpty() const {
  return gun->isEmpty();
}

bool App::getBulletType(int index) const {
  return gun->getBulletType(index);
}

bool App::getCut() const {
  return gun->getCut();
}

int App::getGunSize() const {
  return (int)gun->getBullets().size();
}

const std::vector<char> &App::getBullets() const {
  return gun->getBullets();
}

bool App::invertCurrentBullet() {
  gun->invertCurrentBulletType();
  return true;
}

bool App::reload(int num = 6) {
  gun->initBullets(num);
  return true;
}

int App::getHealth(std::string name) const {
  if (name == "me") 
    return player_user->getHealth();
  return player_ai->getHealth();
}

int App::getMaxHealth(std::string name) const {
  if (name == "me") 
    return player_user->getMaxHealth();
  return player_ai->getMaxHealth();     
}

int App::getNoHealHealth(std::string name) const {
  if (name == "me") 
    return player_user->getNoHealHealth();
  return player_ai->getNoHealHealth();
}

bool App::getCuffed(std::string name) const {
  if (name == "me") 
    return player_user->getCuffed();
  return player_ai->getCuffed();
}

void App::shoot(std::string username, std::string targetname) {
  int damage = gun->shoot();
  targetname == "me" ? player_user->takeDamage(damage) : player_ai->takeDamage(damage);
  if ((username == targetname && damage > 0) || username != targetname && damage == 0) {
    switchOperator();
    same_turn = 0;
  } else {
    same_turn++;
  }
  if (same_turn >= 2) {
    switchOperator();
    same_turn = 0;
  }
  for (const auto& cb : turnDoneListeners) {
    cb();
  }
  setAlive();
  turn++;
  if(checkEnd()) 
    return;
  else 
    aiTurn();
}

bool App::checkEnd() const {
  return player_user->getHealth() <= 0 || player_ai->getHealth() <= 0;
}

void App::setAlive() {
  if(checkEnd()) {
    if (player_user->getHealth() <= 0) {
      isAlive_user = false;
      for (const auto& cb : isUserAliveListeners) {
        cb(false);
      }
    } else if (player_ai->getHealth() <= 0) {
      isAlive_ai = false;
      for (const auto& cb : isAiAliveListeners) {
        cb(false);
      }
    }
  }
}

void App::initItems(std::string name, int num) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> dist(0, static_cast<int>(ItemType::ItemType_Max) - 1);

  for (int i = 0; i < num; ++i) {
    ItemType randomType = static_cast<ItemType>(dist(gen));

    if (name == "me")
      user_items.push_back(std::make_shared<Item>(randomType));
    else
      ai_items.push_back(std::make_shared<Item>(randomType));
  }
}

ItemType App::getItemType(std::string name, int pos) const {
  if (name == "me") 
    return user_items[pos]->getType();
  else 
    return ai_items[pos]->getType();
}

const Item &App::getItem(std::string name, int pos) const {
  if (name == "me")
    return *user_items[pos];
  else 
    return *ai_items[pos];
}

bool App::useItem(std::string username, std::string targetname, int pos) {
  const auto &item = getItem(username, pos);
  if (username == "me") 
    user_items.erase(user_items.begin() + pos);
  else 
    ai_items.erase(ai_items.begin() + pos);
  // switch (item.getType())
  //   case ItemType::Beer: 
  //   case ItemType::Cuff: 
  //   case ItemType::Inverter:
  //   case ItemType::Magnifier:
  //   case ItemType::Saw:
  //   default:
  return false;
}

void App::aiTurn() {
  if(!player_ai->getCuffed()) {
    if(gunEmpty()) {
      reload();
      for (const auto& cb : reloadListeners) {
        cb(getGunSize());
      }
    }
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, 1);
    int action = dist(gen);
    if (action == 0) {
      shoot("ai", "ai");
    } else {
      shoot("ai", "user");
    }
  }
  turn++;
  for (const auto& cb : turnDoneListeners) {
    cb();
  }
  return; 
}
