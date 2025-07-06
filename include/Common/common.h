#pragma once

#include <iostream>
#include <memory>
#include <vector>
#include <random>

//不全
enum class ItemType {
  Beer,
  Saw,
  Magnifier,
  Cuff,
  Inverter,
  Unknown,
  ItemType_Max
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

inline const ItemType from_string(const std::string& type) {
  if (type == "Beer") return ItemType::Beer;
  if (type == "Saw") return ItemType::Saw;
  if (type == "Magnifier") return ItemType::Magnifier;
  if (type == "Cuff") return ItemType::Cuff;
  if (type == "Inverter") return ItemType::Inverter;
  return ItemType::Unknown;
}
