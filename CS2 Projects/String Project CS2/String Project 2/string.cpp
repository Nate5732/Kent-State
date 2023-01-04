// Nathon Iadimarco
// String Project
// CSII Section 001

#include "string.hpp"
#include <iostream>
#include <cassert>
#include <vector>

String::String() {
    stringSize = 1;
    str = new char[1];
    str[0] = '\0';
}


String::String(char ch) {
    if(ch == '\0') {
        stringSize = 1;
        str = new char[1];
        str[0] = '\0';
    } else{
        stringSize = 2;
        str = new char[2];
        str[0] = ch;
        str[1] = '\0';
    }
}

String::String(const char s[]) {
    int size = 0;
    while (s[size] != '\0') {
        ++size;
    }
        
    stringSize = size + 1;
    str = new char[stringSize];
    int i;
    for (i = 0; i < size; ++i) {
        str[i] = s[i];
    }
    str[size] = '\0';
}

// Copy constructor M2
String::String(const String& str2) {
    stringSize = str2.stringSize;
    str = new char[stringSize];
    for (int i = 0; i < stringSize; ++i) {
        str[i] = str2.str[i];
    }
}

// Default constructor M2
String::~String() {
    delete[] str;
}

// Constant time swap M2
void String::swap(String& str2) {
    char* temp = str;
    str = str2.str;
    str2.str = temp;
    int temp_size = stringSize;
    stringSize = str2.stringSize;
    str2.stringSize = temp_size;
}

// Assignment operator M2
String& String::operator=(String rhs) {
    swap(rhs);
    return *this;
}

int String::capacity() const {
    return stringSize - 1;
}

int String::length() const {
    int len = 0;
    while (str[len] != 0){
        ++len;
    }
    return len;
}

char& String::operator[](int i) {
    assert(0 <= i);
    return str[i];
}

char String::operator[](int i) const {
    assert(0 <= i);
    return str[i];
}

// Concatenation
String& String::operator+=(const String& rhs) {
    if(rhs == "") return *this;
    int RightLen = rhs.length();
    int LeftLen = length();
    int TotalLen = LeftLen + RightLen;
    char* temp = new char[stringSize + 1];
    int i = 0;
 
    for (i = 0; i < LeftLen; ++i) {
        if (i <= TotalLen) {
            temp[i] = str[i];
        }
    }
    stringSize = TotalLen + 1;
    delete[] str;
    str = temp;
    int j = 0;
    for (j  = 0; j < RightLen; ++j) {
        str[LeftLen + j] = rhs[j];
    }
    str[TotalLen] = '\0';
    return *this;
}

bool String::operator==(const String& rhs) const {
    if (length() == rhs.length()) {
        for (int i = 0; str[i] != 0 && rhs[i] != 0; ++i) {
            if (str[i] != rhs[i]) {
                return false;
            }
        }
        return true;
    }
    return false;
}

bool String::operator<(const String& rhs)const {
    int i = 0;
    while ((str[i] != 0 && rhs[i] != 0 && str[i] == rhs.str[i])) {
        ++i;
    }
    return str[i] < rhs.str[i];
}

String String::substr(int start, int end) const {
    if (start < 0) return String();
    if (start >= length()) return String();
    if (end < 0) return String();
    if (end < start) return String();
    char* tempChar = new char[end - start + 2];
    int i = start;
    int tempNum = 0;
    while (i <= end) {
        tempChar[tempNum] = str[i];
        ++i;
        ++tempNum;
    }
    tempChar[end - start + 1] = 0;
    String result = tempChar;
    delete[] tempChar;
    return result;
}

int String::findch(int start, char ch) const {
    if ((start < 0) || (start >= length())) return -1;
    int i = start;
    while (str[i] != 0) {
        if (str[i] == ch) return i;
        ++i;
    }
    return -1;
}

int String::findstr(int pos, const String& s) const {
    if (pos < 0) {
        pos = 0;
    }
    if (pos > length() - s.length()) {
        return -1;
    }
    int len = s.length();
    int i = pos;
    while (str[i] != '\0') {
        if (substr(i, i + len - 1) == s) {
            return i;
        }
        ++i;
    }
    return -1;
}


std::istream& operator>>(std::istream& in, String& rhs) {
    char ch[rhs.stringSize];
    in >> ch;
    rhs = String(ch);
    return in;
}

std::ostream& operator<<(std::ostream& out, const String& rhs) {
    out << rhs.str;
    return out;
}

std::vector<String> String::split(char ch) const {
    std::vector<String> result;
    int start = 0;
    while (findch(start, ch) != -1) {
        result.push_back(substr(start, findch(start, ch) -  1));
        start = findch(start, ch) + 1;
    }
    result.push_back(substr(start, length() - 1));

    return result;
}


String operator+(String lhs, const String& rhs) {
    return lhs += rhs;
}

bool operator==(const char lhs[], const String& rhs) {
    return (String(lhs) == rhs);
}

bool operator==(char lhs, const String& rhs) {
    return (String(lhs) == rhs);
}

bool operator<(const char lhs[], const String& rhs) {
    return (String(lhs) < rhs);
}

bool operator<(char lhs, const String& rhs) {
    return (String(lhs) < rhs);
}

bool operator<=(const String& lhs, const String& rhs) {
    return !(rhs < lhs);
}

bool operator!=(const String& lhs, const String& rhs) {
    return !(lhs == rhs);
}

bool operator>=(const String& lhs, const String& rhs) {
    return !(lhs < rhs);
}

bool operator>(const String& lhs, const String& rhs) {
    return (rhs < lhs);
}


