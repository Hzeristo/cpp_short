#include "../../../include/Model/model.h"

Model::Model() {
  std::cout << "Model initializing..." << std::endl;
  init();
  std::cout << "Model initialized" << std::endl;
}

bool Model::getOperator() const {
  return is_me;
}

void Model::switchOperator() {
  is_me = !is_me;
  for (const auto& cb : stringListeners) {
    std::cout << "Operator changed" << std::endl;
    cb(is_me ? "me" : "ai");
  }
}

void Model::init() {
  std::cout << "New Game initializing..." << std::endl;
  gun = std::make_unique<Gun>();
  gun->initBullets(6);
  player_user = std::make_unique<Player>("me", 4, 4, 1);
  player_ai = std::make_unique<Player>("ai", 4, 4, 1);
  running = true;
  turn = 0;
  is_me = true;
  same_turn = 0;
  std::cout << "New Game initialized" << std::endl;
}

void Model::restart() {
  init();
}

bool Model::gunEmpty() const {
  std::cout << "Checking gun empty: " << gun->isEmpty() << std::endl;
  return gun->isEmpty();
}

bool Model::getBulletType(int index) const {
  return gun->getBulletType(index);
}

bool Model::getCut() const {
  return gun->getCut();
}

int Model::getGunSize() const {
  return (int)gun->getBullets().size();
}

const std::vector<char> &Model::getBullets() const {
  return gun->getBullets();
}

bool Model::invertCurrentBullet() {
  gun->invertCurrentBulletType();
  return true;
}

bool Model::reload(int num = 6) {
  gun->initBullets(num);
  return true;
}

int Model::getHealth(std::string name) const {
  if (name == "me") 
    return player_user->getHealth();
  return player_ai->getHealth();
}

int Model::getMaxHealth(std::string name) const {
  if (name == "me") 
    return player_user->getMaxHealth();
  return player_ai->getMaxHealth();     
}

int Model::getNoHealHealth(std::string name) const {
  if (name == "me") 
    return player_user->getNoHealHealth();
  return player_ai->getNoHealHealth();
}

bool Model::getCuffed(std::string name) const {
  if (name == "me") 
    return player_user->getCuffed();
  return player_ai->getCuffed();
}

void Model::shoot(std::string username, std::string targetname) {
  int damage = gun->shoot();
  targetname == "me" ? player_user->takeDamage(damage) : player_ai->takeDamage(damage);
  std::cout << "User: " << username << " shoot: " << targetname << " with damage: "  << damage << std::endl;
  std::cout << "Gun: " << bullets2String(gun->getBullets()) << std::endl;
  std::cout << "user: " << player_user->getHealth() << " ai: " << player_ai->getHealth() << std::endl;
  for (const auto& cb : healthListeners) {
    std::cout << "Health changed: " << targetname << " " << damage << std::endl;
    cb(targetname, (targetname == "me" ? player_user->getHealth() : player_ai->getHealth()));
  }
  bool switched = false;
  if ((username == targetname && damage > 0) || username != targetname && damage == 0) {
    std::cout << "switch operator" << std::endl;
    switchOperator();
    switched = true;
    same_turn = 0;
  } else {
    same_turn++;
  }
  if (same_turn >= 2) {
    switchOperator();
    switched = true;
    same_turn = 0;
  }
  for (const auto& cb : turnDoneListeners) {
    cb();
  }
  setAlive();
  turn++;
  if(switched) {
    aiTurn();
  }
  return;
}

void Model::aiShoot(std::string username, std::string targetname) {
  std::this_thread::sleep_for(std::chrono::seconds(2)); 
  int damage = gun->shoot();
  targetname == "me" ? player_user->takeDamage(damage) : player_ai->takeDamage(damage);
  std::cout << "User: " << username << " shoot: " << targetname << " with damage: "  << damage << std::endl;
  std::cout << "Gun: " << bullets2String(gun->getBullets()) << std::endl;
  std::cout << "user: " << player_user->getHealth() << " ai: " << player_ai->getHealth() << std::endl;
  for (const auto& cb : healthListeners) {
    std::cout << "Health changed: " << targetname << " " << damage << std::endl;
    cb(targetname, (targetname == "me" ? player_user->getHealth() : player_ai->getHealth()));
  }
  bool switched = false;
  if ((username == targetname && damage > 0) || username != targetname && damage == 0) {
    std::cout << "switch operator" << std::endl;
    switchOperator();
    switched = true;
    same_turn = 0;
  } else {
    same_turn++;
  }
  if (same_turn >= 2) {
    switchOperator();
    switched = true;
    same_turn = 0;
  }
  for (const auto& cb : turnDoneListeners) {
    cb();
  }
  setAlive();
  turn++;
  if(switched) {
    return;
  }
  aiTurn();
  return;
}

bool Model::checkEnd() const {
  std::cout << "Checking end: " << (player_user->getHealth() <= 0 || player_ai->getHealth() <= 0) << std::endl;
  return player_user->getHealth() <= 0 || player_ai->getHealth() <= 0;
}

void Model::setAlive() {
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

void Model::initItems(std::string name, int num) {
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

ItemType Model::getItemType(std::string name, int pos) const {
  if (name == "me") 
    return user_items[pos]->getType();
  else 
    return ai_items[pos]->getType();
}

const Item &Model::getItem(std::string name, int pos) const {
  if (name == "me")
    return *user_items[pos];
  else 
    return *ai_items[pos];
}

bool Model::useItem(std::string username, std::string targetname, int pos) {
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

void Model::aiTurn() {
  std::cout << "Ai turn" << std::endl;
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
      aiShoot("ai", "ai");
    } else {
      aiShoot("ai", "me");
    }
  }
  turn++;
  for (const auto& cb : turnDoneListeners) {
    std::cout << "Turn done" << std::endl;
    cb();
  }
  return; 
}
