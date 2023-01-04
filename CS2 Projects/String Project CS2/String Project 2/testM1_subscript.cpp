// string Test Program
//
// Tests subscript
//
// Nathon Iadimarco
#include "string.hpp"
#include <cassert>
#include <iostream>

int main() {

    {
    String str("Test");
    std::cout << str << std::endl;
        
    char letter1 = str[0];
    char letter2 = str[1];
    char letter3 = str[2];
    char letter4 = str[3];
        
    assert(letter1 == 'T');
    assert(letter2 == 'e');
    assert(letter3 == 's');
    assert(letter4 == 't');
    }

    {
    String str("Nathon");
    std::cout << str << std::endl;

    char result;
    result = str[1];

    std::cout << "str[1] == " << result << std::endl << std::endl;
    }

    {
    String str("Iadimarco");
    std::cout << str << std::endl;

    char result;
    result = str[3];

    std::cout << "str[3] == " << result << std::endl << std::endl;
    }

std::cout << "Done testing subscript." << std::endl;

}
