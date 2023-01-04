// Nathon Iadimarco
// arrayTemplate notes for CSII
// arrayTemplate.hpp

#ifndef arrayTemplate_h
#define arrayTemplate_h


//
// A Template version of dynamically allocated array.
//

#include <cassert>

//
// CLASS INV: ptr->T[cap]
// REQUIRES: assignable(T) && copyconstructable(T) && destuctable(T)
//
template <typename T>
class Darray {
public:
               Darray() : cap(0), ptr(0) {};
               Darray(int);
              ~Darray() { delete[] ptr; };
               Darray(const Darray<T>&);
    void       swap(Darray<T>&);
    Darray<T>& operator=(Darray <T> rhs) { swap(rhs); return *this; };
    T          operator[](int i) const   { return ptr[i]; }
    T&         operator[](int i)         { return ptr[i]; }
    void       resize    (int i);
    
private:
    int cap;
    T *ptr;
    
};

//REQUIRES: n>=0
template <typename T>
Darray<T>::Darray(int n) {
    cap = n;
    ptr = new T[cap];
}

template <typename T>
Darray<T>::Darray(const Darray<T>& actual) {
    cap = actual.cap;
    ptr = new T[cap];
    for (int i = 0; i < cap; ++i) {
        ptr[i] = actual.ptr[i];
    }
}

void Darray<T>::swap(Darray<T>& rhs) {
    T *ptr = rhs.pts;
    rhs.ptr = ptr;
    ptr = tptr;
    int temp = rhs.cap;
    rhs.cap = cap;
    cap = temp;
}

void Darray<T>::resize(int n) {
    int smaller = cap;
    if (n < smaller) smaller = n;
    T *temp = new T[n];
    for (int i = 0; i < smaller; ++i) {
        temp[i] = ptr[i];
    }
    delete[] ptr;
    ptr = temp;
    cap = n;
}
#endif
