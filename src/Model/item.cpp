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

Item::Item(ItemType type, EventBus& bus) : type(type), bus(bus) {
  throw std::runtime_error("Not implemented for the first demo");
}

void Item::use(std::string name) {
  throw std::runtime_error("Not implemented for the first demo");
}