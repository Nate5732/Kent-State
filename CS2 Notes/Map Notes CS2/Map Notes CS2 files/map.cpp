




#include <iostream>
#include <fstream>
#include "map.hpp"

map::map() {
    for (int i = 0; i <MAP_SIZE; ++i) {
        coloring[i] = none;
        for (int j=0; j<MAP_SIZE; ++j) neighbor[i][j] = false;
    }
}


//
// ENSURES: Retval == TRUE if no adjacent country has the same color
bool map::isValidColoring(int country, color hue) const {
    for (int i=0; i<numOfCountries; ++i) {
        if (neighbor[country][i] && (coloring[i] == hue))
            return false;
    }
    return true;
}

std::ostream& operator<< (std::ostream& out, color c) {
    switch (c.tint) {
        case red    : out << "red";    break;
        case blue   : out << "blue";   break;
        case green  : out << "green";  break;
        case yellow : out << "yellow"; break;
        case none   : out << "none";
    }
    return out;
}

std::istream& operator>> (std::istream& in, map& m) {
    in >> m.numOfCountries;
    for (int i=0; i < m.numOfCountries; ++i) {
        for (int j=0; j<m.numOfCountries; ++j) {
            int temp;
            in >> temp; std::cout << temp;
            if (temp == 1) m.neighbor[i][j] = true;
            else           m.neighbor[i][j] = false;
        }
        std::cout << std::endl;
    }
    return in;
}

std::ostream& operator<< (std::ostream& out, const map& m) {
    int i;
    out << "Number of Countries: " << m.numOfCountries << std::endl;
    for (i=0; i<m.numOfCountries; ++i)
        out << "Country: " << i << " is " << m.coloring[i] << std::endl;
    return out;
}
