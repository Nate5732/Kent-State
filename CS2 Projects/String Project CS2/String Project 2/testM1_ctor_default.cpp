// string Test Program
//
// Tests:  default constructor, uses ==
//
// Nathon Iadimarco
#include <iostream>
#include <cassert>
#include "string.hpp"

int main () {
    // Setup

    // Test
    String str;

    // Verify
    std::cout << "0 == " << str[0] << std::endl;
    assert(str == '\0');

    std::cout << "Done testing default constructor." << std::endl;
    return 0;
}

