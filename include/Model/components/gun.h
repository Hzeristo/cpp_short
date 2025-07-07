#pragma once

#include "../../Common/common.h"

class Gun;
using GunPtr = std::shared_ptr<Gun>;
class Gun {
public:
  Gun();
  ~Gun() {};

  void initBullets(int num);

  bool isEmpty() const;

  bool getBulletType(int index) const;

  bool getCut() const;

  const std::vector<char>& getBullets() const;

  void setBulletType(int index, bool type);

  bool invertCurrentBulletType();

  int shoot(); // shoot with return value of damage

private:
  bool cut = false;
  std::vector<char> bullets;

  bool checkBulletIndex(int index) const;
};
