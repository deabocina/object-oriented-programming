#pragma once
#include <iostream>
#include <string>
using namespace std;

class Animal {
public:
    virtual void setName(string text) = 0;
    virtual void setLegsNumber(int number) = 0;
    virtual int getLegsNumber() = 0;
    virtual string getName() = 0;
};