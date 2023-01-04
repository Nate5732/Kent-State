//
//  stack.hpp
//  Stack nodes notes
//
//  Created by Nathon Iadimarco on 10/24/22.
//

#ifndef stack_h
#define stack_h

#include <iostream>

















//
// CLASS INV: tos -> x1 -> x2 -> ... -> xN -> 0
//
template <typename T>
class stack {
public:
              stack() : tos(0) {};
              ~stack();
              stack(const stack<T>&);
    void      swap(stack<T>&);
    stack<T>& operator=(stack<T> rhs) { swap(rhs); return *this; };
    bool      isEmpty() const { return tos == 0; };
    bool      isFull() const;
    void      push(const T&);
    T         pop();
    T         top() const;
        
private:
    node<T> *tos;
};

//
// REQUIRES: tos-> x1 -> x2 -> ...xn ->0
// ENSURE:   tos-> item -> x1 -> x2 -> ...xn->0
template <typename T>
void stack<T>::push(const T& item) {
    assert(!isFull());
    node<T> *temp = new node<T>(item);
    temp->next = tos;
    tos = temp;
}

// REQUIRES: tos-> x1 -> x2 -> ...xn ->0
// ENSURE:   tos-> item -> x1 -> x2 -> ...xn->0
template <typename T>
T stack<T>::pop() {
    assert(!isEmpty());
    T result = tos->data;
    node<T> *temp = tos;
    tos = tos->next;
    delete temp;
    return result;
}

template <typename T>
T stack<T>::top() const {
    assert(!isEmpty());
    return tos->data;
}

template <typename T>
stack<T>::~stack() {
// while(!isEmpty()) {
//   pop();                  // This would work
// }
    node<T> *temp;
    while (tos != 0) {
        temp = tos;
        tos = tos->next;
        delete temp;
    }
}

template <typename T>
stack<T>::stack(const stack<T>& actual) : stack() {
    node<T> *temp = actual.tos;
    while (temp != 0) {
        if (tos == 0) {
            tos = new node<T>(temp->data);
            bottom = tos;
        } else {
            bottom->next = new<T>(temp->data);
            bottom = bottom->next
            
        }
        temp = temp->next;
    }
}

template<typename T>
void stack<T>::swap(stack<T> &rhs) {
    node<T> *temp = tos;
    tos = rhs.tos;
    rhs.tos = temp;
}

template <typename T>
bool stack<T>::isFull() const {
    node<T> *temp = new(std::nothrow) node();
    if (temp == 0) return true; //out of memory
    delete temp;
    return false;
    
}
#endif
