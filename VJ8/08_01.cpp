#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

// 1. Write a template function min that returns the smaller of two elements.The elements can be numbers or strings.
// 2. Define a template class for a set.Elements can be added to the set, removed from the set, and it is possible to check 
// if a certain element is in the set or not.
// 3. Write a template function for sorting an array.Write a specialization of this function for arrays of characters(char) 
// where there will be no distinction between uppercase and lowercase letters.
// 4. Write a template class Point and necessary operators so that the following program correctly prints the distance between 
// the given points.The distance between points(2, 3) and (3, 4) is 1.41421.

template <typename T>
T minElement(T a, T b) {
    if (a < b)
        return a;
    else
        return b;
}

template <typename T>
class Set {
private:
    vector<T> elements;
public:
    void add(T element) {
        if (!check(element)) {
            elements.push_back(element);
        }
    }

    void remove(T element) {
        for (int i = 0; i < elements.size(); i++) {
            if (elements[i] == element) {
                elements.erase(elements.begin() + i);
                break;
            }
        }
    }

    int check(T element) {
        for (int i = 0; i < elements.size(); i++) {
            if (elements[i] == element) {
                return 1;
            }
        }
        return 0;
    }
};

template <typename T>
void sortArray(T* array, int size) {
    sort(array, array + size);
}

void sortCharArray(char* array, int size) {
    sort(array, array + size, [](char a, char b) {
        return tolower(a) < tolower(b);
        });
}

template <typename T>
class Point {
private:
    T x, y;
public:
    Point(T x, T y) : x(x), y(y) {}

    T operator - (const Point<T>& other) const {
        return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
    }
    friend ostream& operator << (ostream& os, const Point<T>& point) {
        os << "(" << point.x << "," << point.y << ")";
        return os;
    }
};

int main() {
    cout << "The minimum element is: " << minElement(5, 9) << endl;
    cout << "The minimum element is: " << minElement('x', 'd') << endl;

    Set<int> mySet;
    mySet.add(1);
    mySet.add(2);
    mySet.add(3);
    cout << mySet.check(1) << endl;
    cout << mySet.check(4) << endl;
    mySet.remove(2);
    cout << mySet.check(2) << endl;

    char charArray[] = { 'a','A','c','C','d','D' };
    int size = sizeof(charArray) / sizeof(charArray[0]);
    sortCharArray(charArray, size);
    for (int i = 0; i < size; i++) {
        cout << charArray[i] << " ";
    }

    cout << endl;
    Point<double> p1(2, 3), p2(3, 4);
    cout << "Distance between points " << p1 << " and " << p2 << " is " << p1 - p2 << endl;

    return 0;
}