#pragma once
#include "Spider.hpp"

class Tarantula : public Spider {
    string species;
public:
    void setName(string name);
    string getName() override;
};