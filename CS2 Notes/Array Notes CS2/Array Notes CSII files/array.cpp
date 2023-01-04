


#include "array.hpp"
#include <cstdlib>

// REQUIRES n >= 0
Darray::Darray(int n) {
    cap = n;
    ptr = new int[cap];
}

Darray::~Darray() {
    delete[] ptr;
}
 
//Copy Constructor
Darray::Darray(const Darray& actual) {
    cap = actual.cap;
    ptr = new int[cap];
    for (int i = 0; i < cap; ++i) {
        ptr[i] = actual.ptr[i];
    }
}
/*
//Copy Assignment
Darray& Darray::operator=(const Darray& rhs) {
    if (ptr == rhs.ptr) return *this; // a=a
    delete[] ptr;
    cap = rhs.cap;
    ptr = new int[cap];
    for (int i = 0; i < cap; ++i) {
        ptr[i] = rhs.ptr[i];
    }
    return *this;
    
}
*/

//Constant time swap.
// No matter how big the arrays are, it is always the
// same amount of assignment to swap them
void Darray::swap(Darray& rhs) {
    int* temp = ptr;
    ptr = rhs.ptr;
    rhs.ptr = temp;
    int captemp = cap;
    cap = rhs.cap;
    rhs.cap = captemp;
}

//Copy assignment
Darray& Darray::operator=(const Darray& rhs) {
    swap(rhs);
    return *this;
}

//REQUIRES: n>=0
void Darray::resize(int n) {
    int smaller = cap;
    if (n < smaller) smaller = n;
    int *temp = new int[n];
    for (int i = 0; i < smaller; ++i) {
        temp[i] = ptr[i];
    }
    delete[] ptr;
    ptr = temp;
    cap = n;
}
