#include "../../../include/Model/components/gun.h"

Gun::Gun() {
  std::cout << "Gun initiated" << std::endl;
}

void Gun::initBullets(int num) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::bernoulli_distribution dist(0.5);
  bullets.clear();
  for (int i = 0; i < num; ++i) {
    bullets.push_back(dist(gen));  // 返回的是 true/false，隐式转 char
  }
}

bool Gun::isEmpty() const {
  return bullets.empty();
}

bool Gun::getBulletType(int index) const {
  if(!checkBulletIndex(index)) return;
  return bullets[index];
}

void Gun::setBulletType(int index, bool type) {
  if(!checkBulletIndex(index)) return;
  bullets[index] = type;
}

const std::vector<char>&Gun::getBullets() const {
  return bullets;
} 

bool Gun::invertCurrentBulletType() {
  if(bullets.size() > 0) {
    bullets.back() = !bullets.back();
    return true;
  }
  return false; 
}

int Gun::shoot(){
  if(bullets.size() > 0) {
    return bullets.back() ? 0 : (cut ? 1 : 2);
  }
  return 0;
}

bool Gun::checkBulletIndex(int index) const{
  return index >= 0 && index < bullets.size();
}