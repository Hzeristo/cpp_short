#pragma once

#include "../Common/common.h"


class EventBus;
class Item;
using ItemPtr = std::shared_ptr<Item>;
class Item {
public:
  Item(ItemType type, std::shared_ptr<EventBus> bus);
  ~Item() { std::cout << "Item destoryed" << std::endl; }

  void use(std::string name);

  ItemType type;

  std::shared_ptr<EventBus> bus;
};
