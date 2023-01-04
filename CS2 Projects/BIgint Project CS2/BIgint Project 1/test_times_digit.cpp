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
        bi = bi.timesDigit(1);

        // Verify
        assert(bi == 3);  //Fixed
    
    }
    
    {
        //------------------------------------------------------
        // Setup fixture 2
        bigint bi(40);

        // Test
        bi = bi.timesDigit(2);

        // Verify
        assert(bi == 80);
    
    }
    
    {
        //------------------------------------------------------
        // Setup fixture 3
        bigint bi(1000);

        // Test
        bi = bi.timesDigit(5);

        // Verify
        assert(bi == 5000);
    
    }
    
    {
        //------------------------------------------------------
        // Setup fixture 4
        bigint bi("99999999999999999");

        // Test
        bi = bi.timesDigit(8);

        // Verify
        assert(bi == "799999999999999992");
    
    }
    
    {
        //------------------------------------------------------
        // Setup fixture 5
        bigint bi("897540297801098709702349");

        // Test
        bi = bi.timesDigit(0);

        // Verify
        assert(bi == "0");
    
    }
    
    {
        //------------------------------------------------------
        // Setup fixture 6
        bigint bi(8);

        // Test
        bi = bi.timesDigit(2);

        // Verify
        assert(bi == 16);
    
    }
    
    {
        //------------------------------------------------------
        // Setup fixture 7
        bigint bi(1);

        // Test
        bi = bi.timesDigit(1);

        // Verify
        assert(bi == 1);
    
    }
    
    {
        //------------------------------------------------------
        // Setup fixture 8
        bigint bi("1234567890");

        // Test
        bi = bi.timesDigit(3);

        // Verify
        assert(bi == "3703703670");
    
    }
    
    {
        //------------------------------------------------------
        // Setup fixture 9
        bigint bi("999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999");

        // Test
        bi = bi.timesDigit(1);

        // Verify
        assert(bi == "999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999");
    
    }
    
    {
        //------------------------------------------------------
        // Setup fixture 10
        bigint bi(4);

        // Test
        bi = bi.timesDigit(9);

        // Verify
        assert(bi == 36);
    
    }
    
    {
        //------------------------------------------------------
        // Setup fixture 11
        bigint bi("98799029340271985908263490816351234");

        // Test
        bi = bi.timesDigit(7);

        // Verify
        assert(bi == "691593205381903901357844435714458638");
    
    }
    
    {
        //------------------------------------------------------
        // Setup fixture 12
        bigint bi(9);

        // Test
        bi = bi.timesDigit(9);

        // Verify
        assert(bi == 81);
    
    }
    
    {
        //------------------------------------------------------
        // Setup fixture 13
        bigint bi(90);

        // Test
        bi = bi.timesDigit(1);

        // Verify
        assert(bi == 90);
    
    }
    
    {
        //------------------------------------------------------
        // Setup fixture 14
        bigint bi(0);

        // Test
        bi = bi.timesDigit(9);

        // Verify
        assert(bi == 0);
    
    }
    
    {
        //------------------------------------------------------
        // Setup fixture 15
        bigint bi(1624);

        // Test
        bi = bi.timesDigit(5);

        // Verify
        assert(bi == 8120);
    
    }
    
    
    std::cout << "Done testing bigint * digit" << std::endl;
        return 0;
    }
