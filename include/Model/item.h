#pragma once

#include "../Common/common.h"
#include "../event.h"

//不全
enum class ItemType {
  Beer,
  Saw,
  Magnifier,
  Cuff,
  Inverter
};

inline const std::string to_string(ItemType type);

class Item;
using ItemPtr = std::shared_ptr<Item>;
class Item : public std::enable_shared_from_this<Item>{
public:
  explicit Item(ItemType type) : type(type) {}
  ~Item() {}

  std::shared_ptr<Item> getPtr() { return shared_from_this(); }
  void use(std::string name);

  ItemType type;
};

class ItemUsedEvent : public Event {
public:
  ItemUsedEvent(ItemPtr item, std::string name) : item(item), playerName(name) {}
  ~ItemUsedEvent() {}

  const std::string name() override { return "ItemUsedEvent"; }
  const std::string getItem() const { return ::to_string(item->type); }
  const std::string getPlayer() const { return playerName; }
  const std::string to_string() const { return "ItemUsedEvent: " + getItem() + " by " + getPlayer(); }

  ItemPtr item;
  std::string playerName;
};  