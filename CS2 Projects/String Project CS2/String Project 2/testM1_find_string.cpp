// string Test Program
//
// Tests finding a string starting at a position
//
// Nathon Iadimarco
#include "string.hpp"
#include <cassert>
#include <iostream>

int main() {

{

String str("Nathon");
String str2("Iadimarco");

std::cout << str << std::endl;

int result = str.findstr(5, str2);

std::cout << str2  << " found at or after 5 at: " << result << std::endl << std::endl;


}

{

String str("ComputerScience");
String str2("Computer");

std::cout << str << std::endl;

int result = str.findstr(4, str2);

std::cout << str2 << " found at or after 4 at: " << result << std::endl << std::endl;


}

{

String str("KSU");
String str2("K");

std::cout << str << std::endl;

int result = str.findstr(0, str2);

std::cout << str2 << " found at or after 0 at: " << result << std::endl << std::endl;


}

{

String str("Test");
String str2("Testing");

std::cout << str << std::endl;

int result = str.findstr(2, str2);

std::cout << str2 << " found at or after 2 at: " << result << std::endl;
}

{

String str("Testing");
String str2("Test");

std::cout << str << std::endl;

int result = str.findstr(9, str2);

std::cout << str2 << " found at or after 9 at: " << result << std::endl;

std::cout << "-1, not found" << std::endl << std::endl;

}

std::cout << "Done testing find string." << std::endl;

}

