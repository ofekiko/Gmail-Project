#ifndef IMENU_H
#define IMENU_H

#include <string>

class IMenu{
    public:
    virtual int nextCommand() = 0;
    virtual void displayError(std::string error) = 0;
};


#endif