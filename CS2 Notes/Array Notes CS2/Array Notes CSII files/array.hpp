//
//  array.hpp
//  Array Notes CSII
//
//  Created by Nathon Iadimarco on 10/3/22.
//

#ifndef array_h
#define array_h
// A simple dynamically allocated array.

#include <iostream>
#include <cassert>

//
// CLASS INV: ptr->int[cap]
//
class Darray {
public:
    Darray() : ptr(0), cap(0) {};
    Darray(int);
    Darray(const Darray&); //cctor copy constructor
    ~Darray();             //Destructor
    Darray& operator=(const Darray&);
    //Darray& operator=(Darray); (Second way of doing above)
    void swap(Darray&);
    
    int capacity() const { return cap; };
    int operator[](int) const;
    int& operator[](int);
    void resize(int);
    
private:
    int *ptr;
    int cap;
};


#endif
