#pragma once
#include "Insect.hpp"

class Bee : public Insect {
    string species;
public:
    void setName(string name);
    string getName() override;
};
