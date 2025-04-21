#ifndef IADDF_H
#define IADDF_H

#include <iostream>
#include "ICommand.h"
#include "addFunctionCommand.h"
#include "BloomFilter.h"
#include "BloomFilter.cpp"
using namespace std;

class addFunctionCommand: public ICommand{
private:
    BloomFilter BF;
    string url;
public:
    void setBF(BloomFilter BF){
        this->BF = BF;
    }
    void execute()
    {
        BF.addURL(url);
    }
};

#endif
