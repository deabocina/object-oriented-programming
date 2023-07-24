#pragma once
#include "Animals.hpp"

class Insect : public Animal {
    int number_of_legs;
public:
    void setLegsNumber(int number);
    int getLegsNumber() override;
};