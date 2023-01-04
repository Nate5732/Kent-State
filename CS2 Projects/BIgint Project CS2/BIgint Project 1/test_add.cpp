// bigint Test Program
//
// Tests:  int constructor, uses ==
//
// NEED TO IMPLEMENT
//
#include <iostream>
#include <cassert>
#include "bigint.hpp"


//===========================================================================
int main () {
    {

        // VERY INCOMPLETE set of tests.


        //------------------------------------------------------
        // Setup fixture
        bigint left(0);
        bigint right(0);
        bigint result;

        // Test
        result = left + right;

        // Verify
        assert(left   == 0);
        assert(right  == 0);
        assert(result == 0);
    }

    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(1);
      bigint right(0);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 1);
      assert(right  == 0);
      assert(result == 1);
    }
    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(1);
      bigint right(1);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 1);
      assert(right  == 1);
      assert(result == 2);
    }

    //First Test case making last digit 0
    {
      bigint left(98123);
      bigint right(7);
      bigint result;

      result = left + right;

      assert(left == 98123);
      assert(right == 7);
      assert(result == 98130);
    }

    //Large Number Test Case
    {
      bigint left("9999999999999999");
      bigint right("3399000000");
      bigint result;

      result = left + right;

      assert(left == "9999999999999999");
      assert(right == "3399000000");
      assert(result == "10000003398999999");
     }
     //3 digit turns into 4 digit
     {
       bigint left(999);
       bigint right(1);
       bigint result;

       result = left + right;

       assert(left == 999);
       assert(right == 1);
       assert(result == 1000);
     }

     //adding twos into 8's
     {
       bigint left("22222222222222222222222222222");
         bigint right("888888888888888888888888888888888888888888888888");
       bigint result;

       result = left + right;

       assert(left == "22222222222222222222222222222");
       assert(right == "888888888888888888888888888888888888888888888888");
       assert(result == "888888888888888888911111111111111111111111111110");
     }

     //adding numbers in order
     {
         bigint left("1234567890");
         bigint right("1234567890");
       bigint result;

       result = left + right;

       assert(left == "1234567890");
       assert(right == "1234567890");
       assert(result == "2469135780");
     }

     //Adding very large number to small
     {
         bigint left("9999999999999999999999999999999999999");
         bigint right("1");
       bigint result;

       result = left + right;

       assert(left == "9999999999999999999999999999999999999");
       assert(right == "1");
       assert(result == "10000000000000000000000000000000000000");
     }

     //Adding Equal Numbers
     {
         bigint left(500);
         bigint right(500);
       bigint result;

       result = left + right;

       assert(left == 500);
       assert(right == 500);
       assert(result == 1000);
     }

     //Adding 0 to very large number
     {
       bigint left("9999999999999999999999999999999999999");
       bigint right("0");
       bigint result;

       result = left + right;

       assert(left == "9999999999999999999999999999999999999");
       assert(right == "0");
       assert(result == "9999999999999999999999999999999999999");
     }

     //Adding to 100 digit number
     {
       bigint left("999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999");
       bigint right("999");
       bigint result;

       result = left + right;

       assert(left == "999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999");
       assert(right == "999");
       assert(result == "1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000998");
     }

     //Adding two single digits to make a double digit number
     {
       bigint left(9);
       bigint right(1);
       bigint result;

       result = left + right;

       assert(left == 9);
       assert(right == 1);
       assert(result == 10);
     }

     //Adding with a 199 digit number
     {
       bigint left("1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
       bigint right("9");
       bigint result;

       result = left + right;

       assert(left == "1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
       assert(right == "9");
       assert(result == "1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000009");
     }

     //Adding 1's and 0's
     {
       bigint left("10101010101010101010101010101010");
       bigint right("10101010101010101010");
       bigint result;

       result = left + right;

       assert(left == "10101010101010101010101010101010");
       assert(right == "10101010101010101010");
       assert(result == "10101010101020202020202020202020");
     }

     //Adding small numbers
     {
       bigint left(3);
       bigint right(3);
       bigint result;

       result = left + right;

       assert(left == 3);
       assert(right == 3);
       assert(result == 6);
     }

     //Adding numbers in backwards order
     {
       bigint left("9876543210");
       bigint right("9876543210");
       bigint result;

       result = left + right;

       assert(left == "9876543210");
       assert(right == "9876543210");
       assert(result == "19753086420");
     }

      //Adding 0 to 100 digit number
     {
       bigint left("4444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444");
       bigint right("0");
       bigint result;

       result = left + right;

       assert(left == "4444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444");
       assert(right == "0");
       assert(result == "4444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444");
     }

    std::cout << "Done with testing addition." << std::endl;
    return 0;
}
