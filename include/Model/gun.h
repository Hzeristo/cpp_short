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