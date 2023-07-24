#pragma once
#include "Animals.hpp"

class Bird : public Animal {
    int number_of_legs;
public:
    void setLegsNumber(int number);
    int getLegsNumber() override;
};