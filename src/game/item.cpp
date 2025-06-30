#include "common.h"
#include "item.h"

inline const std::string to_string(ItemType type) {
  switch (type) {
    case ItemType::Beer: return "Beer";
    case ItemType::Saw: return "Saw";
    case ItemType::Magnifier: return "Magnifier";
    case ItemType::Cuff: return "Cuff";
    case ItemType::Inverter: return "Inverter";
    default: return "Unknown";
  }
}

void Item::use(std::string name) {
  ItemUsedEvent event(this->type, name);
  EventBus::getInstance().publish(std::make_shared<const ItemUsedEvent>(event));
}