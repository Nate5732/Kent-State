// File main.cpp

#include "point.hpp"
#include <iostream>
int main() {
    point a, b; //default ctor is called
    point c(); //default ctor is called
    
    point d(3.0, 4.0);
    
    a = point(1.0, 4.0);
    
    a.init(4.3, 5.9);
    b.init(3, 5);
    
    std::cout << a.getx() << std::endl;
    
    b.setx (10);
    
    point c;
    
    // c = a.add(b);  invokes add
    //  c = a.operator+(b);  invokes operator+
    c = a + b; //uses operator+ as just a + sign
    c = a - b; //uses operator-
    
    c.print(std::cout);
    operator<<(std::cout, c);
    std::cout << c;
    
    
    std::cout << c " = " << a " + " << b << std::endl;
    
    double d = a.dist(b);
    
    return 0;
}
