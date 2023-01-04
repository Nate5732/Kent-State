






// Purpose: Map coloring via backtracking
#include <iostream>
#include <fstream>
#include "map.hpp"


// REQUIRES: world is assigned
// ENSURES: Valid four coloring of map
bool colorMap(int country, map& world) {
    if (country == world.numberOfCountries()) return true; // Done
    
    bool doneColoring = false;
    bool aColorRemains = true;
    color hue = red;
    
    while (aColorRemains && !doneColoring) {
        if (world.isValidColoring(country, hue)) {
            world.colorCountry(country, hue);
            doneColoring = colorMap(country+1, world);
        }
        if (hue == yellow)
            aColorRemains = false;
        else
            hue++;
    }
    if(!doneColoring)
        world.colorCountry(country, none); //Need to backtrack
    
    return doneColoring;
}

//
int main() {
    map world;
    
    std::ifstream in("map1.txt");
    in >> world;
    colorMap(0, world);
    std::cout << world;
    std::cout << "Done." << std::endl;
    return 0;
}
