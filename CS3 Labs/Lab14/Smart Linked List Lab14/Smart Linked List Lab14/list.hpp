// Nathon Iadimarco
// CS3 Lab14
// list.hpp
// node class tempate used to contruct lists
// Mikhail Nesterenko
// 5/01/00

#ifndef LIST_HPP_
#define LIST_HPP_

#include <memory>
using std::shared_ptr;
using std::weak_ptr;

// the pointer part of every list is the same
// lists differ by data part
template <typename T>
class node{
public:
    
    node(const T& data): data_(data), next_(nullptr), prev_() {}
    node() : data_(), next_(nullptr), prev_() {}
    
    // functions can be inlined
    T getData() const {return data_;}
    void setData(const T& data){data_=data;}
    
    
    // or can be defined outside
    shared_ptr<node<T>> getNext() const;
    void setNext(const std::shared_ptr<node<T>> &next);
    
    weak_ptr<node<T>> getPrev() const {return prev_;}
    void setPrev(const shared_ptr<node<T>> &prev){prev_=prev;}
    
private:
    T data_;
    shared_ptr<node<T>> next_;
    weak_ptr<node<T>> prev_;
    
};

//
// member functions for node
//
template <typename T>
shared_ptr<node<T>> node<T>::getNext() const {
    return next_;
}

template<typename T>
void node<T>::setNext(const shared_ptr<node<T>>& next) {
    next_=next;
}

#endif // LIST_HPP_
