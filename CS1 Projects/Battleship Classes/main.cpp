#include "battleship.hpp"
#include <iostream>

using std::cout; using std::cin; using std::endl;


int main() {
srand(time(nullptr));
Fleet myFleet;
myFleet.deployFleet();
char y;
cout << "Do you want to printout ships? (y/n):";
cin >> y;
if (y == 'y') {
    myFleet.printFleet();
}
else {
}
while (myFleet.operational()) {
    Location loc;
    loc.fire();
    if (myFleet.isHitNSink(loc)) {
        cout << "You hit a ship.";
    }
    else {
        cout << "You missed.";
    }
    if (y == 'y') {
        myFleet.printFleet();
    }
    else {
    }
        
    }
}
