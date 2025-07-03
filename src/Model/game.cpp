#include "../../include/Common/common.h"
#include "../../include/Model/game.h"

Game::Game(EventBus& bus) : bus(bus) {
  this->subscribe();
}

void Game::onItemUsedEvent(std::shared_ptr<ItemUsedEvent> event) {
  if(event->getUsername() == "me" && event->getPos() < items_me.size()) {
    items_me.erase(items_me.begin() + event->getPos());
  } else if(event->getUsername() == "ai" && event->getPos() < items_ai.size()) {
    items_ai.erase(items_ai.begin() + event->getPos());
  }
}

void Game::initItems() {
  throw std::runtime_error("Not implemented for the first demo");
}

void Game::subscribe() {
  std::weak_ptr w_self = shared_from_this();
  bus.subscribe<ItemUsedEvent>([w_self](EventPtr e){
    if (auto self = w_self.lock()) { 
      auto itemUsedEvent = std::static_pointer_cast<ItemUsedEvent>(e);
      self->onItemUsedEvent(itemUsedEvent);
    } 
  });
}