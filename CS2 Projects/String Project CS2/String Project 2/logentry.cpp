// Nathon Iadimarco
// CS 2
// File:        logentry.cpp
//
// Version:     1.0
// Date:
// Author:
//
// Description: Class implementation for a log entry.
//
//

////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>
#include "string.hpp"
#include "logentry.hpp"

Date::Date(String tmpDate) {
    day = tmpDate.substr(1,2);
    month = tmpDate.substr(4,6);
    String tmpYear = tmpDate.substr(8,11);
    year = changeInt(tmpYear);
}

Time::Time(String tmpTime) {
    String sec = tmpTime.substr(19,20);
    second = changeInt(sec);
    String min = tmpTime.substr(16,17);
    minute = changeInt(min);
    String hours = tmpTime.substr(13,14);
    hour = changeInt(hours);
}

LogEntry::LogEntry(String s) {
    // ...
    std::vector<String> vec = s.split(' ');
    
    if (vec.size() != 10) {
        host = "";
        date = Date();
        time = Time();
        request = "";
        status = "";
        number_of_bytes = 0;
    } else {
        host = vec[0];
        date = vec[3];
        time = vec[3];
        request = vec[5].substr(1,vec[5].length());
        status = vec[8];

        String bytes = vec[9];
        number_of_bytes = changeInt(bytes);

        if (vec[9] == "-") {
            number_of_bytes = 0;
        }

    }
}


std::vector<LogEntry> parse(std::istream& in) {
    std::vector<LogEntry> result;
    while (!in.eof()) {
        String x;
        char ch;
        in.get(ch);
        while(ch != '\0') {
            x = x + ch;
            in.get(ch);
        }
        result.push_back(x);
    }
    return result;
}


void output_all(std::ostream& out, const std::vector<LogEntry> &rhs) {
    for (int i = 0; i < int (rhs.size()) - 1; ++i) {
        out << rhs[i].getHost() << "| " << rhs[i].getDate().getDay() << " " << rhs[i].getDate().getMonth() << " " << rhs[i].getDate().getYear() << "| " << rhs[i].getTime().getHour() << ":" << rhs[i].getTime().getMinute() << ":" << rhs[i].getTime().getSecond() << "| " << rhs[i].getRequest() << "| " << rhs[i].getStatus() << "| " << rhs[i].getNumberOfBytes() << std::endl;
    }
}


void by_host(std::ostream& out, const std::vector<LogEntry>&rhs) {
    for(int i = 0; i < int (rhs.size()); ++i) {
        out << rhs.at(i).getHost() << std::endl;
    }
}


int byte_count(const std::vector<LogEntry> &rhs) {
    int Bytes = 0;
    for(int i=0; i < int (rhs.size()); ++i) {
        Bytes += rhs[i].getNumberOfBytes();
    }
    return Bytes;
}

int changeInt(String str) {
    int result = 0;
    int x = 10;
    int stringLen = str.length();
    for (int i = 0; i < stringLen; ++i) {
        result *= x;
        result += str[i] - '0';
    }
    return result;
}
