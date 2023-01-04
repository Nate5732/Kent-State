// string Test Program
//
// Tests finding a character starting at a position
//
// Nathon Iadimarco
#include "string.hpp"
#include <cassert>
#include <iostream>

int main() {

    {

    String str("Nathon");
    std::cout << str << std::endl;
    char x = 't';
    int result = str.findch(2, x);

    std::cout << x << " found at 2: " << result << std::endl << std::endl;

    }

    {

    String str("Test");
    std::cout << str << std::endl;
    char x = 's';
    int result = str.findch(2, x);

    std::cout << x << " found at 2: " << result << std::endl << std::endl;


    }

    {
    String str("Computing");
    std::cout << str << std::endl;
    char x = 'i';
    int result = str.findch(6, x);

    std::cout << x << " found at 6: " << result << std::endl;

    }

    {
    String str("Iadimarco");
    std::cout << str << std::endl;
    char x = 'I';
    int result = str.findch(0, x);

    std::cout << x << " found at 0: " << result << std::endl << std::endl;
    }
    
    {
    String str("Hello,World");
    std::cout << str << std::endl;
    char x = ',';
    int result = str.findch(5, x);

    std::cout << x << " found at 5: " << result << std::endl << std::endl;
    }

std::cout << "Done testing find char." << std::endl;

}
