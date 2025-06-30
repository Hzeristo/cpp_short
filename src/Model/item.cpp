#include "../../include/Common/common.h"
#include "../../include/Model/item.h"

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
  switch (type) {
    case ItemType::Beer: {
      ItemUsedEvent event(std::make_shared<Item>(this), name);
      EventBus::getInstance().publish(std::make_shared<const ItemUsedEvent>(event));
      break;
    }
    case ItemType::Saw: return ;
    case ItemType::Magnifier: return ;
    case ItemType::Cuff: return ;
    case ItemType::Inverter: return ;
    default: return ;
  } 
}