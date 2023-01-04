// bigint Test Program
//
// Tests:  subscript, uses ==
//
// NEED TO IMPLEMENT
//
#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main () {
    
    {
     // Setup 1
     bigint bi(4);

     // Test
     int digit0 = bi[0];

     // Verify
     assert(bi    == 4);  // Fixed
     assert(digit0 == 4);
    }

    // Adding more test cases

    {
     // Setup 2
     bigint bi(35);

     // Test
     int digit0 = bi[0];
     int digit1= bi[1];

     // Verify
     assert(bi == 35);
     assert(digit0 == 5);
     assert(digit1 == 3);
    }

    {
     // Setup 3
     bigint bi(91);

     // Test
     int digit0 = bi[0];
     int digit1 = bi[1];

     // Verify
     assert(bi == 91);
     assert(digit0 == 1);
     assert(digit1 == 9);
    }

    {
     // Setup 4
     bigint bi(784);

     // Test
     int digit0 = bi[0];
     int digit1 = bi[1];
     int digit2 = bi[2];

     // Verify
     assert(bi == 784);
     assert(digit0 == 4);
     assert(digit1 == 8);
     assert(digit2 == 7);
    }

    {
     // Setup 5
     bigint bi(7192);

     // Test
     int digit0 = bi[0];
     int digit1 = bi[1];
     int digit2 = bi[2];
     int digit3 = bi[3];

     // Verify
     assert(bi == 7192);
     assert(digit0 == 2);
     assert(digit1 == 9);
     assert(digit2 == 1);
     assert(digit3 == 7);
    }

    {
     // Setup 6
     bigint bi(99999);

     // Test
     int digit0 = bi[0];
     int digit1 = bi[1];
     int digit2 = bi[2];
     int digit3 = bi[3];
     int digit4 = bi[4];

     // Verify
     assert(bi == 99999);
     assert(digit0 == 9);
     assert(digit1 == 9);
     assert(digit2 == 9);
     assert(digit3 == 9);
     assert(digit4 == 9);
    }
    
    {
    // Setup 7
    bigint bi(1001);
    
    // Test
    int digit0 = bi[0];
    int digit1 = bi[1];
    int digit2 = bi[2];
    int digit3 = bi[3];

    // Verify
    assert(bi == 1001);
    assert(digit0 == 1);
    assert(digit1 == 0);
    assert(digit2 == 0);
    assert(digit3 == 1);
    }

    {
     // Setup 8
     bigint bi(38902400);

     // Test
     int digit0 = bi[0];
     int digit1 = bi[1];
     int digit2 = bi[2];
     int digit3 = bi[3];
     int digit4 = bi[4];
     int digit5 = bi[5];
     int digit6 = bi[6];
     int digit7 = bi[7];

     // Verify
     assert(bi == 38902400);
     assert(digit0 == 0);
     assert(digit1 == 0);
     assert(digit2 == 4);
     assert(digit3 == 2);
     assert(digit4 == 0);
     assert(digit5 == 9);
     assert(digit6 == 8);
     assert(digit7 == 3);
    }

    {
     // Setup 9
     bigint bi("1234567890");

     // Test
     int digit0 = bi[0];
     int digit1 = bi[1];
     int digit2 = bi[2];
     int digit3 = bi[3];
     int digit4 = bi[4];
     int digit5 = bi[5];
     int digit6 = bi[6];
     int digit7 = bi[7];
     int digit8 = bi[8];
     int digit9 = bi[9];

     // Verify
     assert(bi == "1234567890");
     assert(digit0 == 0);
     assert(digit1 == 9);
     assert(digit2 == 8);
     assert(digit3 == 7);
     assert(digit4 == 6);
     assert(digit5 == 5);
     assert(digit6 == 4);
     assert(digit7 == 3);
     assert(digit8 == 2);
     assert(digit9 == 1);
    }

    {
     // Setup 10
     bigint bi("620418908472304959863");

     // Test
     int digit0 = bi[0];
     int digit1 = bi[1];
     int digit2 = bi[2];
     int digit3 = bi[3];
     int digit4 = bi[4];
     int digit5 = bi[5];
     int digit6 = bi[6];
     int digit7 = bi[7];
     int digit8 = bi[8];
     int digit9 = bi[9];
     int digit10 = bi[10];
     int digit11 = bi[11];
     int digit12 = bi[12];
     int digit13 = bi[13];
     int digit14 = bi[14];
     int digit15 = bi[15];
     int digit16 = bi[16];
     int digit17 = bi[17];
     int digit18 = bi[18];
     int digit19 = bi[19];
     int digit20 = bi[20];

     // Verify
     assert(bi == "620418908472304959863");
     assert(digit0 == 3);
     assert(digit1 == 6);
     assert(digit2 == 8);
     assert(digit3 == 9);
     assert(digit4 == 5);
     assert(digit5 == 9);
     assert(digit6 == 4);
     assert(digit7 == 0);
     assert(digit8 == 3);
     assert(digit9 == 2);
     assert(digit10 == 7);
     assert(digit11 == 4);
     assert(digit12 == 8);
     assert(digit13 == 0);
     assert(digit14 == 9);
     assert(digit15 == 8);
     assert(digit16 == 1);
     assert(digit17 == 4);
     assert(digit18 == 0);
     assert(digit19 == 2);
     assert(digit20 == 6);
    }

    {
     // Setup 11
     bigint bi("99999999999999999999999999999999999999999999999999");

     // Test
     int biDigit[50];
     for(int i = 0; i < 50; i++) {
         biDigit[i] = bi[i];
     }

     // Verify
     assert(bi == "99999999999999999999999999999999999999999999999999");
     for(int i = 0; i < 50; i++) {
         assert(biDigit[i] == 9);
     }
    }

    {
     // Setup 12
     bigint bi("9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999");

     // Test
     int biDigit[100];
     for(int i = 0; i < 100; i++) {
         biDigit[i] = bi[i];
     }

     // Verify
     assert(bi == "9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999");
     for(int i = 0; i < 100; i++) {
         assert(biDigit[i] == 9);
     }
    }

    {
     // Setup 13
     bigint bi("999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999");

     // Test
     int biDigit[150];
     for(int i = 0; i < 150; i++) {
         biDigit[i] = bi[i];
     }

     // Verify
     assert(bi == "999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999");
     for(int i = 0; i < 150; i++) {
         assert(biDigit[i] == 9);
     }
    }

    {
     // Setup 14
     bigint bi("9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999");

     // Test
     int biDigit[199];
     for(int i = 0; i < 199; i++) {
         biDigit[i] = bi[i];
     }

     // Verify
     assert(bi == "9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999");
     for(int i = 0; i < 199; i++) {
          assert(biDigit[i] == 9);
     }
    }

    std::cout << "Done testing subscript." << std::endl;
    return 0;
}

