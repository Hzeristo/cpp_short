#pragma once

#include <iostream>
#include <memory>


//不全
enum class ItemType {
  Beer,
  Saw,
  Magnifier,
  Cuff,
  Inverter
};

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