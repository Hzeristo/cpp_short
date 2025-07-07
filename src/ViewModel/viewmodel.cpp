#include "../include/ViewModel/viewmodel.h"

ViewModel::ViewModel(QObject* parent) : QObject(parent) {
  app = std::make_unique<App>();
  this->init();
}

void ViewModel::init() {
  app->init();

  app->addOperatorCallback([this](std::string name) {
    
  });

  app->addTurnDoneCallback([this]() {
    
  });

  app->addIsUserAliveListener([this](bool alive) {
    
  });

  app->addIsAiAliveListener([this](bool alive) {
    
  });
}

void ViewModel::playerShootSelf() {
  if(app->gunEmpty()) {
    app->reload(1);
    emit statusChanged("Reloading");
  }
  app->shoot("me", "me");
  
}

void ViewModel::playerShootOpponent() {
  if(app->gunEmpty()) {
    app->reload(1);
    //emit
  }
  app->shoot("me", "opponent");
}

