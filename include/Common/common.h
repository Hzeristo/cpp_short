#pragma once

#include <iostream>
#include <memory>
#include <vector>
#include <random>
#include <functional>
#include <thread>
#include <QTimer>

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

class Model;

inline std::string bullets2String(const std::vector<char>& bullets) {
    int real = 0, fake = 0;
    for (char c : bullets) {
        if (c == '1') ++real;
        else ++fake;
    }
    return "true: " + std::to_string(real) + " false: " + std::to_string(fake);
}