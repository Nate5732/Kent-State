// Nathon Iadimarco
// multiply.cpp for biging project

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "bigint.hpp"

int main() {
    std::ifstream file("data1-2.txt");
    if(!file) {
        std::cout << "File not found: data1-2.txt" << std::endl;
        return 1;
    }

    std::cout << "Gets bigints from file and multiplies them until end of file:" << std::endl << std::endl;

    bigint lhs, rhs, result;
    while(!file.eof() && file >> lhs) {
    //getting bigints from file
    if(!file.eof()) file >> rhs;

    //prints values of bigints
    std::cout << "lhs = " << lhs << std::endl;
    std::cout << "rhs = " << rhs << std::endl << std::endl;

    //uses * operator to multiply bigints and prints result
    result = lhs * rhs;
    std::cout << "result = " << result << std::endl << std::endl;
    }

    file.close();
    return 0;
}
