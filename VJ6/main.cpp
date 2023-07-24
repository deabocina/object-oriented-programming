#include <iostream>
#include <string>
#include "Bee.hpp"
#include "Tarantula.hpp"
#include "Falcon.hpp"
#include "Counter.hpp"
using namespace std;

// Define an interface "Animal" with methods that return the number of legs and the species(string) of the animal.
// Implement classes for animals : "Insect," "Spider," and "Bird," and from them, create classes for specific animals.
// Write a class "Counter" that receives animals (prints the species of each added animal) and calculates the total number of legs of all animals.

int main() {
    Bee bee1;
    bee1.setName("Bee");
    bee1.setLegsNumber(6);

    Tarantula tarantula1;
    tarantula1.setName("Tarantula");
    tarantula1.setLegsNumber(8);

    Falcon falcon1;
    falcon1.setName("Falcon");
    falcon1.setLegsNumber(2);

    Falcon falcon2;
    falcon2.setName("Falcon");
    falcon2.setLegsNumber(2);

    Counter counter;
    counter.add(bee1);
    counter.add(tarantula1);
    counter.add(falcon1);
    counter.add(falcon2);
    counter.getSum();

    return 0;
}