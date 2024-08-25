// Nathon Iadimarco
// CS3 Lab3
// 1/25/2024
// Templated List Lab
// Create a new templated class Collection that contains this list as a dynamically allocated member, i.e, the list contains a pointer to the first element.

#ifndef collection_h
#define collection_h

#include <iostream>
#include "list.hpp"
using std::cout;
using std::endl;

template <typename T>
class Collection;

template <typename T>
bool equal (const Collection<T>&, const Collection <T>&);

template <typename T>
class Collection{
public:
    Collection();
    void add(const T& item);
    void remove(const T& item);
    T last();
    void print();
    friend bool equal<T>(const Collection<T>& c1, const Collection<T>& c2);

private:
    node<T>* head;
};


template <typename T>
Collection<T>::Collection() {
    head = nullptr;
}

// Implementing add() method. Takes an item as the argument and adds it to the collection, does not check for duplicates.
template <typename T>
void Collection<T>::add(const T& item) {
    node<T> *tmp = new node<T>;
    tmp->setData(item);
    tmp->setNext(head);
    head = tmp;
}

// Implementing remove() method. Takes an item as the argument and removes all instances of this item from the collection.
template <typename T>
void Collection<T>::remove(const T& item) {
    node<T> *last = nullptr;
    node<T> *current = head;
    
    if (head != nullptr && head->getData() == item && head->getNext() == nullptr) {
        delete head; // Deleting argument if it is the only one in collection.
        head = nullptr;
        return;
    }
    
    while (head->getData() == item && current->getNext() != nullptr) { // while head is pointing to the data and matching item, and next node is not null, skip that value and point to next value.
        head = head->getNext();
    }
    
    while (current->getNext() != nullptr) {
        if (current->getNext()->getData() == item) { // If next data is equal to item to remove then set it equal to last and skip to next then delete last item.
            last = current->getNext();
            current->setNext(current->getNext()->getNext());
            delete last;
        } else { // Otherwise, go to next value to check for match to removal item value.
            last = current;
            current = current->getNext();        }
    }
}

// Implementing last() method. Returns the last item added to the collection.
template <typename T>
T Collection<T>::last() {
    return head->getData();
}

// Implementing print() method. Prints items in the collection.
template <typename T>
void Collection<T>::print() {
    node<T> *current = head;
    
    while (current != nullptr) {
        cout << current->getData() << " "; // Printing current data then a space.
        current = current->getNext(); // Setting current data to the next value since the last one was printed. While loop continues and prints this next value.
    }
    cout << endl;
}

// Implementing bool equal(const Collection&, const Collection&) method. Compares two collections for equality
template <typename T>
bool equal(const Collection<T>& first, const Collection<T>& second) {
    node<T> *list1 = first.head;
    node<T> *list2 = second.head;
    
    while (list1 != nullptr && list2 != nullptr) { // Iterating through both lists until nullptr is reached
        if (list1->getData() != list2->getData()) { // If data is not equal return false and getNext() from each list.
            return false;
        }
        list1 = list1->getNext();
        list2 = list2->getNext();
    }
    return true; // Otherwise if data is found to be equal return true.
}

#endif

