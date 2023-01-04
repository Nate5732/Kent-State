//  Stack class test program
//  Nathon Iadimarco
//  CS2
//  Tests: Default Constructor
//

#include "stack.hpp"
#include <cassert>
#include <iostream>

//===========================================================================
int main ()
{
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        stack<int>  x;

        // VERIFY
        assert(x.empty() == true);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        stack<char>  x;

        // VERIFY
        assert(x.empty() == true);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        stack<String>  x;

        // VERIFY
        assert(x.full() == false);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        stack<int>  x;

        // VERIFY
        assert(x.full() == false);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        stack<char>  x;

        // VERIFY
        assert(x.full() == false);
    }
    
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        stack<String>  x;

        // VERIFY
        assert(x.full() == false);
    }    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        stack<String>  n;

        // VERIFY
        assert(n.empty() == true);
    }

    std::cout << "Done testing Default Constructor." << std::endl;
    return 0;
    
}
