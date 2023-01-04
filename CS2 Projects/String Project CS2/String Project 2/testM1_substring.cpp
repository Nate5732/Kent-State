// string Test Program
//
// Tests substring (sub from starting to end positions)
//
// Nathon Iadimarco
#include "string.hpp"
#include <cassert>
#include <iostream>

int main() {

    {

    String str("Computer");

    std::cout << str << std::endl;

    String result = str.substr(3,6);

    std::cout << "Substring from 3,6 == " << result << std::endl << std::endl;

    }

    {

    String str("Iadimarco");

    std::cout << str << std::endl;

    String result = str.substr(0,2);

    std::cout << "Substring from 0,2 == " << result << std::endl << std::endl;

    }

    {

    String str("Nathon");

    std::cout << str << std::endl;

    String result = str.substr(2,2);

    std::cout << "Substring from 2,2 == " << result << std::endl << std::endl;

    }

    {

    String str("Testing");

    std::cout << str << std::endl;

    String result = str.substr(4,2);

    std::cout << "Substring from 4,2 == " << result << std::endl << std::endl;

    }

std::cout << "Done testing subscript." << std::endl;


}

