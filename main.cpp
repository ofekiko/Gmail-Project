#include <iostream>
#include "IMenu.h"
#include "ICommand.h"
#include <map>
#include "addFunctionCommand.h"
#include "checkFunctionCommand.h"
#include "ConsoleMenu.h"
#include "App.h"

using namespace std;

int main(){
    map<int, ICommand*> commands;
    ICommand* AddFunctionCommand = new addFunctionCommand();
    commands[1] = AddFunctionCommand;
    ICommand* CheckFunctionCommand = new checkFunctionCommand();
    commands[2] = CheckFunctionCommand;

    ConsoleMenu *consoleMenu = new ConsoleMenu();
    App *app = new App(consoleMenu,commands);

    app->run();

// TODO: add code to allow graceful exit
// delete displayArticles;
// delete addArticle;
}
