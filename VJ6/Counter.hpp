#pragma once
#include "Spider.hpp"
#include "Insect.hpp"
#include "Bird.hpp"

class Counter {
    int sum = 0;
public:
    void add(Spider& spider);
    void add(Insect& insect);
    void add(Bird& bird);
    int getSum();
};