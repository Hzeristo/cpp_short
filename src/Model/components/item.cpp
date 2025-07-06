#include "../../../include/Model/components/item.h"
#include "item.h"

Item::Item(ItemType type) {
  this->type = type;
  std::cout << "Item with type: " << to_string(type) << " created" << std::endl;
}

Item::Item(std::string type) {
  this->type = from_string(type);
  std::cout << "Item with type: " << type << " created" << std::endl;
}