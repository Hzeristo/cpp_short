#include "../include/ViewModel/viewmodel.h"

ViewModel::ViewModel(QObject* parent) : QObject(parent) {
  app = std::make_unique<Model>();
  this->init();
}

void ViewModel::init() {
  app->init();

  app->addOperatorCallback([this](std::string name) {
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
}

void ViewModel::playerShootSelf() {
  if(app->gunEmpty()) {
    app->reload(1);
    emit statusChanged("Reloading");
    const auto bullets = app->getBullets();
    emit reloaded(QString::fromStdString(bullets2String(bullets)));
  }
  app->shoot("me", "me");
  
}

void ViewModel::playerShootOpponent() {
  if(app->gunEmpty()) {
    app->reload(1);
    emit statusChanged("Reloading");
    const auto bullets = app->getBullets();
    emit reloaded(QString::fromStdString(bullets2String(bullets)));
  }
  app->shoot("me", "opponent");
}

