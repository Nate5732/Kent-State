//
//  set.hpp
//  Set notes CSII
//
//  Created by Nathon Iadimarco on 9/19/22.
//

#ifndef set_hpp
#define set_hpp
#include <iostream>

const int DOMAIN = 200;

class set {
public:
    set();
    set(int);
    set(int, int);
    set(std::initializer_list<int>);
    
    int card() const;
    bool operator[](int) const;
    
    set operator+(const set&) const;
    set operator*(const set&) const;
    set operator-(const set&) const;
    bool operator==(const set&) const;
    bool operator<=(const set&) const;
    
        friend std::ostream& operator<<(std::ostream&, const set&);
    
private:
        bool element[DOMAIN];
};

set operator+ (int, const set&);
set operator* (int, const set&);
set operator- (int, const set&);
bool operator==(int, const set&);
bool operator<=(int, const set&);
bool operator!=(const set&, const set&);
bool operator<(const set&, const set&);
bool operator>=(const set&, const set&);
bool operator>(const set&, const set&);
#endif /* set_h */
