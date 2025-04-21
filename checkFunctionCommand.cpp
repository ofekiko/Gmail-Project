#ifndef ICHECKF_H
#define ICHECKF_H

#include <iostream>
#include "ICommand.h"
#include "BloomFilter.cpp"

using namespace std;


class checkFunctionCommand : public ICommand{
    private:
    BloomFilter BF;
    string url;
public:
    void execute() {
        BF.checkURL(url);
    }
    void check() {}
};

#endif