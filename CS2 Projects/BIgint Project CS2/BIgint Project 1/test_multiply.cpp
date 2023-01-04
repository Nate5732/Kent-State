// Nathon Iadimarco
// bigint Test Program
// Tests:  multiply, uses ==
//
#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main () {
    
    {
        //------------------------------------------------------
        // Setup fixture
        bigint left(0);
        bigint right(0);
        bigint result;
        
        // Test
        result = left * right;
        
        // Verify
        assert(left   == 0);
        assert(right  == 0);
        assert(result == 0);
    }
    
    {
        //------------------------------------------------------
        // Setup fixture 2
        bigint left(1);
        bigint right(0);
        bigint result;
        
        // Test
        result = left * right;
        
        // Verify
        assert(left   == 1);
        assert(right  == 0);
        assert(result == 0);
    }
    
    {
        //------------------------------------------------------
        // Setup fixture 3
        bigint left(0);
        bigint right(1);
        bigint result;
        
        // Test
        result = left * right;
        
        // Verify
        assert(left   == 0);
        assert(right  == 1);
        assert(result == 0);
    }
    
    {
        //------------------------------------------------------
        // Setup fixture 4
        bigint left(123);
        bigint right(56);
        bigint result;
        
        // Test
        result = left * right;
        
        // Verify
        assert(left   ==  123);
        assert(right  ==   56);
        assert(result == 6888);
    }
    
    {
        //------------------------------------------------------
        // Setup fixture 5
        bigint left(65);
        bigint right(321);
        bigint result;
        
        // Test
        result = left * right;
        
        // Verify
        assert(left   ==    65);
        assert(right  ==   321);
        assert(result == 20865);
    }
    
    {
        //------------------------------------------------------
        // Setup fixture 6
        bigint left(9999);
        bigint right(2);
        bigint result;
        
        // Test
        result = left * right;
        
        // Verify
        assert(left   ==  9999);
        assert(right  ==     2);
        assert(result == 19998);
    }
    
    {
        //------------------------------------------------------
        // Setup fixture 7
        bigint left(2);
        bigint right(999999);
        bigint result;
        
        // Test
        result = left * right;
        
        // Verify
        assert(left   ==       2);
        assert(right  ==  999999);
        assert(result == 1999998);
    }
    {
        //------------------------------------------------------
        // Setup fixture 8
        bigint left(99);
        bigint right(99);
        bigint result;

        // Test
        result = left * right;

        // Verify
        assert(left   ==  99);
        assert(right  ==  99);
        assert(result ==  9801);
    }


    {
        //------------------------------------------------------
        // Setup fixture 9
        bigint left("2222");
        bigint right("888888888888888888888888888888888888");
        bigint result;
        
        // Test
        result = left * right;
        
        // Verify
        assert(left   == "2222");
        assert(right  == "888888888888888888888888888888888888");
        assert(result == "1975111111111111111111111111111111109136");
    }
    
    {
        //------------------------------------------------------
        // Setup fixture 10
        bigint left("777777777777777777777777777777777777777777777");
        bigint right("333333");
        bigint result;
        
        // Test
        result = left * right;
        
        // Verify
        assert(left   == "777777777777777777777777777777777777777777777");
        assert(right  == "333333");
        assert(result == "259258999999999999999999999999999999999999999740741");
    }
    
    {
        //------------------------------------------------------
        // Setup fixture 11
        bigint left("111111111111111111111111111111111111111111");
        bigint right("999999999999999999999999999999999999999999");
        bigint result;
        
        // Test
        result = left * right;
        
        // Verify
        assert(left   == "111111111111111111111111111111111111111111");
        assert(right  == "999999999999999999999999999999999999999999");
        assert(result == "111111111111111111111111111111111111111110888888888888888888888888888888888888888889");
    }
    
    {
        //------------------------------------------------------
        // Setup fixture 12
        bigint left(9);
        bigint right(9);
        bigint result;

        // Test
        result = left * right;

        // Verify
        assert(left   ==  9);
        assert(right  ==  9);
        assert(result ==  81);
    }
    
    {
        //------------------------------------------------------
        // Setup fixture 13
        bigint left("12098374091729340710293497120934");
        bigint right("10");
        bigint result;

        // Test
        result = left * right;

        // Verify
        assert(left   ==  "12098374091729340710293497120934");
        assert(right  ==  "10");
        assert(result ==  "120983740917293407102934971209340");
    }
    
    {
        //------------------------------------------------------
        // Setup fixture 14
        bigint left("999999999999999999999999999999999999");
        bigint right("0");
        bigint result;

        // Test
        result = left * right;

        // Verify
        assert(left   ==  "999999999999999999999999999999999999");
        assert(right  ==  "0");
        assert(result ==  "0");
    }

    {
        //------------------------------------------------------
        // Setup fixture 15
        bigint left("98172034812903478917238419807");
        bigint right("786127836516235");
        bigint result;

        // Test
        result = left * right;

        // Verify
        assert(left   ==  "98172034812903478917238419807");
        assert(right  ==  "786127836516235");
        assert(result ==  "77175769333864317149719489497777023301066645");
    }
    
    {
        //------------------------------------------------------
        // Setup fixture 16
        bigint left("2");
        bigint right("2");
        bigint result;

        // Test
        result = left * right;

        // Verify
        assert(left   ==  "2");
        assert(right  ==  "2");
        assert(result ==  "4");
    }
    
    {
        //------------------------------------------------------
        // Setup fixture 17
        bigint left("70");
        bigint right("2");
        bigint result;

        // Test
        result = left * right;

        // Verify
        assert(left   ==  "70");
        assert(right  ==  "2");
        assert(result ==  "140");
    }
    
    std::cout << "Done testing multiply" << std::endl;
    return 0;
}
