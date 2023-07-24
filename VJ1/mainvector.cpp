#include "vector.hpp"
using namespace std;

// Define a structure that describes a vector. The structure consists of an array of int elements,
// logical size, and physical size of the array. The physical size is initially 'init', and when it
// is filled with values, it is doubled.
// Write functions vector_new, vector_delete, vector_push_back, vector_pop_back,
// vector_front, vector_back i vector_size. The functions are the elements of the structure.

int main() {
    MyVector mv;
    mv.vector_new();
    
    int m;
    cout << "Enter elements, Ctrl+d (Linux) or Ctrl+z (Windows) to end input" << endl;
    while (cin >> m)
        mv.vector_push_back(m);
    
    cout << "First element " << mv.vector_front() << endl;
    cout << "Last element " << mv.vector_back() << endl;
    mv.print_vector();

    cout << "Removing last element" << endl;
    mv.vector_pop_back();
    mv.print_vector();

    cout << "Size " << mv.vector_size() << endl;
    cout << "Capacity " << mv.capacity << endl;

    mv.vector_delete();
}