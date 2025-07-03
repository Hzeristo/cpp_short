#pragma once

#include "../Common/common.h"
#include "../event.h"

class Item;
using ItemPtr = std::shared_ptr<Item>;
class Item : public std::enable_shared_from_this<Item>{
public:
  Item(ItemType type, EventBus& bus);
  ~Item() { std::cout << "Item destoryed" << std::endl; }

  std::shared_ptr<Item> getPtr() { return shared_from_this(); }
  void use(std::string name);

  ItemType type;

  EventBus& bus;
};
