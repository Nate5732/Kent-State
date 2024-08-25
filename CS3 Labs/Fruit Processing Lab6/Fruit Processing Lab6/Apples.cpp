// Nathon Iadimarco Lab6 (Apples)
// sorting apples
// non STL-algorithm code to be replaced by algorthms
// Mikhail Nesterenko
// 09/26/2022
/*

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>
#include <functional>
#include <numeric>

using std::cin; using std::cout; using std::endl;
using std::string;
using std::vector; using std::deque;
using std::generate;

struct Apples {
    double weight; // oz
    string color;  // red or green
    void print() const { cout << color << ", " << weight << endl; }
};



int main() {
    srand(time(nullptr));
    const double minWeight = 3.;
    const double maxWeight = 8.;

    cout << "Input crate size: ";
    int size;
    cin >> size;

    vector <Apples> crate(size);

    // assign random weight and color to apples in the crate
    // replace with generate()
    for (auto& e : crate) {
        generate(crate.begin(), crate.end(), [minWeight, maxWeight]() {
            Apples apple;
            apple.weight = minWeight + static_cast<double>(rand()) / RAND_MAX * (maxWeight - minWeight);
            apple.color = rand() % 2 == 1 ? "red" : "green";
            return apple;
        });
    }



    // for_each() possibly
    cout << "all apples:" << endl;
    std::for_each(crate.begin(), crate.end(), [](Apples& apple) {apple.print();});

    cout << "Enter weight to find: ";
    double toFind;
    cin >> toFind;

    // count_if()
    int cnt = std::count_if(crate.begin(), crate.end(), [=](Apples& heavierApple) {return heavierApple.weight > toFind;});

    cout << "There are " << cnt << " apples heavier than "
        << toFind << " oz" << endl;

    // find_if()
    cout << "at positions ";
    auto it = crate.begin();
    while ((it = std::find_if(it, crate.end(), [toFind](const Apples& apple) { return apple.weight > toFind; })) != crate.end()) {
        cout << " " << it - crate.begin() << " ";
        ++it;
    }
    cout << endl;

    // max_element()
    it = std::max_element(crate.begin(), crate.end(), []( Apples small, Apples big) { return small.weight < big.weight; });
    cout << "Heaviest apple weighs: " << it->weight;
    cout << endl;


    // for_each() or accumulate()
    double totalWeight = 0;
    //std::for_each(crate.begin(), crate.end(), [&totalWeight](Apples appleIt) {return totalWeight += appleIt.weight;});
    //cout << "Total apple weight is: " << totalWeight << " oz" << endl;

    // Using accumulate here. 0.0 is the starting value as a double to accumulate all apples weight values in crate.
    // sum holds value of all apples respective to apples iterated already.
    // appleIt is current apple in iteration process. (lambda adds its weight to sum)
    totalWeight = std::accumulate(crate.begin(), crate.end(), 0.0, [](double sum, Apples appleIt) { return sum + appleIt.weight;});
    cout << "Total apple weight is: " << totalWeight << " oz" << endl;

    // transform();
    cout << "How much should they grow: ";
    double toGrow;
    cin >> toGrow;
    std::transform(crate.begin(), crate.end(), crate.begin(), [=](Apples apple) {
        Apples a;
        a.weight = apple.weight + toGrow;
        a.color = apple.color;
        return a;
        });

    // remove_if()
    cout << "Input minimum acceptable weight: ";
    double minAccept;
    cin >> minAccept;

    crate.erase(std::remove_if(crate.begin(), crate.end(), [&minAccept](Apples removeApple) {return removeApple.weight < minAccept;}), crate.end());
    cout << "removed " << size - crate.size() << " elements" << endl;

    // bubble sort, replace with sort()
    std::sort(crate.begin(), crate.end(), [=](Apples apple1, Apples apple2) {return apple1.weight < apple2.weight;});


    // for_each() possibly
    cout << "sorted remaining apples" << endl;
    std::for_each(crate.begin(), crate.end(), [](Apples apple) {return apple.print();});

}
*/
