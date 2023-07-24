#pragma once
#include "Bird.hpp"

class Falcon : public Bird {
    string species;
public:
    void setName(string name);
    string getName() override;
};