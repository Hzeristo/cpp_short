#include "../include/ViewModel/viewmodel.h"

ViewModel::ViewModel(QObject* parent) : QObject(parent) {
  std::cout << "ViewModel initializing" << std::endl;
  app = std::make_unique<Model>();
  this->init();
  std::cout << "ViewModel initialized" << std::endl;
}

void ViewModel::init() {
  app->addStringCallback([this](std::string name) {
    std::cout << "operatorChanged signal emitted" << std::endl;
    emit operatorChanged(QString::fromStdString(name));
  });

  app->addTurnDoneCallback([this]() {
    emit turnDone();
  });

  app->addIsUserAliveListener([this](bool alive) {
    emit userDead();
  });

  app->addIsAiAliveListener([this](bool alive) {
    emit aiDead();
  });

  app->addHealthCallback([this](std::string name, int health) {
    emit healthChanged(QString::fromStdString(name), health);
  });
}

void ViewModel::playerShootSelf() {
  std::cout << "playerShootSelf" << std::endl;
  if(app->gunEmpty()) {
    std::cout << "Reloading..." << std::endl;
    app->reload(1);
    emit statusChanged("Reloading");
    const auto bullets = app->getBullets();
    emit reloaded(QString::fromStdString(bullets2String(bullets)));
  }
  app->shoot("me", "me");
  return;
}

void ViewModel::playerShootOpponent() {
  std::cout << "playerShootOpponent" << std::endl;
  if(app->gunEmpty()) {
    app->reload(1);
    emit statusChanged("Reloading");
    const auto bullets = app->getBullets();
    emit reloaded(QString::fromStdString(bullets2String(bullets)));
  }
  app->shoot("me", "opponent");
  return;
}

