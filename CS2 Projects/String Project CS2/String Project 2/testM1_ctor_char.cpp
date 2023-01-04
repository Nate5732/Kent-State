// string Test Program
//
// Tests: String(char)
//
// Nathon Iadimarco
#include <iostream>
#include <cassert>
#include "string.hpp"

int main() {
    
    {
        String str('x');
    
        std::cout << "str == " << str << std::endl;
    
        assert(str == 'x');
    }
    
    {
        String str('s');
    
        std::cout << "str == " << str << std::endl;
    
        assert(str == 's');
    }
    
    {
        String str('N');
    
        std::cout << "str == " << str << std::endl;
    
        assert(str == 'N');
    }
    
    {
        String str(' ');
    
        std::cout << "str == " << str << std::endl;
    
        assert(str == ' ');
    }
    
    std::cout << "Done testing char constructor" << std::endl;
    return 0;
}
