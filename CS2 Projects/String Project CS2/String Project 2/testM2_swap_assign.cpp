// string Test Program
//
// Tests swap assignment for M2
//
// Nathon Iadimarco
#include "string.hpp"
#include <cassert>
#include <iostream>

int main() {
    
    {
    String str("Nathon");
    String str2("Iadimarco");
    std::cout << "Strings: " << str << " , " << str2 << std::endl << std::endl;
    str.swap(str2);
        
    std::cout << "Swapped strings: " << str << " , " << str2 << std::endl << std::endl;
    }
    
    {
    String str("A");
    String str2("B");
    std::cout << "Strings: " << str << " , " << str2 << std::endl << std::endl;
    str.swap(str2);
        
    std::cout << "Swapped strings: " << str << " , " << str2 << std::endl << std::endl;
    }
    
    {
    String str("Computer");
    String str2("Science");
    std::cout << "Strings: " << str << " , " << str2 << std::endl << std::endl;
    str.swap(str2);
        
    std::cout << "Swapped strings: " << str << " , " << str2 << std::endl << std::endl;
    }
    
    {
    String str("test");
    String str2("test");
    std::cout << "Strings: " << str << " , " << str2 << std::endl << std::endl;
    str.swap(str2);
        
    std::cout << "Swapped strings: " << str << " , " << str2 << std::endl << std::endl;
    }
    
    {
    String str("Enough");
    String str2("That is");
    std::cout << "Strings: " << str << " , " << str2 << std::endl << std::endl;
    str.swap(str2);
        
    std::cout << "Swapped strings: " << str << " , " << str2 << std::endl << std::endl;
    }
    
    std::cout << "Done testing swap assignment" << std::endl;
}
