
#ifndef Header_h
#define Header_h

#include <cassert>

const int SIZE = 100; // or whatever

template <typename T>
class stack {
public:
    stack() : tos(-1) {};
    bool isEmpty() const { return tos == -1; };
    bool isFull() const { return tos >= SIZE-1; };
    void push(const T& item);
    T    pop();
    T    top() const;
    
private:
    int tos;
    T s[SIZE];
};

//REQUIRES: stack not full
template<typename T>
void stack<T>::push(const T& item) {
    assert(!isFull());
    s[++tos] = item;
}

//REQUIRES: stack not empty
template<typename T>
T stack<T>::pop() {
    assert(!isEmpty());
    return s[tos--];
}

//REQUIRES: stack not empty
template<typename T>
T stack<T>::top() const {
    assert(!isEmpty());
    return s[tos];
}

#endif

