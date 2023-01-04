// string Test Program
//
// Tests: String(const char[])
//
// Nathon Iadimarco
#include <iostream>
#include <cassert>
#include "string.hpp"

int main() {
    
    {
        String str("x");
    
        std::cout << "str == " << str << std::endl;
    
        assert(str == "x");
    }
    
    {
        String str("hi");
    
        std::cout << "str == " << str << std::endl;
    
        assert(str == "hi");
    }
    
    {
        String str("Nathon");
    
        std::cout << "str == " << str << std::endl;
    
        assert(str == "Nathon");
    }
    
    {
        String str("test");
    
        std::cout << "str == " << str << std::endl;
    
        assert(str == "test");
    }
    
    {
        String str("abcdefghijklmnopqrstuvwxyz");
    
        std::cout << "str == " << str << std::endl;
    
        assert(str == "abcdefghijklmnopqrstuvwxyz");
    }
    
    std::cout << "Done testing char array constructor" << std::endl;
    return 0;
    
}
