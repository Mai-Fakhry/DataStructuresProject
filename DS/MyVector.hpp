#ifndef MYVECTOR_HPP
#define MYVECTOR_HPP

#include <stdexcept>
#include <iostream>

template <typename T>
class MyVector {
private:
    T* data;          // Pointer to the dynamically allocated array
    size_t size;      // Current number of elements
    size_t capacity;  // Maximum capacity before resizing

    void resize() {   // Resize the internal array if needed
        capacity *= 2;
        T* newData = new T[capacity];
        for (size_t i = 0; i < size; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }

public:
    MyVector() : size(0), capacity(10) {  // Constructor
        data = new T[capacity];
    }

    ~MyVector() {  // Destructor
        delete[] data;
    }

    void push_back(const T& value) {  // Add an element at the end
        if (size >= capacity) {
            resize();
        }
        data[size] = value;
        ++size;
    }

    T& at(size_t index) const {  // Access element at index
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    size_t getSize() const {  // Get the current size
        return size;
    }

    void clear() {  // Clear the vector
        size = 0;
    }

    bool isEmpty() const {  // Check if the vector is empty
        return size == 0;
    }
};

#endif
