// Nathon Iadimarco
// Lab11 Drink.hpp
// drink class to be used in Coffee Shack lab
// decorator pattern, pointer-based


#include <string>
#include <iostream>
#include <vector>
#include <list>

using std::cout; using std::endl;
using std::string; using std:: cin;
using std::vector; using std::list;

enum class DrinkType {small, medium, large};

class Drink{
public:
    Drink(DrinkType type = DrinkType::small, int price = 0):
        type_(type), price_(price){}
    virtual int getPrice() const {return price_;}
    virtual string getAdditives() const {
        string size;
        if (type_ == DrinkType::small) size = "small";
        if (type_ == DrinkType::medium) size = "medium";
        if (type_ == DrinkType::large) size = "large";
        return size + " coffee with ";
    }
    
private:
    int price_; // Drink Price
    DrinkType type_; // Drink Size
};

// Sugar Decorator ($1)
class Sugar : public Drink {
public:
    Sugar(const Drink* wrapped): wrapped_(wrapped) {}
    int getPrice() const override {return wrapped_->getPrice() + 1;} // Adds $1 to total coffee cost
    string getAdditives() const override {return wrapped_->getAdditives() + "sugar, ";}

private:
    const Drink *wrapped_;
};


// Cream Decorator ($2)
class Cream : public Drink {
public:
    Cream(const Drink* wrapped): wrapped_(wrapped) {}
    int getPrice() const override {return wrapped_->getPrice() + 2;} // Adds $2 to total coffee cost
    string getAdditives() const override {return wrapped_->getAdditives() + "cream, ";}
private:
    const Drink *wrapped_;
};

// Honey Decorator ($3)
class Honey : public Drink {
public:
    Honey(const Drink* wrapped): wrapped_(wrapped) {}
    int getPrice() const override {return wrapped_->getPrice() + 3;} // Adds $3 to total coffee cost
    string getAdditives() const override {return wrapped_->getAdditives() + "honey, ";}
private:
    const Drink *wrapped_;
};

class Customer;

// Barista class, serves customers.
class Barista {
public:
    Barista(Barista* next = nullptr) : next_(next) {}
    virtual Drink* Order(char input, list<Drink*> &coffee) {
        return next_->Order(input, coffee);
    }
    
    void makeCustomer(Customer *person) {customers_.push_back(person);} // Creates customer
    void deleteCustomer(int num) {customers_.erase(customers_.begin() + num);} // Deletes customer
    void notifyCustomer() const;
    string getCustName();
    
    char askAdditive(); // Used to get input of what additive customer wants
    void finishOrder();
    bool done() { return customers_.empty(); }
protected:
    static vector<Customer*> customers_; // Vector of customers
    int custNum; // Used to keep track of current customer
    int custLoop = 0; // Used to loop through all customers to check if it is their drink
private:
    Barista* next_;
};

vector<Customer *> Barista::customers_;


// Barista level classes
class JuniorBarista : public Barista {
public:
    JuniorBarista(Barista *next = nullptr) : Barista(next) {}
    Drink* Order(char input, list<Drink*> &coffee) override;
};

class SeniorBarista : public Barista {
public:
    SeniorBarista(Barista *next = nullptr) : Barista(next) {}
    Drink* Order(char input, list<Drink*> &coffee) override;
};

class Manager : public Barista {
public:
    Manager(Barista *next = nullptr) : Barista(next) {}
    Drink* Order(char input, list<Drink*> &coffee) override;
};

// Customer Class
class Customer {
public:
    Customer(const string& name, Barista* server, Drink* coffee):
        name_(name), server_(server), coffee_(coffee) {server->makeCustomer(this);}
    
    void notify() const;
    string getName() const {return name_;}
    Drink* getDrink() const {return coffee_;}
private:
    string name_;
    Barista *server_;
    Drink *coffee_;
};

// Barista funcs
void Barista::notifyCustomer() const {
    customers_[custNum]->notify();
}

string Barista::getCustName() {
    return customers_[custNum]->getName(); // Retrieves name of current customer
}

char Barista::askAdditive() {
    cout << "Would you like to add [s]ugar, [c]ream, [h]oney, or [d]one?" << endl;
    char additive;
    cin >> additive;
    return additive;
}

void Barista::finishOrder() {
    custNum = rand() % customers_.size();
    this->notifyCustomer();
    cout << customers_[custNum]->getName() << ", here is your "
    << customers_[custNum]->getDrink()->getAdditives()
    << "It will be $" << customers_[custNum]->getDrink()->getPrice()
    << " please." << endl;
    while(customers_[custLoop] != customers_[custNum]) {
        cout << customers_[custLoop]->getName() << " is not happy :(" << endl;
        ++custLoop;
    }
    cout << customers_[custLoop]->getName() << " is happy :)" << endl;
    custLoop = 0;
    this->deleteCustomer(custNum);
}

// Customer funcs
void Customer::notify() const {
    cout << endl << name_ << ", your drink is ready." << endl;
}

// Junior Barista making an order (can not use any additives)
Drink* JuniorBarista::Order(char input, list<Drink*> &coffee) {
    cout << "Welcome to Coffee Shack, can I get you [l]arge, [m]edium, or [s]mall coffee?" << endl;
    cin >> input;
    
    DrinkType drinkSize;
    int price = 0;
    switch(input) {
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
    coffee.push_back(new Drink(drinkSize, price));
    input = this->askAdditive(); // Getting additive input
    
    if (input == 'd') {
        cout << "Our Junior Barista will be preparing your order....." << endl;
        return coffee.back();
    }
    return Barista::Order(input, coffee);
    
}

// Senior Barista making an order (can only use sugar and cream)
Drink* SeniorBarista::Order(char input, list<Drink*> &coffee) {
    while(input != 'h') {
        cout << "Our Senior Barista will be preparing your order....." << endl;
        
        switch(input) {
            case 's':
                coffee.push_back(new Sugar(coffee.back()));
                break;
            case 'c':
                coffee.push_back(new Cream(coffee.back()));
                break;
            case 'd':
                return coffee.back();
        }
        input = this->askAdditive();
    }
    return Barista::Order(input, coffee);
}

// Manager making an order (can use all additives)
Drink* Manager::Order(char input, list<Drink*> &coffee) {
    while(input != 'd') {
        cout << "Our Manager will be preparing your order....." << endl;
        
        switch(input) {
            case 's':
                coffee.push_back(new Sugar(coffee.back()));
                break;
            case 'c':
                coffee.push_back(new Cream(coffee.back()));
                break;
            case 'h':
                coffee.push_back(new Honey(coffee.back()));
        }
        input = this->askAdditive();
    }
    return coffee.back();
}

