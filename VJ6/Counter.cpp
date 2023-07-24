#include <iostream>
#include "Spider.hpp"
#include "Insect.hpp"
#include "Bird.hpp"
#include "Counter.hpp"
using namespace std;

void Counter::add(Spider& spider) {
    sum += spider.getLegsNumber();
    cout << "Added: " << spider.getName() << endl;
}

void Counter::add(Insect& insect) {
    sum += insect.getLegsNumber();
    cout << "Added: " << insect.getName() << endl;
}

void Counter::add(Bird& bird) {
    sum += bird.getLegsNumber();
    cout << "Added: " << bird.getName() << endl;
}

int Counter::getSum() {
    cout << "Total number of legs: " << sum << endl;
    return sum;
}