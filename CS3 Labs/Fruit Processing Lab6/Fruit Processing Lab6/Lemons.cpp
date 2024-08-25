// Nathon Iadimarco Lab6 (Lemons)
// picking the best quality lemons
// converting vectors to priority queue
// Mikhail Nesterenko
// 2/17/2023

/*
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <queue>

using std::cin; using std::cout; using std::endl;
using std::string;
using std::vector;
using std::priority_queue;

struct Lemon {
    double quality;
    friend bool operator<(const Lemon& left, const Lemon& right) {
        return left.quality < right.quality;
    }
};

const int maxBoxSize = 30;
const int highestQuality = 10;

int main() {
    srand(time(nullptr));
    vector <Lemon> box(rand() % maxBoxSize + 1); // random box size

    // random quality assingment
    for (auto& lemon : box)
        lemon.quality = static_cast<double>(rand()) / RAND_MAX * highestQuality;

    cout << "Here are the lemons (best first): " << endl;

    priority_queue<Lemon> lemonQuality;
    for (int i = 0; i < box.size(); ++i) {
        lemonQuality.emplace(box[i]);
    }
    while (!lemonQuality.empty()) {
        Lemon best = lemonQuality.top();
        lemonQuality.pop();
        cout << best.quality << endl;
    }
    cout << endl;
}

*/
