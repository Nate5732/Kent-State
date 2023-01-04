// string Test Program
//
// Tests the length capacity of a string
//
// Nathon Iadimarco
#include "string.hpp"
#include <cassert>
#include <iostream>

int main() {

    {
    String str("Hi");
    
    assert(str.length() == 2);
    }
    
    {
    String str("Nathon");

    assert(str.length() == 6);
    }
    
    {
    String str("");

    assert(str.length() == 0);
    }
    
    {
    String str(" ");

    assert(str.length() == 1);
    }
    
    {
    String str("C");

    assert(str.capacity() == 1);
    }
    
    {
    String str("c");

    assert(str.capacity() == 1);
    }
    
    {
    String str("test");

    assert(str.capacity() == 4);
    }
    
    std::cout << "Done testing capacity and length." << std::endl;
    
}
