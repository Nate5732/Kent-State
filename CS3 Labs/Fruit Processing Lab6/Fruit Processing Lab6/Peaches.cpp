// Nathon Iadimarco Lab6 (Peaches)
// jamming peaches
// non STL-algorithm code to be replaced by algorthms
// Mikhail Nesterenko
// 9/30/2021

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>
#include <functional>
#include <iterator>
#include <numeric>


using std::cin; using std::cout; using std::endl;
using std::string;
using std::vector; using std::deque;
using namespace std::placeholders;

struct Peaches{
    double weight; // oz
    bool ripe;  // ripe or not
    void print() const { cout << (ripe ? "ripe" : "green") << ", " <<  weight << endl; }
};

// putting all small ripe peaches in a jam
// use a binder to create a functor with configurable max weight
// accumulate() or count_if() then remove_if()
// functor class
class jam {
public:
    jam() { jamWeight = 0; }; // Setting weight to 0
    double operator() (deque<Peaches> &peck, double maxJam) {
        jamWeight = accumulate(peck.begin(), peck.end(), 0.0, [&](double sum, const Peaches& peach) {
            return sum + (peach.ripe && peach.weight <= maxJam ? peach.weight : 0);
        });
        // Removing ripe peaches used in jam
        peck.erase(remove_if(peck.begin(), peck.end(), [&](const Peaches& peach) {
            return peach.ripe && peach.weight <= maxJam;
        }), peck.end());
        return jamWeight;
    }

private:
    double jamWeight;
};



int main(){
    srand(time(nullptr));
    const double minWeight = 3.;
    const double maxWeight = 8.;
    
    cout << "Input basket size: ";
    int size;
    cin >> size;
    
    vector <Peaches> basket(size);
    
    // assign random weight and ripeness peaches in the basket
    // replace with generate()
    // filling basket with peaches that have random sizes and ripeness using generate
    generate(basket.begin(), basket.end(), [minWeight, maxWeight] {
        Peaches peach;
        peach.weight = minWeight + static_cast<double>(rand()) / RAND_MAX * (maxWeight - minWeight);
        peach.ripe = (rand() % (1 - 0 + 1)) == 1;
        return peach;
    });
    
    
    // for_each() possibly
    cout << "all peaches" << endl;
    for_each(basket.begin(), basket.end(), [](Peaches peach) {peach.print();}); // Printing all peaches ripeness and weight
    cout << endl;
    
    // moving all the ripe peaches from basket to peck
    // remove_copy_if() with back_inserter()/front_inserter() or equivalents
    // deque to store the ripe peaches
    deque<Peaches> peck;
    std::remove_copy_if(basket.begin(), basket.end(), std::front_inserter(peck), [=](Peaches peach) {return peach.ripe != 1;}); // Makes use of front_inserter to insert elements at the beginning of deque container
    basket.erase(remove_if(basket.begin(), basket.end(), [=](Peaches peach) {return peach.ripe == 1;}), basket.end());
    
    
    // for_each() possibly
    cout << "peaches remaining in the basket" << endl;
    for_each(basket.begin(), basket.end(), [](Peaches& peach) {peach.print();}); // Printing peaches remaining in basket
    cout << endl;
    
    // for_each() possibly
    cout << "peaches moved to the peck" << endl;
    for_each(peck.begin(), peck.end(), [=](Peaches peach) {if(peach.weight!=0)peach.print();}); // Printing peaches moved to peck
    
    
    // prints every "space" peach in the peck
    const int space=3;
    int peach = 1;
    cout << "\nevery " << space << "\'d peach in the peck"<< endl;
    
    // replace with advance()/next()/distance()
    // no explicit iterator arithmetic
    auto it=peck.cbegin();
    while(it != peck.cend()){
        if(peach % space == 0 && it->weight != 0) {
            it->print();
        }
        ++peach;
        std::advance(it, 1); // Moves it forward by 1 using advance
    }
    
    double weightToJam = 10.0;
    jam peachJam; // Functor object of jam class
    auto jammer = std::bind(&jam::operator(), &peachJam, _1, weightToJam); // Binding using placeholder
    double jamWeight = jammer(peck);
    cout << "Weight of jam is " << jamWeight << endl; // Printing jam weight

}

