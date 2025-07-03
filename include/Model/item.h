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
  Item(ItemType type, EventBus& bus);
  ~Item() { std::cout << "Item destoryed" << std::endl; }

  std::shared_ptr<Item> getPtr() { return shared_from_this(); }
  void use(std::string name);

  ItemType type;

  EventBus& bus;
};

class ItemUsedEvent : public Event {
public:
  ItemUsedEvent(ItemType item, std::string username, std::string targetname, int pos) : item(item), username(username), targetname(targetname), pos(pos) {}
  ~ItemUsedEvent() {}

  const std::string name() override { return "ItemUsedEvent"; }
  const std::string getItem() const { return ::to_string(item); }
  const std::string getUsername() const { return username; }
  const std::string getTargetname() const { return targetname; }
  const int getPos() const { return pos; }
  const std::string to_string() const { return "ItemUsedEvent: " + getItem() + " by " + getUsername() + " to " + getTargetname(); }

private:
  ItemType item;
  std::string username;
  std::string targetname;
  int pos;
};  

class TryItemUseEvent : public Event {
public:
  TryItemUseEvent(ItemType item, std::string username, std::string targetname, int pos) : item(item), username(username), targetname(targetname), pos(pos) {}
  ~TryItemUseEvent() {}

  const std::string name() override { return "ItemUsedEvent"; }
  const std::string getItem() const { return ::to_string(item); }
  const std::string getUsername() const { return username; }
  const std::string getTargetname() const { return targetname; }
  const int getPos() const { return pos; }
  const std::string to_string() const { return "ItemUsedEvent: " + getItem() + " by " + getUsername() + " to " + getTargetname(); }

private:
  ItemType item;
  std::string username;
  std::string targetname;
  int pos;
};

class Item2VMEvent : public Event {
public: 
  Item2VMEvent(ItemType item, int pos) : item(item), pos(pos) {}
  ~Item2VMEvent() {};
  const std::string name() override { return "Item2VMEvent"; }
  const std::string getItem() const { return ::to_string(item); }
  const int getPos() const { return pos; }
  const std::string to_string() const { return "Item2VMEvent: " + getItem() + " at " + std::to_string(pos); }

private:
  ItemType item;
  int pos; //0-7
};