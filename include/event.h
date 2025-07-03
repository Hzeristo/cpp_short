#pragma once

#include "Common/common.h"
#include <functional>
#include <typeindex>
#include <unordered_map>
#include <mutex>

//事件基类
class Event;
using EventPtr = std::shared_ptr<Event>;
using ConstEventPtr = std::shared_ptr<const Event>;
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
  using HandlerFunc = std::function<void(ConstEventPtr)>;

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
    auto wrapper = [handler](ConstEventPtr event) {
      auto casted = std::dynamic_pointer_cast<const T>(event);
      if (casted) handler(casted);
    };
    m_listeners[typeid(T)].push_back(wrapper);
  }

  template<typename T>
  void publish(std::shared_ptr<const T> event) {
    static_assert(std::is_base_of<Event, T>::value, "T must inherit from Event");

    std::vector<HandlerFunc> handlers_copy;
    {
      std::lock_guard<std::mutex> lock(mutex);
      auto it = m_listeners.find(typeid(T));
      if (it != m_listeners.end()) {
        handlers_copy = it->second;
      }
    }

    for (auto& handler : handlers_copy) {
      handler(event);
    }
  }

private:
  std::unordered_map<std::type_index, std::vector<HandlerFunc>> m_listeners;
  std::mutex mutex;
};
