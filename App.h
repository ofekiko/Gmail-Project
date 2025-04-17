#ifndef IAPP_H
#define IAPP_H

#include <iostream>
#include "IMenu.h"
#include "ICommand.h"
#include <map>
#include "addFunctionCommand.h"
#include "checkFunctionCommand.h"
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class App {
private:
    IMenu* menu;
    map<int, ICommand*> commands;
public:
    App(IMenu* menu, map<int, ICommand*> commands) : menu(menu), commands(commands) {}
    void run();
};

#endif