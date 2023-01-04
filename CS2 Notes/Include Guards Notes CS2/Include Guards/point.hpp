// File: point.hpp
//
// Simple 2D point ADT
// Include Guards

#include <iostream>
#ifndef CS2_POINT_HPP_
#define CS2_POINT_HPP_

class point {
public:
    point(); //Default
    point(double, double);
    point(double);
    void init(double, double);
    double getx();
    double gety();
    void setx(double);
    void sety(double);
    
    point add(point);
    point operator+(point);
    point operator-(point);
    
    
    point sub(point);
    
    double dist(point);
    
    void print(std::ostream&);
    
    
private:
    double x, y;
};

std::ostream& operator<<(std::ostream&, point);

#endif

