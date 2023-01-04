// string Test Program
//
// Tests Concatenation : +, +=
//
// Nathon Iadimarco
#include "string.hpp"
#include <cassert>
#include <iostream>

int main() {

    {

    String str("Stringy");
    String str2("String");

    String result;
    result = str + str2;

    assert(result == "StringyString");
    }
    
    {
    String str("Nathon ");
    String str2("Iadimarco");

    String result;
    result = str + str2;

    assert(result == "Nathon Iadimarco");
    }
    
    {
    String str("");
    String str2("");

    String result;
    result = str + str2;

    assert(result == "");
    }
    
    {
    String str("Hello");
    String str2("");

    String result;
    result = str + str2;

    assert(result == "Hello");
    }
    
    {
    String str("");
    String str2("Test");

    String result;
    result = str + str2;

    assert(result == "Test");
    }
    
    {
    String str("");
    String str2("");

    String result;
    result = str + str2;

    assert(result == "");
    }
    
    {
    String str("Nate ");
    String str2("I");

    String result;
    result = str + str2;

    assert(result == "Nate I");
    }
    
    {
    String str("Coding ");
    String str2("Now");

    str += str2;

    assert(str == "Coding Now");
    }
    
    {
    String str("");
    String str2("");

    str += str2;

    assert(str == "");
    }
    
    {
    String str("");
    String str2("Hi");

    str += str2;

    assert(str == "Hi");
    }
    
    {
    String str("abxyz");
    String str2("xyz");

    str += str2;

    assert(str == "abxyzxyz");
    }
    
    std::cout << "Done testing concatenation" << std::endl;

}
