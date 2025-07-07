#pragma once

#include "../../Common/common.h"

class Item;
using ItemPtr = std::shared_ptr<Item>;
class Item {
public:
  Item(ItemType type);
  Item(std::string type);
  ~Item() { std::cout << "Item destoryed" << std::endl; }

  ItemType getType() const { return type; }

  void use(std::string name);
private:
  ItemType type;
};