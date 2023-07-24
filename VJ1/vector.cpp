#include "vector.hpp"

void MyVector::vector_new (size_t sz) {
    size = 0, capacity = 1;
    arr = new int[capacity];
}

void MyVector::vector_delete() {
    delete(arr);
}

void MyVector::vector_push_back(int n) {
    if (size == capacity) {
        int* arr2 = new int[size];
        capacity *= 2;
        for (int i = 0; i < size; i++) {
            arr2[i] = arr[i];
        }
        arr = new int[capacity];
        for (int i = 0; i < size; i++) {
            arr[i] = arr2[i];
        }
        delete arr2;
    }
    arr[size] = n;
    size++;
}

void MyVector::vector_pop_back() {
    arr[size] == NULL;
    size--;
}

int& MyVector::vector_front() {
    return arr[0];
}

int& MyVector::vector_back() {
    arr[size - 1];
}

size_t MyVector::vector_size() {
    return size;
}

void MyVector::print_vector()
{
    for (size_t i = 0; i < vector_size(); ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}