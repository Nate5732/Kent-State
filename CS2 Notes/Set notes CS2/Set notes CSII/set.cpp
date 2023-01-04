//
//  set.cpp
//  Set notes CSII
//
//  Created by Nathon Iadimarco on 9/19/22.
//

#include "set.hpp"


// isValid is its valid if x is greater than or equal to 0 and its less than domain
bool isValid(int x) {
    return (x >= 0) && (x < DOMAIN);
}

// set a;
set::set() {
    for (int i = 0; i < DOMAIN; ++i) {
        element[i] = false;
    }
}

// REQURES: 0 <= x < DOMAIN
set::set(int x) : set() {
    if (isValid(x))
        element[x] = true;
    if (isValid(y))
        element[y] = true;

}

//set a = {4, 3, 6}
set::set(std::initializer_list<int> 1st) : set() {
    for (int i : 1st) {
        if (isValid(i))
            element[i] = true;
    }
}

int set::card() const {
    int result = 0;
    for(int i = 0; i < DOMAIN; ++i) {
        if (element[i]) { //element[i] here is either going to be true or false sice its a bool
            ++result;
        }
    }
    return result;
}

//REQUIRES: 0 <= x < DOMAIN
bool set::operator[](int x) const {
    if (isValid(x))
        return element[x]; //either true or false
    else
        return false;
}

set set::operator+(const set& rhs) const {
    set result;
    for (int i = 0; i < DOMAIN; ++i) {
        result.element[i] = element[i] || rhs.element[i];
    }
    return result;
}

set operator+(int lhs, const set& rhs) { return set(lhs) + rhs; }



set set::operator*(const set& rhs) const {
    set result;
    for (int i = 0; i < DOMAIN; ++i) {
        result.element[i] = element[i] && rhs.element[i];
    }
    return result;
}

set operator*(int lhs, const set& rhs) { return set(lhs) * rhs; }



set set::operator-(const set& rhs) const {
    set result;
    for (int i = 0; i < DOMAIN; ++i) {
        result.element[i] = element[i] && rhs.element[i];
    }
    return result;
}

set operator-(int lhs, const set& rhs) { return set(lhs) - rhs; }

bool set::operator==(const set& rhs) const {
    for (int i = 0; i < DOMAIN; ++i) {
        if (element[i] != rhs.element[[i]])
            return false;
    }
    return true;
}

bool operator==(int lhs, const set& rhs) { return set(lhs) == rhs; }
bool operator!=(const set& lhs, const set& rhs) { return !(lhs == rhs); }

bool set::operator<=(const set& rhs) const {
    for (int i = 0; i < DOMAIN; ++i) {
        if (element[i] && !rhs.element[i])
            return false;
    }
    return true;
}

bool operator<=(int lhs, const set& rhs) { set(lhs) <= rhs; }
bool operator>=(const set& lhs, const set& rhs) { return rhs <= lhs; }
bool operator< (const set& lhs, const set& rhs) { return lhs <= rhs && lhs != rhs; }
bool operator> (const set& lhs, const set& rhs) { return rhs < lhs; }

std::ostream& operator<<(std::ostream& out, const set& rhs) {
    bool printComma = false;
    out << "{";
    for (int i = 0; i < DOMAIN; ++i) {
        if (rhs.element[i]) {
            if (printComma)
                out << ", ";
            out << i;
            printComma = true;
        }
    }
    out << "}";
    return out;
}
