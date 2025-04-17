#ifndef ICHECKF_H
#define ICHECKF_H

#include <iostream>
#include "ICommand.h"

using namespace std;


class checkFunctionCommand : public ICommand{
public:
    void execute() override{check();}
    void check() {}
};

#endif