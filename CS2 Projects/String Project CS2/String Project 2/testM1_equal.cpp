// string Test Program
//
// Tests:   ==, uses String(char)
//
// Nathon Iadimarco
#include <iostream>
#include <cassert>
#include "string.hpp"

int main () {
    
    {
        // Creating 2 strings
        String str1('0');
        String str2('0');
        
        std::cout << str1 << " == " << str2 << std::endl;
        // Checking to make sure they are equal
        assert(str1 == str2);
    }
    
    {
        // Creating 2 strings
        String str1('x');
        String str2('x');
        
        std::cout << str1 << " == " << str2 << std::endl;
        // Checking to make sure they are equal
        assert(str1 == str2);
    }
    
    {
        // Creating 2 strings
        String str1(' ');
        String str2(' ');
        
        std::cout << str1 << " == " << str2 << std::endl;
        // Checking to make sure they are equal
        assert(str1 == str2);
    }
    
    {
        // Creating 2 strings
        String str1("Nathon");
        String str2("Nathon");
        
        std::cout << str1 << " == " << str2 << std::endl;
        // Checking to make sure they are equal
        assert(str1 == str2);
    }
    
    {
        // Creating 2 strings
        String str1("testing123");
        String str2("testing123");
        
        std::cout << str1 << " == " << str2 << std::endl;
        // Checking to make sure they are equal
        assert(str1 == str2);
    }
    
    {
        // Creating 2 strings
        String str1("NotEqual");
        String str2("Wrong");
        
        std::cout << str1 << " != " << str2 << std::endl;
        // Checking to make sure they are equal
        assert(str1 != str2);
    }
    
    {
        // Creating 2 strings
        String str1("abcdefghijklmnopqrstuvwxyz");
        String str2("abcdefghijklmnopqrstuvwxyz");
        
        std::cout << str1 << " == " << str2 << std::endl;
        // Checking to make sure they are equal
        assert(str1 == str2);
    }

    std::cout << "Done testing ==." << std::endl;
    return 0;
}
