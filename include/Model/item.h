#pragma once

#include "../Common/common.h"


class EventBus;
class Item;
using ItemPtr = std::shared_ptr<Item>;
class Item {
public:
  Item(ItemType type, EventBus& bus);
  ~Item() { std::cout << "Item destoryed" << std::endl; }

  void use(std::string name);

  ItemType type;

  EventBus& bus;
};
