#pragma once

#include "Common/common.h"
#include <functional>
#include <typeindex>
#include <unordered_map>
#include <mutex>

//事件基类
class Event;
using EventPtr = std::shared_ptr<Event>;
class Event {
public:
  virtual ~Event() = default;
  virtual const std::string name() = 0;
};

class FireEvent;
class OperatorChangeEvent;
class Bullet2VMEvent;
class Gun2VMEvent;

class HealthEvent;
class Health2VMEvent;

class ItemUsedEvent;
class TryItemUseEvent;

class ItemUsedCuffEvent;
class ItemUsedBeerEvent;
class ItemUsedMagnifierEvent;
class ItemUsedInverterEvent;
class ItemUsedSawEvent;
class Item2VMEvent;

//事件总线
class EventBus {
public:
  using HandlerFunc = std::function<void(EventPtr)>;

  EventBus() {
    std::cout << "EventBus created" << std::endl;
  }

  ~EventBus() {
    std::cout << "EventBus destroyed" << std::endl;
  }

  // 禁止拷贝和移动
  EventBus(const EventBus&) = delete;
  EventBus(EventBus&&) = delete;
  EventBus& operator=(const EventBus&) = delete;

  template<typename T>
  void subscribe(HandlerFunc handler) {
    static_assert(std::is_base_of<Event, T>::value, "T must inherit from Event");
    std::lock_guard<std::mutex> lock(mutex);
    auto wrapper = [handler](EventPtr event) {
      auto casted = std::dynamic_pointer_cast<T>(event);
      if (casted) handler(casted);
    };
    m_listeners[typeid(T)].push_back(wrapper);
  }

  template<typename T>
  void publish(std::shared_ptr<T> event) {
    static_assert(std::is_base_of<Event, T>::value, "T must inherit from Event");

    std::vector<HandlerFunc> handlers_copy;
    {
      std::lock_guard<std::mutex> lock(mutex);
      auto it = m_listeners.find(typeid(T));
      if (it != m_listeners.end()) {
        handlers_copy = it->second;
      }
    }

    std::shared_ptr<Event> baseEvent = std::static_pointer_cast<Event>(event);

    for (auto& handler : handlers_copy) {
      handler(baseEvent);
    }
  }

private:
  std::unordered_map<std::type_index, std::vector<HandlerFunc>> m_listeners;
  std::mutex mutex;
};

class HealthEvent : public Event {
public:
  HealthEvent(int value, std::string target) : m_value(value), m_target(target) {};
  ~HealthEvent() {};
  
  int getValue() const { return m_value; };
  std::string getTarget() const { return m_target; };
  const std::string name() override { return m_name; };
private:
  int m_value;
  std::string m_target;
  const std::string m_name = "HealthEvent";
};

class Health2VMEvent : public Event {
public:
  Health2VMEvent(int value, std::string target) : m_value(value), m_target(target) {};
  ~Health2VMEvent() {};
  
  int getValue() const { return m_value; };
  std::string getTarget() const { return m_target; };
  const std::string name() override { return m_name; };
private:
  int m_value;
  std::string m_target;
  const std::string m_name = "Health2VMEvent";
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


class FireEvent : public Event {
public:
  FireEvent(std::string username, std::string targetname) : username(username), targetname(targetname) {};
  ~FireEvent() {};
  const std::string name() override { return "FireEvent"; }
  std::string getUsername() const { return username; }
  std::string getTargetname() const { return targetname; }

private:
  std::string username;
  std::string targetname;
};

class OperatorChangeEvent : public Event {
public:
  OperatorChangeEvent(std::string username, std::string targetname) : username(username), targetname(targetname) {};
  ~OperatorChangeEvent() {};
  const std::string name() override { return "OperatorChangeEvent"; }
  std::string getUsername() const { return username; }
  std::string getTargetname() const { return targetname; }

private:
  std::string username;
  std::string targetname;
};