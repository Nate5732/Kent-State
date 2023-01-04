// Nathon Iadimarco
// add.cpp
// CSII Section 001
// Basics for opening a file for milestone 2

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "bigint.hpp"

int main() {
    std::ifstream in("data1-1.txt");    // Opening file
    if(!in) {                  // Make sure it opened correctly.
        std::cerr << "File not found: data1-1.txt" << std::endl;
        return 1;
    }

    std::cout << "Gets bigints from file and adds them until end of file:" << std::endl;

    bigint lhs;
    bigint rhs;
    bigint result;

    while(!in.eof() && in >> lhs) {
        //getting bigints from input
        if(!in.eof()) in >> rhs;

        //prints bigints
        std::cout << "lhs = " << lhs << std::endl;
        std::cout << "rhs = " << rhs << std::endl << std::endl;

        //adds bigints and prints result
        result = lhs + rhs;
        std::cout << "result = " << result << std::endl << std::endl;
    }

    in.close();
    return 0;
}
