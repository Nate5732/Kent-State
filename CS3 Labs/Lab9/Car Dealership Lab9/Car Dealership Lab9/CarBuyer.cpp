// Nathon Iadimarco
// Car Dealership Lab9

#include <iostream>
#include <vector>
#include <cstdlib>
#include "CarFactory.hpp"
#include <array>

using std::vector;
using std::cout; using std::endl;
using std::string;

class CarLot{
public:
    CarLot();
    Car *testDriveCar(){return car4sale_;}
    
    // if a car is bought, requests a new one
    Car *buyCar(){
        Car *bought = car4sale_;
        car4sale_[next] = *(factories_[rand()%factories_.size()]->requestCar()); // Now works with array instead of just one
        return bought;
    }
    
    Car *nextCar(){
        ++next;
        if (next == lotSize_) {
            next = 0;
        }
        Car* result = &car4sale_[next];
        return result;
    }
    
    int lotSize() { return lotSize_; } // Function to return size of lot (8)
    
    void bought() {next = 0;}
    
private:
    static const int lotSize_ = 8;
    static int next;
    Car car4sale_[lotSize_]; // Array of cars for sale on the lot
    vector<CarFactory *> factories_;
};

int CarLot::next = 0;

CarLot::CarLot(){
    // creates 2 Ford factories and 2 Toyota factories
    factories_.push_back(new FordFactory());
    factories_.push_back(new ToyotaFactory());
    factories_.push_back(new FordFactory());
    factories_.push_back(new ToyotaFactory());
    
    // Filling lot with 8 random cars
    for (int i = 0; i < lotSize_; ++i) {
        car4sale_[i] = *(factories_[rand() % factories_.size()]->requestCar());
    }
}



CarLot *carLotPtr = nullptr; // global pointer instantiation

// test-drives a car
// buys it if Toyota
void toyotaLover(int id){
    if (carLotPtr == nullptr)
        carLotPtr = new CarLot();

    static const std::array<std::string, 5>
       models = {"Corolla", "Camry", "Prius", "4Runner", "Yaris"};
    string TModel_ = models[rand() % models.size()];  // Individual only likes specific model
    
    for(int i = 0; i < carLotPtr->lotSize(); ++i){
        Car *toBuy = carLotPtr -> nextCar();
    
        
        cout << "Jill Toyoter " << id << endl;
        cout << " test driving "
        << toBuy->getMake() << " "
        << toBuy->getModel();
    
        if (toBuy->getMake() == "Toyota" && toBuy->getModel() == TModel_){ // Correct make and model for preference causes purchase
            cout << " love it! buying it!" << endl;
            carLotPtr -> buyCar();
            carLotPtr -> bought(); // Resets next to 0 so next person will test first car on lot
            break;
        } else {
            cout << " did not like it!" << endl;
        }
    }
}
    
// test-drives a car
// buys it if Ford
void fordLover(int id){
    if (carLotPtr == nullptr)
        carLotPtr = new CarLot();

    static const std::array<std::string, 4>
       models = {"Focus", "Mustang", "Explorer", "F-150"};
    string FModel_ = models[rand() % models.size()]; // Individual only likes specific model
    
    for(int i = 0; i < carLotPtr->lotSize(); ++i){
        Car *toBuy = carLotPtr -> nextCar();
    
        cout << "Jack Fordman " << id << endl;
        cout << " test driving "
        << toBuy->getMake() << " "
        << toBuy->getModel();
    
        if (toBuy->getMake() == "Ford" && toBuy->getModel() == FModel_){ // Correct make and model for preference causes purchase
            cout << " love it! buying it!" << endl;
            carLotPtr -> buyCar();
            carLotPtr -> bought(); // Resets next to 0 so next person will test first car on lot
            break;
        } else {
            cout << " did not like it!" << endl;
        }
    }
}
    
    
    int main() {
        srand(time(nullptr));
        
        const int numBuyers=20;
        for(int i=0; i < numBuyers; ++i)
            if(rand()% 2 == 0)
                toyotaLover(i);
            else
                fordLover(i);
    }

