// Nathon Iadimarco
// bigint Test Program
//
// Tests:  times_10, uses ==
//
// NEED TO IMPLEMENT
//
#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main () {
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(3);

        // Test
        bi = bi.times10(0);

        // Verify
        assert(bi == 3);  //Fixed
    }
    
    {
        //------------------------------------------------------
        // Setup fixture 2
        bigint bi(59);

        // Test
        bi = bi.times10(1);
    
        // Verify
        assert(bi == 590);
    
    }

    {
        //------------------------------------------------------
        // Setup fixture 3
        bigint bi("999999");

        // Test
        bi = bi.times10(4);

        // Verify
        assert(bi == "9999990000");

    }

    {
        //------------------------------------------------------
        // Setup fixture 4
        bigint bi(296);

        // Test
        bi = bi.times10(1);

        // Verify
        assert(bi == 2960);

    }

    {
        //------------------------------------------------------
        // Setup fixture 5
        bigint bi("1234567890");

        // Test
        bi = bi.times10(6);

        // Verify
        assert(bi == "1234567890000000");

    }
    
    {
        //------------------------------------------------------
        // Setup fixture 6
        bigint bi("999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999");

        // Test
        bi = bi.times10(4);

        // Verify
        assert(bi == "9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999990000");

    }
    
    {
        //------------------------------------------------------
        // Setup fixture 7
        bigint bi("9286349562093458702987346891");

        // Test
        bi = bi.times10(9);

        // Verify
        assert(bi == "9286349562093458702987346891000000000");

    }
    
    {
        //------------------------------------------------------
        // Setup fixture 8
        bigint bi(1);

        // Test
        bi = bi.times10(8);

        // Verify
        assert(bi == 100000000);

    }
    
    {
        //------------------------------------------------------
        // Setup fixture 9
        bigint bi("9999999999");

        // Test
        bi = bi.times10(3);

        // Verify
        assert(bi == "9999999999000");

    }
    
    {
        //------------------------------------------------------
        // Setup fixture 10
        bigint bi("1000000000000000000000000000000000000000000000");

        // Test
        bi = bi.times10(2);

        // Verify
        assert(bi == "100000000000000000000000000000000000000000000000");

    }
    
    {
        //------------------------------------------------------
        // Setup fixture 11
        bigint bi("1000000000000000000000000000000000000000000000");

        // Test
        bi = bi.times10(0);

        // Verify
        assert(bi == "1000000000000000000000000000000000000000000000");

    }
    
    {
        //------------------------------------------------------
        // Setup fixture 12
        bigint bi(90);

        // Test
        bi = bi.times10(4);

        // Verify
        assert(bi == 900000);

    }
    
    {
        //------------------------------------------------------
        // Setup fixture 13
        bigint bi(10);

        // Test
        bi = bi.times10(5);

        // Verify
        assert(bi == 1000000);

    }
    
    {
        //------------------------------------------------------
        // Setup fixture 14
        bigint bi("909009909090099090099009090909");

        // Test
        bi = bi.times10(9);

        // Verify
        assert(bi == "909009909090099090099009090909000000000");

    }
    
    {
        //------------------------------------------------------
        // Setup fixture 15
        bigint bi(15);

        // Test
        bi = bi.times10(1);

        // Verify
        assert(bi == 150);

    }
    
std::cout << "Done testing bigint * digit" << std::endl;
return 0;
}
