// string Test Program
//
// Tests: <, >, <=, >=
//
// Nathon Iadimarco
#include "string.hpp"
#include <cassert>
#include <iostream>

int main() {

    {

    char str1 = 'n';
    String str2("nathon");

    bool result = str1 < str2;
    assert(result);

    }

    {
    char str1 [] = "code";
    String str2("coding");

    bool result = str1 < str2;
    assert(result);

    }
    
    {

    String str1("Test");
    String str2("Testing");

    bool result = str1 < str2;
    assert(result);
    }

    {

    String str1("lap");
    String str2("laptop");

    bool result = str1 < str2;
    assert(result);
    }

    {
    String str1("Iadimarco");
    String str2("Iadimarco");

    bool result = str1 <= str2;
    assert(result);
    }

    {
    String str1("Computer");
    String str2("Compute");

    bool result = str1 > str2;
    assert(result);

    }

    {
    String str1("Computer");
    String str2("Computer");

    bool result = str1 >= str2;
    assert(result);

    }

    {
    String str1("ab");
    String str2("c");
        
    bool result = str1 < str2;
    assert(result);
    }


    {
    String str1("a");
    String str2("z");
        
    bool result = str1 < str2;
    assert(result);
    }
    
    {
    String str1("abcdefghijklmnopqrstuvwxyz");
    String str2("a");

    bool result = str1 > str2;
    assert(result);
    }

std::cout << "Done Testing Less Than." << std::endl;

}

