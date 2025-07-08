#pragma once
#include "../Common/common.h"
#include "../mainwindow.h"
#include "../ViewModel/viewmodel.h"

class App : public QObject {
    Q_OBJECT
public:
    App(MainWindow& window);
    ~App() {};
private:
    MainWindow& mainWindow;
    ViewModel* viewModel;
};
    
