#pragma once
#include "Animals.hpp"

class Spider : public Animal {
    int number_of_legs;
public:
    void setLegsNumber(int number);
    int getLegsNumber() override;
};