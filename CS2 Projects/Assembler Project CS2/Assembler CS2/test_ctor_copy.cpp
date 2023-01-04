//  Stack class test program
//  Nathon Iadimarco
//  CS2
//  Tests: Copy Constructor
//

#include "stack.hpp"
#include <cassert>
#include <iostream>

//===========================================================================
int main ()
{
    {
        stack<int> test;
        test.push(3);
        stack<int> copyTest(test);
        
        assert(test.top() == copyTest.top());
    }
    
    {
        stack<int> test;
        test.push(69);
        stack<int> copyTest(test);
        
        assert(test.top() == copyTest.top());
    }

    {
        stack<char> test;
        test.push('x');
        stack<char> copyTest(test);
        
        assert(test.top() == copyTest.top());
    }

    {
        stack<char> test;
        test.push('x');
        test.push('i');
        stack<char> copyTest(test);
        
        assert(test.top() == copyTest.top());
    }

    {
        stack<int> test;
        test.push(999);
        test.push(5);
        stack<int> copyTest(test);
        
        assert(test.top() == copyTest.top());
    }

    {
        stack<String> test;
        test.push("Nathon ");
        test.push("Iadimarco");
        stack<String> copyTest(test);
        
        assert(test.top() == copyTest.top());
    }
    
    {
        stack<String> test;
        test.push("123");
        test.push("456");
        stack<String> copyTest(test);
        
        assert(test.top() == copyTest.top());
    }
    
    {
        stack<String> test;
        test.push("I");
        test.push("Phone");
        stack<String> copyTest(test);
        
        assert(test.top() == copyTest.top());
    }
    
    {
        stack<String> test;
        test.push(" ");
        test.push(" ");
        stack<String> copyTest(test);
        
        assert(test.top() == copyTest.top());
    }
    
    {
        stack<String> test;
        test.push("");
        test.push("");
        stack<String> copyTest(test);
        
        assert(test.top() == copyTest.top());
    }

    {
        stack<String> test;
        test.push("Stringy String");
        test.push(" Of ");
        test.push("Strings");
        stack<String> copyTest(test);
        
        assert(test.top() == copyTest.top());
    }
    
    {
        stack<String> test;
        test.push("365 ");
        test.push("Days ");
        test.push("Year");
        stack<String> copyTest(test);
        
        assert(test.top() == copyTest.top());
    }

    {
        stack<String> test;
        test.push("Copying ");
        test.push("4 ");
        test.push("Different ");
        test.push("Elements ");
        stack<String> copyTest(test);
        
        assert(test.top() == copyTest.top());
    }
    
    {
        stack<String> test;
        test.push("5 ");
        test.push("Entire ");
        test.push("Strings ");
        test.push("Right ");
        test.push("Here.");
        stack<String> copyTest(test);
        
        assert(test.top() == copyTest.top());
    }
    
    std::cout << "Done testing Copy Constructor." << std::endl;
    return 0;
    
}

