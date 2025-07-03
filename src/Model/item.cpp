#include "../../include/Common/common.h"
#include "../../include/Model/item.h"
#include "../../include/Model/event.h"

Item::Item(ItemType type, EventBus& bus) : type(type), bus(bus) {
  throw std::runtime_error("Not implemented for the first demo");
}

void Item::use(std::string name) {
  throw std::runtime_error("Not implemented for the first demo");
}