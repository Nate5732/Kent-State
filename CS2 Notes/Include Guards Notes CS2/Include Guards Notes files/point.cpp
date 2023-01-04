// File: point.cpp
#include "point.hpp"

point::point() {
    x = 0.0;
    y = 0.0;
}

point::point(double nx, double ny) {
    x = nx;
    y = ny;
}


void point::init(double nx, double ny) {
    x = nx;
    y = ny;
}

double point::getx() {
    return x;
}

double point::gety() {
    return y;
}

void point::setx(double nx) {
    x = nx;
}

void point::sety(double ny) {
    y = ny;
}

point point::operator+(point rhs) {
    point result;
    result.x = x + rhs.x;
    result.y = y + rhs.y;
    return result;
}

point point::operator-(point rhs) {
    point result;
    result.x = x - rhs.x;
    result.y = y + rhs.y;
    return result;
}


point point::add(point rhs) {
    point result;
    
    result.x = x + rhs.x;
    result.y = y + rhs.y;
    
    return result;
}

void point::print(std::ostream& out) {
    out << "(" << x << " , " << y << ")";
}

std::ostream& operator<<(std::ostream& out, point rhs) {
    out << "(" << rhs.getx() << " , " << rhs.gety() << ")";
}
