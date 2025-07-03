#pragma once

#include "../Common/common.h"
#include "../event.h"

class Gun;
using GunPtr = std::shared_ptr<Gun>;
class Gun : public std::enable_shared_from_this<Gun> {
public:
  Gun(EventBus& bus);
  ~Gun() {};

  bool getBulletType(int index);

  void invertCurrentBulletType();

  void shoot(std::string username, std::string targetname);

  void onFireEvent(std::shared_ptr<FireEvent> event);

  void onItemUsedSawEvent();

  void subscribe(EventBus& bus);

private:
  bool cut = false;
  std::vector<bool> bullets;
  EventBus& bus;
};
