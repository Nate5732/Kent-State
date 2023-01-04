//  Stack class test program
//  Nathon Iadimarco
//  CS2
//  Tests: Destructor
//

#include "stack.hpp"
#include <cassert>
#include <iostream>

//===========================================================================
int main() {

    {
        stack<int> test;
        
        test.~stack();
         
        assert(test.empty() == true);
    }
    
    {
        stack<int> test;
        test.push(2);
        test.~stack();
         
        assert(test.empty() == true);
    }
    
    {
        stack<int> test;
        test.push(53);
        test.push(7);
        test.~stack();
         
        assert(test.empty() == true);
    }
    
    {
        stack<char> test;
        test.push('x');
        test.~stack();
         
        assert(test.empty() == true);
    }
    
    {
        stack<char> test;
        test.push('x');
        test.push('i');
        test.~stack();
         
        assert(test.empty() == true);
    }
    
    {
        stack<String> test;
        test.push("abcdefghijklmnopqrstuvwxyz");
        test.~stack();
         
        assert(test.empty() == true);
    }

    {
        stack<String> test;
        test.push("Nathon ");
        test.push("Iadimarco");
        test.~stack();
         
        assert(test.empty() == true);
    }
    
    {
        stack<String> test;
        test.push("Delete ");
        test.push("3 ");
        test.push("Strings");
        test.~stack();
         
        assert(test.empty() == true);
    }

    {
        stack<int> test;
        test.push(999999);
        test.~stack();
         
        assert(test.empty() == true);
    }
    
    {
        stack<int> test;
        test.push(12345);
        test.~stack();
         
        assert(test.empty() == true);
    }
    
    std::cout << "Done testing Destructor." << std::endl;
    return 0;
    
}

