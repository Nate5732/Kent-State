// Nathon Iadimarco
// Bigint.hpp
// CS II Section 001
 
#ifndef bigint_hpp_
#define bigint_hpp_
 
#include <iostream>
#include <fstream>
 
const int CAPACITY = 200;
 
class bigint {
public:
    bigint();  // Default Constructor to set bigint to 0
    bigint(int); // Initializing to an int
    bigint(const char[]); // Setting to a char[]
    void debugPrint(std::ostream&) const; // Debugging method for bigint
    bool operator==(const bigint&); // Method to compare if two bigints are equal
    friend std::ostream& operator<<(std::ostream&, const bigint&); // Method to ouput bigint
    bigint operator+(const bigint&) const; // Adds two Bigint's together
    int operator[](int) const; // (Subscript) Returns position of digit in a bigint
    friend std::istream& operator>>(std::istream&, bigint&); // Method to read bigint from input
    bigint timesDigit(int) const; // Method to multiply bigint by an integer 0-9
    bigint times10(int) const; // Method to multiply bigint by 10^n
    bigint operator*(const bigint&) const; // Method to multiply 2 bigints
private:
    int value[CAPACITY]; // Values within bigint
};
 
 
#endif
 

