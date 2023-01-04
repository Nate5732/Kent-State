// string Test Program
//
// Tests copy constructor for M2
//
// Nathon Iadimarco
#include "string.hpp"
#include <cassert>
#include <iostream>

int main() {
    {
    String str("Nathon");
    String copy(str);
    
    assert(str == copy);
    std::cout << str << " == " << copy << std::endl << std::endl;
    }
    
    {
    String str("Testing a long string of words");
    String copy(str);
        
    assert(str == copy);
    std::cout << str << " == " << copy << std::endl << std::endl;
    }
    
    {
    String str(" ");
    String copy(str);
        
    assert(str == copy);
    std::cout << str << " == " << copy << std::endl << std::endl;
    }
    
    {
    String str("a");
    String copy(str);
        
    assert(str == copy);
    std::cout << str << " == " << copy << std::endl << std::endl;
    }
    
    {
    String str("abcdefghijklmnopqrstuvwxyz");
    String copy(str);
        
    assert(str == copy);
    std::cout << str << " == " << copy << std::endl << std::endl;
    }
    
    {
    String str("jdbsduiufvrpfibqjdnbfabhibbfbgpiabkjasldjbdfigasdgfkjbadfbgabidfgbdsfpgijwdkfojb");
    String copy(str);
        
    assert(str == copy);
    std::cout << str << " == " << copy << std::endl << std::endl;
    }
    
    {
    String str("N a t h o n");
    String copy(str);
        
    assert(str == copy);
    std::cout << str << " == " << copy << std::endl << std::endl;
    }
    
    {
    String str("10");
    String copy(str);
        
    assert(str == copy);
    std::cout << str << " == " << copy << std::endl << std::endl;
    }
    
    {
    String str("Enough");
    String copy(str);
        
    assert(str == copy);
    std::cout << str << " == " << copy << std::endl << std::endl;
    }
    
    std::cout << "Done testing copy constructor" << std::endl;
}
