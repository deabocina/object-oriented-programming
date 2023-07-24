#include <iostream>
#include <vector>
#include "vector.hpp"
using namespace OOP;

// 1. Create a class "Vec3" representing a 3D vector.Write the necessary constructors and destructors. Overload the following operators :
// Input and output operators(>> , << ),
// Assignment operator ( = ),
// Addition and subtraction operators(+, -) for vector addition and subtraction,
// Multiplication and division operators(*, / ) for scalar multiplication and division,
// Compound assignment operators(+=, -=, =, /=),
// Equality and inequality operators(== , != ) for element - wise comparison,
// Dot product operator (),
// Subscript operator ([]), to access individual vector coordinates.
//
// 2. Write a member function that normalizes the vector.
// 3. Place the class from the first task inside the namespace "OOP."

int main() {
    Vec3 a, b, c;
    int scalar;

    std::cin >> a;
    std::cin >> b;

    c = a + b;
    std::cout << c;
    c = a - b;
    std::cout << c;

    scalar = a * b;
    std::cout << scalar << std::endl;

    c = a * 2;
    std::cout << c;
    c = a / 3;
    std::cout << c;

    a += 2;
    std::cout << a;
    a -= 3;
    std::cout << a;

    a *= 2;
    std::cout << a;
    a /= 2;
    std::cout << a;

    a += b;
    std::cout << a;
    a -= b;
    std::cout << a;

    a *= b;
    std::cout << a;
    a /= b;
    std::cout << a;

    std::cout << a['x'] << " ";
    std::cout << a['y'] << " ";
    std::cout << a['z'] << std::endl;

    normalise(a);
    std::cout << a;
}