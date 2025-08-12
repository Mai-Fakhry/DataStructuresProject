#ifndef DSTACK_HPP
#define DSTACK_HPP

#include <iostream>
#include <cassert>
#include "Post.hpp"

using namespace std;

typedef Post StackElement;

class Stack {
private:
    int myCapacity;
    int myTop;
    StackElement* myArray;

public:
    Stack(int numElements = 10) {
        assert(numElements > 0);
        myCapacity = numElements;
        
        try {
            myArray = new StackElement[myCapacity];
        } catch (bad_alloc& e) {
            cerr << "Memory allocation failed: " << e.what() << endl;
            exit(1);  // Terminate the program if memory allocation fails
        }

        myTop = -1;
    }

    ~Stack() {
        delete[] myArray;
    }

    bool isEmpty() const {
        return (myTop == -1);
    }

    void push(const StackElement& value) {
        if (myTop < myCapacity - 1) {
            myArray[++myTop] = value;
        } else {
            cerr << "Stack is full. Cannot push more elements." << endl;
            exit(1);
        }
    }

    void pop() {
        if (isEmpty()) {
            cerr << "Stack is empty. Cannot pop." << endl;
            exit(1);
        }
        --myTop;
    }

    StackElement top() const {
        if (isEmpty()) {
            cerr << "Stack is empty. Cannot access top element." << endl;
            exit(1);
        }
        return myArray[myTop];
    }

    void display(ostream& out) const {
        for (int i = myTop; i >= 0; --i) {
            out << myArray[i] << endl;
        }
    }

    int size() const {
        return myTop + 1;
    }
};

#endif
