#ifndef IADDF_H
#define IADDF_H

#include <iostream>
#include "ICommand.h"
#include "BloomFilter.h"
#include "BloomFilter.cpp"
using namespace std;

class addFunctionCommand: public ICommand{
public:
    void execute(){};
};

#endif
