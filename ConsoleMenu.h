#ifndef ICONSOLEMENU_H
#define ICONSOLEMENU_H

#include <iostream>
#include "IMenu.h"

using namespace std;


class ConsoleMenu : public IMenu{
public:
    int nextCommand();
    void displayError(std::string error);     
};

#endif