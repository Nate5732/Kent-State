// Nathon Iadimarco
// Defines member functions for battleship.hpp
// 4/4/2022

#include "battleship.hpp"
#include <iostream>

using std::cout; using std::cin; using std::endl;


Location::Location() {
    x_ = -1;
    y_ = '*';
}

Ship::Ship() {
    sunk_ = false;
}

void Location::pick() {
        x_ = rand() % fieldSize_ + 1;
        int y = rand() % fieldSize_ + 1;
        switch (y) {
        case 1:
            y_ = 'a';
            break;
        case 2:
            y_ = 'b';
            break;
        case 3:
            y_ = 'c';
        case 4:
            y_ = 'd';
            break;
        case 5:
            y_ = 'e';
            break;
        case 6:
            y_ = 'f';
            break;
        }
}

bool compare(const Location& loc1, const Location& loc2) {
    return (loc1.x_ == loc2.x_ && loc1.y_ == loc2.y_);
}
    

void Location::fire() {
    cout << "Input a spot (1-6 a-f): ";
    cin >> x_ >> y_;
}

void Location::print() const {
    cout << x_ << y_ << endl;
}

void Ship::printShip() const {
    cout << "Ship at location ";
    loc_.print();
    if (sunk_) {
        cout << "This ship is sunk" << endl;
    }
    else {
        cout << "This ship is not sunk" << endl;
    }

}

void Ship::sink() {
    sunk_ = true;
}

void Ship::setLocation(const Location& loc) {
    loc_ = loc;
}

bool Ship::match(const Location& loc) const {
    return compare(loc, loc_);
}


void Fleet::printFleet() const {
    for (int i = 0; i < fleetSize_; i++) {
        ships_[i].printShip();
    }
}

int Fleet::check(const Location & loc) const {
    for (int i = 0; i < fleetSize_; i++) {
        if (ships_[i].match(loc)) {
            return i;
        }
    }
    return -1;
}

void Fleet::deployFleet() {
    int shipsDeployed = 0;
    while (shipsDeployed < fleetSize_) {
        Location loc;
        loc.pick();
        int pos = check(loc);
        if (pos == -1) {
            ships_[shipsDeployed].setLocation(loc);
            shipsDeployed++;
        }
    }
}

bool Fleet::operational() const {
    for (int i = 0; i < fleetSize_; i++) {
        if (!ships_[i].isSunk())
            return true;
    }
    return false;
}

bool Fleet::isHitNSink(const Location &loc) {
    int a;
    a = check(loc);
    if (a > -1){
    return true;
    }
    else {
        return false;
    }
}
