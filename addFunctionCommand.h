#ifndef IADDF_H
#define IADDF_H

#include <iostream>
#include "ICommand.h"


using namespace std;

class addFunctionCommand : public ICommand{
public:
    void execute() override {add();}
    void add() {}
};

#endif