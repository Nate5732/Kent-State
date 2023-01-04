//  Stack class test program
//  Nathon Iadimarco
//  CS2
//  Tests: Push and Pop
//

#include "stack.hpp"
#include <cassert>
#include <iostream>

//===========================================================================
int main() {
    
    {
        stack<int> test;
        test.push(5);
        
        assert(test.empty() == false);
        assert(test.top() == 5);
    }
    
    {
        stack<int> test;
        test.push(0);
        
        assert(test.empty() == false);
        assert(test.top() == 0);
    }
    
    {
        stack<int> test;
        test.push(10);
        
        assert(test.empty() == false);
        assert(test.top() == 10);
    }
            
    {
        stack<int> test;
        test.push(10);
        test.pop();
            
        assert(test.empty() == true);
    }
    
    {
        stack<int> test;
        test.push(99999999);
        test.pop();
            
        assert(test.empty() == true);
    }
        
    {
        stack<char> test;
        test.push('x');
        test.pop();
        
        assert(test.empty() == true);
    }
    
    {
        stack<char> test;
        test.push('n');
        test.pop();
        
        assert(test.empty() == true);
    }
    
    {
        stack<char> test;
        test.push(' ');
        test.pop();
        
        assert(test.empty() == true);
    }

    {
        stack<char> test;
        test.push('x');
        test.push('i');
        test.pop();
        
        assert(test.empty() == false);
        assert(test.top() == 'x');
    }
    
    {
        stack<String> test;
        test.push("Nathon");
        test.pop();
            
        assert(test.empty() == true);
    }
    
    {
        stack<String> test;
        test.push("abcdefghijklmnopqrstuvwxyz");
        test.pop();
            
        assert(test.empty() == true);
    }
                
    {
        stack<String> test;
        test.push("one");
        test.push("two");
        test.pop();
            
        assert(test.empty() == false);
    }
    
    {
        stack<String> test;
        test.push("Computer ");
        test.push("Science");
        test.pop();
            
        assert(test.empty() == false);
        assert(test.top() == "Computer ");
    }
    
    {
        stack<String> test;
        test.push("Nathon ");
        test.push("Iadimarco");
        test.pop();
            
        assert(test.empty() == false);
        assert(test.top() == "Nathon ");
    }
    
    {
        stack<String> test;
        test.push("Don't pop");
        test.push("Popped");
        test.pop();
            
        assert(test.empty() == false);
        assert(test.top() == "Don't pop");
    }
    
    {
        stack<String> test;
        test.push(" ");
        test.push(" ");
        test.pop();
            
        assert(test.empty() == false);
        assert(test.top() == " ");
    }
    
    std::cout << "Done testing Push and Pop." << std::endl;
    return 0;
    
}
