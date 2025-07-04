#include <iostream>
#include <QApplication>
#include "../include/mainwindow.h"


int main(int argc, char *argv[]) {

    std::shared_ptr<EventBus> bus = std::make_shared<EventBus>();

    Game game(bus);

    Player player_me("me", 5, 5, 1, bus);
    Player player_ai("ai", 5, 5, 1, bus);

    Gun gun(bus);

    QApplication app(argc, argv);
    MainWindow window;
    window.resize(1200, 750);
    window.show();    

    return app.exec();             
}
