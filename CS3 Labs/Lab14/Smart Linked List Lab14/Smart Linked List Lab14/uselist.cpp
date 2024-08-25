// Nathon Iadimarco
// CS3 Lab14
// uselist.cpp
// demoes list template usage
// 6/17/14
// Mikhail Nesterenko

#include <iostream>
#include <memory>
#include "list.hpp" // list template

using std::cout; using std::endl;
using std::shared_ptr; using std::make_shared;

int main(){
    shared_ptr<node<int>> head, currentPtr;
    
    //
    // integer list manipulation
    //
    
    // first node
    head = make_shared<node<int>>();
    head->setData(1);
    
    currentPtr = make_shared<node<int>>(); // second node
    currentPtr->setData(2);
    
    head->setNext(currentPtr); // list contains two nodes
    
    cout << head->getData() << " "; // printing head node
    
    // deallocating head node
    currentPtr=head->getNext();
    head=head->getNext();
    currentPtr.reset();
    
    // printing and deallocating the last element
    if (head->getNext() != nullptr) {
        cout << head->getNext()->getData() << endl;
    }
    
    
    //
    // character list manipulation
    //
    
    // allocating head node
    shared_ptr<node<char>> charHead = make_shared<node<char>>();
    shared_ptr<node<char>> current = charHead;
    current->setData('A');
    
    // creating list
    for(char letter = 'B'; letter <= 'Z'; ++letter){
        shared_ptr<node<char>> newNode = make_shared<node<char>>();
        newNode->setData(letter);
        current->setNext(newNode);
        newNode->setPrev(current);
        current = newNode;
    }
    
    
    // Printing out the list of chars
    for(current = charHead;  current != nullptr; current=current->getNext())
        cout << current->getData() << ' ';
    cout << endl;
}
