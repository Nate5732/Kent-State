// Nathon Iadimarco
// Coffee Shack Lab11
// Part 2/3, Coffee Shack with Barista and notifying
// Decorator Observer Chain of Responsibility

#include "Drink.hpp"
#include <ctime>
#include <random>

int main() {
    srand((unsigned)time(nullptr));

    const int totalCust = 4; // Total number of customers
    cout << "Today, there are " << totalCust << " customer(s) at the shack!" << endl;
    JuniorBarista *server = new JuniorBarista(new SeniorBarista(new Manager));
    int custIndex = 0; // Used to iterate through customers
    while(custIndex != totalCust || !server->done()) { // While selected customer isnt equal to total or the customers vector is not empty.
        int ready = rand() % 2; // 50/50 chance for coffee to be ready
        if(ready == 0 && custIndex != totalCust) { // Not ready
            char input = '\0';
            list<Drink *> coffee;
            string name;

            server->Order(input, coffee);

            cout << "Can I get your name? ";
            cin >> name;

            new Customer(name, server, coffee.back());
            custIndex++; // Moving on to help next customer
        } else if (ready == 1 && !server->done()) { // Ready
            server->finishOrder();
        }
    }
    return 0;
}


