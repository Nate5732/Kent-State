// Nathon Iadimarco
// Coffee Shack Lab11
// Part 1, Coffee Shack no barista
// Decorator Observer Chain of Responsibility
/*
#include <iostream>
#include "Drink.hpp"

int main() {
    
    char size;
    char additive = '\0';
    Drink* coffee;
    DrinkType drinkSize;
    int price;
    cout << "Welcome to Coffee Shack, can I get you [l]arge, [m]edium, or [s]mall coffee?" << endl;
    cin >> size;
    
    // Switch case to add respective price to size of drink requested
    switch (size) {
        case 'l':
            drinkSize = DrinkType::large;
            price = 10;
            break;
        case 'm':
            drinkSize = DrinkType::medium;
            price = 7;
            break;
        case 's':
            drinkSize = DrinkType::small;
            price = 5;
            break;
    }
    
    coffee = new Drink(drinkSize, price);
    
        while (additive != 'd') {
            if (size == 'l') {
                price = 10;
                drinkSize = DrinkType::large;
                cout << "Would you like to add [s]ugar, [c]ream, [h]oney, or [d]one?" << endl;
                cin >> additive;
                if (additive == 's') coffee = new Sugar(coffee);
                if (additive == 'c') coffee = new Cream(coffee);
                if (additive == 'h') coffee = new Honey(coffee);
            }
            if (size == 'm') {
                price = 7;
                drinkSize = DrinkType::medium;
                cout << "Would you like to add [s]ugar, [c]ream, [h]oney, or [d]one?" << endl;
                cin >> additive;
                if (additive == 's') coffee = new Sugar(coffee);
                if (additive == 'c') coffee = new Cream(coffee);
                if (additive == 'h') coffee = new Honey(coffee);
            }
            if (size == 's') {
                price = 5;
                drinkSize = DrinkType::small;
                cout << "Would you like to add [s]ugar, [c]ream, [h]oney, or [d]one?" << endl;
                cin >> additive;
                if (additive == 's') coffee = new Sugar(coffee);
                if (additive == 'c') coffee = new Cream(coffee);
                if (additive == 'h') coffee = new Honey(coffee);
            }
        }
    string name;
    cout << "Can I get your name? ";
    cin >> name;
    cout << name << ", your " << coffee->getAdditives() << "is ready. It will be $" << coffee->getPrice() << ", please." << endl;
}

*/

