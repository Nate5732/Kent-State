//  Stack class test program
//  Nathon Iadimarco
//  CS2
//  Tests: Assignment
//

#include "stack.hpp"
#include <cassert>
#include <iostream>

int main() {
    
    
    {
        stack<int> test1;
        test1.push(99);
        
        stack<int> test2;
        
        test2 = test1;
        
        assert(test1.empty() == false);
        assert(test1.top() == 99);
        
        assert(test2.empty() == false);
        assert(test2.top() == 99);
    }
    
    {
        stack<int> test1;
        test1.push(5732);
        
        stack<int> test2;
        
        test2 = test1;
        
        assert(test1.empty() == false);
        assert(test1.top() == 5732);
        
        assert(test2.empty() == false);
        assert(test2.top() == 5732);
    }

    {
        stack<char> test1;
        test1.push('x');
        
        stack<char> test2;
        
        test2 = test1;
        
        assert(test1.empty() == false);
        assert(test1.top() == 'x');
        
        assert(test2.empty() == false);
        assert(test2.top() == 'x');
    }



    {
        stack<char> test1;
        test1.push('n');
        
        stack<char> test2;
        
        test2 = test1;
        
        assert(test1.empty() == false);
        assert(test1.top() != 'x');
        
        assert(test2.empty() == false);
        assert(test2.top() == 'n');
    }


    {
        stack<String> test1;
        test1.push("nate");
        
        stack<String> test2;
        
        test2 = test1;
        
        assert(test1.empty() == false);
        assert(test1.top() == "nate");
        
        assert(test2.empty() == false);
        assert(test2.top() == "nate");
        assert(test2.top() == test1.top());
    }
 
    {
        stack<String> test1;
        test1.push("Nate5732");
        
        stack<String> test2;
        
        test2 = test1;
        
        assert(test1.empty() == false);
        assert(test1.top() == "Nate5732");
        
        assert(test2.empty() == false);
        assert(test2.top() == "Nate5732");
        assert(test2.top() == test1.top());
    }

    {
        stack<String> test1;
        test1.push("123");
        test1.push("test");
        stack<String> test2;
        
        test2 = test1;
        
        assert(test1.empty() == false);
        assert(test1.top() == "test");
        
        assert(test2.empty() == false);
        assert(test2.top() == "test");
        assert(test2.top() == test1.top());
    }

    {
        stack<String> test1;
        test1.push("Kent State University");
        stack<String> test2;
        
        test2 = test1;
        
        assert(test1.empty() == false);
        assert(test1.top() == "Kent State University");
        
        assert(test2.empty() == false);
        assert(test2.top() == "Kent State University");
        assert(test2.top() == test1.top());
    }
    
    {
        stack<String> test1;
        test1.push("Testing this");
        stack<String> test2;
        
        test2 = test1;
        
        assert(test1.empty() == false);
        assert(test1.top() == "Testing this");
        
        assert(test2.empty() == false);
        assert(test2.top() == "Testing this");
        assert(test2.top() == test1.top());
    }
    
    {
        stack<String> test1;
        test1.push(" ");
        stack<String> test2;
        
        test2 = test1;
        
        assert(test1.empty() == false);
        assert(test1.top() == " ");
        
        assert(test2.empty() == false);
        assert(test2.top() == " ");
        assert(test2.top() == test1.top());
    }
    
    {
        stack<String> test1;
        test1.push("");
        stack<String> test2;
        
        test2 = test1;
        
        assert(test1.empty() == false);
        assert(test1.top() == "");
        
        assert(test2.empty() == false);
        assert(test2.top() == "");
        assert(test2.top() == test1.top());
    }
    
    std::cout << "Done testing Assignment." << std::endl;
    return 0;
    
}
