#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <stdexcept>
#include <iostream>

using namespace std;

template <typename T>
class Vector {
private:
    T* data;
    size_t capacity;
    size_t size;

    // Function to resize the array when it's full
    void resize() {
        capacity *= 2; // Double the capacity
        T* newData = new T[capacity];

        // Copy old elements to the new array
        for (size_t i = 0; i < size; ++i) {
            newData[i] = data[i];
        }

        // Delete the old array and update the pointer
        delete[] data;
        data = newData;
    }

public:
    MyVector() : data(new T[1]), capacity(1), size(0) {}

    ~MyVector() {
        delete[] data;
    }

    // Function to add an element at the end of the vector
    void push_back(const T& value) {
        if (size == capacity) {
            resize(); // Resize if capacity is reached
        }
        data[size++] = value;
    }

    // Function to access an element by index with bounds check (non-const)
    T& at(size_t index) {
        if (index >= size) {
            throw out_of_range("Index out of bounds");
        }
        return data[index];
    }

    // Const version of at() for const objects
    const T& at(size_t index) const {
        if (index >= size) {
            throw out_of_range("Index out of bounds");
        }
        return data[index];
    }

    // Function to access an element by index (non-const version)
    T& operator[](size_t index) {
        return data[index];
    }

    // Const version of operator[] (for const objects)
    const T& operator[](size_t index) const {
        return data[index];
    }


    size_t getSize() const {
        return size;
    }


    size_t getCapacity() const {
        return capacity;
    }


    bool isEmpty() const {
        return size == 0;
    }


    void clear() {
        size = 0; 
    }

    // Function to remove the last element of the vector
    void pop_back() {
        if (size > 0) {
            --size;
        }
    }

    // Function to insert an element at a specified index
    void insert(size_t index, const T& value) {
        if (index > size) {
            throw std::out_of_range("Index out of bounds");
        }

        if (size == capacity) {
            resize(); // Resize if capacity is reached
        }

        // Shift elements to the right to make space for the new element
        for (size_t i = size; i > index; --i) {
            data[i] = data[i - 1];
        }

        data[index] = value;
        ++size;
    }

    // Function to remove an element at a specified index
    void erase(size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of bounds");
        }

        // Shift elements to the left to fill the gap
        for (size_t i = index; i < size - 1; ++i) {
            data[i] = data[i + 1];
        }

        --size;
    }

    // Function to display the contents of the vector
    void display() const {
        for (size_t i = 0; i < size; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }

    // Iterator functions to support range-based for loops
    T* begin() {
        return data;
    }

    T* end() {
        return data + size;
    }

    const T* begin() const {
        return data;
    }

    const T* end() const {
        return data + size;
    }
};

#endif
