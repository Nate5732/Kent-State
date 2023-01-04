// Nathon Iadimarco
// Bigint.cpp
// CS II Section 001
 
#include "bigint.hpp"
 
// Setting bigint to 0
bigint::bigint() {
    for(int i = 0; i < CAPACITY; i++) {
        value[i] = 0;
    }
}
 
// Setting bigint to an int value (x)
bigint::bigint(int x) {
    for (int i = 0; i < CAPACITY; i++) {
        value[i] = x % 10;
        x /= 10;
    }
}
 
// Setting bigint to a const char[] value
bigint::bigint(const char arr[]) {
    int arrSize = 0;
    
    for (int i = 1; arr[i] != '\0'; i++) {
        arrSize++;
    }
    
    for (int i = 0; i < CAPACITY; i++) {
        if (i <= arrSize) {
            value[i] = arr[arrSize - i] - '0';
        }
        else {
            value[i] = 0;
            
        }
    }
}
 
// Prints each value of bigint
void bigint::debugPrint(std::ostream& out) const {
    for(int i = 0; i < CAPACITY; i++) {
            out << value[i] << '|';
    }
    out << std::endl;
}
 
// Checking if a bigint is equal to another bigint
bool bigint::operator==(const bigint& rhs) {
    for (int i = 0; i < CAPACITY; i++) {
        if (value[i] != rhs.value[i]) {
            return false;
        }
    }
    return true;
}
 
// Takes stream and bigint as input and outputs bigint
std::ostream& operator<<(std::ostream& out, const bigint& bi) {
    bool numStart = false;
    int Digits = 0;
    for (int i = CAPACITY - 1; i >= 0; i--) {
        if (bi.value[i] != 0) {
            numStart = true;
        }
        
        if (numStart == true){
            if (Digits < 40) {
                out << bi.value[i];
                Digits++;
            }
            else if (Digits == 40) {
                out << std::endl << bi.value[i];
                Digits++;
            }
            else if (Digits > 40 && Digits < 80) {
                out << bi.value[i];
                Digits++;
            }
            else if (Digits == 80) {
                out << std::endl << bi.value[i];
                Digits++;
            }
            else if (Digits > 80 && Digits < 120) {
                out << bi.value[i];
                Digits++;
            }
            else if (Digits == 120) {
                out << std::endl << bi.value[i];
                Digits++;
            }
            else if (Digits > 120 && Digits < 160) {
                out << bi.value[i];
                Digits++;
            }
            else if (Digits == 160) {
                out << std::endl << bi.value[i];
                Digits++;
            }
            else {
                out << bi.value[i];
                Digits++;
            }
            
        }
    }
    
    if (numStart == false) {
        out << 0;
    }
    return out;
}

// Overloading operator+ to add two bigints
bigint bigint::operator+(const bigint& rhs) const {
    bigint result;
    int digit = 0;
    for (int i = 0; i < CAPACITY; ++i) {
        result.value[i] = value[i] + rhs.value[i] + digit;
        if(result.value[i] > 9) {
            digit = 1;
        }
        else {
            digit = 0;
        }
        result.value[i] %= 10;
    }
    return result;
}

// Overloads subscript operator[]
int bigint::operator[](int x) const {
    return value[x];
}

// Overloads insertion operator
std::istream& operator>>(std::istream& in, bigint& rhs){
    char ch;
    char arr[CAPACITY];
    for (int j = 0; j < CAPACITY; j++){
        arr[j] = 0;
    }
    in >> ch;
    for (int i = 0; i<CAPACITY && ch != ';'; ++i){
        arr[i] = ch;
        in >> ch;
    }

    rhs = bigint(arr);
    return in;
}

// Multiplies bigint by an int 0-9
bigint bigint::timesDigit(int singleDigit) const {
    bigint result;
    int carry = 0;
    for(int i = 0; i < CAPACITY; i++) {
        result.value[i] = (value[i] * singleDigit) + carry;
            if(result.value[i] > 9) {
                carry = result.value[i] / 10;
            }
            else {
                carry = 0;
            }
        result.value[i] %= 10;
    }
    return result;
}

// Multiplies bigint by 10^n
bigint bigint::times10(int exp) const {
    bigint result;
    if(exp == 0) {
        return *this;
    }

    for(int i = CAPACITY - 1; i > 0; i--) {
        result.value[i] = value[i - 1];
    }
    --exp;

    while(exp > 0) {
    for(int i = CAPACITY - 1; i > 0; i--) {
            result.value[i] = result.value[i - 1];
        }
        --exp;
    }
    return result;
}

// Multiplies 2 bigints
bigint bigint::operator*(const bigint& rhs) const {
    bigint product;
    bigint num;
    for(int i = 0; i < CAPACITY; i++) {
        num = timesDigit(rhs.value[i]);
        product = product + num.times10(i);
    }
    return product;
}
