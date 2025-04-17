#include "ConsoleMenu.h"

int ConsoleMenu::nextCommand() {
    string userInput;
    cin >> userInput;
    return stoi(userInput);
}
void ConsoleMenu::displayError(string error){
    cout << error << endl;
}

